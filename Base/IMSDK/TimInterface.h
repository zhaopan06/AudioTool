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
    static TimInterface* getInstance();
private:
    TimInterface();
    static TimInterface *pTimInterfaceFace;
public:

    //初始化腾讯IM
    int initSDK();
    //获取IM版本
    QString getSDKVersion();
    //初始化接受消息回调
    void initRecvNewMsgCallback();

    void initTIMConvGetConvList();
    void getInitTIMConvGetConvListMSGTojson(QByteArray json_msg_array);

    //获取总的红点数量
    int getTIMConvGetTotalUnreadMessageCount();
    void sendTIMMsgSendMessageReadReceipts(QString uid);

    //登录相关
    int  login();
    int  logout();

    /*****************c2c相关*****************************/
    //c2c发送消息
    int sendMessage_c2c(const char* conv_id, const char* json_msg_param, const void* user_data);
    void initTIMMsgGetMsgList(QString userid);
    void getTIMMsgGetMsgList(QByteArray json_msg_array);
    //组建发送消息的json方法 文字
    void setC2CSendJson(IMType type, QString text, QString toUid);
    void SendC2CImage(QString path, QString toUid);

    /*-----------群组相关-----------*/
    //加入群组
    void groupJoin(const char* group_id);
    void groupOut(const char* group_id);

    //组建发送消息的json方法
    void setSendJson(IMType type, QString text);
    void sendImage(QString path);
    //设置自定义消息体
    QString setCustomJson(IMType imType, QString text);
private:
    //有新消息,解析消息
    void getMSGTojson(QByteArray msg);
    //群内发送消息
    int sendMessage_group(const char* conv_id, const char* json_msg_param, const void* user_data);
signals:
    void msg_numbers(int);//总红点数量
    void msg_uidNumbers(QString, int);//单个回话的红点数量

    void msg_liveClose();
    void loginStatus(int,QString);
    void newMes();
    void msg_notice(QVariantMap, QString);
    void msg_emotion(QVariantMap, QString,int);//表情
    void msg_image(QVariantMap, QString, QString);
    void msg_txt(QVariantMap, QString, int);//文字
    void msg_vip(QVariantMap, QString url);
    void msg_micInfo(QVariantList);
    void msg_gift(QVariantMap,  QVariantMap,  QVariantMap);
    void updateContribute();
    void msg_updateMicList();
    void msg_multipleAuthoriation(QVariantMap);
    void msg_uninit();

    void c2c_msg_text(QVariantMap, QString);
    void c2c_initTimList(QVariantList);
    void c2c_initTimMsgList(QVariantList);
    void c2c_msg_image(QVariantMap, QString, QString);
    void c2c_msg_inviteFriends(QVariantMap);
private:


};

#endif // TIMINTERFACE_H
