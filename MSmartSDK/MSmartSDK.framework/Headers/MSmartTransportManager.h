//
//  MSmartTransportManager.h
//  MSmartSDK
//
//  Created by 黄海 on 15/6/5.
//  Copyright (c) 2015年 yellowsea. All rights reserved.
//

#import "MSmartSDK.h"

/*#
 *  Push message result notice
 *  Use [[NSNotificationCenter defaultCenter] addObserver:observer selector:@selector(yourSelector:) name:PushNotification object:nil];
 *  the class of object of NSNotification is NSDictionary，contain key @"pushType",the value:
 *
 *  @param remotePushType       push message type.Please refer to RemotePushType in MSmartDefinition.h for detail.）
 *
 *                              RemotePushType_User_Login                = 0, // 用户在其他地方登陆
 *                              RemotePushType_Device_Status             = 1, // 家电特殊状态上报
 *                              RemotePushType_Family_Delete             = 2, // 家庭被家长删除
 *                              RemotePushType_Member_Add                = 3, // 邀请成员加入家庭
 *                              RemotePushType_Member_Add_Respond        = 4, // 邀请成员加入家庭响应
 *                              RemotePushType_Member_Delete             = 5, // 删除家庭成员
 *                              RemotePushType_Member_Join_Send          = 6, // 申请加入家庭
 *                              RemotePushType_Member_Join_Response      = 7, // 申请加入家庭响应
 *                              RemotePushType_Member_Quite              = 8, // 成员退出家庭
 *                              RemotePushType_Device_On                 = 9, // 家电上线推送
 *                              RemotePushType_Device_Off                = 10,// 家电离线推送
 *                              RemotePushType_Device_Reactivity         = 11,// 家电再次激活(家电被其他家庭激活)
 *                              RemotePushType_Device_UpdateId           = 12,// 家电更新DID
 *                              RemotePushType_Device_Add                = 13,// 添加家电(家长向家庭中添加家电，家庭成员收到此推送)
 *                              RemotePushType_Device_Delete             = 14,// 删除家电(家长删除家庭中的家电，家庭成员收到此推送)
 *                              RemotePushType_Device_Share              = 15,// 家电分享-主人发送分享
 *                              RemotePushType_Device_Share_Response     = 16,// 家电分享响应
 *                              RemotePushType_Beg_Device_Share          = 17,// 家电分享-主人发送分享
 *                              RemotePushType_Beg_Device_Share_Response = 18,// 请求家电分享响应
 *                              RemotePushType_Device_Share_Cancel       = 19,// 家电主人撤销分享
 *                              RemotePushType_Device_Owner_Delete       = 20,// 家电主人删除家电
 *                              RemotePushType_Pro2Base                  = 21,// 应用服务器推送(主应用接收)
 *  除了,根据推送类型有所不同（左边为key,右边为value,都是NSString数据类型）
 *
 *      RemotePushType_User_Login           : 用户在其他地方登陆
 *                      tips                    账号在其他地方登录
 *
 *      RemotePushType_Family_Delete        : 家庭被删除通知
 *                      loginAccount            发送邀请的家长账号（邮箱或手机）
 *                      familyNumber            邀请加入的家庭号
 *                      familyId                邀请加入的家庭ID
 *                      timeStamp               消息时间戳
 *                      tips                    {发送邀请的家长昵称}邀请您加入{“家庭名”}家庭
 *
 *       RemotePushType_Member_Add          : 添加成员(家长发送邀请)
 *                      loginAccount            发送邀请的家长账号（邮箱或手机）
 *                      familyNumber            邀请加入的家庭号
 *                      familyId                邀请加入的家庭ID
 *                      timeStamp               消息时间戳
 *                      tips                    {发送邀请的家长昵称}邀请您加入{“家庭名”}家庭
 *
 *       RemotePushType_Member_Add_Respond  : 添加成员(成员应答)
 *                      accept                  是否同意请求（0为拒绝，1为同意）
 *                      loginAccount            回应邀请的成员账号（邮箱或手机）
 *                      familyNumber            邀请加入的家庭号
 *                      familyId                邀请加入的家庭ID
 *                      timeStamp               消息时间戳
 *                      tips                    {回应成员昵称}同意/拒绝加入{“家庭名”}家庭
 *
 *       RemotePushType_Member_Delete       : 家长删除成员后，系统向家庭所有成员推送删除成员消息。
 *                      loginAccount            被删除的成员账号（邮箱或手机）
 *                      familyNumber            退出的家庭号
 *                      familyId                退出的家庭ID
 *                      timeStamp               消息时间戳
 *                      tips                    1、向被删除成员提示：您已被退出{“家庭名”}家庭
 *                                              2、向其他成员提示：{被删除成员昵称}已被退出{“家庭名”}家庭
 *
 *       RemotePushType_Member_Join_Send    : 成员发送加入家庭请求，系统将请求消息推送给该家庭的所有家长，需要家长处理同意或拒绝。
 *                       loginAccount           请求加入的成员账号（邮箱或手机）
 *                       userId                 请求加入的成员ID
 *                       familyNumber           请求加入的家庭号
 *                       familyId               请求加入的家庭ID
 *                       timeStamp              消息时间戳
 *                       tips                   {请求的成员昵称}请求加入{“家庭名”}家庭
 *
 *       RemotePushType_Member_Join_Response : 家长处理成员请求加入的请求后，如果同意成员请求，则向家庭所有用户推送成员加入家庭息；如果拒绝成员请求，则只向请求的成员推送消息。
 *                       accept                 是否同意请求（0为拒绝，1为同意）
 *                       adminAccount           处理请求的家长账号（邮箱或手机）
 *                       memAccount             请求加入的成员账号（邮箱或手机）
 *                       familyNumber           请求加入的家庭号
 *                       familyId               请求加入的家庭ID
 *                       timeStamp              消息时间戳
 *                       tips                   1、向请求的成员提示：{回应的家长昵称}同意/拒绝您加入{“家庭名”}家庭
 *                                              2、向家庭其他成员提示：{请求的成员昵称}已加入{“家庭名”}家庭
 *
 *
 *       RemotePushType_Member_Quite        :  成员退出家庭后，向家庭所有成员推送消息。可向用户提示“xx成员已退出xxx家庭”
 *                       loginAccount           退出的成员账号
 *                       familyNumber           退出的家庭号
 *                       familyId               退出的家庭ID
 *                       timeStamp              消息时间戳
 *                       tips                   {退出成员昵称}已退出{“家庭名”}家庭
 *
 *       RemotePushType_Device_On           : 家电上线提醒
 *                       deviceId               家电ID
 *                       timeStamp              消息时间戳
 *
 *       RemotePushType_Device_Off          : 家电离线提醒
 *                       deviceId               家电ID
 *                       timeStamp              消息时间戳
 *
 *       RemotePushType_Device_Reactivity   : 家电再次激活(被其他家庭或人激活)
 *                       deviceId               家电ID
 *                       familyNumberOld        家电的原家庭号
 *                       familyIdOld            家电的原家庭ID
 *                       familyNumberNew        家电的新家庭号
 *                       timeStamp              消息时间戳
 *                       familyIdNew            家电的新家庭ID
 *                       tips                   {家电名称}已从{“原家庭（用户）名”}家庭（用户）绑定至{“新家庭（用户）名”}家庭（用户）
 *
 *       RemotePushType_Device_UpdateId     : 更新家电ID
 *                       preDeviceId            旧的家电ID
 *                       curDeviceId            新的家电ID
 *
 *       RemotePushType_Device_Add          : 家长添加家电后，系统向家庭所有成员推送添加家电消息。
 *                      deviceId                家电ID
 *                      familyNumber            家电的家庭号
 *                      familyId                家电的家庭ID
 *                      timeStamp               消息时间戳
 *                      tips                    {家电名称}已绑定至{“家庭名称”}家庭
 *
 *       RemotePushType_Device_Delete       : 家长删除家电后，系统向家庭所有成员推送删除家电消息。
 *                      deviceId                被删除的家电ID
 *                      familyNumber            家电的家庭号
 *                      familyId                家电的家庭号
 *                      timeStamp               消息时间戳
 *                      tips                    {家电名称}已从{“家庭名称”}家庭删除
 *
 *       RemotePushType_Device_Share        : 家电分享-主人发送分享
 *                      loginAccount            发送分享的账号（邮箱或手机）
 *                      userId                  发送者的userId
 *                      deviceId                待分享控制权限的家电ID
 *                      deviceType              家电类型
 *                      wifiVersion             Wifi版本
 *                      deviceSn                家电的sn
 *                      deviceSubType           家电子类型
 *                      deviceName              家电名称
 *                      deviceDes               家电描述
 *                      timeStamp               消息时间戳
 *                      tips                    {发送请求的用户昵称}请求将{家电名称}分享给您
 *
 *       RemotePushType_Device_Share_Response   : 家电分享响应
 *                      accept                  是否同意请求（0为拒绝，1为同意）
 *                      loginAccount            发送回应的账号（邮箱或手机）
 *                      userId                  发送者的userId
 *                      deviceId                分享的家电ID
 *                      deviceType              家电类型
 *                      wifiVersion             Wifi版本
 *                      deviceSn                家电的sn
 *                      deviceSubType           家电子类型
 *                      deviceName              家电名称
 *                      deviceDes               家电描述
 *                      timeStamp               消息时间戳
 *                      tips                    {回应请求的好友昵称}同意/拒绝分享您的{家电名称}
 *
 *       RemotePushType_Beg_Device_Share        : 请求家电分享
 *                      loginAccount            做请求操作用户的账号（邮箱或手机）
 *                      userId                  做请求操作用户的userId
 *                      deviceId                请求分享的家电ID
 *                      deviceType              家电类型
 *                      wifiVersion             Wifi版本
 *                      deviceSn                家电的sn
 *                      deviceSubType           家电子类型
 *                      deviceName              家电名称
 *                      deviceDes               家电描述
 *                      timeStamp               消息时间戳
 *                      tips                    {发送请求的用户昵称}请求将{家电名称}分享给您
 *
 *       RemotePushType_Beg_Device_Share_Response : 请求家电分享响应
 *                      accept                  是否同意请求（0为拒绝，1为同意）
 *                      loginAccount            家电主人的用户的账号（邮箱或手机）
 *                      userId                  家电主人的用户的userId
 *                      deviceId                家电ID
 *                      deviceType              家电类型
 *                      wifiVersion             Wifi版本
 *                      deviceSn                家电的sn
 *                      deviceSubType           家电子类型
 *                      deviceName              家电名称
 *                      deviceDes               家电描述
 *                      timeStamp               消息时间戳
 *                      tips                    {回应请求的好友昵称}同意/拒绝分享您的{家电名称}
 *
 *       RemotePushType_Device_Share_Cancel     : 家电主人撤销分享
 *                      loginAccount            做删除操作用户的账号（邮箱或手机）
 *                      userId                  发送者的userId
 *                      deviceId                被撤销权限的家电ID
 *                      deviceType              家电类型
 *                      wifiVersion             Wifi版本
 *                      deviceSn                家电的sn
 *                      deviceSubType           家电子类型
 *                      deviceName              家电名称
 *                      deviceDes               家电描述
 *                      timeStamp               消息时间戳
 *                      tips                    {发送请求的用户昵称}请求将{家电名称}分享给您
 *
 *       RemotePushType_Device_Owner_Delete     : 家电主人删除家电
 *                      loginAccount            做删除操作用户的账号（邮箱或手机）
 *                      userId                  发送者的userId
 *                      deviceId                被删除的家电ID
 *                      deviceType              家电类型
 *                      wifiVersion             Wifi版本
 *                      deviceSn                家电的sn
 *                      deviceSubType           家电子类型
 *                      deviceName              家电名称
 *                      deviceDes               家电描述
 *                      timeStamp               消息时间戳
 *                      tips                    {发送请求的用户昵称}请求将{家电名称}分享给您
 *
 */
