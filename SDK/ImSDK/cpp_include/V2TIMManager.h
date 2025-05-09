// Copyright (c) 2021 Tencent. All rights reserved.

/////////////////////////////////////////////////////////////////////////////////
//
//       IMSDK 主核心类，负责 IMSDK 的初始化、登录、消息收发，建群退群等功能
//
/////////////////////////////////////////////////////////////////////////////////

#ifndef __V2TIM_MANAGER_H__
#define __V2TIM_MANAGER_H__

#include "V2TIMCallback.h"
#include "V2TIMCommon.h"
#include "V2TIMCommunity.h"
#include "V2TIMFriendship.h"
#include "V2TIMGroup.h"
#include "V2TIMListener.h"
#include "V2TIMMessage.h"

class V2TIMMessageManager;
class V2TIMGroupManager;
class V2TIMConversationManager;
class V2TIMFriendshipManager;
class V2TIMOfflinePushManager;
class V2TIMSignalingManager;
class V2TIMCommunityManager;

class TIM_API V2TIMManager {
public:
    virtual ~V2TIMManager() {}

    /////////////////////////////////////////////////////////////////////////////////
    //
    //                               初始化
    //
    /////////////////////////////////////////////////////////////////////////////////

    /**
     * 1.1 获取 V2TIMManager 管理器实例。
     */
    static V2TIMManager *GetInstance();

    /**
     * 1.2 添加 SDK 监听
     */
    virtual void AddSDKListener(V2TIMSDKListener *listener) = 0;

    /**
     * 1.3 移除 SDK 监听
     */
    virtual void RemoveSDKListener(V2TIMSDKListener *listener) = 0;

    /**
     * 1.4 初始化 SDK
     *
     * @param sdkAppID 应用 ID，必填项，可以在[控制台](https://console.cloud.tencent.com/im)中获取
     * @param config   配置信息
     * @return true：成功；false：失败
     */
    virtual bool InitSDK(uint32_t sdkAppID, const V2TIMSDKConfig &config) = 0;

    /**
     * 1.5 反初始化 SDK
     *
     */
    virtual void UnInitSDK() = 0;

    /**
     * 1.6 获取 SDK 版本
     * @return 返回版本号，字符串表示，例如 5.0.10
     */
    virtual V2TIMString GetVersion() = 0;

    /**
     *  1.7 获取服务器当前时间
     *
     *  可用于信令离线推送场景下超时判断。
     *
     *  示例：
     *  信令邀请方：设置邀请的服务器时间 serverTime 。
     *  信令接收方：收到信令推送，根据 serverTime 判断信令是否超时 。
     *
     *  @return UTC 时间戳，单位 s
     */
    virtual int64_t GetServerTime() = 0;

    /////////////////////////////////////////////////////////////////////////////////
    //
    //                               登录登出
    //
    /////////////////////////////////////////////////////////////////////////////////

    /**
     * 2.1 登录
     *
     * 登录需要设置用户名 userID 和用户签名 userSig，userSig 生成请参考 [UserSig 后台
     * API](https://cloud.tencent.com/document/product/269/32688)。
     *
     * @note 请注意如下特殊逻辑:
     * - 登陆时票据过期：Login 函数的回调会返回 ERR_USER_SIG_EXPIRED：6206 错误码，此时生成新的 userSig 重新登录。
     * - 在线时票据过期：用户在线期间也可能收到 V2TIMSDKListener::OnUserSigExpired 回调，此时也是需要您生成新的 userSig 并重新登录。
     * - 在线时被踢下线：用户在线情况下被踢，SDK 会通过 V2TIMSDKListener::OnKickedOffline 回调通知给您，此时可以 UI 提示用户，并再次调用 Login() 重新登录。
     * - 同平台多设备在线：该功能为IM旗舰版功能，购买[旗舰版套餐包](https://buy.cloud.tencent.com/avc?from=17487)后可使用，详见[价格说明](https://cloud.tencent.com/document/product/269/11673?from=17224#.E5.9F.BA.E7.A1.80.E6.9C.8D.E5.8A.A1.E8.AF.A6.E6.83.85)。
     */
    virtual void Login(const V2TIMString &userID, const V2TIMString &userSig, V2TIMCallback *callback) = 0;

    /**
     *
     * 2.2 登出
     *
     * 退出登录，如果切换账号，需要 Logout 回调成功或者失败后才能再次 Login，否则 Login 可能会失败。
     */
    virtual void Logout(V2TIMCallback *callback) = 0;

