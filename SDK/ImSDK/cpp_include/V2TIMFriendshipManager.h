// Copyright (c) 2021 Tencent. All rights reserved.

/////////////////////////////////////////////////////////////////////
//
//                     腾讯云通信服务 IMSDK
//
//          关系链接口，里面包含了好友的添加、删除，黑名单的添加、删除等逻辑
//
/////////////////////////////////////////////////////////////////////

#ifndef __V2TIM_FRIENDSHIP_MANAGER_H__
#define __V2TIM_FRIENDSHIP_MANAGER_H__

#include "V2TIMCallback.h"
#include "V2TIMDefine.h"
#include "V2TIMFriendship.h"
#include "V2TIMListener.h"

/**
 * ## 关系链接口，包含了好友的添加和删除，黑名单的添加和删除等逻辑
 */
class TIM_API V2TIMFriendshipManager {
public:
    virtual ~V2TIMFriendshipManager() {}

    /////////////////////////////////////////////////////////////////////////////////
    //
    //                         关系链和用户资料监听器
    //
    /////////////////////////////////////////////////////////////////////////////////

    /**
     * 1.1 添加关系链监听器
     */
    virtual void AddFriendListener(V2TIMFriendshipListener* listener) = 0;

    /**
     * 1.2 移除关系链监听器
     */
    virtual void RemoveFriendListener(V2TIMFriendshipListener* listener) = 0;

    /////////////////////////////////////////////////////////////////////////////////
    //
    //                       好友添加、删除、列表获取、资料设置接口函数
    //
    /////////////////////////////////////////////////////////////////////////////////

    /**
     * 2.1 获取好友列表
     */
    virtual void GetFriendList(V2TIMValueCallback<V2TIMFriendInfoVector>* callback) = 0;

    /**
     * 2.2 获取指定好友资料
     *
     * @param userIDList 好友 userID 列表
     *                   - ID 建议一次最大 100
     * 个，因为数量过多可能会导致数据包太大被后台拒绝，后台限制数据包最大为 1M。
     */
    virtual void GetFriendsInfo(const V2TIMStringVector& userIDList,
                                V2TIMValueCallback<V2TIMFriendInfoResultVector>* callback) = 0;

    /**
     * 2.3 设置指定好友资料
     */
    virtual void SetFriendInfo(const V2TIMFriendInfo& info, V2TIMCallback* callback) = 0;

    /**
     * 2.4 搜索好友（5.4.666 及以上版本支持，需要您购买旗舰版套餐）
     * @note
     *  - 该功能为 IM 旗舰版功能，[购买旗舰版套餐包](https://buy.cloud.tencent.com/avc?from=17474)后可使用，详见[价格说明](https://cloud.tencent.com/document/product/269/11673?from=17176#.E5.9F.BA.E7.A1.80.E6.9C.8D.E5.8A.A1.E8.AF.A6.E6.83.85)
     *  - 该接口返回的是本地存储的用户资料，包含好友和非好友资料，您可以根据 V2TIMFriendInfoResult 中的 getRelation 来判断是否为好友。
     */
    virtual void SearchFriends(const V2TIMFriendSearchParam& searchParam,
                               V2TIMValueCallback<V2TIMFriendInfoResultVector>* callback) = 0;

    /**
     * 2.5 添加好友
     */
    virtual void AddFriend(const V2TIMFriendAddApplication& application,
                           V2TIMValueCallback<V2TIMFriendOperationResult>* callback) = 0;

    /**
     * 2.6 删除好友
     *
     * @param userIDList 要删除的好友 userID 列表
     *                   - ID 建议一次最大 100
     * 个，因为数量过多可能会导致数据包太大被后台拒绝，后台限制数据包最大为 1M。
     * @param deleteType 删除类型
     *                   - @ref V2TIM_FRIEND_TYPE_SINGLE：单向好友
     *                   - @ref V2TIM_FRIEND_TYPE_BOTH：双向好友
     */
    virtual void DeleteFromFriendList(
        const V2TIMStringVector& userIDList, V2TIMFriendType deleteType,
        V2TIMValueCallback<V2TIMFriendOperationResultVector>* callback) = 0;

