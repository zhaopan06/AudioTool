#include "HttpAsyncWorker.h"
#include <QNetworkReply>
#include <QDebug>
#include "Global.h"
#include <QPointer>
#include "HttpUserInfo.h"
#include "qtimer.h"
#include <QSslConfiguration>
#include "ToastPage.h"
#include "qurlquery.h"

HttpAsyncWorker* HttpAsyncWorker::getInstance()
{
    static HttpAsyncWorker instance;
    return &instance;
}

HttpAsyncWorker::HttpAsyncWorker(QObject* parent)
    : QObject(parent),
    m_manager(new QNetworkAccessManager(this)),
    m_activeRequests(0),
    m_maxConcurrentRequests(4),
    m_requestTimeout(30000)
{
    moveToThread(&m_workerThread);
    m_manager->moveToThread(&m_workerThread);
    m_workerThread.start();

    connect(this, &HttpAsyncWorker::requestAdded, this, &HttpAsyncWorker::handleRequest, Qt::QueuedConnection);
}

HttpAsyncWorker::~HttpAsyncWorker()
{
    m_workerThread.quit();
    m_workerThread.wait();
}

void HttpAsyncWorker::submitRequest(RequestMethod method, const QString& url,
                                    const ResponseCallback& successCallback,
                                    const ErrorCallback& errorCallback,
                                    const QVariantMap &body,
                                    QObject* context /* = nullptr */)
{
    QMutexLocker locker(&m_queueMutex);

    RequestTask task;
    task.method = method;
    task.url = url;
    task.body = body;
    task.successCallback = successCallback;
    task.errorCallback = errorCallback;
    task.context = context ? context : g_main;
    task.timeout = m_requestTimeout;

    m_requestQueue.enqueue(task);
    emit requestAdded();
}

void HttpAsyncWorker::handleRequest()
{
    QMutexLocker locker(&m_queueMutex);

    if (m_requestQueue.isEmpty() || m_activeRequests >= m_maxConcurrentRequests)
    {
        return;
    }

    RequestTask task = m_requestQueue.dequeue();
    m_activeRequests++;

    QByteArray body = QJsonDocument::fromVariant(task.body).toJson();
    QString fullUrl = m_baseUrl + task.url;
    QNetworkRequest request = createRequest(fullUrl);

    QSharedPointer<QTimer> timeoutTimer(new QTimer);
    timeoutTimer->setSingleShot(true);
    timeoutTimer->setInterval(task.timeout);

    QNetworkReply* reply = nullptr;
    switch (task.method)
    {
    case RequestMethod::GET:
    {
        QNetworkRequest request = createRequest(fullUrl, task.body);
        reply = m_manager->get(request);
        break;
    }
    case RequestMethod::POST:
        reply = m_manager->post(request, body);
        break;
    case RequestMethod::PUT:
        reply = m_manager->put(request, body);
        break;
    case RequestMethod::PATCH:
        reply = m_manager->sendCustomRequest(request, "PATCH", body);
        break;
    }

    if (reply)
    {
        // 设置超时处理
        connect(timeoutTimer.data(), &QTimer::timeout, [=]() {
            reply->abort();
            QMetaObject::invokeMethod(qApp, []() {
                QString toastMsg = QStringLiteral("请求超时");
                ToastPage::showToast(nullptr,toastMsg);
            }, Qt::QueuedConnection);
        });
        timeoutTimer->start();

        QObject::connect(reply, &QNetworkReply::finished, reply, [=]{

            timeoutTimer->stop();

            QByteArray response = reply->readAll();
            QJsonParseError json_error;
            QJsonDocument jsonDocument = QJsonDocument::fromJson(response, &json_error);

            QPointer<QObject> targetContext = task.context ? QPointer<QObject>(task.context) :  QPointer<QObject>(g_main);
            if (reply->error() != QNetworkReply::NoError)
            {
                if(task.errorCallback)
                {
                    const int errorCode = reply->error();
                    const QString errorMsg = reply->errorString();
                    const auto errorCallback = task.errorCallback;
                    QMetaObject::invokeMethod(qApp, [=]() {
                        if (!targetContext)
                        {
                            qDebug() << "Context object no longer exists";
                            return;
                        }
                        try {
                            errorCallback(errorCode, errorMsg);
                        } catch (...) {
                            qCritical() << "Exception in error callback";
                        }
                    }, Qt::QueuedConnection);
                }

                QString errorMsg = reply->errorString();
                qDebug()<<"errorMsg---"<<errorMsg<<"reply->error()---"<<reply->error();
                QMetaObject::invokeMethod(g_main, [=]() {
                    ToastPage::showToast(nullptr,errorMsg);
                }, Qt::QueuedConnection);
            }
            else if(json_error.error != QJsonParseError::NoError)
            {
                if(task.errorCallback)
                {
                    const QString errorMsg = json_error.errorString();
                    const auto errorCallback = task.errorCallback;
                    QMetaObject::invokeMethod(targetContext, [=]() {
                        errorCallback(-1, "JSON parse error: " + errorMsg);
                    }, Qt::QueuedConnection);
                }

                QString errorMsg = json_error.errorString();
                QMetaObject::invokeMethod(g_main, [=]() {
                    ToastPage::showToast(nullptr,errorMsg);
                }, Qt::QueuedConnection);
            }
            else if(jsonDocument["code"].toInt() != 1)
            {
                if(jsonDocument["code"].toInt() == 0 || jsonDocument["code"].toInt() == 356)
                {
                    emit error_msg_box_text(jsonDocument["message"].toString(),jsonDocument["code"].toInt());
                }

                if(task.errorCallback)
                {
                    QMetaObject::invokeMethod(targetContext, [=]() {
                        task.errorCallback(jsonDocument["code"].toInt(),
                                           jsonDocument["message"].toString());
                    }, Qt::QueuedConnection);
                }

                QString errorMsg = jsonDocument["message"].toString();
                QMetaObject::invokeMethod(g_main, [=]() {
                    ToastPage::showToast(nullptr,errorMsg);
                }, Qt::QueuedConnection);
            }
            else if(task.successCallback)
            {                
                QMetaObject::invokeMethod(targetContext, [=]() {
                    task.successCallback(jsonDocument.toVariant().toMap());
                }, Qt::QueuedConnection);
            }

            reply->deleteLater();
            m_activeRequests--;

            QMetaObject::invokeMethod(this, &HttpAsyncWorker::handleRequest, Qt::QueuedConnection);
        });
    }
    else
    {
        m_activeRequests--;
        QString errorMsg = "Failed to create request";
        QMetaObject::invokeMethod(g_main, [=]() {
            ToastPage::showToast(nullptr,errorMsg);
        }, Qt::QueuedConnection);

        QMetaObject::invokeMethod(this, &HttpAsyncWorker::handleRequest, Qt::QueuedConnection);
    }
}

