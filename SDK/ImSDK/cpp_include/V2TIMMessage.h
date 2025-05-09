// Copyright (c) 2021 Tencent. All rights reserved.

#ifndef __V2TIM_MESSAGE_H__
#define __V2TIM_MESSAGE_H__

#include "V2TIMCommon.h"
#include "V2TIMFriendship.h"
#include "V2TIMGroup.h"

/////////////////////////////////////////////////////////////////////////////////
//
//                    （一）枚举值定义
//
/////////////////////////////////////////////////////////////////////////////////

/// 消息优先级
enum V2TIMMessagePriority {
    /// 默认
    V2TIM_PRIORITY_DEFAULT = 0,
    /// 高优先级，一般用于礼物等重要消息
    V2TIM_PRIORITY_HIGH = 1,
    /// 常规优先级，一般用于普通消息
    V2TIM_PRIORITY_NORMAL = 2,
    /// 低优先级，一般用于点赞消息
    V2TIM_PRIORITY_LOW = 3,
};

/// 消息状态
enum V2TIMMessageStatus {
    /// 消息发送中
    V2TIM_MSG_STATUS_SENDING = 1,
    /// 消息发送成功
    V2TIM_MSG_STATUS_SEND_SUCC = 2,
    /// 消息发送失败
    V2TIM_MSG_STATUS_SEND_FAIL = 3,
    /// 消息被删除
    V2TIM_MSG_STATUS_HAS_DELETED = 4,
    /// 导入到本地的消息
    V2TIM_MSG_STATUS_LOCAL_IMPORTED = 5,
    /// 被撤销的消息
    V2TIM_MSG_STATUS_LOCAL_REVOKED = 6,
};

/// 消息类型
enum V2TIMElemType {
    /// 未知消息
    V2TIM_ELEM_TYPE_NONE = 0,
    /// 文本消息
    V2TIM_ELEM_TYPE_TEXT = 1,
    /// 自定义消息
    V2TIM_ELEM_TYPE_CUSTOM = 2,
    /// 图片消息
    V2TIM_ELEM_TYPE_IMAGE = 3,
    /// 语音消息
    V2TIM_ELEM_TYPE_SOUND = 4,
    /// 视频消息
    V2TIM_ELEM_TYPE_VIDEO = 5,
    /// 文件消息
    V2TIM_ELEM_TYPE_FILE = 6,
    /// 地理位置消息
    V2TIM_ELEM_TYPE_LOCATION = 7,
    /// 表情消息
    V2TIM_ELEM_TYPE_FACE = 8,
    /// 群 Tips 消息
    V2TIM_ELEM_TYPE_GROUP_TIPS = 9,
    /// 合并消息
    V2TIM_ELEM_TYPE_MERGER = 10,
};

DEFINE_VECTOR(V2TIMElemType)
typedef TXV2TIMElemTypeVector V2TIMElemTypeVector;

/// 推送规则
enum V2TIMOfflinePushFlag {
    /// 按照默认规则进行推送
    V2TIM_OFFLINE_PUSH_DEFAULT = 0,
    /// 不进行推送
    V2TIM_OFFLINE_PUSH_NO_PUSH = 1,
};

/// 图片类型
enum V2TIMImageType {
    /// 原图
    V2TIM_IMAGE_TYPE_ORIGIN = 0x01,
    /// 缩略图
    V2TIM_IMAGE_TYPE_THUMB = 0x02,
    /// 大图
    V2TIM_IMAGE_TYPE_LARGE = 0x04,
};

/// 群 Tips 类型
enum V2TIMGroupTipsType {
    /// 未定义
    V2TIM_GROUP_TIPS_TYPE_NONE = 0x00,
    /// 主动入群（memberList 加入群组，非 Work 群有效）
    V2TIM_GROUP_TIPS_TYPE_JOIN = 0x01,
    /// 被邀请入群（opMember 邀请 memberList 入群，从 8.0 版本开始支持除 AVChatRoom 之外的所有群类型）
    V2TIM_GROUP_TIPS_TYPE_INVITE = 0x02,
    /// 退出群 (opMember 退出群组)
    V2TIM_GROUP_TIPS_TYPE_QUIT = 0x03,
    /// 踢出群 (opMember 把 memberList 踢出群组)
    V2TIM_GROUP_TIPS_TYPE_KICKED = 0x04,
    /// 设置管理员 (opMember 把 memberList 设置为管理员)
    V2TIM_GROUP_TIPS_TYPE_SET_ADMIN = 0x05,
    /// 取消管理员 (opMember 取消 memberList 管理员身份)
    V2TIM_GROUP_TIPS_TYPE_CANCEL_ADMIN = 0x06,
    /// 群资料变更 (opMember 修改群资料： groupName & introduction & notification & faceUrl & owner & allMute & custom)
    V2TIM_GROUP_TIPS_TYPE_GROUP_INFO_CHANGE = 0x07,
    /// 群成员资料变更 (opMember 修改群成员资料：muteTime)
    V2TIM_GROUP_TIPS_TYPE_MEMBER_INFO_CHANGE = 0x08,
    /// 话题资料变更 (opMember 修改话题资料：topicName & introduction & notification & faceUrl & allMute & topicCustomData)
    V2TIM_GROUP_TIPS_TYPE_TOPIC_INFO_CHANGE = 0x09,
    /// 置顶群消息
    V2TIM_GROUP_TIPS_TYPE_PINNED_MESSAGE_ADDED = 0x0A,
    /// 取消置顶群消息
    V2TIM_GROUP_TIPS_TYPE_PINNED_MESSAGE_DELETED = 0x0B,
};

/// 消息拉取方式
enum V2TIMMessageGetType {
    /// 获取云端更老的消息
    V2TIM_GET_CLOUD_OLDER_MSG = 1,
    /// 获取云端更新的消息
    V2TIM_GET_CLOUD_NEWER_MSG = 2,
    /// 获取本地更老的消息
    V2TIM_GET_LOCAL_OLDER_MSG = 3,
    /// 获取本地更新的消息
    V2TIM_GET_LOCAL_NEWER_MSG = 4,
};

/// 群消息已读成员列表过滤类型
enum V2TIMGroupMessageReadMembersFilter {
    /// 群消息已读成员列表
    V2TIM_GROUP_MESSAGE_READ_MEMBERS_FILTER_READ   = 0,
    /// 群消息未读成员列表
    V2TIM_GROUP_MESSAGE_READ_MEMBERS_FILTER_UNREAD = 1,
};

/// iOS 离线推送的类型
enum V2TIMIOSOfflinePushType {
    /// 普通的 APNs 推送
    V2TIM_IOS_OFFLINE_PUSH_TYPE_APNS = 0,
    /// VoIP 推送
    V2TIM_IOS_OFFLINE_PUSH_TYPE_VOIP = 1,
};

/// 配置离线推送时，注册的设备 token 类型
enum V2TIMOfflinePushTokenType {
    /// 默认是厂商 token: APNS/小米 push/Huawei push 等
    V2TIM_OFFLINE_PUSH_TOKEN_TYPE_DEFAULT = 0,
    /// TPNS
    V2TIM_OFFLINE_PUSH_TOKEN_TYPE_TPNS    = 1,
    /// VoIP push，目前仅支持 iOS
    V2TIM_OFFLINE_PUSH_TOKEN_TYPE_VOIP    = 2,
};

/////////////////////////////////////////////////////////////////////////////////
//
//                     （二）结构体定义
//
/////////////////////////////////////////////////////////////////////////////////

struct TIM_API V2TIMOfflinePushConfig {
    /// 注册应用到厂商平台时获取的 token。
    V2TIMBuffer token;
    /// IM 控制台证书 ID
    uint32_t businessID;

