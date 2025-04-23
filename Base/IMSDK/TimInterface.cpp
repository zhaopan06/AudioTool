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
        { // 失败
            qDebug()<<"sendMessage_group error-----------";
            return ;
        }
        else
        {
            // 成功
            qDebug()<<"sendMessage_group suess-----------";
        }
    };

    return TIMMsgSendNewMsg(conv_id, kTIMConv_Group, json_msg_param, callback, user_data);
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
    {
        qDebug() << "JSON parse failure:" << error.errorString();
        return;
    }

    if (!json_doc.isArray())
    {
        qDebug() << "Expected JSON array but got something else";
        return;
    }

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

            QJsonObject elem = elem_value.toObject();
            uint32_t elem_type = elem["elem_type"].toInt();

            QString content = elem[kTIMTextElemContent].toString();//内容

            switch (elem_type) {
            case TIMElemType::kTIMElem_Text:  // 文本
            {
                // 处理文本消息
                qDebug()<<tr("文本消息---") + content;
                break;
            }

            case TIMElemType::kTIMElem_Sound:  // 声音
                qDebug()<<tr("声音---") + content;
                // 处理声音消息
                break;

            case TIMElemType::kTIMElem_File:  // 文件
                qDebug()<<tr("文件---") + content;
                // 处理文件消息
                break;

            case TIMElemType::kTIMElem_Image:  // 图片
                qDebug()<<tr("图片---") + content;
                // 处理图片消息
                break;

            case TIMElemType::kTIMElem_Custom:
            {
                QString str_content = msg_obj["message_cloud_custom_str"].toString();
                QJsonObject str_doc = QJsonDocument::fromJson(str_content.toLatin1()).object();
                if("groupMsg" == str_doc["tximMsgType"].toString())
                {
                    //TODO 这里处理自定义信息
                    qDebug()<<tr("groupMsg---");
                }
                break;
            }
            case TIMElemType::kTIMElem_GroupTips:  // 群组系统消息
            {
                qDebug()<<tr("群组系统消息1---") + content;
                break;
            }
            case TIMElemType::kTIMElem_Face:  // 表情
                qDebug()<<tr("表情---") + content;
                // 处理表情消息
                break;

            case TIMElemType::kTIMElem_Location:  // 位置
                qDebug()<<tr("位置---") + content;
                // 处理位置消息
                break;

            case TIMElemType::kTIMElem_GroupReport:  // 群组系统通知
                qDebug()<<tr("群组系统通知2---")+content;
                // 处理群组通知
                break;

            case TIMElemType::kTIMElem_Video:  // 视频
                qDebug()<<tr("视频---") + content;
                // 处理视频消息
                break;

            default:
                qDebug() << "Unknown message element type:" << elem_type;
                break;
            }
        }
    }
}