QNetworkRequest HttpAsyncWorker::createRequest(const QString& url, const QVariantMap &body)
{
    QUrlQuery query;
    for (auto it = body.constBegin(); it != body.constEnd(); ++it)
    {
        query.addQueryItem(it.key(), it.value().toString());
    }
    QUrl qurl(url);
    qurl.setQuery(query);

    QNetworkRequest request;
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    if(url.contains("user-avatar-frame-record/wear"))
        request.setUrl(url);
    else
        request.setUrl(qurl);

    if (url.startsWith("https://", Qt::CaseInsensitive))
    {
        QSslConfiguration sslConfig = QSslConfiguration::defaultConfiguration();
        sslConfig.setPeerVerifyMode(QSslSocket::VerifyNone);
        sslConfig.setProtocol(QSsl::TlsV1_2OrLater);
        request.setSslConfiguration(sslConfig);
    }

    for (auto it = m_map.constBegin(); it != m_map.constEnd(); ++it)
    {
        request.setRawHeader(it.key().toUtf8(), it.value().toUtf8());
    }

    QString token = HttpUserInfo::instance()->gettoken();
    request.setRawHeader("token", token.isEmpty() ? "0" : token.toLatin1());
    return request;
}

void HttpAsyncWorker::setMaxConcurrentRequests(int max)
{
    QMutexLocker locker(&m_queueMutex);
    m_maxConcurrentRequests = qMax(1, max);
}

void HttpAsyncWorker::setBaseUrl(const QString& baseUrl)
{
    QMutexLocker locker(&m_queueMutex);
    m_baseUrl = baseUrl;
}

void HttpAsyncWorker::setRequestTimeout(int milliseconds)
{
    QMutexLocker locker(&m_queueMutex);
    m_requestTimeout = qMax(1000, milliseconds);
}

void HttpAsyncWorker::setHeaders()
{
    QMutexLocker locker(&m_queueMutex);
    QMap<QString, QString> map;
    map.insert("deviceId", "11");
    map.insert("appVersion", "1.0");
    map.insert("deviceType", "2");
    map.insert("osVersion", "win10");
    map.insert("root", "0");
    map.insert("deviceName", "PC");
    map.insert("channel", "1");
    map.insert("emulator", "0");
    map.insert("networkType", "0");
    m_map = map;
}

void HttpAsyncWorker::addHeader(const QString& key, const QString& value)
{
    QMutexLocker locker(&m_queueMutex);
    m_map.insert(key, value);
}

void HttpAsyncWorker::removeHeader(const QString& key)
{
    QMutexLocker locker(&m_queueMutex);
    m_map.remove(key);
}
