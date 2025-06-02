#include "TimInterface.h"
#include "Global.h"
#include "qcoreapplication.h"
#include "qdebug.h"
#include "HttpUserInfo.h"
#include <QJsonObject>
#include <QJsonDocument>
#include "MsgBox.h"

TimInterface* TimInterface::pTimInterfaceFace = NULL;
TimInterface *TimInterface::getInstance()
{
    if(pTimInterfaceFace == NULL)
    {
        pTimInterfaceFace = new TimInterface();
    }
    return pTimInterfaceFace;
}

TimInterface::TimInterface()
{

}

int TimInterface::initSDK()
{
    uint64_t sdk_app_id = 1600037216;
    QString path = QCoreApplication::applicationDirPath();
    QJsonObject jsonObj;
    jsonObj["kTIMSdkConfigLogFilePath"] = path.toUtf8().data();
    jsonObj["kTIMSdkConfigConfigFilePath"] = path.toUtf8().data();
    QJsonDocument doc(jsonObj);
    QString jsonString = doc.toJson(QJsonDocument::Compact);
    int code = TIMInit(sdk_app_id, jsonString.toUtf8().data());
    if (TIM_SUCC != code)
    {
        qDebug()<<"TIMInit error code----------"<<code;
    }
    initRecvNewMsgCallback();

    TIMSetKickedOfflineCallback([](const void* user_data) {
        MsgBox::showMsg(NULL,tr("提示"), tr("被踢下线，请重启登录"));
    }, this);

    TIMSetUserSigExpiredCallback([](const void* user_data) {
        MsgBox::showMsg(NULL,tr("提示"), tr("IMToken过期，请重启登录"));
    }, this);
    //添加好友回调
    TIMSetOnAddFriendCallback([](const char* json_identifier_array, const void* user_data) {

    }, this);
    //删除好友回调
    TIMSetOnDeleteFriendCallback([](const char* json_identifier_array, const void* user_data) {

    }, this);

    TIMSetConvTotalUnreadMessageCountChangedCallback([](int total_unread_count, const void* user_data) {
        //TODO 这里返回红点总数
        TimInterface* ths = (TimInterface*)user_data;
        emit ths->msg_numbers(total_unread_count);
    }, this);

    TIMSetConvEventCallback([](TIMConvEvent conv_event, const char* json_conv_array, const void* user_data){
        TimInterface* ths = (TimInterface*)user_data;
        QJsonParseError error;
        QJsonDocument json_doc = QJsonDocument::fromJson(json_conv_array, &error);
        if (json_doc.isNull())
            return;
        if (!json_doc.isArray())
            return;
        QVariantList list = json_doc.toVariant().toList();
        if(list.size() > 0)
        {
            QVariantMap data = list.at(0).toMap();
            QString uid = data["conv_id"].toString();
            int numbers =  data["conv_unread_num"].toInt();
            emit ths->msg_uidNumbers(uid, numbers);
        }
    }, this);

    TIMSetMsgReadedReceiptCallback([](const char* json_msg_readed_receipt_array, const void* user_data) {
        QJsonParseError error;
        QJsonDocument json_doc = QJsonDocument::fromJson(json_msg_readed_receipt_array, &error);
        qDebug()<<"TIMSetMsgReadedReceiptCallback---"<<json_doc;

    },this);
    return code;
}

QString TimInterface::getSDKVersion()
{
    return TIMGetSDKVersion();
}

int TimInterface::login()
{
    TIMCommCallback callback = [](int32_t code, const char* desc, const char* json_param, const void* user_data) {
        TimInterface* ths = (TimInterface*)user_data;

        emit ths->loginStatus(code, desc);
    };

    QString ImUserID = "user" + HttpUserInfo::instance()->getUserID();
    QString IMtoken = HttpUserInfo::instance()->getImToken();
    return TIMLogin(ImUserID.toLatin1(), IMtoken.toLatin1(), callback, this);
}

int  TimInterface::logout()
{
    TIMCommCallback callback = [](int32_t code, const char* desc, const char* json_param, const void* user_data) {

        qDebug()<<"logout code---"<<code;

    };
    return TIMLogout(callback, this);
}

