#ifndef HTTPINTERFACE_H
#define HTTPINTERFACE_H
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QObject>
#include <QVariantMap>
#include <QMap>

#define BASE_API_URL "https://testapi.linkfunapp.com/app"
#define LIVE_BASE_API_URL ""
#define LOGIN_URL "/user/login" //登录
#define H5Test "https://testm.linkfunapp.com/app.html#/h5/"
#define H5 "https://m.linkfunapp.com/app.html#/h5/"


enum class PhoneCodeType : int
{
    TYPE_LOGIN = 0,// 登录
    TYPE_RESET_PWD = 1,// 找回密码
    TYPE_RESET_MOBILE = 2,//重置手机号
    ATYPE_UNREGISTER = 3// 注销
};

using callBack = std::function<void(const QVariant &content)>;
using ErrCallBack = std::function<void(const QVariant &content)>;
using downLoadCallBack = std::function<void(const QString &path)>;

class HttpInterFace : public QObject
{
    Q_OBJECT
public:
    static HttpInterFace* getInstance();
    //获取验证码
    void getCaptcha(QString phone,QString region_code, callBack callback);

    QVariantMap loginToServer(QString account, QString passwd);

    QVariantMap joinRoom(int roomId, int entryType, QString subTopic);
    void joinRoom(int roomId, int entryType, QString subTopic, callBack callback);

    QVariantMap closeRoom(QString roomId);
    //上麦
    QVariantMap addMic(QString roomId, int type);

    //抱上麦
    QVariantMap b_upMic(QString roomId, QString targetUserId);
    //抱下麦
    QVariantMap b_downMic(QString roomId, QString targetUserId);
    //自己下麦
    QVariantMap m_downMic();
    QVariantMap micOpenOrClose(QString roomId, QString targetUserId, int type);
    QVariantMap lockMic(int type, int seat);

    QVariantMap settingEmceeOrAdmin(int settingType, QString targetUserId);

    void downLoad(QString url, downLoadCallBack callBack);
    //上传图片
    void uploadFile(const QString &filePath, int type, callBack callback);

    //更新直播间信息 传参 name 房间名称 announcement 房间公告 roomId 房间id  photo 房间封面
    void uploadLiveInfo(QString photo, QString name, QString announcement, QString roomId, callBack callback);

    /*公会相关*/
    QVariantMap getFamilyDetail();

    void getLiveRoomInfo_asy(callBack callBack);

    QVariantMap followUser(QString followedId, int isFollow);

    void getOnlineInfo(QString roomId, int currentPage, callBack callBack);
    void getMicApplyList(QString roomId, callBack callBack);
    void getContributeList(int type, int timeType, int size, QString roomId, callBack callBack);
    void getPcNewUserSquareList(int pageNum, int pageSize, callBack callBack);
    void getCommonConfig(callBack callBack);
    void getUserInfo(QString userId, callBack callBack);
    void getGiftWall(QString userID, int giftType, int isLighten, callBack callBack);
    void getUserMedals(QString userID, callBack callBack);
    void clearCardiacValue(QString roomId, callBack callBack);
    void noticeFans(QString roomId, callBack callBack);
    void queryMessageListUserInfo(QString roomId, callBack callBack, ErrCallBack errorCallBack = nullptr);
    void getMyFollow(int currentPage, int requestType, callBack callBack, QString param = "");
    void getMessageList(callBack callBack);
    void getOwnerAuthList(QString roomId, callBack callBack);
    void getRecommendRoom(QString roomId, callBack callBack);
    void getHouPushData(QString roomId,callBack callBack);
    void useReferralCard(QString placeId, QString roomId, callBack callBack);
    void getHotDataHistory(QString roomId, int currentPage, callBack callBack);
    void getDressUp(int type, int currentPage, callBack callBack);
    void setDressUp(int avatarFrameId, int type, callBack callBack);
    QVariantMap getGiftList();


private:
    explicit HttpInterFace(QObject *parent = nullptr);
    ~HttpInterFace();



    QVariantMap httpsPut_syn(QString url, QVariantMap jsonMap);

    QVariantMap httpsGet_syn(QString url);
    void httpsGet_asy(QString url, QVariantMap jsonMap, callBack callback, ErrCallBack errorCallBack = nullptr);//get异步

    QVariantMap httpsPost_syn(QString url ,QVariantMap jsonMap);//同步
    void httpPost_asy(QString url , QVariantMap jsonMap, callBack callback);//Post异步

private:
    QNetworkAccessManager m_pNetworkAccessManager; //同步
    QNetworkAccessManager m_http_asy; //异步
    QString m_version;
    QString m_token;

signals:
    void error_msg_box_text(QString,int);
    void reLogin();
public:
    QString m_authorization;
};

#endif // HTTPINTERFACE_H
