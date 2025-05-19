#ifndef TIMINTERFACE_H
#define TIMINTERFACE_H
#include "TIMCloud.h"
#include <QObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

/*
 *  message - type：消息类型 1 文本，2 图片，3音频，
 *  8 爆灯 9 emjio表情单图 10 骰子，11 划拳,
 *  12 操作类型消息（例如：主持将xxx抱上麦。显示样式与普通消息一样，只是文本颜色不一样），  系统消息
 *  13 通知类型消息
（例如：xxx来了。无需显示发送者头像，需要显示用户等级）  15. 用户等级提升提示 （例如：恭喜 xxx 等级提升到多少级）16：pk通知    17：vip表情
 */
enum IMType {
    IMType_Text = 1,
    IMType_Image = 2,
    IMType_Sound = 3,
    IMType_light = 8,
    IMType_emjio = 9,
    IMType_dice = 10,
    IMType_finger = 11,
    IMType_upMic = 12,
    IMType_notice = 13,
    IMType_Level = 15,
    IMType_PK = 16,
    IMType_VIP = 17,
    IMType_machine = 18
};


class TimInterface : public QObject
{
    Q_OBJECT
public:
    TimInterface();

    //初始化腾讯IM
    int initSDK();
    //获取IM版本
    QString getSDKVersion();
    //初始化接受消息回调
    void initRecvNewMsgCallback();

    //登录
    int  login();
    //登出
    int  logout();
    //c2c发送消息
    int sendMessage_c2c(const char* conv_id, const char* json_msg_param, const void* user_data);


    /*-----------群组相关-----------*/
    //加入群组
    void groupJoin(const char* group_id);
    //群内发送消息
    int sendMessage_group(const char* conv_id, const char* json_msg_param, const void* user_data);
    //组建发送消息的json方法
    void setSendJson(IMType type, QString text);
    void sendImage(QString path);
    //设置自定义消息体
    QString setCustomJson(IMType imType, QString text);
private:
    //有新消息,解析消息
    void getMSGTojson(QByteArray msg);

signals:
    void msg_liveClose();
    void loginStatus(int,QString);
    void newMes();

    void msg_notice(QVariantMap, QString);
    void msg_emotion(QString);//纯表情
    void msg_image(QVariantMap, QString);
    void msg_txt(QVariantMap, QString, int);//文字
    void msg_dice(QString);//骰子
    void msg_finger(QString);//猜拳
    void msg_mic(QString);//猜拳


    void msg_micInfo(QVariantList);
    void msg_gift(QVariantMap,  QVariantMap,  QVariantMap);
    void updateContribute();
    void msg_updateMicList();

    void msg_uninit();
private:


};

#endif // TIMINTERFACE_H
