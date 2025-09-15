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
    void setLoginInfo(QVariantMap data);
    QVariantMap getLoginInfo();   
    QString getUserID();
    QString getImgTag();
    QString getName();
    const QString gettoken();
    QString getImToken();
    void setRoomInfo(QVariantMap data);
    QVariantMap getRoomInfo();
    QVariantMap getInvInfo();   
    QString getIMRoomID(); 
    QString getClassRoomID();
    void setPhoneAreaInfo(QVariant data);
    QVariant getPhoneAreaInfo();
private:
    static QReadWriteLock readWriteLock;
    static QScopedPointer<HttpUserInfo> instance_;
    QVariantMap m_loginInfo;
    QVariant m_areaInfo;
    QVariant m_phoneAreaInfo;
    QString m_token = "0";
    QString m_wsPath;
    QString m_coverPath;
    QString m_classID;
    QString m_areaID;
    QString m_userID;
    QString m_chatRoomId;
    QString m_IMtoken;
    QVariantMap m_roomInfo;
    QVariantMap m_invInfo;
signals:

};
#endif