    /// token 的类型，默认是 V2TIM_OFFLINE_PUSH_TOKEN_TYPE_DEFAULT
    /// @note V2TIM_OFFLINE_PUSH_TOKEN_TYPE_TPNS 字段已废弃
    /// - 如果您之前通过 TPNS 接入离线推送，并且在 TPNS 控制台配置推送信息，可以继续按照该方式接入推送功能；
    /// - 如果您从未接入 TPNS，从未在 TPNS 控制台配置推送信息，IM 将不在支持 TPNS 方式接入离线推送功能, 推荐参照如下方式接入：
    ///  https://cloud.tencent.com/document/product/269/74284
    V2TIMOfflinePushTokenType token_type;

    V2TIMOfflinePushConfig();
    V2TIMOfflinePushConfig(const V2TIMOfflinePushConfig &);
    ~V2TIMOfflinePushConfig();
};

/// 接收时不会播放声音
#define kIOSOfflinePushNoSound "push.no_sound"
/// 接收时播放系统声音
#define kIOSOfflinePushDefaultSound "default"

/// 自定义消息 push。
struct TIM_API V2TIMOfflinePushInfo {
    /// 离线推送展示的标题。
    V2TIMString title;
    /// 离线推送展示的内容。
    /// 自定义消息进行离线推送，必须设置此字段内容。
    V2TIMString desc;
    /// 离线推送扩展字段，
    /// iOS: 收到离线推送的一方可以在 UIApplicationDelegate -> didReceiveRemoteNotification ->
    /// userInfo 拿到这个字段，用这个字段可以做 UI 跳转逻辑
    V2TIMString ext;
    /// 是否关闭推送（默认开启推送）。
    bool disablePush;
    /// iOS 离线推送的类型（仅对 iOS 生效）
    /// 默认值是 V2TIM_IOS_OFFLINE_PUSH_TYPE_APNS
    V2TIMIOSOfflinePushType iOSPushType;
    /// 离线推送忽略 badge 计数（仅对 iOS 生效），
    /// 如果设置为 true，在 iOS 接收端，这条消息不会使 APP 的应用图标未读计数增加。
    bool ignoreIOSBadge;
    /// 离线推送声音设置（仅对 iOS 生效），
    /// 当 iOSSound = kIOSOfflinePushNoSound，表示接收时不会播放声音。
    /// 当 iOSSound = kIOSOfflinePushDefaultSound，表示接收时播放系统声音。
    /// 如果要自定义 iOSSound，需要先把语音文件链接进 Xcode 工程，然后把语音文件名（带后缀）设置给
    /// iOSSound。
    V2TIMString iOSSound;
    /// iOS 离线推送的通知级别  (iOS 15 及以上支持)
    /// "passive"，不会发出声音、振动或横幅提示，只会静默地出现在通知中心。适用于不紧急的信息，例如应用内的社交活动更新或推荐内容。
    /// "active", 会发出声音或振动，并显示横幅提示。适用于一般的重要通知，例如消息提醒、日历事件等。（默认类型）
    /// "time-sensitive"，会发出声音或振动，并显示横幅提示，这种级别的通知会打扰用户，即使用户启用了“专注模式”（Focus Mode）。适用于需要用户立即关注的紧急通知，例如安全警报、重要的时间提醒等。打开需要在苹果开发者平台和 xcode 项目中增加相应的配置。
    /// "critical", 会发出声音或振动，并显示横幅提示。这种级别的通知会打扰用户，即使设备处于静音模式。适用于极其重要的紧急通知，例如公共安全警报、严重的健康警告等。打开需要向 Apple 特殊申请。
    V2TIMString iOSInterruptionLevel;
    /// 设置 iOS 后台透传消息
    /// 设置打开后，离线接收会唤起应用并透传消息内容 ext
    bool enableIOSBackgroundNotification;
    /// 离线推送声音设置（仅对 Android 生效, 仅 imsdk 6.1 及以上版本支持）
    /// 只有华为和谷歌手机支持设置铃音提示，小米铃音设置请您参照：https://dev.mi.com/console/doc/detail?pId=1278%23_3_0
    /// 另外，谷歌手机 FCM 推送在 Android 8.0 及以上系统设置声音提示，必须调用 setAndroidFCMChannelID 设置好 channelID，才能生效。
    /// AndroidSound: Android 工程里 raw 目录中的铃声文件名，不需要后缀名。
    V2TIMString AndroidSound;
    /// 离线推送设置 OPPO 手机 8.0 系统及以上的渠道 ID（仅对 Android 生效）。
    V2TIMString AndroidOPPOChannelID;
    /// 离线推送设置 FCM 通道手机 8.0 系统及以上的渠道 ID（仅对 Android 生效）。
    V2TIMString AndroidFCMChannelID;
    /// 离线推送设置小米通道手机 8.0 系统及以上的渠道 ID（仅对 Android 生效）。
    V2TIMString AndroidXiaoMiChannelID;
    /// 离线推送设置 VIVO 推送消息分类 (待废弃接口，VIVO 推送服务于 2023 年 4 月 3 日优化消息分类规则，推荐使用 AndroidVIVOCategory 设置消息类别)
    /// VIVO 手机离线推送消息分类，0：运营消息，1：系统消息。默认取值为 1 。
    int AndroidVIVOClassification;
    /// 离线推送设置 VIVO 推送消息类别，详见：https://dev.vivo.com.cn/documentCenter/doc/359。(VIVO 推送服务于 2023 年 4 月 3 日优化消息分类规则，推荐使用 AndroidVIVOCategory 设置消息类别，不需要再关注和设置 AndroidVIVOClassification)
    V2TIMString AndroidVIVOCategory;
    /// 离线推送设置华为推送消息分类，详见：https://developer.huawei.com/consumer/cn/doc/development/HMSCore-Guides/message-classification-0000001149358835
    V2TIMString AndroidHuaWeiCategory;
    /// 离线推送设置 OPPO 推送消息分类，详见：https://open.oppomobile.com/new/developmentDoc/info?id=13189
    /// 通讯与服务类型有："IM"，"ACCOUNT"等；内容与营销类型有："NEWS"，"CONTENT"等
    V2TIMString AndroidOPPOCategory;
    /// 离线推送设置 OPPO 推送通知栏消息提醒等级，详见：https://open.oppomobile.com/new/developmentDoc/info?id=13189
    /// 使用生效前，需要先设置 AndroidOPPOCategory  指定 category 为 IM 类消息。消息提醒等级有：1，通知栏；2，通知栏 + 锁屏 （默认）；16，通知栏 + 锁屏 + 横幅 + 震动 + 铃声；
    int AndroidOPPONotifyLevel;
    /// 离线推送设置 Honor 推送消息分类，详见：https://developer.honor.com/cn/docs/11002/guides/notification-class
    /// Honor 推送消息分类: "NORMAL", 表示消息为服务通讯类; "LOW", 表示消息为资讯营销类
    V2TIMString AndroidHonorImportance;
    /// 设置华为设备离线推送的通知图片, url 使用的协议必须是 HTTPS 协议，取值样例：https://example.com/image.png
    /// 图片文件须小于 512KB，规格建议为 40dp x 40dp，弧角大小为 8dp。超出建议规格的图片会存在图片压缩或图片显示不全的情况。图片格式建议使用 JPG/JPEG/PNG。
    V2TIMString AndroidHuaWeiImage;
    /// 设置荣耀设备离线推送的通知图片, url 使用的协议必须是 HTTPS 协议，取值样例：https://example.com/image.png
    /// 图标文件大小须小于 100KB，图标建议规格大小：160px x 160px，弧角大小为 32px，超出规格大小的图标会存在图片压缩或显示不全的情况。
    V2TIMString AndroidHonorImage;
    /// 设置 Google FCM 设备离线推送的通知图片，未展开消息时显示为大图标，展开消息后展示为大图片. url 使用的协议必须是 HTTPS 协议，取值样例：https://example.com/image.png
    /// 图标文件大小须小于 1 MB，超出规格大小的图标会存在图片压缩或显示不全的情况。
    V2TIMString AndroidFCMImage;
    /// 设置 APNs 离线推送的通知图片, 借助 iOS 10 Service Extension 特性，可以下载并展示在弹窗上.iOSImage 使用的协议必须是 HTTPS 协议，取值样例：https://example.com/image.png
    /// 限制说明：
    /// - 图片：支持 JPEG、GIF、PNG，大小不超过 10 MB
    /// 使用说明：
    /// - 需要在 IM 控制台打开 mutable-content 属性，支持 iOS 10 Service Extension 特性
    /// - 获取 iOSImage 资源的 key 值是 "image"
    V2TIMString iOSImage;
    /// 设置鸿蒙设备离线推送的通知图片，URL使用的协议必须是HTTPS协议，取值样例：https://example.com/image.png。
    /// 支持图片格式为png、jpg、jpeg、heif、gif、bmp，图片长*宽 < 25000像素。
    V2TIMString HarmonyImage;
    /// 设置鸿蒙设备离线推送通知消息类别，详见：https://developer.huawei.com/consumer/cn/doc/HMSCore-Guides/message-classification-0000001149358835
    V2TIMString HarmonyCategory;
    /// 离线推送忽略 badge 计数（仅对 Harmony 生效），
    /// 如果设置为 YES，在 Harmony 接收端，这条消息不会使 APP 的应用图标未读计数增加。
    bool ignoreHarmonyBadge;