    /**
     * 2.3 获取登录用户
     */
    virtual V2TIMString GetLoginUser() = 0;

    /**
     * 2.4 获取登录状态
     *
     * 如果用户已经处于已登录和登录中状态，请勿再频繁调用登录接口登录。
     *
     * @return 登录状态
     */
    virtual V2TIMLoginStatus GetLoginStatus() = 0;

    /////////////////////////////////////////////////////////////////////////////////
    //
    //                         消息收发
    //
    /////////////////////////////////////////////////////////////////////////////////

    /**
     * 3.1 设置基本消息（文本消息和自定义消息）的事件监听器
     *
     * @note 图片消息、视频消息、语音消息等高级消息的监听，请参考: @ref V2TIMMessageManager::AddAdvancedMsgListener() 接口。
     *
     */
    virtual void AddSimpleMsgListener(V2TIMSimpleMsgListener *listener) = 0;

    /**
     * 3.2 移除基本消息（文本消息和自定义消息）的事件监听器
     */
    virtual void RemoveSimpleMsgListener(V2TIMSimpleMsgListener *listener) = 0;

    /**
     * 3.3 发送单聊普通文本消息（最大支持 12KB）
     *
     * 文本消息支持云端的脏词过滤，如果用户发送的消息中有敏感词，callback 回调将会返回 ERR_SVR_COMM_SENSITIVE_TEXT(80001) 错误码。
     *
     * @return 返回消息的唯一标识 ID
     */
    virtual V2TIMString SendC2CTextMessage(const V2TIMString &text, const V2TIMString &userID,
                                           V2TIMSendCallback *callback) = 0;

    /**
     * 3.4 发送单聊自定义（信令）消息（最大支持 12KB）
     *
     * 自定义消息本质就是一端二进制
     * buffer，您可以在其上自由组织自己的消息格式（常用于发送信令），但是自定义消息不支持云端敏感词过滤。
     *
     * @return 返回消息的唯一标识 ID
     * @note 该接口发送的消息默认不会推送，如果需要推送，请调用 @ref
     * V2TIMMessageManager::SendMessage 接口。
     */
    virtual V2TIMString SendC2CCustomMessage(const V2TIMBuffer &customData, const V2TIMString &userID,
                                             V2TIMSendCallback *callback) = 0;

    /**
     * 3.5 发送群聊普通文本消息（最大支持 12KB）
     *
     * @param priority 设置消息的优先级，我们没有办法所有消息都能 100%
     * 送达每一个用户，但高优先级的消息会有更高的送达成功率。
     *                 - @ref
     * V2TIM_PRIORITY_HIGH：云端会优先传输，适用于在群里发送重要消息，比如主播发送的文本消息等。
     *                 - @ref
     * V2TIM_PRIORITY_NORMAL：云端按默认优先级传输，适用于在群里发送非重要消息，比如观众发送的弹幕消息等。
     * @return 返回消息的唯一标识 ID
     */
    virtual V2TIMString SendGroupTextMessage(const V2TIMString &text, const V2TIMString &groupID,
                                             V2TIMMessagePriority priority, V2TIMSendCallback *callback) = 0;

    /**
     * 3.6 发送群聊自定义（信令）消息（最大支持 12KB）
     *
     * @param priority   设置消息的优先级，我们没有办法所有消息都能 100%
     * 送达每一个用户，但高优先级的消息会有更高的送达成功率。
     *                   - @ref
     * V2TIM_PRIORITY_HIGH：云端会优先传输，适用于在群里发送重要信令，比如连麦邀请，PK邀请、礼物赠送等关键性信令。
     *                   - @ref
     * V2TIM_PRIORITY_NORMAL：云端按默认优先级传输，适用于在群里发送非重要信令，比如观众的点赞提醒等等。
     * @return 返回消息的唯一标识 ID
     * @note 该接口发送的消息默认不会推送，如果需要推送，请调用 @ref
     * V2TIMMessageManager::SendMessage 接口。
     */
    virtual V2TIMString SendGroupCustomMessage(const V2TIMBuffer &customData, const V2TIMString &groupID,
                                               V2TIMMessagePriority priority, V2TIMSendCallback *callback) = 0;

    /////////////////////////////////////////////////////////////////////////////////
    //
    //                        群相关操作
    //
    /////////////////////////////////////////////////////////////////////////////////