static NSString *const PushNotification       = @"MSPushNotification";


/*#
 *   Transport result notice
 *   Use [[NSNotificationCenter defaultCenter] addObserver:observer selector:@selector(yourSelector:) name:TransportNotification object:nil];
 *   the class of object of NSNotification is NSDictionary.
 *
 *
 *                      dic{
 *                      key:@"deviceId"     type:NSString   appliance ID
 *                      key:@"tag"          type:NSNumber   command tag
 *                      key:@"cmdArray"     type:NSArray    decimal command array
 *                      key:@"hexCmdArray"  type:NSArray    hexadecimal command array
 *                      key:@"error"        type:NSError    error message
 *
 *
 **/
static NSString *const TransportNotification  = @"MSTransportNotification";

/*#
 *   Appliance state change notice
 *   Use [[NSNotificationCenter defaultCenter] addObserver:observer selector:@selector(yourSelector:) name:DeviceStateChangedNotification object:nil];
 *   the class of object of NSNotification is NSDictionary.
 *
 *
 *                      dic{
 *                      key:@"deviceId"     type:NSString        appliance ID
 *                      key:@"deviceSn"     type:NSString        appliance SN
 *                      key:@"deviceState"  type:NSDictionary    state dictionary
 *                       eg：  deviceState =     {
 *                            anion = on;
 *                            model = manual;
 *                            offtimer = off;
 *                            offtimervalue = 1920;
 *                            pm25 = 5;
 *                            power = on;
 *                            timer = off;
 *                            tvoc = 0;
 *                            windspeed = weak;
 *                        };
 **/
static NSString *const DeviceStateChangedNotification  = @"MSDeviceStateChangedNotification";

static NSString *const Pro2baseToPluginNotification    = @"MSPro2baseToPlugin";


@interface MSmartTransportManager : MSmartBaseManager

/**
 Transport manager.

 @return transport manager
 
 **Example:**
 
  MSmartTransportManager* manager = [MSmartTransportManager sharedManager];
 
  [manager MSmartTestModel:@"join us!"];
 */
+ (MSmartTransportManager*) sharedManager;

/**
 Send data to appliance

 @since (mainland/overseas)  (group/single user)
 @param deviceID appliance ID
 @param tempArray data
 @param tag the tag of the send
 */
- (void)sendDataWithDeviceID:(NSString *)deviceID
                    tempArray:(NSArray *)tempArray
                          tag:(int)tag;

/**
 You can use this API to get the message once receive a push message from M-Cloud.

 @since (mainland/overseas)  (group/single user)
 @param message the message of receive push
 @return YES:valid，NO:invalid
 */
- (BOOL)handlePushMessage:(NSString *)message;

@end