    V2TIMOfflinePushInfo();
    V2TIMOfflinePushInfo(const V2TIMOfflinePushInfo &);
    ~V2TIMOfflinePushInfo();
};

struct V2TIMElem;
struct V2TIMTextElem;
struct V2TIMCustomElem;
struct V2TIMImageElem;
struct V2TIMVideoElem;
struct V2TIMSoundElem;
struct V2TIMFileElem;
struct V2TIMFaceElem;
struct V2TIMLocationElem;
struct V2TIMMergerElem;
struct V2TIMGroupTipsElem;

DEFINE_POINT_VECTOR(V2TIMElem)
typedef TXPV2TIMElemVector V2TIMElemVector;

class V2TIMCallback;

class V2TIMDownloadCallback;

template <class T>
class V2TIMValueCallback;

#define kImSDK_MesssageAtALL "__kImSDK_MesssageAtALL__"

/// 高级消息
struct TIM_API V2TIMMessage : V2TIMBaseObject {
    /// 消息 ID（消息创建的时候为空，消息发送的时候会生成）
    V2TIMString msgID;
    /// 消息的 UTC 时间戳
    int64_t timestamp;
    /// 消息发送者
    V2TIMString sender;
    /// 消息发送者昵称
    V2TIMString nickName;
    /// 消息发送者好友备注
    V2TIMString friendRemark;
    /// 如果是群组消息，nameCard 为发送者的群名片
    V2TIMString nameCard;
    /// 消息发送者头像
    /// 在 C2C 场景下，陌生人的头像不会实时更新，如需更新陌生人的头像（如在 UI
    /// 上点击陌生人头像以展示陌生人信息时）， 请调用 V2TIMManager.h -> GetUsersInfo
    /// 接口触发信息的拉取。待拉取成功后，SDK 会更新本地头像信息，即 faceURL 字段的内容。
    /// @note 请不要在收到每条消息后都去 GetUsersInfo，会严重影响程序性能。
    V2TIMString faceURL;
    /// 如果是群组消息，groupID 为会话群组 ID，否则为空
    V2TIMString groupID;
    /// 如果是单聊消息，userID 为会话用户 ID，否则为空，
    /// 假设自己和 userA 聊天，无论是自己发给 userA 的消息还是 userA 发给自己的消息，这里的 userID
    /// 均为 userA
    V2TIMString userID;
    /// 群聊中的消息序列号云端生成，在群里是严格递增且唯一的,
    /// 单聊中的序列号是本地生成，不能保证严格递增且唯一。
    uint64_t seq;
    /// 消息随机码
    uint64_t random;
    /// 消息发送状态
    V2TIMMessageStatus status;
    /// 是否支持消息扩展（6.7 及其以上版本支持，需要您购买旗舰版套餐）
    /// 直播群（AVChatRoom）消息不支持该功能。
    /// 您需要先到 IM 控制台配置该功能。
    bool supportMessageExtension;
    /// 消息发送者是否是自己
    bool isSelf;
    /// 消息自己是否已读
    bool IsRead() const;
    /// 消息对方是否已读（只有 C2C 消息有效）
    /// 该字段为 true 的条件是消息 timestamp <= 对端标记会话已读的时间
    bool IsPeerRead() const;
    /// 消息是否需要已读回执
    /// @note
    /// <p> 群聊消息 6.1 及以上版本支持该特性，需要您先到 IM 控制台配置支持已读回执的群类型。
    /// <p> 单聊消息 6.2 及以上版本支持该特性。
    /// <p> 群聊消息和单聊消息都需要购买旗舰版套餐包。
    bool needReadReceipt;
    /// 是否是广播消息，仅直播群支持（6.5 及以上版本支持，需要您购买旗舰版套餐）
    bool isBroadcastMessage;
    /// 消息优先级（只有 onRecvNewMessage 收到的 V2TIMMessage 获取有效）
    V2TIMMessagePriority priority;
    /// 群消息中被 @ 的用户 UserID 列表（即该消息都 @ 了哪些人）
    V2TIMStringVector groupAtUserList;
    /// 消息元素列表
    ///
    /// 推荐一条消息只存放一个 elem，在收到这条消息时，调用 elemList[0] 获取这个elem，示例代码如下：
    /// if (1 == message.elemList.Size()) {
    ///     V2TIMElem *elem = message.elemList[0];
    ///     switch (elem->elemType) {
    ///         case V2TIM_ELEM_TYPE_TEXT:
    ///             V2TIMTextElem *textElem = static_cast<V2TIMTextElem *>(elem);
    ///             break;
    ///         case V2TIM_ELEM_TYPE_CUSTOM:
    ///             V2TIMCustomElem *customElem = static_cast<V2TIMCustomElem *>(elem);
    ///             break;
    ///         case V2TIM_ELEM_TYPE_FACE:
    ///             V2TIMFaceElem *faceElem = static_cast<V2TIMFaceElem *>(elem);
    ///             break;
    ///         case V2TIM_ELEM_TYPE_LOCATION:
    ///             V2TIMLocationElem *locationElem = static_cast<V2TIMLocationElem *>(elem);
    ///             break;
    ///         default:
    ///             break;
    ///     }
    /// }
    ///
    /// 如果一条消息有多个 elem，遍历 elemList 列表，获取全部 elem 元素，示例代码如下：
    /// for (size_t i = 0; i < message.elemList.Size(); ++i) {
    ///     V2TIMElem *elem = message.elemList[i];
    ///     switch (elem->elemType) {
    ///         case V2TIM_ELEM_TYPE_TEXT:
    ///             V2TIMTextElem *textElem = static_cast<V2TIMTextElem *>(elem);
    ///             break;
    ///         case V2TIM_ELEM_TYPE_CUSTOM:
    ///             V2TIMCustomElem *customElem = static_cast<V2TIMCustomElem *>(elem);
    ///             break;
    ///         case V2TIM_ELEM_TYPE_FACE:
    ///             V2TIMFaceElem *faceElem = static_cast<V2TIMFaceElem *>(elem);
    ///             break;
    ///         case V2TIM_ELEM_TYPE_LOCATION:
    ///             V2TIMLocationElem *locationElem = static_cast<V2TIMLocationElem *>(elem);
    ///             break;
    ///         default:
    ///             break;
    ///     }
    /// }
    ///
    /// 如果您的一条消息需要多个 elem，可以在创建 Message 对象后，调用 elemList.PushBack 添加新
    /// elem， 以 V2TIMTextElem 和 V2TIMCustomElem 多 elem 为例，示例代码如下： 
    /// V2TIMCustomElem *customElem = new V2TIMCustomElem(); 
    /// customElem->data = buffer; 
    /// V2TIMMessage message = messageManager.CreateTextMessage("text");
    /// message.elemList.PushBack(customElem);
    V2TIMElemVector elemList;
    /// 获取消息自定义数据（本地保存，不会发送到对端，程序卸载重装后失效）
    V2TIMBuffer GetLocalCustomData() const;
    /// 设置消息自定义数据（本地保存，不会发送到对端，程序卸载重装后失效）
    void SetLocalCustomData(const V2TIMBuffer &localCustomData, V2TIMCallback *callback);
    /// 获取消息自定义数据,可以用来标记语音、视频消息是否已经播放（本地保存，不会发送到对端，程序卸载重装后失效）
    int GetLocalCustomInt() const;
    /// 设置消息自定义数据,可以用来标记语音、视频消息是否已经播放（本地保存，不会发送到对端，程序卸载重装后失效）
    void SetLocalCustomInt(int localCustomInt, V2TIMCallback *callback);
    /// 消息自定义数据（云端保存，会发送到对端，程序卸载重装后还能拉取到）
    V2TIMBuffer cloudCustomData;
    /// 消息是否不计入会话未读数：默认为 false，表明需要计入会话未读数，设置为
    /// true，表明不需要计入会话未读数
    /// <p> 5.3.425 及以上版本支持, 会议群（Meeting）默认不支持该字段
    bool isExcludedFromUnreadCount;
    /// 消息是否不计入会话 lastMsg：默认为 false，表明需要计入会话 lastMsg，设置为
    /// true，表明不需要计入会话 lastMsg
    bool isExcludedFromLastMessage;
    /// 消息是否不过内容审核（【云端审核】）
    /// 只有在开通【云端审核】功能后，isExcludedFromContentModeration 设置才有效，设置为 true，表明不过内容审核，设置为 false：表明过内容审核。
    ///【云端审核】开通流程请参考 [云端审核功能](https://cloud.tencent.com/document/product/269/83795#.E4.BA.91.E7.AB.AF.E5.AE.A1.E6.A0.B8.E5.8A.9F.E8.83.BD)
    bool isExcludedFromContentModeration;
    /// 消息自定义审核配置 ID（从 7.8 版本开始支持）
    /// 在开通【云端审核】功能后，您可以请前往 [控制台](https://console.cloud.tencent.com/im) (云端审核 -> 审核配置 -> 自定义配置 -> 添加自定义配置) 获取配置 ID。
    ///【自定义审核】配置流程请参考 [云端审核功能]（https://cloud.tencent.com/document/product/269/78633#a5efc9e8-a7ec-40e3-9b18-8ed1910f589c）
    /// @note 该字段需要发消息前设置，仅用于控制发消息时的消息审核策略，其值不会存储在漫游和本地
    V2TIMString customModerationConfigurationID;
    /// 是否被标记为有安全风险的消息（从 7.4 版本开始支持）
    /// 暂时只支持语音和视频消息。
    /// 只有在开通【云端审核】功能后才生效，【云端审核】开通流程请参考 [云端审核功能](https://cloud.tencent.com/document/product/269/83795#.E4.BA.91.E7.AB.AF.E5.AE.A1.E6.A0.B8.E5.8A.9F.E8.83.BD)。
    /// 如果您发送的语音或视频消息内容不合规，云端异步审核后会触发 SDK 的 onRecvMessageModified 回调，回调里的 message 对象该字段值为 true。
    bool hasRiskContent;
    /// 是否禁用消息发送前云端回调（从 8.1 版本开始支持）
    bool disableCloudMessagePreHook;
    /// 是否禁用消息发送后云端回调（从 8.1 版本开始支持）
    bool disableCloudMessagePostHook;

