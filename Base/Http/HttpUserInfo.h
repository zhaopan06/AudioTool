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
    //登录信息
    void setLoginInfo(QVariantMap data);
    QVariantMap getLoginInfo();
    //用户信息相关
    void setHttpUserInfo(QVariantMap data);
    QVariantMap getHttpUserInfo();
    QString getUserID();


    //websocket相关
    QString getWSPath();
    void setWSPath(QString path);

    //获取个人token
    const QString gettoken();
    QString getImToken();

    //设置房间信息
    void setRoomInfo(QVariantMap data);
    QVariantMap getRoomInfo();
    QString getRoomID();

    //设置地域信息
    void setAreaInfo(QVariant data);
    QVariant getAreaInfo();

    //设置手机号区号和归属地信息
    void setPhoneAreaInfo(QVariant data);
    QVariant getPhoneAreaInfo();

    /***********************开播所需相关*********************/
    //获取封面地址
    void setCoverInfo(QString path);
    QString getCoverInfo();

    //设置已选择的直播分类
    void setClassID(QString id);
    QString getClassID();

    //设置已选择的直播地域
    void setLiveArea(QString area);    
    QString getLiveArea();
    /******************************************************/

private:
    static QReadWriteLock readWriteLock;
    static QScopedPointer<HttpUserInfo> instance_;

    QVariantMap m_roomInfo;
    QVariantMap m_loginInfo;
    QVariantMap m_HttpUserInfo;
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
    QString m_IMtoken;
signals:

};
#endif // HttpUserInfo_H
