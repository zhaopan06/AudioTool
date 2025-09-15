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
#include <QThread>
#include "HttpAsynWorkFace.h"
#include "ToastPage.h"

HttpAsynWorkFace httpasynWork;

HttpInterFace *HttpInterFace::getInstance()
{
    static HttpInterFace pHttpInterFace;
    return &pHttpInterFace;
}

HttpInterFace::HttpInterFace(QObject *parent) : QObject(parent)
{
    httpasynWork.initInterFace();
    httpasynWork.setBaseUrl(BASE_API_URL);
    QVariantMap map;
    map.insert("deviceId", "11");
    map.insert("appVersion", "1.0");
    map.insert("deviceType", "2");
    map.insert("osVersion", "win10");
    map.insert("root", "0");
    map.insert("deviceName", "PC");
    map.insert("channel", "1");
    map.insert("emulator", "0");
    map.insert("networkType", "0");
    httpasynWork.setHeaders(map);
}

HttpInterFace::~HttpInterFace()
{
}

void HttpInterFace::submitRequest(RequestMethod method, const QString &url, const callBack &successCallback, const ErrorCallback &errorCallback, const QVariantMap &body, QObject *context)
{
    httpasynWork.setToken(HttpUserInfo::instance()->gettoken());
    QPointer<QObject> newObject = QPointer<QObject>(context ? context : g_main);
    httpasynWork.submitRequest( static_cast<HttpAsynWorkFace::RequestMethod>(method),url,successCallback,[=](int code, const QString& str){

        if (!newObject || !newObject.data())
        {
            return;
        }

       QMetaObject::invokeMethod(newObject, [=]() {
           QString toastMsg = QString::number(code) +  QStringLiteral("--") + str;
           ToastPage::showToast(nullptr,toastMsg);
       }, Qt::QueuedConnection);

        if(code == 0 || code == 356)
        {
            emit error_msg_box_text(str, code);
        }

        if(errorCallback)
        {
            QMetaObject::invokeMethod(newObject, [=]() {
                errorCallback(code,str);
            }, Qt::QueuedConnection);
        }

    },body,newObject);
}

void  HttpInterFace::getCaptcha(QString phone, QString region_code, callBack callback, ErrorCallback errBack, QObject *context)
{
    QVariantMap jsonMap;
    jsonMap.insert("smsType", 1);
    jsonMap.insert("areaCode","+86");
    jsonMap.insert("phone",phone);

    const QString strUrl = "/sms/send";    
    submitRequest(RequestMethod::POST,strUrl,callback,errBack,jsonMap,context);
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

    QNetworkAccessManager *manager = new QNetworkAccessManager();
    QNetworkReply *reply = manager->post(request, multiPart);
    multiPart->setParent(reply);

    connect(reply, &QNetworkReply::finished, [=](){
        QByteArray responseData = reply->readAll();
        QJsonParseError json_error;
        QJsonDocument jsonDocument = QJsonDocument::fromJson(responseData, &json_error);
        if(json_error.error != QJsonParseError::NoError)
        {
            emit error_msg_box_text(json_error.errorString(),-1);
            reply->deleteLater();
            manager->deleteLater();
            return;
        }
        if(jsonDocument["code"].toInt() != 1)
        {
            emit error_msg_box_text(jsonDocument["message"].toString(),jsonDocument["code"].toInt());
            reply->deleteLater();
            manager->deleteLater();
            return;
        }
        callback(jsonDocument.toVariant());
        reply->deleteLater();
        manager->deleteLater();
    });
}