    /// 消息的离线推送信息
    V2TIMOfflinePushInfo offlinePushInfo;
    /// 消息撤回者（从 7.4 版本开始支持）
    /// 仅当消息为撤回状态时有效
    V2TIMUserFullInfo revokerInfo;
    /// 消息撤回原因 （从 7.4 版本开始支持）
    /// 仅当消息为撤回状态时有效
    V2TIMString revokeReason;

    /// 消息置顶者 （从 8.0 版本开始支持）
    /// 只有通过 GetPinnedGroupMessageList 获取到的置顶消息才包含该字段
    V2TIMGroupMemberInfo pinnerInfo;

    V2TIMMessage();
    V2TIMMessage(const V2TIMMessage &);
    V2TIMMessage &operator =(const V2TIMMessage &);
    ~V2TIMMessage() override;
};

DEFINE_VECTOR(V2TIMMessage)
typedef TXV2TIMMessageVector V2TIMMessageVector;

/////////////////////////////////////////////////////////////////////////////////
//
//                         消息元素基类
//
/////////////////////////////////////////////////////////////////////////////////

/// 消息元素基类
struct TIM_API V2TIMElem : V2TIMBaseObject {
    /// 元素类型
    V2TIMElemType elemType;

    V2TIMElem();
    V2TIMElem(const V2TIMElem &);
    ~V2TIMElem() override;
};

/////////////////////////////////////////////////////////////////////////////////
//
//                         文本消息 Elem
//
/////////////////////////////////////////////////////////////////////////////////

/// 文本消息 Elem
struct TIM_API V2TIMTextElem : public V2TIMElem {
    /// 消息文本
    V2TIMString text;

    V2TIMTextElem();
    V2TIMTextElem(const V2TIMTextElem &);
    V2TIMTextElem &operator=(const V2TIMTextElem &);
    ~V2TIMTextElem() override;
};

/////////////////////////////////////////////////////////////////////////////////
//
//                         自定义消息 Elem
//
/////////////////////////////////////////////////////////////////////////////////

/// 自定义消息 Elem
struct TIM_API V2TIMCustomElem : public V2TIMElem {
    /// 自定义消息二进制数据
    V2TIMBuffer data;
    /// 自定义消息描述信息
    V2TIMString desc;
    /// 自定义消息扩展字段
    V2TIMString extension;

    V2TIMCustomElem();
    V2TIMCustomElem(const V2TIMCustomElem &);
    V2TIMCustomElem &operator=(const V2TIMCustomElem &);
    ~V2TIMCustomElem() override;
};

/////////////////////////////////////////////////////////////////////////////////
//
//                         图片消息 Elem
//
/////////////////////////////////////////////////////////////////////////////////

/// 图片元素
struct TIM_API V2TIMImage {
    /// 图片 ID，内部标识，可用于外部缓存 key
    V2TIMString uuid;
    /// 图片类型
    V2TIMImageType type;
    /// 图片大小（type == V2TIM_IMAGE_TYPE_ORIGIN 有效）
    uint64_t size;
    /// 图片宽度
    uint32_t width;
    /// 图片高度
    uint32_t height;
    /// 图片 url
    V2TIMString url;