    /**
     * 2.7 检查指定用户的好友关系
     *
     *  @param userIDList 要检查的 userID 列表
     *  @param checkType 检查类型 （单向好友检查、双向好友检查）
     *
     *  @note checkType 的使用需要注意：
     *  - checkType 如果传入
     * V2TIM_FRIEND_TYPE_SINGLE，结果返回：V2TIM_FRIEND_RELATION_TYPE_NONE、V2TIM_FRIEND_RELATION_TYPE_IN_MY_FRIEND_LIST
     * 两种情况
     *  - checkType 如果传入
     * V2TIM_FRIEND_TYPE_BOTH，结果返回：V2TIM_FRIEND_RELATION_TYPE_NONE、V2TIM_FRIEND_RELATION_TYPE_IN_MY_FRIEND_LIST、
     *                                 V2TIM_FRIEND_RELATION_TYPE_IN_OTHER_FRIEND_LIST、V2TIM_FRIEND_RELATION_TYPE_BOTH_WAY
     * 四种情况
     */
    virtual void CheckFriend(const V2TIMStringVector& userIDList, V2TIMFriendType checkType,
                             V2TIMValueCallback<V2TIMFriendCheckResultVector>* callback) = 0;

    /////////////////////////////////////////////////////////////////////////////////
    //
    //                          好友申请、删除接口函数
    //
    /////////////////////////////////////////////////////////////////////////////////

    /**
     *  3.1 获取好友申请列表
     *
     *  @note
     *   - 好友申请列表包括发起的好友申请和收到的好友申请。
     *   - 最多支持100个。
     */
    virtual void GetFriendApplicationList(
        V2TIMValueCallback<V2TIMFriendApplicationResult>* callback) = 0;

    /**
     * 3.2 同意好友申请
     *
     * @param application  好友申请信息，GetFriendApplicationList 成功后会返回
     * @param responseType 建立单向/双向好友关系
     */
    virtual void AcceptFriendApplication(
        const V2TIMFriendApplication& application, V2TIMFriendAcceptType acceptType,
        V2TIMValueCallback<V2TIMFriendOperationResult>* callback) = 0;
    
    /**
     * 3.3 同意好友申请，并设置备注
     *
     * @param application  好友申请信息，GetFriendApplicationList 成功后会返回
     * @param responseType 建立单向/双向好友关系
     * @param remark  好友备注，最长 96 个字节
     */
    virtual void AcceptFriendApplication(
        const V2TIMFriendApplication& application, V2TIMFriendAcceptType acceptType, const V2TIMString& remark,
        V2TIMValueCallback<V2TIMFriendOperationResult>* callback) = 0;

    /**
     * 3.4 拒绝好友申请
     *
     * @param application 好友申请信息，@ref GetFriendApplicationList 成功后会返回
     */
    virtual void RefuseFriendApplication(
        const V2TIMFriendApplication& application,
        V2TIMValueCallback<V2TIMFriendOperationResult>* callback) = 0;

    /**
     * 3.5 删除好友申请
     *
     * @param application 好友申请信息，@ref GetFriendApplicationList 成功后会返回
     */
    virtual void DeleteFriendApplication(const V2TIMFriendApplication& application,
                                         V2TIMCallback* callback) = 0;

    /**
     * 3.6 设置好友申请已读
     */
    virtual void SetFriendApplicationRead(V2TIMCallback* callback) = 0;

    /////////////////////////////////////////////////////////////////////////////////
    //
    //                          黑名单接口函数
    //
    /////////////////////////////////////////////////////////////////////////////////

    /**
     * 4.1 添加用户到黑名单
     */
    virtual void AddToBlackList(const V2TIMStringVector& userIDList,
                                V2TIMValueCallback<V2TIMFriendOperationResultVector>* callback) = 0;

    /**
     * 4.2 把用户从黑名单中删除
     */
    virtual void DeleteFromBlackList(
        const V2TIMStringVector& userIDList,
        V2TIMValueCallback<V2TIMFriendOperationResultVector>* callback) = 0;

    /**
     * 4.3 获取黑名单列表
     */
    virtual void GetBlackList(V2TIMValueCallback<V2TIMFriendInfoVector>* callback) = 0;

    /////////////////////////////////////////////////////////////////////////////////
    //
    //                          好友分组接口函数
    //
    /////////////////////////////////////////////////////////////////////////////////

