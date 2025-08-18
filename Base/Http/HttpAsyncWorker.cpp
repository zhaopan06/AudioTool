#include "HttpAsyncWorker.h"
#include <QNetworkReply>
#include <QDebug>
#include "Global.h"
#include <QPointer>
#include "HttpUserInfo.h"

HttpAsyncWorker* HttpAsyncWorker::getInstance()
{
    static HttpAsyncWorker instance;
    return &instance;
}

HttpAsyncWorker::HttpAsyncWorker(QObject* parent)
    : QObject(parent),
    m_manager(new QNetworkAccessManager(this)),
    m_activeRequests(0),
    m_maxConcurrentRequests(4)
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
                                    const QVariantMap &body)
{
    QMutexLocker locker(&m_queueMutex);

    RequestTask task;
    task.method = method;
    task.url = url;
    QByteArray data = QJsonDocument::fromVariant(body).toJson();
    task.body = data;
    task.successCallback = successCallback;
    task.errorCallback = errorCallback;

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

    QString fullUrl = m_baseUrl + task.url;
    QNetworkRequest request = createRequest(fullUrl);

    QNetworkReply* reply = nullptr;
    switch (task.method)
    {
    case RequestMethod::GET:
        reply = m_manager->get(request);
        break;
    case RequestMethod::POST:       
        reply = m_manager->post(request, task.body);
        break;
    case RequestMethod::PUT:
        reply = m_manager->put(request, task.body);
        break;
    case RequestMethod::PATCH:
        break;
    }

    if (reply)
    {
        m_activeRequests--;
        QObject::connect(reply, &QNetworkReply::readyRead, reply, [=]{

            QByteArray response = reply->readAll();
            QJsonParseError json_error;
            QJsonDocument jsonDocument = QJsonDocument::fromJson(response, &json_error);
            if(json_error.error != QJsonParseError::NoError)
            {
                if(task.errorCallback)
                {
                    qDebug()<<"json_error.errorString()---"<<json_error.errorString();
                    QMetaObject::invokeMethod(g_main, [task,json_error]() {
                        task.errorCallback(-1, json_error.errorString());
                    }, Qt::QueuedConnection);
                }
                reply->deleteLater();
                return;
            }
            if(jsonDocument["code"].toInt() != 1)
            {
                if(task.errorCallback)
                {
                    QMetaObject::invokeMethod(g_main, [task,jsonDocument]() {
                        task.errorCallback(jsonDocument["code"].toInt(), jsonDocument["message"].toString());
                    }, Qt::QueuedConnection);
                }
                qDebug()<<"error---"<<jsonDocument["message"].toString();
                reply->deleteLater();
                return;
            }

            QMetaObject::invokeMethod(g_main, [task,jsonDocument]() {
                task.successCallback(jsonDocument.toVariant().toMap());
            }, Qt::QueuedConnection);


            reply->deleteLater();
        });
    }
    else
    {
        m_activeRequests--;
        if (task.errorCallback)
        {
            QMetaObject::invokeMethod(g_main, [task]() {
                task.errorCallback(-1, "Failed to create request");
            });
        }
    }

    // 处理下一个请求
    QMetaObject::invokeMethod(this, &HttpAsyncWorker::handleRequest, Qt::QueuedConnection);
}

QNetworkRequest HttpAsyncWorker::createRequest(const QString& url)
{
    QNetworkRequest request(url);
    QSslConfiguration config;
    config.setPeerVerifyMode(QSslSocket::VerifyNone);
    config.setProtocol(QSsl::TlsV1_2);
    request.setSslConfiguration(config);
    request.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("application/json"));

    for (auto it = m_map.constBegin(); it != m_map.constEnd(); ++it)
    {
        QByteArray key = it.key().toUtf8();
        QByteArray value = it.value().toUtf8();
        request.setRawHeader(key,value);
    }

    if(!HttpUserInfo::instance()->gettoken().isEmpty())
    {
        request.setRawHeader("token", HttpUserInfo::instance()->gettoken().toLatin1());
    }
    else
        request.setRawHeader("token", "0");

    return request;
}

void HttpAsyncWorker::setMaxConcurrentRequests(int max)
{
    m_maxConcurrentRequests = max;
}

void HttpAsyncWorker::setBaseUrl(const QString& baseUrl)
{
    m_baseUrl = baseUrl;
}

void HttpAsyncWorker::setHeaders()
{
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