    /**
     *  下载图片
     *
     *  下载的数据需要由开发者缓存，IM SDK 每次调用 DownloadImage
     * 都会从服务端重新下载数据。建议通过图片的 uuid 作为 key 进行图片文件的存储。
     *
     *  @param path 图片保存路径，需要外部指定
     */
    void DownloadImage(const V2TIMString &path, V2TIMDownloadCallback *callback);

    V2TIMImage();
    V2TIMImage(const V2TIMImage &);
    ~V2TIMImage();
};

DEFINE_VECTOR(V2TIMImage)
typedef TXV2TIMImageVector V2TIMImageVector;

/// 图片消息Elem
struct TIM_API V2TIMImageElem : public V2TIMElem {
    /// 图片路径（只有发送方可以获取到）
    V2TIMString path;
    /// 接收图片消息的时候这个字段会保存图片的所有规格，目前最多包含三种规格：原图、大图、缩略图，每种规格保存在一个
    /// TIMImage 对象中
    V2TIMImageVector imageList;

    V2TIMImageElem();
    V2TIMImageElem(const V2TIMImageElem &);
    V2TIMImageElem &operator=(const V2TIMImageElem &);
    ~V2TIMImageElem() override;
};

/////////////////////////////////////////////////////////////////////////////////
//
//                         语音消息 Elem
//
/////////////////////////////////////////////////////////////////////////////////

/// 语音消息 Elem
struct TIM_API V2TIMSoundElem : public V2TIMElem {
    /// 语音文件路径（只有发送方才能获取到）
    V2TIMString path;
    /// 语音消息内部 ID
    V2TIMString uuid;
    /// 语音数据大小
    uint64_t dataSize;
    /// 语音长度（秒）
    uint32_t duration;

    /// 获取语音的 URL 下载地址
    void GetUrl(V2TIMValueCallback<V2TIMString> *callback);

    /**
     *  下载语音
     *
     *  DownloadSound 接口每次都会从服务端下载，如需缓存或者存储，开发者可根据 uuid 作为 key
     * 进行外部存储，ImSDK 并不会存储资源文件。
     *
     *  @param path 语音保存路径，需要外部指定
     */
    void DownloadSound(const V2TIMString &path, V2TIMDownloadCallback *callback);
    
    /**
     *  将语音转成文字（7.4 及以上版本支持）
     *
     *  @param language 识别的语言。
     *
     *  @note
     *  - 语音转文字是增值付费功能，处于内测阶段，您可通过 [即时通信 IM 语音转文字插件交流群](https://zhiliao.qq.com/s/c5GY7HIM62CK/cPSYGIIM62CH) 联系我们为您开通体验完整功能。
     */
    void ConvertVoiceToText(const V2TIMString &language, V2TIMValueCallback<V2TIMString> *callback);

    V2TIMSoundElem();
    V2TIMSoundElem(const V2TIMSoundElem &);
    V2TIMSoundElem &operator=(const V2TIMSoundElem &);
    ~V2TIMSoundElem() override;
};

/////////////////////////////////////////////////////////////////////////////////
//
//                         视频消息 Elem
//
/////////////////////////////////////////////////////////////////////////////////

/// 视频消息 Elem
struct TIM_API V2TIMVideoElem : public V2TIMElem {
    /// 视频文件路径（只有发送方才能获取到）
    V2TIMString videoPath;
    /// 截图文件路径（只有发送方才能获取到）
    V2TIMString snapshotPath;
    /// 视频 ID,内部标识，可用于外部缓存 key
    V2TIMString videoUUID;
    /// 视频大小
    uint64_t videoSize;
    /// 视频类型
    V2TIMString videoType;
    /// 视频时长
    uint32_t duration;
    /// 截图 ID,内部标识，可用于外部缓存 key
    V2TIMString snapshotUUID;
    /// 截图 size
    uint64_t snapshotSize;
    /// 截图宽
    uint32_t snapshotWidth;
    /// 截图高
    uint32_t snapshotHeight;

    /// 获取视频的 URL 下载地址
    void GetVideoUrl(V2TIMValueCallback<V2TIMString> *callback);

    /// 获取截图的 URL 下载地址
    void GetSnapshotUrl(V2TIMValueCallback<V2TIMString> *callback);

    /**
     *  下载视频
     *
     *  DownloadVideo 接口每次都会从服务端下载，如需缓存或者存储，开发者可根据 uuid 作为 key
     * 进行外部存储，ImSDK 并不会存储资源文件。
     *
     *  @param path 视频保存路径，需要外部指定
     */
    void DownloadVideo(const V2TIMString &path, V2TIMDownloadCallback *callback);

    /**
     *  下载视频截图
     *
     *  DownloadSnapshot 接口每次都会从服务端下载，如需缓存或者存储，开发者可根据 uuid 作为 key
     * 进行外部存储，ImSDK 并不会存储资源文件。
     *
     *  @param path 截图保存路径，需要外部指定
     */
    void DownloadSnapshot(const V2TIMString &path, V2TIMDownloadCallback *callback);

    V2TIMVideoElem();
    V2TIMVideoElem(const V2TIMVideoElem &);
    V2TIMVideoElem &operator=(const V2TIMVideoElem &);
    ~V2TIMVideoElem() override;
};

/////////////////////////////////////////////////////////////////////////////////
//
//                         文件消息 Elem
//
/////////////////////////////////////////////////////////////////////////////////

/// 文件消息 Elem
struct TIM_API V2TIMFileElem : public V2TIMElem {
    /// 文件路径（只有发送方才能获取到）
    V2TIMString path;
    /// 文件 ID,内部标识，可用于外部缓存 key
    V2TIMString uuid;
    /// 文件显示名称
    V2TIMString filename;
    /// 文件大小
    uint64_t fileSize;

    /// 获取文件的 URL 下载地址
    void GetUrl(V2TIMValueCallback<V2TIMString> *callback);

    /**
     *  下载文件
     *
     *  DownloadFile 接口每次都会从服务端下载，如需缓存或者存储，开发者可根据 uuid 作为 key
     * 进行外部存储，ImSDK 并不会存储资源文件。
     *
     *  @param path 文件保存路径，需要外部指定
     */
    void DownloadFile(const V2TIMString &path, V2TIMDownloadCallback *callback);

    V2TIMFileElem();
    V2TIMFileElem(const V2TIMFileElem &);
    V2TIMFileElem &operator=(const V2TIMFileElem &);
    ~V2TIMFileElem() override;
};

/////////////////////////////////////////////////////////////////////////////////
//
//                         地理位置 Elem
//
/////////////////////////////////////////////////////////////////////////////////

/// 地理位置 Elem
struct TIM_API V2TIMLocationElem : public V2TIMElem {
    /// 地理位置描述信息
    V2TIMString desc;
    /// 经度，发送消息时设置
    double longitude;
    /// 纬度，发送消息时设置
    double latitude;

    V2TIMLocationElem();
    V2TIMLocationElem(const V2TIMLocationElem &);
    V2TIMLocationElem &operator=(const V2TIMLocationElem &);
    ~V2TIMLocationElem() override;
};

/////////////////////////////////////////////////////////////////////////////////
//
//                         表情消息 Elem
//
/////////////////////////////////////////////////////////////////////////////////