    /**
     * 5.1 新建好友分组
     *
     * @param groupName  分组名称
     * @param userIDList 要添加到分组中的好友 userID 列表
     */
    virtual void CreateFriendGroup(
        const V2TIMString& groupName, const V2TIMStringVector& userIDList,
        V2TIMValueCallback<V2TIMFriendOperationResultVector>* callback) = 0;

    /**
     * 5.2 获取分组信息
     *
     * @param groupNameList 要获取信息的好友分组名称列表, 传入空的 V2TIMStringVector 获得所有分组信息
     */
    virtual void GetFriendGroups(const V2TIMStringVector& groupNameList,
                                 V2TIMValueCallback<V2TIMFriendGroupVector>* callback) = 0;

    /**
     * 5.3 删除好友分组
     */
    virtual void DeleteFriendGroup(const V2TIMStringVector& groupNameList,
                                   V2TIMCallback* callback) = 0;

    /**
     * ## 修改好友分组的名称
     *
     * @param oldName  旧的分组名称
     * @param newName  新的分组名称
     * @param callback 回调
     */
    virtual void RenameFriendGroup(const V2TIMString& oldName, const V2TIMString& newName,
                                   V2TIMCallback* callback) = 0;

    /**
     * 5.4 添加好友到一个好友分组
     */
    virtual void AddFriendsToFriendGroup(
        const V2TIMString& groupName, const V2TIMStringVector& userIDList,
        V2TIMValueCallback<V2TIMFriendOperationResultVector>* callback) = 0;

    /**
     * 5.5 从好友分组中删除好友
     */
    virtual void DeleteFriendsFromFriendGroup(
        const V2TIMString& groupName, const V2TIMStringVector& userIDList,
        V2TIMValueCallback<V2TIMFriendOperationResultVector>* callback) = 0;

    /////////////////////////////////////////////////////////////////////////////////
    //
    //                         公众号接口函数
    //
    /////////////////////////////////////////////////////////////////////////////////

    /**
     * 6.1 订阅公众号（7.6 及其以上版本支持）
     */
    virtual void SubscribeOfficialAccount(const V2TIMString& officialAccountID, V2TIMCallback* callback) = 0;

    /**
     * 6.2 取消订阅公众号（7.6 及其以上版本支持）
     */
    virtual void UnsubscribeOfficialAccount(const V2TIMString& officialAccountID, V2TIMCallback* callback) = 0;

    /**
     * 6.3 获取公众号列表（7.6 及其以上版本支持）
     * @note officialAccountIDList 传空时，获取订阅的公众号列表
     */
    virtual void GetOfficialAccountsInfo(const V2TIMStringVector& officialAccountIDList,
                                         V2TIMValueCallback<V2TIMOfficialAccountInfoResultVector>* callback) = 0;

    /////////////////////////////////////////////////////////////////////////////////
    //
    //                         关注/粉丝功能接口函数
    //
    /////////////////////////////////////////////////////////////////////////////////

    /**
     *  7.1 关注用户（从 7.8 版本开始支持）
     * 
     *  @note
     *   - 一次最多支持关注 20 个用户。
     *   - 该功能为 IM 旗舰版功能，[购买旗舰版套餐包](https://buy.cloud.tencent.com/avc?from=17491)后可使用，详见[价格说明](https://cloud.tencent.com/document/product/269/11673?from=17472#.E5.9F.BA.E7.A1.80.E6.9C.8D.E5.8A.A1.E8.AF.A6.E6.83.85)。
     */
    virtual void FollowUser(const V2TIMStringVector& userIDList, V2TIMValueCallback<V2TIMFollowOperationResultVector>* callback) = 0;

    /**
     *  7.2 取消关注用户（从 7.8 版本开始支持）
     * 
     *  @note
     *   - 一次最多支持取消关注 20 个用户。
     *   - 该功能为 IM 旗舰版功能，[购买旗舰版套餐包](https://buy.cloud.tencent.com/avc?from=17491)后可使用，详见[价格说明](https://cloud.tencent.com/document/product/269/11673?from=17472#.E5.9F.BA.E7.A1.80.E6.9C.8D.E5.8A.A1.E8.AF.A6.E6.83.85)。
     */
    virtual void UnfollowUser(const V2TIMStringVector& userIDList, V2TIMValueCallback<V2TIMFollowOperationResultVector>* callback) = 0;