int TimInterface::sendMessage_group(const char *conv_id, const char *json_msg_param, const void *user_data)
{
    TIMCommCallback callback = [](int32_t code, const char* desc, const char* json_param, const void* user_data) {

        if (code != ERR_SUCC)
        {
            qDebug()<<"group error-----------";
            return ;
        }
        else
        {
            qDebug()<<"group msg send suess-----------";
        }
    };

    return TIMMsgSendNewMsg(conv_id, kTIMConv_Group, json_msg_param, callback, user_data);
}

void TimInterface::setSendJson(IMType type, QString text)
{
    QVariantMap json_value_text;
    if(type == IMType_Text)
        json_value_text[kTIMElemType] = kTIMElem_Text;
    else if(type == IMType_Image)
        json_value_text[kTIMElemType] = kTIMElem_Image;
    else
        json_value_text[kTIMElemType] = kTIMElem_Custom;

    json_value_text[kTIMTextElemContent] = text;


    // 创建消息元素数组
    QVariantMap json_value_msg;
    QVariantList elem_array;
    elem_array.append(json_value_text);
    json_value_msg[kTIMMsgElemArray] = elem_array;

    json_value_msg[kTIMMsgSender] = "user" + HttpUserInfo::instance()->getUserID();
    json_value_msg[kTIMMsgClientTime] = time(NULL);
    json_value_msg[kTIMMsgServerTime] = time(NULL);
    json_value_msg[kTIMMsgConvId] = HttpUserInfo::instance()->getIMRoomID();
    json_value_msg[kTIMMsgConvType] = kTIMConv_Group;
    json_value_msg["message_cloud_custom_str"] = setCustomJson(type,text);

    // 转换为 JSON 字符串
    QJsonDocument doc(QJsonObject::fromVariantMap(json_value_msg));    
    sendMessage_group(HttpUserInfo::instance()->getIMRoomID().toLatin1(), doc.toJson(), this);
}

void TimInterface::sendImage(QString path)
{
    QVariantMap json_value_image;
    json_value_image[kTIMElemType] = kTIMElem_Image;
    json_value_image[kTIMImageElemOrigPath] = path;

    // 创建消息元素数组
    QVariantMap json_value_msg;
    QVariantList elem_array;
    elem_array.append(json_value_image);
    json_value_msg[kTIMMsgElemArray] = elem_array;

    json_value_msg[kTIMMsgSender] = "user" + HttpUserInfo::instance()->getUserID();
    json_value_msg[kTIMMsgClientTime] = time(NULL);
    json_value_msg[kTIMMsgServerTime] = time(NULL);
    json_value_msg[kTIMMsgConvId] = HttpUserInfo::instance()->getIMRoomID();
    json_value_msg[kTIMMsgConvType] = kTIMConv_Group;
    json_value_msg["message_cloud_custom_str"] = setCustomJson(IMType_Image,"");

    // 转换为 JSON 字符串
    QJsonDocument doc(QJsonObject::fromVariantMap(json_value_msg));
    sendMessage_group(HttpUserInfo::instance()->getIMRoomID().toLatin1(), doc.toJson(), this);
}

QString TimInterface::setCustomJson(IMType imType, QString text)
{
    QVariantMap message;
    message["body"] = text;
    message["type"] = imType;

    QVariantMap action;
    action["clickType"] = 0;
    action["responseType"] = 0;


    QVariantMap roomInfo = HttpUserInfo::instance()->getRoomInfo();
    QJsonDocument user_doc(QJsonObject::fromVariantMap(roomInfo["userInfoResponse"].toMap()));    

    QVariantMap CustomJson;
    CustomJson["tximMsgType"] = "groupMsg";
    CustomJson["isRead"] = false;
    CustomJson["message"] = message;
    CustomJson["action"] = action;
    CustomJson["user"] = roomInfo["userInfoResponse"].toMap();

    QJsonDocument doc(QJsonObject::fromVariantMap(CustomJson));
    return doc.toJson();
}


int TimInterface::sendMessage_c2c(const char *conv_id, const char *json_msg_param, const void *user_data)
{
    TIMCommCallback callback = [](int32_t code, const char* desc, const char* json_param, const void* user_data) {

        if (code != ERR_SUCC)
        { // 失败
            qDebug()<<"groupJoin error-----------code-"<<code<<"---desc-"<<desc;
            return ;
        }
        else
        {
            // 成功
            qDebug()<<"sendMessage_c2c suess-----------";
        }
    };
    return TIMMsgSendMessage(conv_id, kTIMConv_C2C, json_msg_param, nullptr, callback, user_data);
}

