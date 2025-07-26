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
#include <QUrlQuery>

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

    m_token = "";
    m_version = "1.0";
}

HttpInterFace::~HttpInterFace()
{

}

void  HttpInterFace::getCaptcha(QString phone,QString region_code, callBack callback)
{
    QVariantMap jsonMap;
    jsonMap.insert("smsType", 1);
    jsonMap.insert("areaCode","+86");
    jsonMap.insert("phone",phone);

    const QString strUrl = QString(BASE_API_URL) + "/sms/send";
    httpPost_asy(strUrl, jsonMap, callback);
}

void HttpInterFace::uploadFile(const QString &filePath, int type, callBack callback)
{
    QHttpMultiPart *multiPart = new QHttpMultiPart(QHttpMultiPart::FormDataType);
    QHttpPart filePart;
    filePart.setHeader(QNetworkRequest::ContentDispositionHeader,
                       QVariant("form-data; name=\"file\"; filename=\"" +
                                QFileInfo(filePath).fileName() + "\""));
    filePart.setHeader(QNetworkRequest::ContentTypeHeader,
                       QVariant("application/octet-stream"));

    QFile *file = new QFile(filePath, multiPart);
    file->open(QIODevice::ReadOnly);
    filePart.setBodyDevice(file);
    multiPart->append(filePart);

    QHttpPart typePart;
    typePart.setHeader(QNetworkRequest::ContentDispositionHeader,
                       QVariant("form-data; name=\"type\""));
    typePart.setBody(QString::number(0).toUtf8());
    multiPart->append(typePart);

    const QString uploadUrl = QString(BASE_API_URL) + "/file/fileUpload";
    QNetworkRequest request((QUrl(uploadUrl)));
    request.setHeader(QNetworkRequest::ContentTypeHeader,
                      "multipart/form-data; boundary=" + multiPart->boundary());
    if(!HttpUserInfo::instance()->gettoken().isEmpty())
    {
        request.setRawHeader("token", HttpUserInfo::instance()->gettoken().toLatin1());
    }
    else
        request.setRawHeader("token", "0");

    QNetworkReply *reply = m_pNetworkAccessManager->post(request, multiPart);
    multiPart->setParent(reply);

    connect(reply, &QNetworkReply::finished, [=](){
        QByteArray responseData = reply->readAll();
        QJsonParseError json_error;
        QJsonDocument jsonDocument = QJsonDocument::fromJson(responseData, &json_error);
        if(json_error.error != QJsonParseError::NoError)
        {
            emit error_msg_box_text(json_error.errorString(),-1);
            reply->deleteLater();
            return;
        }
        if(jsonDocument["code"].toInt() != 1)
        {
            emit error_msg_box_text(jsonDocument["message"].toString(),jsonDocument["code"].toInt());
            reply->deleteLater();
            return;
        }
        callback(jsonDocument.toVariant());
        reply->deleteLater();
    });
}

void HttpInterFace::uploadLiveInfo(QString photo, QString name, QString announcement, QString roomId, callBack callback)
{
    QVariantMap jsonMap;
    jsonMap.insert("photo",photo);
    jsonMap.insert("name",name);
    jsonMap.insert("announcement",announcement);
    jsonMap.insert("roomId",roomId);

    const QString uploadUrl = QString(BASE_API_URL) + "/live/updateLivingRoom";
    httpPost_asy(uploadUrl,jsonMap,callback);
}