    /**
     *  7.3 获取我的关注列表（从 7.8 版本开始支持）
     * 
     *  @param nextCursor  分页拉取标志，第一次拉取填 ""，回调成功如果 nextCursor 不为 ""，需要分页，可以传入该值再次拉取，直至 nextCursor 返回为 @""
     * 
     *  @note
     *   - 该功能为 IM 旗舰版功能，[购买旗舰版套餐包](https://buy.cloud.tencent.com/avc?from=17491)后可使用，详见[价格说明](https://cloud.tencent.com/document/product/269/11673?from=17472#.E5.9F.BA.E7.A1.80.E6.9C.8D.E5.8A.A1.E8.AF.A6.E6.83.85)。
     */
    virtual void GetMyFollowingList(const V2TIMString& nextCursor, V2TIMValueCallback<V2TIMUserInfoResult>* callback) = 0;

    /**
     *  7.4 获取我的粉丝列表（从 7.8 版本开始支持）
     * 
     *  @param nextCursor  分页拉取标志，第一次拉取填 ""，回调成功如果 nextCursor 不为 ""，需要分页，可以传入该值再次拉取，直至 nextCursor 返回为 ""
     * 
     *  @note
     *   - 该功能为 IM 旗舰版功能，[购买旗舰版套餐包](https://buy.cloud.tencent.com/avc?from=17491)后可使用，详见[价格说明](https://cloud.tencent.com/document/product/269/11673?from=17472#.E5.9F.BA.E7.A1.80.E6.9C.8D.E5.8A.A1.E8.AF.A6.E6.83.85)。
     */
    virtual void GetMyFollowersList(const V2TIMString& nextCursor, V2TIMValueCallback<V2TIMUserInfoResult>* callback) = 0;

    /**
     *  7.5 获取我的互关列表（从 7.8 版本开始支持）
     * 
     *  @param nextCursor  分页拉取标志，第一次拉取填 ""，回调成功如果 nextCursor 不为 ""，需要分页，可以传入该值再次拉取，直至 nextCursor 返回为 ""
     * 
     *  @note
     *   - 该功能为 IM 旗舰版功能，[购买旗舰版套餐包](https://buy.cloud.tencent.com/avc?from=17491)后可使用，详见[价格说明](https://cloud.tencent.com/document/product/269/11673?from=17472#.E5.9F.BA.E7.A1.80.E6.9C.8D.E5.8A.A1.E8.AF.A6.E6.83.85)。
     */
    virtual void GetMutualFollowersList(const V2TIMString& nextCursor, V2TIMValueCallback<V2TIMUserInfoResult>* callback) = 0;

    /**
     *  7.6 获取指定用户的 关注/粉丝/互关 数量信息（从 7.8 版本开始支持）
     * 
     *  @note
     *   - 该功能为 IM 旗舰版功能，[购买旗舰版套餐包](https://buy.cloud.tencent.com/avc?from=17491)后可使用，详见[价格说明](https://cloud.tencent.com/document/product/269/11673?from=17472#.E5.9F.BA.E7.A1.80.E6.9C.8D.E5.8A.A1.E8.AF.A6.E6.83.85)。
     */
    virtual void GetUserFollowInfo(const V2TIMStringVector& userIDList, V2TIMValueCallback<V2TIMFollowInfoVector>* callback) = 0;

    /**
     *  7.7 检查指定用户的关注类型（从 7.8 版本开始支持）
     * 
     *  @note
     *   - 该功能为 IM 旗舰版功能，[购买旗舰版套餐包](https://buy.cloud.tencent.com/avc?from=17491)后可使用，详见[价格说明](https://cloud.tencent.com/document/product/269/11673?from=17472#.E5.9F.BA.E7.A1.80.E6.9C.8D.E5.8A.A1.E8.AF.A6.E6.83.85)。
     */
    virtual void CheckFollowType(const V2TIMStringVector& userIDList, V2TIMValueCallback<V2TIMFollowTypeCheckResultVector>* callback) = 0;

};

#endif  // __V2TIM_FRIENDSHIP_MANAGER_H__