void TimInterface::initRecvNewMsgCallback()
{
    TIMAddRecvNewMsgCallback([](const char* json_msg_array, const void* user_data) {
        TimInterface* ths = (TimInterface*)user_data;
        ths->getMSGTojson(json_msg_array);
    }, this);
}

void TimInterface::getInitTIMConvGetConvListMSGTojson(QByteArray json_msg_array)
{
    // 解析JSON消息数组
    QJsonParseError error;
    QJsonDocument json_doc = QJsonDocument::fromJson(json_msg_array, &error);
    if (json_doc.isNull())
        return;
    if (!json_doc.isArray())
        return;

    emit c2c_initTimList(json_doc.toVariant().toList());
}

int TimInterface::getTIMConvGetTotalUnreadMessageCount()
{
    TIMCommCallback callback = [](int32_t code, const char* desc, const char* json_param, const void* user_data) {

        if (code != ERR_SUCC)
        {
            qDebug()<<"getTIMConvGetTotalUnreadMessageCount error-----------code-"<<code<<"---desc-"<<desc;
            return ;
        }
        else
        {

        }
    };
    return TIMConvGetTotalUnreadMessageCount(callback,this);
}
//TODO 设置未读清零
void TimInterface::sendTIMMsgSendMessageReadReceipts(QString uid)
{
    QJsonObject json_msgget_param;
    json_msgget_param[kTIMMsgReceiptConvId] = uid;
    json_msgget_param[kTIMMsgReceiptConvType] = kTIMConv_C2C;
    json_msgget_param[kTIMMsgReceiptTimeStamp] = "";
    json_msgget_param[kTIMMsgReceiptMsgId] = "";
    json_msgget_param[kTIMMsgReceiptIsPeerRead] = true;
    json_msgget_param[kTIMMsgReceiptReadCount] = 1;
    json_msgget_param[kTIMMsgReceiptUnreadCount] = 0;

    QJsonDocument doc(json_msgget_param);
    TIMMsgSendMessageReadReceipts(doc.toJson(), [](int32_t code, const char* desc, const char* json_params, const void* user_data){
        if (code != ERR_SUCC)
        {
            qDebug()<<"TIMMsgSendMessageReadReceipts error-----------code-"<<code<<"---desc-"<<desc;
            return ;
        }
        else
        {
            qDebug()<<"111 -----------code-"<<code<<"---desc-"<<desc;
            return ;
        }
    },this);
}

void TimInterface::initTIMMsgGetMsgList(QString userid)
{
    QJsonObject json_msg;
    QJsonObject json_msgget_param;
    json_msgget_param[kTIMMsgGetMsgListParamLastMsg] = json_msg;
    json_msgget_param[kTIMMsgGetMsgListParamIsRamble] = true;
    json_msgget_param[kTIMMsgGetMsgListParamIsForward] = false;
    json_msgget_param[kTIMMsgGetMsgListParamCount] = 10;
    QJsonDocument doc(json_msgget_param);

    TIMMsgGetMsgList(userid.toStdString().c_str(), kTIMConv_C2C, doc.toJson(), [](int32_t code, const char* desc, const char* json_params, const void* user_data) {

        if (code != ERR_SUCC)
        {
            return;
        }
        TimInterface* ths = (TimInterface*)user_data;
        ths->getTIMMsgGetMsgList(json_params);

    }, this);
}

void TimInterface::getTIMMsgGetMsgList(QByteArray json_msg_array)
{
    // 解析JSON消息数组
    QJsonParseError error;
    QJsonDocument json_doc = QJsonDocument::fromJson(json_msg_array, &error);
    if (json_doc.isNull())
        return;
    if (!json_doc.isArray())
        return;


    emit c2c_initTimMsgList(json_doc.toVariant().toList());
}

