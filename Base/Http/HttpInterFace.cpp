#include "HttpInterFace.h"
#include <QEventLoop>
#include <QJsonDocument>
#include <QProcess>
#include <QFile>
#include <QFileInfo>
#include <QHttpPart>
#include <QStandardPaths>
#include "Global.h"
#include "HttpUserInfo.h"

HttpInterFace* HttpInterFace::pHttpInterFace = NULL;

HttpInterFace *HttpInterFace::getInstance()
{
    if(pHttpInterFace == NULL)
    {
        pHttpInterFace = new HttpInterFace();
    }

    return pHttpInterFace;
}

HttpInterFace::HttpInterFace(QObject *parent) : QObject(parent)
{
    m_pNetworkAccessManager = new QNetworkAccessManager;
    m_http_asy = new QNetworkAccessManager;

    QProcess p(0);
    p.start("wmic csproduct get uuid ");    p.waitForStarted();
    p.waitForFinished();
    m_uuid = QString::fromLocal8Bit(p.readAllStandardOutput());
    m_uuid = m_uuid.remove("UUID").trimmed();

    m_token = "";
    m_version = "1.0";
}

HttpInterFace::~HttpInterFace()
{

}

QVariantMap HttpInterFace:: getCaptcha(QString phone,QString region_code)
{
    QVariantMap jsonMap;
    jsonMap.insert("smsType", 1);
    jsonMap.insert("areaCode","+86");
    jsonMap.insert("phone",phone);

    const QString strUrl = QString(BASE_API_URL) + "/sms/send";
    return httpPost_syn(strUrl,jsonMap);
}

void HttpInterFace::uploadFile(QString filePath, QString scenes , callBack callback)
{
    const QString uploadUrl = QString(BASE_API_URL) + "/api/v1/misc/upload";

    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "Failed to open file for reading:" << file.errorString();
        return;
    }
    QByteArray fileData = file.readAll();
    file.close();

    QFileInfo fileInfo(filePath);
    QString filename = fileInfo.fileName();

    QVariantMap jsonMap;
    jsonMap.insert("body",fileData.toBase64());
    jsonMap.insert("filename",filename);
    jsonMap.insert("pre",true);
    jsonMap.insert("scenes",scenes);

    httpPost_asy(uploadUrl,jsonMap,callback);
}

void HttpInterFace::downLoad(QString url, downLoadCallBack callBack)
{
    QString path = mapDownloadImagePath(url);
    QFile tempFile;
    if(tempFile.exists(path))
    {
        callBack(path);
        return;
    }

    QNetworkAccessManager *manager = new QNetworkAccessManager();
    QNetworkRequest request;
    request.setUrl(QUrl(url));
    QNetworkReply *reply = manager->get(request);
    QObject::connect(reply, &QNetworkReply::finished, [=]()
                     {
                         if (reply->error() != QNetworkReply::NoError)
                         {
                             qDebug() << "Error:" << reply->errorString();
                         }
                         else
                         {                             
                             QByteArray downloadedData = reply->readAll(); // 处理响应数据
                             QFile file(path);
                             if (file.open(QIODevice::WriteOnly))
                             {
                                 file.write(downloadedData);
                                 file.close();
                                 callBack(path);
                             }
                             else
                             {
                                 qDebug() << "Error saving file:" << file.errorString();
                             }
                         }
                         reply->deleteLater();
                         manager->deleteLater();
                     });
}


QVariantMap HttpInterFace::getFamilyDetail()
{
    QString url = BASE_API_URL + QString("/family/getFamilyDetail");
    return httpsGet_syn(url);
}


QVariantMap HttpInterFace::loginToServer(QString phone,QString verifyCode)
{
    QVariantMap jsonMap;
    jsonMap.insert("phone",phone);
    jsonMap.insert("verifyCode", verifyCode);
    jsonMap.insert("authType", -1);
    QString url = BASE_API_URL + QString(LOGIN_URL);
    return httpsPost_syn(url,jsonMap);
}

QVariantMap HttpInterFace::addMic(int roomId, int type)
{
    QVariantMap jsonMap;
    jsonMap.insert("roomId",roomId);
    jsonMap.insert("type", type);
    QString url = BASE_API_URL + QString("/live/dealApplyMic");
    return httpsPost_syn(url,jsonMap);
}