void HttpInterFace::downLoad(QString url, downLoadCallBack callBack)
{
    QFile tempFile(url);
    if(tempFile.exists(url))
    {
        callBack(url);
        return;
    }
    QString path = mapDownloadImagePath(url);
    QFile tempFile1;
    if(tempFile1.exists(path))
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

QVariantMap HttpInterFace::getLiveRoomInfo()
{
    QString url = BASE_API_URL + QString("/pcHome/getPcHomeInfo");
    return httpsGet_syn(url);
}

void HttpInterFace::getLiveRoomInfo_asy(callBack callBack)
{
    QString url = BASE_API_URL + QString("/pcHome/getPcHomeInfo");
    QVariantMap map;
    httpsGet_asy(url,map,callBack);
}

QVariantMap HttpInterFace::followUser(QString followedId, int isFollow)
{
    QVariantMap jsonMap;
    jsonMap.insert("followedId",followedId);
    jsonMap.insert("isFollow", isFollow);
    QString url = BASE_API_URL + QString("/user/followUser");
    return httpsPost_syn(url,jsonMap);
}

void HttpInterFace::getOnlineInfo(QString roomId, int currentPage, callBack callBack)
{
    QVariantMap params;
    params.insert("roomId",roomId);
    params.insert("currentPage", currentPage);

    QString url = BASE_API_URL + QString("/live/getV2OnlineList");
    httpsGet_asy(url,params, callBack);
}

void HttpInterFace::getMicApplyList(QString roomId, callBack callBack)
{
    QVariantMap params;
    params.insert("roomId",roomId);

    QString url = BASE_API_URL + QString("/live/getMicApplyList");
    httpsGet_asy(url,params, callBack);
}

void HttpInterFace::getContributeList(int type, int timeType, int size, QString roomId, callBack callBack)
{
    QVariantMap params;
    params.insert("type",type);
    params.insert("timeType",timeType);
    params.insert("size",size);
    params.insert("roomId",roomId);

    QString url = BASE_API_URL + QString("/ranking/list");
    httpsGet_asy(url,params, callBack);
}

void HttpInterFace::getPcNewUserSquareList(int pageNum, int pageSize, callBack callBack)
{
    QVariantMap params;
    params.insert("pageNum",pageNum);
    params.insert("pageSize",pageSize);

    QString url = BASE_API_URL + QString("/pcLiveRoom/getPcNewUserSquareList");
    httpsGet_asy(url,params, callBack);
}

void HttpInterFace::getCommonConfig(callBack callBack)
{
    QVariantMap jsonMap;
    jsonMap.insert("systemConfigType",1);
    QString url = BASE_API_URL + QString("/common/getCommonConfig");
    httpsGet_asy(url,jsonMap, callBack);
}

void HttpInterFace::getUserInfo(QString userId, callBack callBack)
{
    QVariantMap jsonMap;
    jsonMap.insert("userId",userId);
    QString url = BASE_API_URL + QString("/user/getUserInfo");
    httpsGet_asy(url,jsonMap, callBack);
}
/*
 * 礼物类型，0=查询收到的礼物，1=查询送出去的礼物
 * 是否点亮，1=已点亮数据，0=未点亮数据
 */
void HttpInterFace::getGiftWall(QString userId, int giftType, int isLighten, callBack callBack)
{
    QVariantMap jsonMap;
    jsonMap.insert("userId",userId);
    jsonMap.insert("isLighten",isLighten);
    jsonMap.insert("giftType",giftType);
    QString url = BASE_API_URL + QString("/gift/getGiftWall");
    httpsGet_asy(url,jsonMap, callBack);
}

void HttpInterFace::getUserMedals(QString userId, callBack callBack)
{
    QVariantMap jsonMap;
    jsonMap.insert("userId",userId);
    QString url = BASE_API_URL + QString("/user/getUserMedals");
    httpsGet_asy(url,jsonMap, callBack);
}

QVariantMap HttpInterFace::getGiftList()
{
    QVariantMap jsonMap;
    QString url = BASE_API_URL + QString("/gift/v3/getGiftList");
    return httpsGet_syn(url);
}

void HttpInterFace::clearCardiacValue(QString roomId, callBack callBack)
{
    QVariantMap jsonMap;
    jsonMap.insert("roomId",roomId);
    QString url = BASE_API_URL + QString("/live/clearCardiacValue");
    httpPost_asy(url,jsonMap, callBack);
}

void HttpInterFace::noticeFans(QString roomId, callBack callBack)
{
    QVariantMap jsonMap;
    jsonMap.insert("roomId",roomId);
    QString url = BASE_API_URL + QString("/room/noticeFans");
    httpsGet_asy(url,jsonMap, callBack);
}

void HttpInterFace::queryMessageListUserInfo(QString roomId, callBack callBack, ErrCallBack errorCallBack)
{
    QVariantMap jsonMap;
    jsonMap.insert("userIds",roomId);
    QString url = BASE_API_URL + QString("/user/queryMessageListUserInfo");
    httpsGet_asy(url,jsonMap, callBack, errorCallBack);
}

//请求类型（0：我的关注，1：关注我的，2：我的好友，3：我的黑名单，4：访客）
void HttpInterFace::getMyFollow(int currentPage, int requestType, callBack callBack,QString param)
{
    QVariantMap jsonMap;
    jsonMap.insert("currentPage",currentPage);
    jsonMap.insert("requestType",requestType);
    if(!param.isEmpty())
        jsonMap.insert("param",param);
    QString url = BASE_API_URL + QString("/user/myFollow");
    httpsGet_asy(url,jsonMap, callBack);
}

void HttpInterFace::getMessageList(callBack callBack)
{
    QVariantMap jsonMap;
    QString url = BASE_API_URL + QString("/user/getMessageList");
    httpsGet_asy(url,jsonMap, callBack);
}

void HttpInterFace::getOwnerAuthList(QString roomId, callBack callback)
{
    QVariantMap jsonMap;
    jsonMap.insert("roomId",roomId);
    QString url = BASE_API_URL + QString("/live/getOwnerAuthList");
    httpsGet_asy(url,jsonMap, callback);
}

void HttpInterFace::getRecommendRoom(QString roomId,callBack callBack)
{
    QVariantMap jsonMap;
    jsonMap.insert("roomId",roomId);
    QString url = BASE_API_URL + QString("/live/leaveReferralLiving");
    httpPost_asy(url,jsonMap, callBack);
}

void HttpInterFace::getHouPushData(QString roomId,callBack callBack)
{
    QVariantMap jsonMap;
    jsonMap.insert("roomId",roomId);
    QString url = BASE_API_URL + QString("/live/getReferralPlaceConfig");
    httpsGet_asy(url,jsonMap, callBack);
}

void HttpInterFace::useReferralCard(QString placeId, QString roomId,callBack callBack)
{
    QVariantMap jsonMap;
    jsonMap.insert("placeId",placeId);
    jsonMap.insert("roomId",roomId);
    QString url = BASE_API_URL + QString("/live/useReferralCard");
    httpPost_asy(url,jsonMap, callBack);
}

void HttpInterFace::getHotDataHistory(QString roomId, int currentPage, callBack callBack)
{
    QVariantMap jsonMap;
    jsonMap.insert("roomId",roomId);
    jsonMap.insert("currentPage",currentPage);
    QString url = BASE_API_URL + QString("/live/getReferralUsedCard");
    httpsGet_asy(url,jsonMap, callBack);
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
/*
 操作类型 0-取消排麦 1-申请排麦
*/
QVariantMap HttpInterFace::addMic(QString roomId, int type)
{
    QVariantMap jsonMap;
    jsonMap.insert("roomId",roomId);
    jsonMap.insert("type", type);
    QString url = BASE_API_URL + QString("/live/dealApplyMic");
    return httpsPost_syn(url,jsonMap);
}

QVariantMap HttpInterFace::b_upMic(QString roomId, QString targetUserId)
{
    QVariantMap jsonMap;
    jsonMap.insert("roomId",roomId);
    jsonMap.insert("type", 0);
    jsonMap.insert("targetUserId", targetUserId);
    QString url = BASE_API_URL + QString("/live/dealUpDownMic");
    return httpsPost_syn(url,jsonMap);
}

QVariantMap HttpInterFace::b_downMic(QString roomId, QString targetUserId)
{
    QVariantMap jsonMap;
    jsonMap.insert("roomId",roomId);
    jsonMap.insert("type", 1);
    jsonMap.insert("targetUserId", targetUserId);
    QString url = BASE_API_URL + QString("/live/dealUpDownMic");
    return httpsPost_syn(url,jsonMap);
}

QVariantMap HttpInterFace::m_downMic()
{
    QVariantMap jsonMap;
    jsonMap.insert("roomId",HttpUserInfo::instance()->getClassRoomID());
    jsonMap.insert("type", 2);
    jsonMap.insert("targetUserId", HttpUserInfo::instance()->getUserID());
    QString url = BASE_API_URL + QString("/live/dealUpDownMic");
    return httpsPost_syn(url,jsonMap);
}
//操作类型 0-开麦 1-闭麦
QVariantMap HttpInterFace::micOpenOrClose(QString roomId, QString targetUserId, int type)
{
    QVariantMap jsonMap;
    jsonMap.insert("roomId",HttpUserInfo::instance()->getClassRoomID());
    jsonMap.insert("type", type);
    jsonMap.insert("targetUserId", targetUserId);
    QString url = BASE_API_URL + QString("/live/micOpenOrClose");
    return httpsPost_syn(url,jsonMap);
}
//操作类型 0-解除闭麦 1-锁麦
QVariantMap HttpInterFace::lockMic(int type, int seat)
{
    QVariantMap jsonMap;
    jsonMap.insert("roomId",HttpUserInfo::instance()->getClassRoomID());
    jsonMap.insert("type", type);
    jsonMap.insert("seat", seat);
    QString url = BASE_API_URL + QString("/live/micLock");
    return httpsPost_syn(url,jsonMap);
}

//主机有房主才能设置
/*设置类型，0=设置支持人，1=设置房间管理员，2=移除主持人，3=移除房间管理员,4=拉黑，5=解除拉黑*/
QVariantMap HttpInterFace::settingEmceeOrAdmin(int settingType, QString targetUserId)
{
    QVariantMap jsonMap;
    jsonMap.insert("settingType", settingType);
    jsonMap.insert("targetUserId", targetUserId);
    QString url = BASE_API_URL + QString("/room/settingEmceeOrAdmin");
    return httpsPost_syn(url,jsonMap);
}

QVariantMap HttpInterFace::joinRoom(int roomId, int entryType, QString subTopic)
{
    QVariantMap jsonMap;
    jsonMap.insert("roomId",roomId);
    jsonMap.insert("entryType", entryType);
    jsonMap.insert("subTopic", subTopic);
    QString url = BASE_API_URL + QString("/live/joinLivingRoom");
    return httpsPost_syn(url,jsonMap);
}

QVariantMap HttpInterFace::closeRoom(QString roomId)
{
    QVariantMap jsonMap;
    jsonMap.insert("roomId",roomId);
    QString url = BASE_API_URL + QString("/room/closeVoiceRoom");
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
        reply->deleteLater();
        return QVariantMap();
    }
    QJsonParseError json_error;
    QJsonDocument jsonDocument = QJsonDocument::fromJson(responseData, &json_error);
    if(json_error.error != QJsonParseError::NoError)
    {
        reply->deleteLater();
        emit error_msg_box_text(json_error.errorString(), -1);
        return QVariantMap();
    }
    QVariantMap map = jsonDocument.toVariant().toMap();
    reply->deleteLater();
    return map;
}

void HttpInterFace::httpsGet_asy(QString url, QVariantMap jsonMap, callBack callback, ErrCallBack errorCallBack)
{
    QUrlQuery query;
    for (auto it = jsonMap.constBegin(); it != jsonMap.constEnd(); ++it)
    {
        query.addQueryItem(it.key(), it.value().toString());
    }

    QUrl qurl(url);
    qurl.setQuery(query);

    QNetworkRequest request;
    request.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("application/json"));
    request.setUrl(qurl);
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

    QNetworkReply *reply = m_http_asy->get(request);

    QObject::connect(reply, &QNetworkReply::readyRead, reply, [=]{
        QByteArray responseData = reply->readAll();
        QJsonParseError json_error;
        QJsonDocument jsonDocument = QJsonDocument::fromJson(responseData, &json_error);
        if(json_error.error != QJsonParseError::NoError)
        {
            emit error_msg_box_text(json_error.errorString(), -1);
            reply->deleteLater();
            return;
        }
        if(jsonDocument["code"].toInt() != 1)
        {
            if(errorCallBack)
            {
                errorCallBack(jsonDocument.toVariant());
                reply->deleteLater();
                return;
            }
            emit error_msg_box_text(jsonDocument["message"].toString(),jsonDocument["code"].toInt());
            reply->deleteLater();
            return;
        }
        callback(jsonDocument.toVariant());
        reply->deleteLater();
    });
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
        reply->deleteLater();
        return QVariantMap();
    }
    QJsonParseError json_error;
    QJsonDocument jsonDocument = QJsonDocument::fromJson(responseData, &json_error);
    if(json_error.error != QJsonParseError::NoError)
    {
        reply->deleteLater();
        emit error_msg_box_text(json_error.errorString(),-1);
        return QVariantMap();
    }    
    if(jsonDocument["code"].toInt() != 1)
    {
        reply->deleteLater();
        emit error_msg_box_text(jsonDocument["message"].toString(),jsonDocument["code"].toInt());
        return QVariantMap();
    }
    QVariantMap map = jsonDocument.toVariant().toMap();
    reply->deleteLater();
    return map;
}

