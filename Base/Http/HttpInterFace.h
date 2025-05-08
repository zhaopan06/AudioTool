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

enum class PhoneCodeType : int
{
    TYPE_LOGIN = 0,// 登录
    TYPE_RESET_PWD = 1,// 找回密码
    TYPE_RESET_MOBILE = 2,//重置手机号
    ATYPE_UNREGISTER = 3// 注销
};

using callBack = std::function<void(const QVariant &content)>;

using downLoadCallBack = std::function<void(const QString &path)>;

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

    //上麦
    QVariantMap addMic(int roomId, int type);

    //下载
    void downLoad(QString url, downLoadCallBack callBack);
    //上传图片
    void uploadFile(QString filePath, QString scenes, callBack callback);

    /*公会相关*/
    QVariantMap getFamilyDetail();

    QVariantMap getLiveRoomInfo();

    QVariantMap followUser(QString followedId, int isFollow);

    void getOnlineInfo(QString roomId, int currentPage, callBack callBack);
    void getMicApplyList(QString roomId, callBack callBack);
    void getContributeList(int type, int timeType, int size, QString roomId, callBack callBack);
    void getPcNewUserSquareList(int pageNum, int pageSize, callBack callBack);

private:
    explicit HttpInterFace(QObject *parent = nullptr);
    ~HttpInterFace();

    QVariantMap httpsGet_syn(QString url);

    QVariantMap httpsPut_syn(QString url, QVariantMap jsonMap);

    void httpsGet_asy(QString url, QVariantMap jsonMap, callBack callback);//get异步
    void httpPost_asy(QString url , QVariantMap jsonMap, callBack callback);//Post异步
    void httpsPost_asy(QString url , QVariantMap jsonMap);//异步

    QVariantMap httpPost_syn(QString url , QVariantMap jsonMap);
    QVariantMap httpsPost_syn(QString url ,QVariantMap jsonMap);//同步

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
};

#endif // HTTPINTERFACE_H