void HttpInterFace::uploadLiveInfo(QString photo, QString name, QString announcement, QString roomId, callBack callback)
{
    QVariantMap jsonMap;
    jsonMap.insert("photo",photo);
    jsonMap.insert("name",name);
    jsonMap.insert("announcement",announcement);
    jsonMap.insert("roomId",roomId);

    const QString strUrl = "/live/updateLivingRoom";
    submitRequest(RequestMethod::POST,strUrl,callback,nullptr,jsonMap);
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

void HttpInterFace::getLiveRoomInfo_asy(callBack callBack, QObject *context)
{
    QVariantMap jsonMap;
    QString strUrl = QString("/pcHome/getPcHomeInfo");
    submitRequest(RequestMethod::GET,strUrl,callBack,nullptr,jsonMap,context);
}

void HttpInterFace::followUser(QString followedId, int isFollow, callBack callBack, QObject *context)
{
    QVariantMap jsonMap;
    jsonMap.insert("followedId",followedId);
    jsonMap.insert("isFollow", isFollow);
    QString url = QString("/user/followUser");
    submitRequest(RequestMethod::POST,url,callBack,nullptr,jsonMap,context);
}

void HttpInterFace::getOnlineInfo(QString roomId, int currentPage, callBack callBack)
{
    QVariantMap jsonMap;
    jsonMap.insert("roomId",roomId);
    jsonMap.insert("currentPage", currentPage);

    QString url = QString("/live/getV2OnlineList");
    submitRequest(RequestMethod::GET,url,callBack,nullptr,jsonMap);
}

void HttpInterFace::getMicApplyList(QString roomId, callBack callBack)
{
    QVariantMap jsonMap;
    jsonMap.insert("roomId",roomId);

    QString url = QString("/live/getMicApplyList");
    submitRequest(RequestMethod::GET,url,callBack,nullptr,jsonMap);
}

void HttpInterFace::getContributeList(int type, int timeType, int size, QString roomId, callBack callBack)
{
    QVariantMap params;
    params.insert("type",type);
    params.insert("timeType",timeType);
    params.insert("size",size);
    params.insert("roomId",roomId);

    QString url = QString("/ranking/list");
    submitRequest(RequestMethod::GET,url,callBack,nullptr,params);
}

void HttpInterFace::getPcNewUserSquareList(int pageNum, int pageSize, callBack callBack)
{
    QVariantMap params;
    params.insert("pageNum",pageNum);
    params.insert("pageSize",pageSize);

    QString url = QString("/pcLiveRoom/getPcNewUserSquareList");
    submitRequest(RequestMethod::GET,url,callBack,nullptr,params);
}

void HttpInterFace::getCommonConfig(callBack callBack)
{
    QVariantMap jsonMap;
    jsonMap.insert("systemConfigType",1);    
    QString url = QString("/common/getCommonConfig");
    submitRequest(RequestMethod::GET,url,callBack,nullptr,jsonMap);
}

void HttpInterFace::getUserInfo(QString userId, callBack callBack)
{
    QVariantMap jsonMap;
    jsonMap.insert("userId",userId);
    QString url = QString("/user/getUserInfo");
    submitRequest(RequestMethod::GET,url,callBack,nullptr,jsonMap);
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
    QString url = QString("/gift/getGiftWall");
    submitRequest(RequestMethod::GET,url,callBack,nullptr,jsonMap);
}

void HttpInterFace::getUserMedals(QString userId, callBack callBack)
{
    QVariantMap jsonMap;
    jsonMap.insert("userId",userId);
    QString url = QString("/user/getUserMedals");
    submitRequest(RequestMethod::GET,url,callBack,nullptr,jsonMap);
}

void HttpInterFace::getGiftList(callBack callBack, QObject *context)
{
    QVariantMap jsonMap;
    QString url = QString("/gift/v3/getGiftList");
    submitRequest(RequestMethod::GET,url,callBack,nullptr,jsonMap,context);
}

void HttpInterFace::updateRoomInfo(QString roomId, int entryType, callBack callback)
{
    QVariantMap jsonMap;
    jsonMap.insert("roomId",roomId);
    jsonMap.insert("entryType",entryType);
    QString strUrl = QString("/live/getLivingRoom");
    submitRequest(RequestMethod::POST,strUrl,callback,nullptr,jsonMap);
}

void HttpInterFace::clearCardiacValue(QString roomId, callBack callBack)
{
    QVariantMap jsonMap;
    jsonMap.insert("roomId",roomId);
    QString strUrl = QString("/live/clearCardiacValue");
    submitRequest(RequestMethod::POST,strUrl,callBack,nullptr,jsonMap);
}

void HttpInterFace::noticeFans(QString roomId, callBack callBack)
{
    QVariantMap jsonMap;
    jsonMap.insert("roomId",roomId);
    QString url = QString("/room/noticeFans");
    submitRequest(RequestMethod::GET,url,callBack,nullptr,jsonMap);
}

void HttpInterFace::queryMessageListUserInfo(QString roomId, callBack callBack, ErrCallBack errorCallBack)
{
    QVariantMap jsonMap;
    jsonMap.insert("userIds",roomId);
    QString url = QString("/user/queryMessageListUserInfo");
    submitRequest(RequestMethod::GET,url,callBack,nullptr,jsonMap);
}

//请求类型（0：我的关注，1：关注我的，2：我的好友，3：我的黑名单，4：访客）
void HttpInterFace::getMyFollow(int currentPage, int requestType, callBack callBack,QString param)
{
    QVariantMap jsonMap;
    jsonMap.insert("currentPage",currentPage);
    jsonMap.insert("requestType",requestType);
    if(!param.isEmpty())
        jsonMap.insert("param",param);
    QString url = QString("/user/myFollow");
    submitRequest(RequestMethod::GET,url,callBack,nullptr,jsonMap);
}

void HttpInterFace::getMessageList(callBack callBack)
{
    QVariantMap jsonMap;
    QString url = QString("/user/getMessageList");
    submitRequest(RequestMethod::GET,url,callBack,nullptr,jsonMap);
}

void HttpInterFace::getOwnerAuthList(QString roomId, callBack callBack)
{
    QVariantMap jsonMap;
    jsonMap.insert("roomId",roomId);
    QString url = QString("/live/getOwnerAuthList");
    submitRequest(RequestMethod::GET,url,callBack,nullptr,jsonMap);
}

void HttpInterFace::getRecommendRoom(QString roomId,callBack callBack)
{
    QVariantMap jsonMap;
    jsonMap.insert("roomId",roomId);
    QString url = QString("/live/leaveReferralLiving");
    submitRequest(RequestMethod::POST,url,callBack,nullptr,jsonMap);
}

void HttpInterFace::getHouPushData(QString roomId,callBack callBack)
{
    QVariantMap jsonMap;
    jsonMap.insert("roomId",roomId);
    QString url = QString("/live/getReferralPlaceConfig");
    submitRequest(RequestMethod::GET,url,callBack,nullptr,jsonMap);
}

void HttpInterFace::useReferralCard(QString placeId, QString roomId,callBack callBack)
{
    QVariantMap jsonMap;
    jsonMap.insert("placeId",placeId);
    jsonMap.insert("roomId",roomId);
    QString strUrl = QString("/live/useReferralCard");
    submitRequest(RequestMethod::GET,strUrl,callBack,nullptr,jsonMap);
}

void HttpInterFace::getHotDataHistory(QString roomId, int currentPage, callBack callBack)
{
    QVariantMap jsonMap;
    jsonMap.insert("roomId",roomId);
    jsonMap.insert("currentPage",currentPage);
    QString url = QString("/live/getReferralUsedCard");
    submitRequest(RequestMethod::GET,url,callBack,nullptr,jsonMap);
}
//装扮类型 0 头像框 1 座驾 2 气泡 3 直播间背景
void HttpInterFace::getDressUp(int type,int currentPage, callBack callBack)
{
    QVariantMap jsonMap;
    jsonMap.insert("type",type);
    jsonMap.insert("currentPage",currentPage);
    QString url = QString("/user-avatar-frame-record/listV2");
    submitRequest(RequestMethod::GET,url,callBack,nullptr,jsonMap);
}

void HttpInterFace::setDressUp(int avatarFrameId, int type, callBack callBack)
{
    QVariantMap jsonMap;
    QString strUrl = QString("/user-avatar-frame-record/wear?avatarFrameId=%1&type=%2").arg(avatarFrameId).arg(type);
    submitRequest(RequestMethod::POST,strUrl,callBack,nullptr,jsonMap);
}

void HttpInterFace::loginToServer(QString phone, QString verifyCode, callBack callBack,ErrorCallback errBack, QObject *context)
{
    QVariantMap jsonMap;
    jsonMap.insert("phone",phone);
    jsonMap.insert("verifyCode", verifyCode);
    jsonMap.insert("authType", -1);
    QString url = QString("/user/login");
    submitRequest(RequestMethod::POST,url,callBack,errBack,jsonMap,context);
}

// 操作类型 0-取消排麦 1-申请排麦
void HttpInterFace::addMic(QString roomId, int type, callBack callBack, QObject *context)
{
    QVariantMap jsonMap;
    jsonMap.insert("roomId",roomId);
    jsonMap.insert("type", type);
    QString url = QString("/live/dealApplyMic");
    submitRequest(RequestMethod::POST,url,callBack,nullptr,jsonMap,context);
}

void HttpInterFace::b_upMic(QString roomId, QString targetUserId, callBack callBack, QObject *context)
{
    QVariantMap jsonMap;
    jsonMap.insert("roomId",roomId);
    jsonMap.insert("type", 0);
    jsonMap.insert("targetUserId", targetUserId);
    QString url = QString("/live/dealUpDownMic");
    submitRequest(RequestMethod::POST,url,callBack,nullptr,jsonMap,context);
}

void HttpInterFace::b_downMic(QString roomId, QString targetUserId, callBack callBack, QObject *context)
{
    QVariantMap jsonMap;
    jsonMap.insert("roomId",roomId);
    jsonMap.insert("type", 1);
    jsonMap.insert("targetUserId", targetUserId);
    QString url = QString("/live/dealUpDownMic");
    submitRequest(RequestMethod::POST,url,callBack,nullptr,jsonMap,context);
}

void HttpInterFace::m_downMic()
{
    QVariantMap jsonMap;
    jsonMap.insert("roomId",HttpUserInfo::instance()->getClassRoomID());
    jsonMap.insert("type", 2);
    jsonMap.insert("targetUserId", HttpUserInfo::instance()->getUserID());
    QString url = QString("/live/dealUpDownMic");
    submitRequest(RequestMethod::POST,url,nullptr,nullptr,jsonMap,nullptr);
}

//操作类型 0-开麦 1-闭麦
void HttpInterFace::micOpenOrClose(QString roomId, QString targetUserId, int type)
{
    QVariantMap jsonMap;
    jsonMap.insert("roomId",HttpUserInfo::instance()->getClassRoomID());
    jsonMap.insert("type", type);
    jsonMap.insert("targetUserId", targetUserId);
    QString url = QString("/live/micOpenOrClose");
    submitRequest(RequestMethod::POST,url,nullptr,nullptr,jsonMap,nullptr);
}
//操作类型 0-解除闭麦 1-锁麦
void HttpInterFace::lockMic(int type, int seat)
{
    QVariantMap jsonMap;
    jsonMap.insert("roomId",HttpUserInfo::instance()->getClassRoomID());
    jsonMap.insert("type", type);
    jsonMap.insert("seat", seat);
    QString url = QString("/live/micLock");
    submitRequest(RequestMethod::POST,url,nullptr,nullptr,jsonMap,nullptr);
}

//主机有房主才能设置
/*设置类型，0=设置支持人，1=设置房间管理员，2=移除主持人，3=移除房间管理员,4=拉黑，5=解除拉黑*/
void HttpInterFace::settingEmceeOrAdmin(int settingType, QString targetUserId)
{
    QVariantMap jsonMap;
    jsonMap.insert("settingType", settingType);
    jsonMap.insert("targetUserId", targetUserId);
    QString url = QString("/room/settingEmceeOrAdmin");
    submitRequest(RequestMethod::POST,url,nullptr,nullptr,jsonMap,nullptr);
}

void HttpInterFace::joinRoom(int roomId, int entryType, QString subTopic, callBack callback, ErrorCallback errBack)
{
    QVariantMap jsonMap;
    jsonMap.insert("roomId",roomId);
    jsonMap.insert("entryType", entryType);
    jsonMap.insert("subTopic", subTopic);
    QString strUrl = QString("/live/joinLivingRoom");
    submitRequest(RequestMethod::POST,strUrl,callback,errBack,jsonMap);
}

void HttpInterFace::closeRoom(QString roomId, callBack callback)
{
    QVariantMap jsonMap;
    jsonMap.insert("roomId",roomId);
    QString url = QString("/room/closeVoiceRoom");
    submitRequest(RequestMethod::POST,url,callback,nullptr,jsonMap);
}