QVariantMap HttpInterFace::createRoom(QString roomPhoto, QString roomName)
{
    QVariantMap jsonMap;
    jsonMap.insert("roomPhoto",roomPhoto);
    jsonMap.insert("roomName", roomName);
    QString url = BASE_API_URL + QString("/live/createLiveRoom");
    return httpsPost_syn(url,jsonMap);
}

QVariantMap HttpInterFace::joinRoom(int roomId, int entryType, QString subTopic)
{
    QVariantMap jsonMap;
    jsonMap.insert("roomId",roomId);
    jsonMap.insert("entryType", entryType);
    jsonMap.insert("subTopic", subTopic);
    QString url = BASE_API_URL + QString(LIVE_START);
    return httpsPost_syn(url,jsonMap);
}

QVariantMap HttpInterFace::httpsPut_syn(QString url, QVariantMap jsonMap)
{
    QNetworkRequest request;
    QSslConfiguration config;
    config.setPeerVerifyMode(QSslSocket::VerifyNone);
    request.setSslConfiguration(config);
    request.setRawHeader("Authorization",m_authorization.toUtf8());
    request.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("application/json;charset=UTF-8"));
    request.setUrl(QUrl(url));

    QByteArray postData = QJsonDocument::fromVariant(jsonMap).toJson();
    QNetworkReply *reply = m_pNetworkAccessManager->put(request,postData);
    if (NULL == reply)
    {
        delete m_pNetworkAccessManager;
        return QVariantMap();
    }

    QEventLoop eventloop;
    connect(m_pNetworkAccessManager, &QNetworkAccessManager::finished, &eventloop, &QEventLoop::quit);
    eventloop.exec();

    QByteArray responseData = reply->readAll();
    if(responseData.isEmpty())
    {
        return QVariantMap();
    }
    QJsonParseError json_error;
    QJsonDocument jsonDocument = QJsonDocument::fromJson(responseData, &json_error);
    QVariantMap map = jsonDocument.toVariant().toMap();
    return map;
}

void HttpInterFace::httpsGet_asy(QString url, callBack callback)
{
    QNetworkRequest request;
    request.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("application/json"));
    request.setUrl(QUrl(url));


    QNetworkReply *reply = m_http_asy->get(request);

    auto processResponse = [=]()
    {
        QObject::connect(reply, &QNetworkReply::readyRead, reply, [=]{
            QByteArray responseData = reply->readAll();
            QJsonParseError json_error;
            QJsonDocument jsonDocument = QJsonDocument::fromJson(responseData, &json_error);
            callback(jsonDocument.toVariant());
            reply->deleteLater();});
    };
    processResponse();
}

QVariantMap HttpInterFace::httpsGet_syn(QString url)
{
    QNetworkRequest request;
    QSslConfiguration config;
    config.setPeerVerifyMode(QSslSocket::VerifyNone);
    config.setProtocol(QSsl::TlsV1_2);
    request.setSslConfiguration(config); 
    request.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("application/json"));
    request.setUrl(QUrl(url));

    if(!HttpUserInfo::instance()->gettoken().isEmpty())
    {
        request.setRawHeader("token", HttpUserInfo::instance()->gettoken().toLatin1());
    }
    else
        request.setRawHeader("token", "0");


    QNetworkReply *reply = m_pNetworkAccessManager->get(request);
    if (NULL == reply)
    {
        delete m_pNetworkAccessManager;
        return QVariantMap();
    }

    QEventLoop eventloop;
    connect(m_pNetworkAccessManager, &QNetworkAccessManager::finished, &eventloop, &QEventLoop::quit);
    eventloop.exec();

    QByteArray responseData = reply->readAll();    
    if(responseData.isEmpty())
    {
        return QVariantMap();
    }
    QJsonParseError json_error;
    QJsonDocument jsonDocument = QJsonDocument::fromJson(responseData, &json_error);
    QVariantMap map = jsonDocument.toVariant().toMap();
    return map;
}