/// 表情消息 Elem
struct TIM_API V2TIMFaceElem : public V2TIMElem {
    /**
     *  表情索引，用户自定义
     *  1. 表情消息由 TIMFaceElem 定义，SDK 并不提供表情包，如果开发者有表情包，可使用 index
     * 存储表情在表情包中的索引，由用户自定义，或者直接使用 data 存储表情二进制信息以及字符串
     * key，都由用户自定义，SDK 内部只做透传。
     *  2. index 和 data 只需要传入一个即可，ImSDK 只是透传这两个数据。
     */
    uint32_t index;
    /// 额外数据，用户自定义
    V2TIMBuffer data;

    V2TIMFaceElem();
    V2TIMFaceElem(const V2TIMFaceElem &);
    V2TIMFaceElem &operator=(const V2TIMFaceElem &);
    ~V2TIMFaceElem() override;
};

/////////////////////////////////////////////////////////////////////////////////
//
//                         合并消息 Elem
//
/////////////////////////////////////////////////////////////////////////////////

/// 合并消息 Elem
struct TIM_API V2TIMMergerElem : public V2TIMElem {
    /// 合并消息里面又包含合并消息我们称之为合并嵌套，合并嵌套层数不能超过 100 层，
    /// 如果超过限制，layersOverLimit 为 true，title 和 abstractList 为空，DownloadMergerMessage
    /// 会返回 ERR_MERGER_MSG_LAYERS_OVER_LIMIT 错误码。
    bool layersOverLimit;
    /// 合并消息 title
    V2TIMString title;
    /// 合并消息摘要列表
    V2TIMStringVector abstractList;

    /// 下载被合并的消息列表
    void DownloadMergerMessage(V2TIMValueCallback<V2TIMMessageVector> *callback);

    V2TIMMergerElem();
    V2TIMMergerElem(const V2TIMMergerElem &);
    V2TIMMergerElem &operator=(const V2TIMMergerElem &);
    ~V2TIMMergerElem() override;
};

/////////////////////////////////////////////////////////////////////////////////
//
//                         群 Tips 消息 Elem
//
/////////////////////////////////////////////////////////////////////////////////

/// 群 tips 消息会存消息列表，群里所有的人都会展示，比如 xxx 进群，xxx 退群，xxx 群资料被修改了等
struct TIM_API V2TIMGroupTipsElem : public V2TIMElem {
    /// 群组 ID
    V2TIMString groupID;
    /// 群Tips类型
    V2TIMGroupTipsType type;
    /// 操作者群成员资料
    V2TIMGroupMemberInfo opMember;
    /// 被操作人列表
    V2TIMGroupMemberInfoVector memberList;
    /// 群信息变更（type = V2TIM_GROUP_TIPS_TYPE_INFO_CHANGE 时有效）
    V2TIMGroupChangeInfoVector groupChangeInfoList;
    /// 成员变更（type = V2TIM_GROUP_TIPS_TYPE_MEMBER_INFO_CHANGE 时有效）
    V2TIMGroupMemberChangeInfoVector memberChangeInfoList;
    /// 当前群人数（type =
    /// V2TIM_GROUP_TIPS_TYPE_INVITE、TIM_GROUP_TIPS_TYPE_QUIT_GRP、TIM_GROUP_TIPS_TYPE_KICKED
    /// 时有效）
    uint32_t memberCount;

    V2TIMGroupTipsElem();
    V2TIMGroupTipsElem(const V2TIMGroupTipsElem &);
    V2TIMGroupTipsElem &operator=(const V2TIMGroupTipsElem &);
    ~V2TIMGroupTipsElem() override;
};

/////////////////////////////////////////////////////////////////////////////////
//
//                         已读回执
//
/////////////////////////////////////////////////////////////////////////////////

/// 消息已读回执
struct TIM_API V2TIMMessageReceipt {
    /// 消息 ID
    V2TIMString msgID;
    /// C2C 消息接收对象
    V2TIMString userID;
    /// C2C 对端消息是否已读
    bool isPeerRead;
    /// C2C 对端已读的时间
    /// 如果 msgID 为空，该字段表示对端用户标记会话已读的时间
    /// 如果 msgID 不为空，该字段表示对端用户发送消息已读回执的时间（8.1 及以上版本支持）
    int64_t timestamp;
    /// 群 ID
    V2TIMString groupID;
    /// 群消息已读人数
    int32_t readCount ;
    /// 群消息未读人数
    int32_t unreadCount ;

    V2TIMMessageReceipt();
    V2TIMMessageReceipt(const V2TIMMessageReceipt &);
    ~V2TIMMessageReceipt();
};

DEFINE_VECTOR(V2TIMMessageReceipt)
typedef TXV2TIMMessageReceiptVector V2TIMMessageReceiptVector;

/// Group 消息已读群成员信息
struct TIM_API V2TIMGroupMessageReadMemberList {
    /// 获取下一次分页拉取的游标
    uint64_t nextSeq;
    /// 会话列表是否已经拉取完毕
    bool isFinished;
    /// 群消息已读或未读的群成员列表
    V2TIMGroupMemberInfoVector members;

    V2TIMGroupMessageReadMemberList();
    V2TIMGroupMessageReadMemberList(const V2TIMGroupMessageReadMemberList &);
    ~V2TIMGroupMessageReadMemberList();
};

/////////////////////////////////////////////////////////////////////////////////
//
//                         用户消息接收选项
//
/////////////////////////////////////////////////////////////////////////////////

struct TIM_API V2TIMReceiveMessageOptInfo {
    /// 用户 ID
    V2TIMString userID;
    /// 消息接收选项
    V2TIMReceiveMessageOpt receiveOpt;
    /// 获取消息免打扰开始时间：小时
    int32_t startHour;
    /// 获取消息免打扰开始时间：分钟
    int32_t startMinute;
    /// 获取消息免打扰开始时间：秒
    int32_t startSecond;
    /**
     *  获取消息免打扰开始的 UTC 时间戳
     *  @note
     *  - 如果返回的 startTimeStamp 大于 0，您可以直接使用
     *  - 如果返回的 startTimeStamp 等于 0，您需要调用 getStartHour()、getStartMinute()、getStartSecond() 来获取免打扰的相对开始时间
     */
    uint32_t startTimeStamp;
    /// 获取免打扰持续时长，单位：秒
    uint32_t duration;

    V2TIMReceiveMessageOptInfo();
    V2TIMReceiveMessageOptInfo(const V2TIMReceiveMessageOptInfo &);
    ~V2TIMReceiveMessageOptInfo();
};

DEFINE_VECTOR(V2TIMReceiveMessageOptInfo)
typedef TXV2TIMReceiveMessageOptInfoVector V2TIMReceiveMessageOptInfoVector;

/////////////////////////////////////////////////////////////////////////////////
//
//                         消息搜索
//
/////////////////////////////////////////////////////////////////////////////////

/// 消息搜索参数
struct TIM_API V2TIMMessageSearchParam {
    /**
     * 关键字列表，最多支持5个。当消息发送者以及消息类型均未指定时，关键字列表必须非空；否则，关键字列表可以为空。
     */
    V2TIMStringVector keywordList;

    /**
     * 指定关键字列表匹配类型，可设置为“或”关系搜索或者“与”关系搜索.
     * 取值分别为 V2TIM_KEYWORD_LIST_MATCH_TYPE_OR 和
     * V2TIM_KEYWORD_LIST_MATCH_TYPE_AND，默认为“或”关系搜索。
     */
    V2TIMKeywordListMatchType keywordListMatchType;

    /**
     * 指定 userID 发送的消息，最多支持5个。
     */
    V2TIMStringVector senderUserIDList;

    /// 指定搜索的消息类型集合，传入空数组表示搜索支持的全部类型消息（V2TIMFaceElem 和
    /// V2TIMGroupTipsElem 不支持）取值详见 @V2TIMElemType。
    V2TIMElemTypeVector messageTypeList;