    /**
     * 4.1 设置群组监听器
     */
    virtual void AddGroupListener(V2TIMGroupListener *listener) = 0;

    /**
     * 4.2 设置群组监听器
     */
    virtual void RemoveGroupListener(V2TIMGroupListener *listener) = 0;

    /**
     * 4.3 创建群组
     *
     * @param groupType
     * 群类型，我们为您预定义好了几种常用的群类型，您也可以在控制台定义自己需要的群类型：
     *  - "Work"       ：工作群，成员上限 200 人，不支持由用户主动加入，需要他人邀请入群，适合用于类似微信中随意组建的工作群（对应老版本的 Private 群）。
     *  - "Public"     ：公开群，成员上限 2000 人，任何人都可以申请加群，但加群需群主或管理员审批，适合用于类似 QQ 中由群主管理的兴趣群。
     *  - "Meeting"    ：会议群，成员上限 6000 人，任何人都可以自由进出，且加群无需被审批，适合用于视频会议和在线培训等场景（对应老版本的 ChatRoom 群）。
     *  - "Community"  ：社群，成员上限 100000 人，任何人都可以自由进出，且加群无需被审批，适合用于知识分享和游戏交流等超大社区群聊场景。5.8 版本开始支持，需要您购买旗舰版套餐。
     *  - "AVChatRoom" ：直播群，人数无上限，任何人都可以自由进出，消息吞吐量大，适合用作直播场景中的高并发弹幕聊天室。
     *
     * @param groupID   自定义群组 ID，可以传空字符串，此时系统会自动分配 groupID，并通过 callback 返回。
     *                  "Community" 类型自定义群组 ID 必须以 "@TGS#_" 作为前缀。
     * @param groupName 群名称，不能为空字符串，最长 100 字节，使用 UTF-8 编码，1 个汉字占 3 个字节。
     *
     * @note 请注意如下特殊逻辑:
     *  - 不支持在同一个 SDKAPPID 下创建两个相同 groupID 的群。
     *  - 社群（Community）功能仅 5.8.1668 增强版及以上版本支持，需[购买旗舰版套餐包](https://buy.cloud.tencent.com/avc?from=17213)并[申请开通](https://cloud.tencent.com/document/product/269/3916?from=17215)后方可使用。
     *  - 直播群（AVChatRoom）：在进程重启或重新登录之后，如果想继续接收直播群的消息，请您调用 joinGroup 重新加入直播群。
     */
    virtual void CreateGroup(const V2TIMString &groupType, const V2TIMString &groupID, const V2TIMString &groupName,
                             V2TIMValueCallback<V2TIMString> *callback) = 0;

    /**
     * 4.4 加入群组
     *
     *  @note 请注意如下特殊逻辑:
     *  - 工作群（Work）：不能主动入群，只能通过群成员调用 V2TIMGroupManager::InviteUserToGroup() 接口邀请入群。
     *  - 公开群（Public）：申请入群后，需要管理员审批，管理员在收到 V2TIMGroupListener::OnReceiveJoinApplication 回调后调用
     *  V2TIMGroupManager::GetGroupApplicationList() 接口处理加群请求。
     *  - 其他群：可以直接入群。
     *  - 直播群（AVChatRoom）：在进程重启或重新登录之后，如果想继续接收直播群的消息，请您调用 joinGroup 重新加入直播群。
     *  - 直播群（AVChatRoom）：直播群新成员可以查看入群前消息，该功能为 IM 旗舰版功能，[购买旗舰版套餐包](https://buy.cloud.tencent.com/avc?from=17484)后可使用，详见[价格说明](https://cloud.tencent.com/document/product/269/11673?from=17179#.E5.9F.BA.E7.A1.80.E6.9C.8D.E5.8A.A1.E8.AF.A6.E6.83.85)
     */
    virtual void JoinGroup(const V2TIMString &groupID, const V2TIMString &message, V2TIMCallback *callback) = 0;

    /**
     * 4.5 退出群组
     *
     * @note 在公开群（Public）、会议（Meeting）和直播群（AVChatRoom）中，群主是不可以退群的，群主只能调用 DismissGroup 解散群组。
     */
    virtual void QuitGroup(const V2TIMString &groupID, V2TIMCallback *callback) = 0;

