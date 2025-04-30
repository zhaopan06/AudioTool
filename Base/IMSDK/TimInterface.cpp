#include "TimInterface.h"
#include "qcoreapplication.h"
#include "qdebug.h"
#include "HttpUserInfo.h"
#include <QJsonObject>
#include <QJsonDocument>

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


    QString ImUserID = "user" + HttpUserInfo::instance()->getUserID();
    QString IMtoken = HttpUserInfo::instance()->getImToken();
    login(ImUserID.toLatin1(), IMtoken.toLatin1());
    initRecvNewMsgCallback();
    return code;
}

QString TimInterface::getSDKVersion()
{
    return TIMGetSDKVersion();
}

int TimInterface::login(const char *user_id, const char *IMtoken)
{
    TIMCommCallback callback = [](int32_t code, const char* desc, const char* json_param, const void* user_data) {
        TimInterface* ths = (TimInterface*)user_data;

        emit ths->loginStatus(code, desc);
    };
    return TIMLogin(user_id, IMtoken, callback, this);
}

int  TimInterface::logout(TIMCommCallback cb, const void *user_data)
{
    return TIMLogout(cb, user_data);
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
            qDebug()<<"group suess-----------";
        }
    };

    return TIMMsgSendNewMsg(conv_id, kTIMConv_Group, json_msg_param, callback, user_data);
}

void TimInterface::setSendJson(IMType type, QString text)
{
    QVariantMap json_value_text;
    if(type == IMType_Text)
        json_value_text[kTIMElemType] = kTIMElem_Text;
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
    json_value_msg[kTIMMsgConvId] = HttpUserInfo::instance()->getRoomID();
    json_value_msg[kTIMMsgConvType] = kTIMConv_Group;
    json_value_msg["message_cloud_custom_str"] = setCustomJson(type,text);

    // 转换为 JSON 字符串
    QJsonDocument doc(QJsonObject::fromVariantMap(json_value_msg));    
    sendMessage_group(HttpUserInfo::instance()->getRoomID().toLatin1(), doc.toJson(), this);
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
    qDebug()<<"send user---"<<user_doc;

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
            qDebug()<<"sendMessage_c2c error-----------";
            return ;
        }
        else
        {
            // 成功
            qDebug()<<"sendMessage_c2c suess-----------";
        }
    };
    return TIMMsgSendNewMsg(conv_id, kTIMConv_C2C, json_msg_param, callback, user_data);
}

void TimInterface::initRecvNewMsgCallback()
{
    TIMAddRecvNewMsgCallback([](const char* json_msg_array, const void* user_data) {
        TimInterface* ths = (TimInterface*)user_data;
        ths->newMessages(json_msg_array);
    }, this);
}

void TimInterface::newMessages(QString msg)
{
    getMSGTojson(msg.toLatin1());
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
            QJsonObject str_doc = QJsonDocument::fromJson(str_content.toLatin1()).object();
            qDebug()<<"jieshou str_doc---"<<str_doc;

            //收集发送者的信息
            QJsonObject user_doc = str_doc["user"].toObject();
            m_user_info.insert("name", user_doc["name"].toString());
            m_user_info.insert("photo", user_doc["photo"].toString());
            m_user_info.insert("userId", user_doc["userId"].toString());


            QJsonObject elem = elem_value.toObject();
            uint32_t elem_type = elem["elem_type"].toInt();
            switch (elem_type) {
            case TIMElemType::kTIMElem_Text:  // 文本
            {
                // 处理文本消息
                QString content = elem[kTIMTextElemContent].toString();//内容

                qDebug()<<tr("文本消息---") + content.toUtf8();

                if("groupMsg" == str_doc["tximMsgType"].toString())
                {
                    QJsonObject message_ob = str_doc["message"].toObject();
                    int type = message_ob["type"].toInt();
                    qDebug()<<"type---"<<type;

                }
                break;
            }           

            case TIMElemType::kTIMElem_Custom:
            {                
                if("groupMsg" == str_doc["tximMsgType"].toString())
                {
                    //TODO 这里处理自定义信息
                    QJsonObject message_ob = str_doc["message"].toObject();
                    int type = message_ob["type"].toInt();
                    qDebug()<<"type---"<<type;
                    qDebug()<<"body = "<<message_ob["body"];

                    switch (type) {
                    case 8://爆灯
                    {
                        QString imagePath = ":/images/emotion/vc_emoji_2.png";
                        emit msg_emotion(imagePath);
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

                        QString imagePath = ":/images/emotion/vc_emoji_" + QString::number(number) + ".png";
                        emit msg_emotion(imagePath);                        
                        break;
                    }
                    case 10://10 骰子
                    {
                        int num = message_ob["body"].toString().toInt();
                        QString imagePath = ":/images/emotion/icon_dice_" +QString::number(num) + ".png";
                        emit msg_dice(imagePath);
                        break;
                    }
                    case 11://11 划拳
                    {
                        int num = message_ob["body"].toString().toInt();
                        QString imagePath = ":/images/emotion/icon_finger_" +QString::number(num) + ".png";
                        emit msg_finger(imagePath);
                        break;
                    }
                    case 12://12 操作类型消息（例如：主持将xxx抱上麦。显示样式与普通消息一样，只是文本颜色不一样），
                    {
                        break;
                    }
                    case 13://*13 通知类型消息（例如：xxx来了。无需显示发送者头像，需要显示用户等级）
                    {
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
                        break;
                    }
                    case 18://麦味机
                    {
                        int num = message_ob["body"].toString().toInt();
                        QString imagePath = ":/images/emotion/icon_mic_" +QString::number(num) + ".png";
                        emit msg_dice(imagePath);
                        break;
                    }
                    default:
                        break;
                    }
                }
                break;
            }
            case TIMElemType::kTIMElem_GroupTips:  // 群组系统消息
            {                
                break;
            }          

            default:
                qDebug() << "Unknown message element type:" << elem_type;
                break;
            }
        }
    }
}


