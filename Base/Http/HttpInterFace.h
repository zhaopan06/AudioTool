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
#define LIVE_START "/live/joinLivingRoom" //加入房间


#define USER_INFO "/api/v1/auth/pwd-login"   //用户信息
#define LIVE_INFO "/lives/me"   //用户信息 和保存用户信息
#define LIVE_STOP "/lives/me/stop" //结束直播

enum class PhoneCodeType : int
{
    TYPE_LOGIN = 0,// 登录
    TYPE_RESET_PWD = 1,// 找回密码
    TYPE_RESET_MOBILE = 2,//重置手机号
    ATYPE_UNREGISTER = 3// 注销
};

using callBack = std::function<void(const QVariant &content)>;

class HttpInterFace : public QObject
{
    Q_OBJECT
public:
    static HttpInterFace* getInstance();

    //获取验证码
    QVariantMap getCaptcha(QString phone,QString region_code);
    QVariantMap loginToServer(QString account, QString passwd);
    QVariantMap createRoom(QString roomPhoto, QString roomName);
    QVariantMap joinRoom(int roomId, int entryType, QString subTopic);

    QVariantMap addMic(int roomId, int type);
    /*********************以下暂时无用*********************/
    void loginToServer_asy(QString account,QString passwd);



    //密码登录
    QVariantMap loginForPassword(const QString &country_code
               , const QString &mobile
               , const QString &password);
    //重置密码
    QVariantMap resetPassword(PhoneCodeType type
                              ,QString country_code
                              ,QString code
                              ,QString mobile
                              ,QString password);

    //上传图片 场景类型 QString: avatar | cover | image | video | audio
    void uploadFile(QString filePath, QString scenes, callBack callback);
    //TODO zp 下载图片(待完善)
    void downLoadFile(QString url, QString path);
    void downLoad(QString url, QString path);
    //获取主播个人信息
    QVariantMap getUserInfo();
    //开播 display_type 1横屏， 2竖屏
    QVariantMap startLive(int display_type);
    //结束直播
    QVariantMap endLive();

    //获取房间信息
    void getRoomInfo(callBack callback);
    //更新房间信息
    QVariantMap updateRoomInfo(QString category_id, QString cover_url, QString notice, QString title, QString video_url, QString live_region, bool showInfo);

    /********************************************************/
    QVariantMap getLiveInfo();
    QVariantMap saveLiveInfo(QVariantMap jsonMap);

    QVariantMap stopLive();

private:
    explicit HttpInterFace(QObject *parent = nullptr);
    ~HttpInterFace();

    void addBaseParams(QVariantMap &jsonMap);

    QVariantMap httpsGet_syn(QString url);

    QVariantMap httpsPut_syn(QString url, QVariantMap jsonMap);

    void httpsGet_asy(QString url, callBack callback);//get异步
    void httpPost_asy(QString url , QVariantMap jsonMap, callBack callback);//Post异步
    void httpsPost_asy(QString url , QVariantMap jsonMap);//异步

    QVariantMap httpPost_syn(QString url , QVariantMap jsonMap);//同步
    QVariantMap httpsPost_syn(QString url ,QVariantMap jsonMap);

private slots:
    void replyFinished(QNetworkReply *reply);

private:
    QNetworkAccessManager* m_pNetworkAccessManager; //同步
    QNetworkAccessManager* m_http_asy; //异步
    static HttpInterFace *pHttpInterFace;
    QString m_uuid;
    QString m_version;
    QString m_token;

public:
    QString m_authorization;
    QString domain_base = "http://streamer.dev.zenkoo.xyz";
};

#endif // HTTPINTERFACE_H