void TimInterface::setC2CSendJson(IMType type, QString text, QString toUid)
{
    QVariantMap json_value_text;
    if(type == IMType_Text)
        json_value_text[kTIMElemType] = kTIMElem_Text;
    else if(type == IMType_Image)
        json_value_text[kTIMElemType] = kTIMElem_Image;
    else
        json_value_text[kTIMElemType] = kTIMElem_Custom;

    json_value_text[kTIMTextElemContent] = text;


    // 创建消息元素数组
    QVariantMap json_value_msg;
    QVariantList elem_array;
    elem_array.append(json_value_text);
    json_value_msg[kTIMMsgElemArray] = elem_array;
    json_value_msg[kTIMMsgSender] = "user" + HttpUserInfo::instance()->getUserID();
    json_value_msg[kTIMMsgClientTime] = time(NULL);
    json_value_msg[kTIMMsgServerTime] = time(NULL);
    json_value_msg[kTIMMsgConvId] = toUid;
    json_value_msg[kTIMMsgConvType] = kTIMConv_C2C;

    QJsonDocument doc(QJsonObject::fromVariantMap(json_value_msg));
    sendMessage_c2c(toUid.toLatin1(), doc.toJson(), this);
}

void TimInterface::SendC2CImage(QString path, QString toUid)
{
    QVariantMap json_value_image;
    json_value_image[kTIMElemType] = kTIMElem_Image;
    json_value_image[kTIMImageElemOrigPath] = path;

    // 创建消息元素数组
    QVariantMap json_value_msg;
    QVariantList elem_array;
    elem_array.append(json_value_image);
    json_value_msg[kTIMMsgElemArray] = elem_array;

    json_value_msg[kTIMMsgSender] = "user" + HttpUserInfo::instance()->getUserID();
    json_value_msg[kTIMMsgClientTime] = time(NULL);
    json_value_msg[kTIMMsgServerTime] = time(NULL);
    json_value_msg[kTIMMsgConvId] = toUid;
    json_value_msg[kTIMMsgConvType] = kTIMConv_C2C;
    json_value_msg["message_cloud_custom_str"] = setCustomJson(IMType_Image,"");

    // 转换为 JSON 字符串
    QJsonDocument doc(QJsonObject::fromVariantMap(json_value_msg));
    sendMessage_c2c(toUid.toLatin1(), doc.toJson(), this);
}

void TimInterface::initTIMConvGetConvList()
{
    TIMConvGetConvList([](int32_t code, const char* desc, const char* json_param, const void* user_data) {

        TimInterface* ths = (TimInterface*)user_data;
        ths->getInitTIMConvGetConvListMSGTojson(json_param);

    }, this);


}


void TimInterface::groupJoin(const char* group_id)
{
    TIMCommCallback callback = [](int32_t code, const char* desc, const char* json_param, const void* user_data) {

        if (code != ERR_SUCC)
        {
            qDebug()<<"groupJoin error-----------code-"<<code<<"---desc-"<<desc;
            return ;
        }
        else
        {            
            qDebug()<<"groupJoin suess-----------";
        }
    };
    TIMGroupJoin(group_id, "hello", callback, this);
}

void TimInterface::groupOut(const char *group_id)
{
    TIMCommCallback callback = [](int32_t code, const char* desc, const char* json_param, const void* user_data) {

        if (code != ERR_SUCC)
        {
            qDebug()<<"groupOut error-----------code-"<<code<<"---desc-"<<desc;
            return ;
        }
        else
        {
            qDebug()<<"groupOut suess-----------";
        }
    };
    TIMGroupQuit(group_id, callback, this);
}

