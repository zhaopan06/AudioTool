#ifndef TIMINTERFACE_H
#define TIMINTERFACE_H
#include "TIMCloud.h"
#include <QObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

class TimInterface : public QObject
{
    Q_OBJECT
public:
    TimInterface();
    //初始化腾讯IM
    int initSDK();
    //获取IM版本
    QString getSDKVersion();
    //登录
    int  login(const char *user_id, const char *IMtoken);
    //登出
    int  logout(TIMCommCallback	cb, const void *user_data);
    //群内发送消息
    int sendMessage_group(const char* conv_id, const char* json_msg_param, const void* user_data);
    //c2c发送消息
    int sendMessage_c2c(const char* conv_id, const char* json_msg_param, const void* user_data);
    //初始化接受消息回调
    void initRecvNewMsgCallback();
    //有新消息
    void newMessages(QString msg);
    //加入群组

    /*-----------群组相关-----------*/
    //加入群组
    void groupJoin(const char* group_id);
    //解析消息
    void getMSGTojson(QByteArray msg);

signals:
    void loginStatus(int,QString);
    void newMes();

    void msg_emotion(QString);//纯表情
    void msg_txt(QString);//文字
    void msg_dice(QString);//骰子
    void msg_finger(QString);//猜拳
    void msg_mic(QString);//猜拳

private:
    QVariantMap m_user_info; //消息发送者的信息

};

#endif // TIMINTERFACE_H
