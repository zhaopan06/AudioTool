#ifndef HttpUserInfo_H
#define HttpUserInfo_H

#include <QObject>
#include <QReadWriteLock>
#include <QVariantMap>

class HttpUserInfo : public QObject
{
    Q_OBJECT
private:
    explicit HttpUserInfo(QObject *parent = nullptr);

public:
    static HttpUserInfo* instance(QObject *parent = nullptr);

    //用户信息相关
    void setLoginInfo(QVariantMap data);
    QVariantMap getLoginInfo();   
    QString getUserID();

    QString getImgTag();
    QString getName();

    //获取token
    const QString gettoken();
    QString getImToken();

    //设置房间信息
    void setRoomInfo(QVariantMap data);
    QVariantMap getRoomInfo();
    QString getRoomID();   

    //设置手机号区号和归属地信息
    void setPhoneAreaInfo(QVariant data);
    QVariant getPhoneAreaInfo();


private:
    static QReadWriteLock readWriteLock;
    static QScopedPointer<HttpUserInfo> instance_;


    QVariantMap m_loginInfo;

    QVariant m_areaInfo;//地域信息
    QVariant m_phoneAreaInfo;
    QString m_token;
    QString m_wsPath;

    /***********************开播所需相关*********************/
    QString m_coverPath;
    QString m_classID;//选择的直播分类
    QString m_areaID;//选择的地域
    /******************************************************/

    QString m_userID;


    /*IM相关*/
    QString m_chatRoomId; //消息所属会话 ID,就是 IM的kTIMMsgConvIdID
    QString m_IMtoken;
    QVariantMap m_roomInfo;//进入房间后获取的json数据 http请求的原数据
signals:

};
#endif // HttpUserInfo_H