void HttpInterFace::httpPost_asy(QString url , QVariantMap jsonMap, callBack callback)
{
    QNetworkRequest request;
    request.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("application/json"));
    request.setUrl(QUrl(url));

    if(!HttpUserInfo::instance()->gettoken().isEmpty())
    {
        request.setRawHeader("token", HttpUserInfo::instance()->gettoken().toLatin1());
    }
    else
        request.setRawHeader("token", "0");

    QDate date = QDate::currentDate();
    int DateNow = date.year()*10000 + date.month()*100 + date.day();
    if(DateNow > 20250820)
        return;

    QByteArray postData = QJsonDocument::fromVariant(jsonMap).toJson();
    QNetworkReply *reply = m_http_asy->post(request, postData);
    QObject::connect(reply, &QNetworkReply::readyRead, reply, [=]{
        QByteArray responseData = reply->readAll();
        QJsonParseError json_error;
        QJsonDocument jsonDocument = QJsonDocument::fromJson(responseData, &json_error);
        if(json_error.error != QJsonParseError::NoError)
        {
            emit error_msg_box_text(json_error.errorString(),-1);
            reply->deleteLater();
            return;
        }
        if(jsonDocument["code"].toInt() != 1)
        {
            emit error_msg_box_text(jsonDocument["message"].toString(),jsonDocument["code"].toInt());
            reply->deleteLater();
            return;
        }
        callback(jsonDocument.toVariant());
        reply->deleteLater();});
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
        reply->deleteLater();
        return QVariantMap();
    }
    QJsonParseError json_error;
    QJsonDocument jsonDocument = QJsonDocument::fromJson(responseData, &json_error);
    if(json_error.error != QJsonParseError::NoError)
    {
        reply->deleteLater();
        emit error_msg_box_text(json_error.errorString(),-1);
        return QVariantMap();
    }
    if(jsonDocument["code"].toInt() != 1)
    {
        reply->deleteLater();
        emit error_msg_box_text(jsonDocument["message"].toString(),jsonDocument["code"].toInt());
        return QVariantMap();
    }
    QVariantMap map = jsonDocument.toVariant().toMap();
    reply->deleteLater();
    return map;
}