    /**
     * 4.6 解散群组
     * @note 请注意如下特殊逻辑:
     *  - Work：任何人都无法解散群组。
     *  - 其他群：群主可以解散群组。
     */
    virtual void DismissGroup(const V2TIMString &groupID, V2TIMCallback *callback) = 0;

    /////////////////////////////////////////////////////////////////////////////////
    //
    //                        资料相关操作
    //
    /////////////////////////////////////////////////////////////////////////////////

    /**
     * 5.1 获取用户资料
     *
     *  @note
     *   - 获取自己的资料，传入自己的 ID 即可。
     *   - userIDList 建议一次最大 100 个，因为数量过多可能会导致数据包太大被后台拒绝，后台限制数据包最大为 1MB。
     */
    virtual void GetUsersInfo(const V2TIMStringVector &userIDList,
                              V2TIMValueCallback<V2TIMUserFullInfoVector> *callback) = 0;

    /**
     * 5.2 修改个人资料
     */
    virtual void SetSelfInfo(const V2TIMUserFullInfo &info, V2TIMCallback *callback) = 0;

    /**
     *  5.3 订阅用户资料，从 7.4 版本开始支持
     *
     *  @param userIDList 待订阅的用户 ID
     *
     *  @note
     *   - 该接口用于订阅陌生人的资料变更事件，订阅成功后，当订阅用户资料发生变更，您可以通过监听 OnUserInfoChanged 回调来感知
     *   - 订阅列表最多允许订阅 200 个，超过限制后，会自动淘汰最先订阅的用户
     *   - 自己的资料变更通知不需要订阅，默认会通过 OnSelfInfoUpdated 回调通知给您
     *   - 好友的资料变更通知不需要订阅，默认会通过 OnFriendInfoChange 回调通知给您
     *   - 该功能为 IM 旗舰版功能，[购买旗舰版套餐包](https://buy.cloud.tencent.com/avc?from=17491)后可使用，详见[价格说明](https://cloud.tencent.com/document/product/269/11673?from=17472#.E5.9F.BA.E7.A1.80.E6.9C.8D.E5.8A.A1.E8.AF.A6.E6.83.85)。
     */
    virtual void SubscribeUserInfo(const V2TIMStringVector &userIDList, V2TIMCallback *callback) = 0;

    /**
     *  5.4 取消订阅用户资料，从 7.4 版本开始支持
     * 
     *  @param userIDList 需要取消订阅的用户 ID
     * 
     *  @note
     *   - 当 userIDList 为空时，取消当前所有的订阅
     *   - 该功能为 IM 旗舰版功能，[购买旗舰版套餐包](https://buy.cloud.tencent.com/avc?from=17491)后可使用，详见[价格说明](https://cloud.tencent.com/document/product/269/11673?from=17472#.E5.9F.BA.E7.A1.80.E6.9C.8D.E5.8A.A1.E8.AF.A6.E6.83.85)。
     */
    virtual void UnsubscribeUserInfo(const V2TIMStringVector &userIDList, V2TIMCallback *callback) = 0;

    /**
     *  5.5 搜索云端用户资料（8.4 及以上版本支持）
     * @param param 用户搜索参数，详见 V2TIMUserSearchParam 的定义
     * @note
     * - 该功能为 IM 增值功能，详见[价格说明](https://cloud.tencent.com/document/product/269/11673?from=17176#.E5.9F.BA.E7.A1.80.E6.9C.8D.E5.8A.A1.E8.AF.A6.E6.83.85)
     * - 如果您没有开通该服务，调用接口会返回 60020 错误码
     * - 该接口返回的是云端存储的用户资料，包括好友和非好友资料，您可以调用 checkFriend 接口来判断是否为好友。
    */
    virtual void SearchUsers(const V2TIMUserSearchParam &param, V2TIMValueCallback<V2TIMUserSearchResult> *callback) = 0;

    /**
     *  5.6 查询用户状态，从 6.3 版本开始支持
     *
     *  @param userIDList 需要获取的用户 ID
     *
     *  @note
     *  - 如果您想查询自己的自定义状态，您只需要传入自己的 userID 即可
     *  - 当您批量查询时，接口只会返回查询成功的用户状态信息；当所有用户均查询失败时，接口会报错
     *  - 查询其他用户状态为 IM 旗舰版功能，[购买旗舰版套餐包](https://buy.cloud.tencent.com/avc?from=17491)后可使用，详见[价格说明](https://cloud.tencent.com/document/product/269/11673?from=17472#.E5.9F.BA.E7.A1.80.E6.9C.8D.E5.8A.A1.E8.AF.A6.E6.83.85)。
     */
    virtual void GetUserStatus(const V2TIMStringVector &userIDList,
                               V2TIMValueCallback<V2TIMUserStatusVector> *callback) = 0;