    /**
     * 搜索“全部会话”还是搜索“指定的会话”：
     * <p> 如果设置 conversationID == nil，代表搜索全部会话。
     * <p> 如果设置 conversationID != nil，代表搜索指定会话。会话唯一 ID，C2C 单聊组成方式为: "c2c_userID"：群聊组成方式为: "group_groupID"
     */
    V2TIMString conversationID;

    /// 搜索的起始时间点。默认为0即代表从现在开始搜索。UTC 时间戳，单位：秒
    uint32_t searchTimePosition;

    /// 从起始时间点开始的过去时间范围，单位秒。默认为0即代表不限制时间范围，传24x60x60代表过去一天。
    uint32_t searchTimePeriod;

    /**
     * 分页的页号：用于分页展示查找结果，从零开始起步。
     * 比如：您希望每页展示 10 条结果，请按照如下规则调用：
     * - 首次调用：通过参数 pageSize = 10, pageIndex = 0 调用 searchLocalMessage，从结果回调中的
     * totalCount 可以获知总共有多少条结果。
     * - 计算页数：可以获知总页数：totalPage = (totalCount % pageSize == 0) ? (totalCount /
     * pageSize) : (totalCount / pageSize + 1) 。
     * - 再次调用：可以通过指定参数 pageIndex （pageIndex < totalPage）返回后续页号的结果。
     *
     * @note 仅对接口 searchLocalMessages 生效
     */
    uint32_t pageIndex;

    /**
     * 每页结果数量：用于分页展示查找结果，如不希望分页可将其设置成 0，但如果结果太多，可能会带来性能问题。
     * @note 仅对接口 searchLocalMessages 生效
     */
    uint32_t pageSize;

    /**
     * 每次云端搜索返回结果的条数。
     * @note 仅对接口 searchCloudMessages 生效
     */
    uint32_t searchCount;

    /**
     * 每次云端搜索的起始位置。第一次填空字符串，续拉时填写 V2TIMMessageSearchResult 中的返回值。
     * @note 仅对接口 searchCloudMessages 生效
     */
    V2TIMString searchCursor;

    V2TIMMessageSearchParam();
    V2TIMMessageSearchParam(const V2TIMMessageSearchParam &);
    V2TIMMessageSearchParam &operator=(const V2TIMMessageSearchParam &);
    ~V2TIMMessageSearchParam();
};

struct TIM_API V2TIMMessageSearchResultItem {
    /// 会话ID
    V2TIMString conversationID;
    /// 当前会话一共搜索到了多少条符合要求的消息
    uint32_t messageCount;

    /**
     * 满足搜索条件的消息列表
     * <p>如果您本次搜索【指定会话】，那么 messageList
     * 中装载的是本会话中所有满足搜索条件的消息列表。 <p>如果您本次搜索【全部会话】，那么
     * messageList 中装载的消息条数会有如下两种可能：
     * - 如果某个会话中匹配到的消息条数 > 1，则 messageList 为空，您可以在 UI 上显示“ messageCount
     * 条相关记录”。
     * - 如果某个会话中匹配到的消息条数 = 1，则 messageList 为匹配到的那条消息，您可以在 UI
     * 上显示之，并高亮匹配关键词。
     */
    V2TIMMessageVector messageList;

    V2TIMMessageSearchResultItem();
    V2TIMMessageSearchResultItem(const V2TIMMessageSearchResultItem &);
    ~V2TIMMessageSearchResultItem();
};

DEFINE_VECTOR(V2TIMMessageSearchResultItem)
typedef TXV2TIMMessageSearchResultItemVector V2TIMMessageSearchResultItemVector;

struct TIM_API V2TIMMessageSearchResult {
    /**
     * 如果您本次搜索【指定会话】，那么返回满足搜索条件的消息总数量；
     * 如果您本次搜索【全部会话】，那么返回满足搜索条件的消息所在的所有会话总数量。
     */
    uint32_t totalCount;

    /**
     * 如果您本次搜索【指定会话】，那么返回结果列表只包含该会话结果；
     * 如果您本次搜索【全部会话】，那么对满足搜索条件的消息根据会话 ID 分组，分页返回分组结果；
     */
    V2TIMMessageSearchResultItemVector messageSearchResultItems;

    /// 下一次云端搜索的起始位置。
    V2TIMString searchCursor;

    V2TIMMessageSearchResult();
    V2TIMMessageSearchResult(const V2TIMMessageSearchResult &);
    V2TIMMessageSearchResult &operator=(const V2TIMMessageSearchResult &);
    ~V2TIMMessageSearchResult();
};

/////////////////////////////////////////////////////////////////////////////////
//
//                         消息拉取
//
/////////////////////////////////////////////////////////////////////////////////

struct TIM_API V2TIMMessageListGetOption {
    /**
     * 拉取消息类型，可以设置拉取本地、云端更老或者更新的消息
     *
     * @note 请注意
     * <p>当设置从云端拉取时，会将本地存储消息列表与云端存储消息列表合并后返回。如果无网络，则直接返回本地消息列表。
     * <p>关于 getType、拉取消息的起始消息、拉取消息的时间范围 的使用说明：
     * - getType 可以用来表示拉取的方向：往消息时间更老的方向 或者 往消息时间更新的方向；
     * - lastMsg/lastMsgSeq 用来表示拉取时的起点，第一次拉取时可以不填或者填 0；
     * - getTimeBegin/getTimePeriod
     * 用来表示拉取消息的时间范围，时间范围的起止时间点与拉取方向(getType)有关；
     * -
     * 当起始消息和时间范围都存在时，结果集可理解成：「单独按起始消息拉取的结果」与「单独按时间范围拉取的结果」
     * 取交集；
     * - 当起始消息和时间范围都不存在时，结果集可理解成：从当前会话最新的一条消息开始，按照 getType
     * 所指定的方向和拉取方式拉取。
     */
    V2TIMMessageGetType getType;

    /// 拉取单聊历史消息
    V2TIMString userID;

    /// 拉取群组历史消息
    V2TIMString groupID;

    /// 拉取消息数量
    uint32_t count;

    /// 拉取的消息类型集合，getType 为 V2TIM_GET_LOCAL_OLDER_MSG 和 V2TIM_GET_LOCAL_NEWER_MSG 有效，传入空数组表示拉取全部类型消息，取值详见 @V2TIMElemType。
    V2TIMElemTypeVector messageTypeList;

    /**
     * 拉取消息的起始消息
     *
     * @note 请注意，
     * <p>拉取 C2C 消息，只能使用 lastMsg 作为消息的拉取起点；如果没有指定 lastMsg，默认使用会话的最新消息作为拉取起点。
     * <p>拉取 Group 消息时，除了可以使用 lastMsg 作为消息的拉取起点外，也可以使用 lastMsgSeq 来指定消息的拉取起点，二者的区别在于：
     * - 使用 lastMsg 作为消息的拉取起点时，返回的消息列表里不包含当前设置的 lastMsg；
     * - 使用 lastMsgSeq 作为消息拉取起点时，返回的消息列表里包含当前设置的 lastMsgSeq 所表示的消息。
     *
     * @note 在拉取 Group 消息时，
     * <p>如果同时指定了 lastMsg 和 lastMsgSeq，SDK 优先使用 lastMsg 作为消息的拉取起点。
     * <p>如果 lastMsg 和 lastMsgSeq 都未指定，消息的拉取起点分为如下两种情况：
     * -  如果设置了拉取的时间范围，SDK 会根据 @getTimeBegin 所描述的时间点作为拉取起点；
     * -  如果未设置拉取的时间范围，SDK 默认使用会话的最新消息作为拉取起点。
     */
    V2TIMMessage *lastMsg;
    uint64_t lastMsgSeq;