void TimInterface::getMSGTojson(QByteArray json_msg_array)
{    
    // 解析JSON消息数组
    QJsonParseError error;
    QJsonDocument json_doc = QJsonDocument::fromJson(json_msg_array, &error);
    if (json_doc.isNull())
        return;
    if (!json_doc.isArray())
        return;

    QJsonArray json_array_msgs = json_doc.array();
    // 遍历消息
    for (const QJsonValue& json_value_msg : json_array_msgs)
    {
        if (!json_value_msg.isObject())
            continue;

        QJsonObject msg_obj = json_value_msg.toObject();
        QJsonArray elems = msg_obj["message_elem_array"].toArray();

        // 遍历消息元素
        for (const QJsonValue& elem_value : elems)
        {
            if (!elem_value.isObject())
                continue;

            QString str_content = msg_obj["message_cloud_custom_str"].toString();
            QJsonObject str_doc = QJsonDocument::fromJson(str_content.toUtf8()).object();

            if("onlinePush" == str_doc["tximMsgType"].toString())
            {
                if(20 == str_doc["clickType"].toInt())
                {
                    //回到首页
                    emit msg_liveClose();
                }
            }

            QJsonObject elem = elem_value.toObject();
            uint32_t elem_type = elem["elem_type"].toInt();
            switch (elem_type) {
            case TIMElemType::kTIMElem_Text:  // 文本
            {
                // 处理文本消息
                if("groupMsg" == str_doc["tximMsgType"].toString())
                {
                    QString content = elem[kTIMTextElemContent].toString();
                    qDebug()<<tr("文本消息---") + content;
                    QJsonObject message_ob = str_doc["message"].toObject();
                    int type = message_ob["type"].toInt();
                    qDebug()<<"text body = "<<type;
                    switch (type) {
                    case 0:
                    {
                        QVariantMap user = str_doc["ext"].toObject()["user"].toVariant().toMap();
                        emit msg_txt(user, content, 12);
                        break;
                    }
                    case 1:
                    {
                        QVariantMap user = str_doc["user"].toVariant().toMap();
                        emit msg_txt(user, content, type);
                        break;
                    }

                    case 12://12 操作类型消息（例如：主持将xxx抱上麦。显示样式与普通消息一样，只是文本颜色不一样），
                    {
                        QVariantMap user = str_doc["user"].toVariant().toMap();
                        emit msg_txt(user, content, type);
                        break;
                    }

                    case 13://*13 通知类型消息（例如：xxx来了。无需显示发送者头像，需要显示用户等级）
                    {
                        QVariantMap user = str_doc["user"].toVariant().toMap();
                        emit msg_notice(user, content);
                        break;
                    }


                    }
                }
                //处理c2c消息
                if(kTIMConv_C2C == msg_obj["message_conv_type"].toInt())
                {
                    QString content = elem[kTIMTextElemContent].toString();
                    QVariantMap userJosn = msg_obj["message_sender_profile"].toVariant().toMap();
                    emit c2c_msg_text(userJosn, content);
                }
                break;
            }
            case TIMElemType::kTIMElem_Image:  // 图片
            {
                if("groupMsg" == str_doc["tximMsgType"].toString())
                {
                    QJsonObject message_ob = str_doc["message"].toObject();
                    int type = message_ob["type"].toInt();
                    switch (type) {
                    case 2:
                    {
                        QVariantMap user = str_doc["user"].toVariant().toMap();
                        QString path = elem["image_elem_thumb_url"].toString();
                        QString largePath = elem["image_elem_large_url"].toString();
                        emit msg_image(user, path, largePath);
                    }
                    }
                }

                //处理c2c消息
                if(kTIMConv_C2C == msg_obj["message_conv_type"].toInt())
                {
                    QString path = elem["image_elem_thumb_url"].toString();
                    QString largePath = elem["image_elem_large_url"].toString();

                    QVariantMap userJosn = msg_obj["message_sender_profile"].toVariant().toMap();
                    emit c2c_msg_image(userJosn, path, largePath);
                }
                break;
            }

            case TIMElemType::kTIMElem_Custom:
            {                
                if("groupMsg" == str_doc["tximMsgType"].toString())
                {                    
                    QJsonObject message_ob = str_doc["message"].toObject();
                    int type = message_ob["type"].toInt();
                    qDebug()<<"body = "<<message_ob["body"]<<" type=="<<type;
                    QVariantMap user = str_doc["user"].toVariant().toMap();

                    switch (type) {
                    case 8://爆灯
                    {
                        QString imagePath = "images/emotion/vc_emoji_2.png";
                        emit msg_emotion(user, imagePath, 3);
                        break;
                    }
                    case 9://9 emjio表情单图
                    {
                        int number = message_ob["body"].toString().right(3).toInt();

                        if(number <= 20)
                            number ++;
                        else if(number >= 31 && number < 36)
                            number -= 4;
                        else if(number == 43)
                            number = 32;
                        else if(number == 45)
                            number = 33;
                        else if(number >= 38 && number < 40)
                            number -= 4 ;

                        QString imagePath = "images/emotion/vc_emoji_" + QString::number(number) + ".png";
                        emit msg_emotion(user, imagePath, 5);
                        break;
                    }
                    case 10://10 骰子
                    {
                        int num = message_ob["body"].toString().toInt();
                        QString imagePath = "images/emotion/icon_dice_" +QString::number(num) + ".png";
                        emit msg_emotion(user, imagePath, 1);
                        break;
                    }
                    case 11://11 划拳
                    {
                        int num = message_ob["body"].toString().toInt();
                        QString imagePath = "images/emotion/icon_finger_" +QString::number(num) + ".png";
                        emit msg_emotion(user, imagePath, 2);
                        break;
                    }
                    case 18://麦味机
                    {
                        int num = message_ob["body"].toString().toInt();
                        QString imagePath = "images/emotion/icon_mic_" +QString::number(num) + ".png";
                        emit msg_emotion(user, imagePath, 4);
                        break;
                    }
                    case 15://*15. 用户等级提升提示 （例如：恭喜 xxx 等级提升到多少级）
                    {
                        break;
                    }
                    case 16://*16：pk通知
                    {
                        break;
                    }
                    case 17://*17：vip表情
                    {
                        QString vipurl = message_ob["vipurl"].toString();
                        qDebug()<<"vip---"<<vipurl;
                        emit msg_vip(user, vipurl);
                        break;
                    }
                    default:
                    {
                        if(type > 0)
                        {
                            qDebug() << "kTIMElem_Custom message element type:" << type;
                            emit msg_uninit();
                        }
                        break;
                    }
                    }
                }
                break;
            }
            case TIMElemType::kTIMElem_GroupTips:  // 群组系统消息
            {                
                break;
            }
            //礼物相关
            /*
            action 定义
            100001->礼物  100002->飘屏  100004->排麦 取消排麦
            100005->惩罚转盘  100006->麦位变化  100007->违规  100008->修改直播间  100009->用户信息修改
            100010->用户装扮修改  100011->直播间用户权限变更  100012->热度
            100013 ->排行榜变更 100014->刷新直播Banner  100015->现场模式  100016->活动
            100020 ->PK 发起方申请 发起方主持弹出邀请倒计时
            1000020->PK 发起方申请 接收方收到弹出 显示同意或者拒绝
            100026 ->PK 发起方取消邀请 发起方主持弹窗消失 提示
            1000026->PK 发起方 取消邀请 接收方主持收到 弹窗消失 提示
            100027 ->PK 接收方拒绝 接收方主持 弹窗消失 提示
            1000027->PK 接收方拒绝 发起方主持弹窗消失 提示
            100021 ->PK 接收方同意PK 接收方收到 展示倒计时 页面变化
            1000021->PK 接收方同意PK  发起方收到 展示倒计时 页面变化
            这是im 收到消息后 解析根据 action 这个字段 做相应处理
            */
            case TIMElemType::kTIMElem_GroupReport:
            {

                QString giftMsg = elem["group_report_elem_user_data"].toString();
                QJsonObject object = QJsonDocument::fromJson(giftMsg.toUtf8()).object();
                int action = object["action"].toString().toInt();               
                switch (action) {
                case 100001:
                {
                    QVariantMap fromUser =  object["data"].toObject()["fromUser"].toVariant().toMap();
                    QVariantList toUsers =  object["data"].toObject()["toUsers"].toVariant().toList();
                    QVariantMap gift =  object["data"].toObject()["gift"].toVariant().toMap();

                    for(QVariant var : toUsers)
                    {
                        emit msg_gift(fromUser, gift, var.toMap());
                    }
                    break;
                }
                case 100004:
                {
                    emit msg_updateMicList();
                    break;
                }
                case 100006:
                {
                    QVariantList list =  object["data"].toObject()["micInfoList"].toVariant().toList();
                    emit msg_micInfo(list);
                    emit msg_updateMicList();
                    break;
                }
                case 100008:
                {
                    qDebug()<<"100008 object==="<<object;
                    break;
                }
                case 100009:
                {
                    qDebug()<<"100009 object==="<<object;
                    break;
                }
                case 100010:
                {
                    qDebug()<<"100010 object==="<<object;
                    break;
                }
                case 100011:
                {
                    emit msg_multipleAuthoriation(object.toVariantMap());
                    qDebug()<<"100011 object==="<<object;
                    break;
                }
                case 100012://100012->热度
                {
                    qDebug()<<"100012 object==="<<object;
                    break;
                }
                case 100013://100013 ->排行榜变更
                {
                    qDebug()<<"100013 object==="<<object;
                    emit updateContribute();
                    break;
                }
                default:
                {
                    if(action > 100000)
                    {
                        qDebug() << "kTIMElem_GroupReport message element type:" << action;
                        emit msg_uninit();
                    }
                    break;
                }
                }
                break;
            }
            default:
            {
                qDebug() << "Unknown message element type:" << elem_type;
                break;
            }
            }
        }
    }
}