    /**
     *  5.7 设置自己的状态，从 6.3 版本开始支持
     *
     *  @param status 待设置的自定义状态
     *
     *  @note 该接口只支持设置自己的自定义状态，即 V2TIMUserStatus.customStatus
     */
    virtual void SetSelfStatus(const V2TIMUserStatus &status, V2TIMCallback *callback) = 0;

    /**
     *  5.8 订阅用户状态，从 6.3 版本开始支持
     *
     *  @param userIDList 待订阅的用户 ID
     *
     *  @note
     *   - 当成功订阅用户状态后，当对方的状态（包含在线状态、自定义状态）发生变更后，您可以监听 OnUserStatusChanged 回调来感知
     *   - 如果您需要订阅好友列表的状态，您只需要在控制台上打开开关即可，无需调用该接口
     *   - 该接口不支持订阅自己，您可以通过监听 OnUserStatusChanged 回调来感知自身的自定义状态的变更
     *   - 订阅列表最多允许订阅 200 个，超过限制后，会自动淘汰最先订阅的用户
     *   - 该功能为 IM 旗舰版功能，[购买旗舰版套餐包](https://buy.cloud.tencent.com/avc?from=17491)后可使用，详见[价格说明](https://cloud.tencent.com/document/product/269/11673?from=17472#.E5.9F.BA.E7.A1.80.E6.9C.8D.E5.8A.A1.E8.AF.A6.E6.83.85)。
     */
    virtual void SubscribeUserStatus(const V2TIMStringVector &userIDList, V2TIMCallback *callback) = 0;

    /**
     *  5.9 取消订阅用户状态，从 6.3 版本开始支持
     *
     *  @note
     *   - 当 userIDList 为空时，取消当前所有的订阅
     *   - 该功能为 IM 旗舰版功能，[购买旗舰版套餐包](https://buy.cloud.tencent.com/avc?from=17491)后可使用，详见[价格说明](https://cloud.tencent.com/document/product/269/11673?from=17472#.E5.9F.BA.E7.A1.80.E6.9C.8D.E5.8A.A1.E8.AF.A6.E6.83.85)。
     */
    virtual void UnsubscribeUserStatus(const V2TIMStringVector &userIDList, V2TIMCallback *callback) = 0;

    /////////////////////////////////////////////////////////////////////////////////
    //
    //                        高级功能
    //
    /////////////////////////////////////////////////////////////////////////////////

    /**
     * ## 高级消息功能入口
     *
     * @return 高级消息管理类实例
     */
    virtual V2TIMMessageManager *GetMessageManager() = 0;

    /**
     * ## 高级群组功能入口
     *
     * @return 高级群组管理类实例
     */
    virtual V2TIMGroupManager *GetGroupManager() = 0;

    /**
     * ## 社群功能入口
     *
     * @return 社群管理类实例
     */
    virtual V2TIMCommunityManager *GetCommunityManager() = 0;

    /**
     * ## 会话功能入口
     *
     * @return 会话管理类实例
     */
    virtual V2TIMConversationManager *GetConversationManager() = 0;

    /**
     * ## 关系链功能入口
     *
     * @return 关系链管理类实例
     */
    virtual V2TIMFriendshipManager *GetFriendshipManager() = 0;

    /**
     * ## 离线推送功能入口
     *
     * @return 离线推送功能类实例
     */
    virtual V2TIMOfflinePushManager *GetOfflinePushManager() = 0;

    /**
     * ## 信令功能入口
     *
     * @return 信令管理类实例
     */
    virtual V2TIMSignalingManager *GetSignalingManager() = 0;

    /////////////////////////////////////////////////////////////////////////////////
    //
    //                        扩展接口
    //
    /////////////////////////////////////////////////////////////////////////////////

    /**
     * 实验性 API 接口
     *
     * @param api 接口名称
     * @param param 接口参数
     *
     * @note 该接口提供一些实验性功能
     */
    virtual void CallExperimentalAPI(const V2TIMString &api, const void *param,
                                     V2TIMValueCallback<V2TIMBaseObject> *callback) = 0;
};

#endif  // __V2TIM_MANAGER_H__