    /**
     * 拉取消息的时间范围
     * @getTimeBegin  表示时间范围的起点；默认为 0，表示从现在开始拉取；UTC 时间戳，单位：秒
     * @getTimePeriod 表示时间范围的长度；默认为 0，表示不限制时间范围；单位：秒
     *
     * @note
     * <p> 时间范围的方向由参数 getType 决定
     * <p> 如果 getType 取 V2TIM_GET_CLOUD_OLDER_MSG/V2TIM_GET_LOCAL_OLDER_MSG，表示从 getTimeBegin 开始，过去的一段时间，时间长度由 getTimePeriod 决定
     * <p> 如果 getType 取 V2TIM_GET_CLOUD_NEWER_MSG/V2TIM_GET_LOCAL_NEWER_MSG，表示从 getTimeBegin 开始，未来的一段时间，时间长度由 getTimePeriod 决定
     * <p> 取值范围区间为闭区间，包含起止时间，二者关系如下：
     * - 如果 getType 指定了朝消息时间更老的方向拉取，则时间范围表示为 [getTimeBegin-getTimePeriod, getTimeBegin]
     * - 如果 getType 指定了朝消息时间更新的方向拉取，则时间范围表示为 [getTimeBegin, getTimeBegin+getTimePeriod]
     */
    int64_t getTimeBegin;
    int64_t getTimePeriod;

    /**
     * 拉取群组历史消息时，支持按照消息序列号 seq 拉取（从 7.1 版本开始有效）
     *
     * @note
     * - 仅拉取群组历史消息时有效；
     * - 消息序列号 seq 可以通过 V2TIMMessage 对象的 seq 字段获取；
     * - 当 getType 设置为从云端拉取时，会将本地存储消息列表与云端存储消息列表合并后返回；如果无网络，则直接返回本地消息列表；
     * - 当 getType 设置为从本地拉取时，直接返回本地的消息列表；
     * - 当 getType 设置为拉取更旧的消息时，消息列表按照时间逆序，也即消息按照时间戳从大往小的顺序排序；
     * - 当 getType 设置为拉取更新的消息时，消息列表按照时间顺序，也即消息按照时间戳从小往大的顺序排序。
     */
    V2TIMUInt64Vector messageSeqList;

    V2TIMMessageListGetOption();
    V2TIMMessageListGetOption(const V2TIMMessageListGetOption &);
    V2TIMMessageListGetOption &operator=(const V2TIMMessageListGetOption &);
    ~V2TIMMessageListGetOption();
};

/////////////////////////////////////////////////////////////////////////////////
//
//                         消息拓展
//
/////////////////////////////////////////////////////////////////////////////////

struct TIM_API V2TIMMessageExtension {
    /// 消息扩展信息 key
    V2TIMString extensionKey;
    /// 消息扩展信息 value
    V2TIMString extensionValue;

    V2TIMMessageExtension();
    V2TIMMessageExtension(const V2TIMMessageExtension &);
    V2TIMMessageExtension &operator=(const V2TIMMessageExtension &);
    ~V2TIMMessageExtension();
};

DEFINE_VECTOR(V2TIMMessageExtension)
typedef TXV2TIMMessageExtensionVector V2TIMMessageExtensionVector;

/////////////////////////////////////////////////////////////////////////////////
//
//                         消息扩展操作结果
//
/////////////////////////////////////////////////////////////////////////////////

struct TIM_API V2TIMMessageExtensionResult {
    /// 返回码
    int32_t resultCode;
    /// 返回信息
    V2TIMString resultInfo;
    /// 扩展信息
    V2TIMMessageExtension extension;

    V2TIMMessageExtensionResult();
    V2TIMMessageExtensionResult(const V2TIMMessageExtensionResult &);
    V2TIMMessageExtensionResult &operator=(const V2TIMMessageExtensionResult &);
    ~V2TIMMessageExtensionResult();
};

DEFINE_VECTOR(V2TIMMessageExtensionResult)
typedef TXV2TIMMessageExtensionResultVector V2TIMMessageExtensionResultVector;

/////////////////////////////////////////////////////////////////////////////////
//
//                         消息回应
//
/////////////////////////////////////////////////////////////////////////////////

struct TIM_API V2TIMMessageReaction {
    /// 消息回应 ID
    V2TIMString reactionID;
    /// 使用同一个 reactionID 回应消息的总的用户个数
    uint32_t totalUserCount;
    /// 使用同一个 reactionID 回应消息的部分用户列表（用户列表数量取决于调用 getMessageReactions 接口时设置的 maxUserCountPerReaction 值）
    V2TIMUserInfoVector partialUserList;
    /// 自己是否使用了该 reaction
    bool reactedByMyself;

    V2TIMMessageReaction();
    V2TIMMessageReaction(const V2TIMMessageReaction &);
    V2TIMMessageReaction &operator=(const V2TIMMessageReaction &);
    ~V2TIMMessageReaction();
};

DEFINE_VECTOR(V2TIMMessageReaction)
typedef TXV2TIMMessageReactionVector V2TIMMessageReactionVector;

/////////////////////////////////////////////////////////////////////////////////
//
//                         消息回应列表拉取结果
//
/////////////////////////////////////////////////////////////////////////////////

struct TIM_API V2TIMMessageReactionResult {
    /// 返回码
    int32_t resultCode;
    /// 返回信息
    V2TIMString resultInfo;
    /// 消息 ID
    V2TIMString msgID;
    /// 消息回应列表
    V2TIMMessageReactionVector reactionList;

    V2TIMMessageReactionResult();
    V2TIMMessageReactionResult(const V2TIMMessageReactionResult &);
    V2TIMMessageReactionResult &operator=(const V2TIMMessageReactionResult &);
    ~V2TIMMessageReactionResult();
};

DEFINE_VECTOR(V2TIMMessageReactionResult)
typedef TXV2TIMMessageReactionResultVector V2TIMMessageReactionResultVector;

/////////////////////////////////////////////////////////////////////////////////
//
//                         消息回应用户列表拉取结果
//
/////////////////////////////////////////////////////////////////////////////////

struct TIM_API V2TIMMessageReactionUserResult {
    /// 用户列表
    V2TIMUserInfoVector userInfoList;
    /// 下次分页拉取 seq
    uint32_t nextSeq;
    /// 是否全部拉取完毕
    bool isFinished;

    V2TIMMessageReactionUserResult();
    V2TIMMessageReactionUserResult(const V2TIMMessageReactionUserResult &);
    V2TIMMessageReactionUserResult &operator=(const V2TIMMessageReactionUserResult &);
    ~V2TIMMessageReactionUserResult();
};

/////////////////////////////////////////////////////////////////////////////////
//
//                         消息回应变更列表
//
/////////////////////////////////////////////////////////////////////////////////

struct TIM_API V2TIMMessageReactionChangeInfo {
    /// 消息 ID
    V2TIMString msgID;
    /// 消息回应列表
    V2TIMMessageReactionVector reactionList;

    V2TIMMessageReactionChangeInfo();
    V2TIMMessageReactionChangeInfo(const V2TIMMessageReactionChangeInfo &);
    V2TIMMessageReactionChangeInfo &operator=(const V2TIMMessageReactionChangeInfo &);
    ~V2TIMMessageReactionChangeInfo();
};

DEFINE_VECTOR(V2TIMMessageReactionChangeInfo)
typedef TXV2TIMMessageReactionChangeInfoVector V2TIMMessageReactionChangeInfoVector;

#endif /* __V2TIM_MESSAGE_H__ */
