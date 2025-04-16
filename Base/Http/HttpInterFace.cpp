#include "HttpInterFace.h"
#include <QEventLoop>
#include <QJsonDocument>
#include <QProcess>
#include <QFile>
#include <QFileInfo>
#include <QHttpPart>

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

//    httpClient = new HttpClient();
//    httpClient->manager(m_http_asy);

//    connect(m_http_asy, SIGNAL(finished(QNetworkReply*)),this, SLOT(replyFinished(QNetworkReply*)));

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

QVariantMap HttpInterFace:: loginForPassword(const QString &country_code
      , const QString &mobile
      , const QString &password)
{
    QVariantMap jsonMap;
    jsonMap.insert("country_code",country_code);
    jsonMap.insert("mobile",mobile);
    jsonMap.insert("password",password);

    const QString strUrl = QString(BASE_API_URL) + "/api/v1/auth/pwd-login";
    return httpPost_syn(strUrl,jsonMap);
}
//获取手机区号
QVariantMap HttpInterFace::getConfig()
{
    const QString url = domain_base + "/api/v1/misc/configs";
    return httpPost_syn(url,QVariantMap());
}

QVariantMap HttpInterFace::resetPassword(PhoneCodeType type
                                         ,QString country_code
                                         ,QString code
                                         ,QString mobile
                                         ,QString password)
{
    QVariantMap jsonMap;
    jsonMap.insert("biz_type",static_cast<std::underlying_type<PhoneCodeType>::type>(type));
    jsonMap.insert("code_key",0);
    jsonMap.insert("country_code",country_code);
    jsonMap.insert("code",code);
    jsonMap.insert("mobile",mobile);
    jsonMap.insert("password",password);

    const QString url = domain_base + "/api/v1/user/reset-password";
    return httpPost_syn(url,jsonMap);
}

QVariantMap HttpInterFace::getLiveClass()
{
    const QString url = domain_base + "/api/v1/misc/comm/live-categories";
    return httpsGet_syn(url);
}

void HttpInterFace::uploadFile(QString filePath, QString scenes , callBack callback)
{
    const QString uploadUrl = domain_base + "/api/v1/misc/upload";

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

void HttpInterFace::downLoadFile(QString url,QString path)
{
    QNetworkRequest request(url);
    QNetworkReply *reply = m_http_asy->get(request);

    QObject::connect(reply, &QNetworkReply::finished, [&]() {
        if (reply->error() != QNetworkReply::NoError)
        {
            qDebug() << "Error:" << reply->errorString();
        }
        else
        {
            QByteArray downloadedData = reply->readAll();

            QFile file(path);
            if (file.open(QIODevice::WriteOnly))
            {
                file.write(downloadedData);
                file.close();
                qDebug() << "File downloaded successfully";
            } else {
                qDebug() << "Error saving file:" << file.errorString();
            }
        }

        reply->deleteLater();
    });
}

void HttpInterFace::downLoad(QString url, QString path)
{
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
                                 qDebug() << "File downloaded successfully";
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

QVariantMap HttpInterFace::getUserInfo()
{
    QString url = domain_base + "/api/v1/user/profile";
    return httpsGet_syn(url);
}

QVariantMap HttpInterFace::startLive(int display_type)
{
    QString url = domain_base + "/api/v1/streamer/open-live";
    QVariantMap jsonMap;
    jsonMap.insert("display_type",display_type);

    return httpsPost_syn(url,jsonMap);
}

QVariantMap HttpInterFace::endLive()
{
    QString url = domain_base + "/api/v1/streamer/close-live";
    QVariantMap jsonMap;

    return httpsPost_syn(url,jsonMap);
}

void HttpInterFace::getRoomInfo(callBack callback)
{
    QString url = domain_base + "/api/v1/streamer/room";
    httpsGet_asy(url,callback);
}

QVariantMap HttpInterFace::updateRoomInfo(QString category_id,
                                   QString cover_url,
                                   QString notice,
                                   QString title,
                                   QString video_url,
                                   QString live_region,
                                   bool showInfo)
{
    QString url = domain_base + "/api/v1/streamer/update-room";
    QVariantMap jsonMap;
    jsonMap.insert("category_id",category_id);
    jsonMap.insert("cover_url",cover_url);
    jsonMap.insert("notice",notice);
    jsonMap.insert("show_viewer_info",showInfo);
    jsonMap.insert("title",title);
    jsonMap.insert("video_url",video_url);
    jsonMap.insert("live_region",live_region.toInt());

    return httpsPost_syn(url,jsonMap);
}

/**********************************************************/
void HttpInterFace::addBaseParams(QVariantMap &jsonMap)
{
    jsonMap.insert("token ",m_token);
    jsonMap.insert("deviceId ",m_uuid);
    jsonMap.insert("appVersion",m_version);
    jsonMap.insert("deviceType","2");
    jsonMap.insert("osVersion ","win10");
    jsonMap.insert("root",0);
    jsonMap.insert("deviceName","PC");
    jsonMap.insert("channel ", "1");
    jsonMap.insert("emulator",0);
    jsonMap.insert("networkType ","0");
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

void HttpInterFace::loginToServer_asy(QString account,QString passwd)
{
    QVariantMap jsonMap;
    addBaseParams(jsonMap);
    jsonMap.insert("mobile",account);
    jsonMap.insert("verification_code",passwd);
    QString url = BASE_API_URL + QString(LOGIN_URL);
    httpsPost_asy(url,jsonMap);
}

QVariantMap HttpInterFace::getLiveInfo()
{
    QString url = LIVE_BASE_API_URL + QString(LIVE_INFO);
    return httpsGet_syn(url);
}

QVariantMap HttpInterFace::saveLiveInfo(QVariantMap jsonMap)
{
    QString url = LIVE_BASE_API_URL + QString(LIVE_INFO);
    return httpsPut_syn(url,jsonMap);
}

QVariantMap HttpInterFace::stopLive()
{
    QString url = LIVE_BASE_API_URL + QString(LIVE_STOP);
    return httpsPost_syn(url,QVariantMap());
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

    qDebug()<<"url---"<<url;
    qDebug()<<"1--------------"<<postData;
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