void HttpInterFace::httpPost_asy(QString url , QVariantMap jsonMap, callBack callback)
{
    QNetworkRequest request;
    request.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("application/json"));
    request.setUrl(QUrl(url));

    QByteArray postData = QJsonDocument::fromVariant(jsonMap).toJson();

    QNetworkReply *reply = m_http_asy->post(request, postData);

    auto processResponse = [=]()
    {
        QObject::connect(reply, &QNetworkReply::readyRead, reply, [=]{
            QByteArray responseData = reply->readAll();
            QJsonParseError json_error;
            QJsonDocument jsonDocument = QJsonDocument::fromJson(responseData, &json_error);
            callback(jsonDocument.toVariant());
            reply->deleteLater();});
    };
    processResponse();
}

QVariantMap HttpInterFace::httpPost_syn(QString url ,QVariantMap jsonMap)
{
    QNetworkRequest request;
    request.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("application/json"));
    request.setUrl(QUrl(url));

    QByteArray postData = QJsonDocument::fromVariant(jsonMap).toJson();
    QNetworkReply *reply = m_pNetworkAccessManager->post(request, postData);
    if (NULL == reply)
    {
        delete m_pNetworkAccessManager;
        return QVariantMap();
    }

    QEventLoop eventloop;
    connect(m_pNetworkAccessManager, &QNetworkAccessManager::finished, &eventloop, &QEventLoop::quit);
    eventloop.exec();

    QByteArray responseData = reply->readAll();    
    if(responseData.isEmpty())
    {
        return QVariantMap();
    }
    QJsonParseError json_error;
    QJsonDocument jsonDocument = QJsonDocument::fromJson(responseData, &json_error);
    QVariantMap map = jsonDocument.toVariant().toMap();
    reply->deleteLater();
    return map;
}

QVariantMap HttpInterFace::httpsPost_syn(QString url ,QVariantMap jsonMap)
{
    QByteArray postData = QJsonDocument::fromVariant(jsonMap).toJson();
    QNetworkRequest request(url);
    if(!HttpUserInfo::instance()->gettoken().isEmpty())
    {
        request.setRawHeader("token", HttpUserInfo::instance()->gettoken().toLatin1());
    }
    else
        request.setRawHeader("token", "0");

    request.setRawHeader("deviceId", "11");
    request.setRawHeader("appVersion", "1.0");
    request.setRawHeader("deviceType", "2");
    request.setRawHeader("osVersion", "win10");
    request.setRawHeader("root", "0");
    request.setRawHeader("deviceName", "PC");
    request.setRawHeader("channel", "1");
    request.setRawHeader("emulator", "0");
    request.setRawHeader("networkType", "0");
    request.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("application/json"));

    QNetworkReply *reply = m_pNetworkAccessManager->post(request, postData);
    if (NULL == reply)
    {
        delete m_pNetworkAccessManager;
        return QVariantMap();
    }

    QEventLoop eventloop;
    connect(m_pNetworkAccessManager, &QNetworkAccessManager::finished, &eventloop, &QEventLoop::quit);
    eventloop.exec();

    QByteArray responseData = reply->readAll();
    if(responseData.isEmpty())
    {
        return QVariantMap();
    }
    QJsonParseError json_error;
    QJsonDocument jsonDocument = QJsonDocument::fromJson(responseData, &json_error);
    QVariantMap map = jsonDocument.toVariant().toMap();
    return map;
}

void HttpInterFace::httpsPost_asy(QString url ,QVariantMap jsonMap)
{
    QByteArray postData = QJsonDocument::fromVariant(jsonMap).toJson();

    QNetworkRequest request;
    QSslConfiguration config;
    config.setPeerVerifyMode(QSslSocket::VerifyNone);
    config.setProtocol(QSsl::TlsV1_2);
    request.setSslConfiguration(config);
    request.setRawHeader("Authorization",m_authorization.toUtf8());
    request.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("application/json"));
    request.setHeader(QNetworkRequest::ContentLengthHeader, postData.length());
    request.setUrl(QUrl(url));

    m_http_asy->post(request, postData);
}

void HttpInterFace::replyFinished(QNetworkReply *reply)
{
    if(reply->url().toString().contains(LOGIN_URL))
    {

    }
    else if(reply->url().toString().contains(LOGIN_URL))
    {

    }
    reply->deleteLater();
}
