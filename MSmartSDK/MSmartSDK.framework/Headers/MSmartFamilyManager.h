//
//  MSmartFamilyManager.h
//  MSmartSDK
//
//  Created by Ryan on 15/9/22.
//  Copyright (c) 2015年 yellowsea. All rights reserved.
//

#import "MSmartBaseManager.h"
#import "MSmartDefinition.h"

/**
 Family manager
 
 @note This class is only available for Family mode (MSmartWorkModeFamily) and is unavailable for Friend mode(MSmartWorkModeFriend),see MSmartWorkMode for detailed mode.
 */
@interface MSmartFamilyManager : MSmartBaseManager
#pragma mark - 家庭组相关接口，若不需要家庭组相关概念可不使用

/**
 家庭管理类的单例.

 @since (mainland)  (group)
 @return 家庭管理类的单例
 */
+ (instancetype)sharedManager;

/**
 加入家庭：用户申请加入某个家庭，将接口调用成功，会推送一条消息给该家庭的家长，若该家庭的家长同意则加入家庭成功

 @param familyID 申请加入的家庭Id
 @param completion 异步执行返回(block)
 
  - error：error.code值为0表示执行成功；大于0表示执行失败；具体错误提示见 MSmartErrorCode 定义或error.localizedDescription
 */
- (void)joinFamilyWithFamilyID:(NSString *)familyID
                     completion:(void(^)(NSError *error))completion;

/**
 加入家庭应答：当家长收到申请加入的推送后，调用该接口应答是否同意加入，若同意加入则该用户会成为家庭的成员，并且推送消息通知所有家庭成员

 @since (mainland)  (group)
 @param isAccept 是否同意
 @param familyID 申请加入的家庭Id
 @param userID 申请的用户Id
 @param completion 异步执行返回(block)
 
  - error：error.code值为0表示执行成功；大于0表示执行失败；具体错误提示见 MSmartErrorCode 定义或error.localizedDescription
 */
- (void) joinFamilyResponseWith:(BOOL)isAccept
                       familyID:(NSString *)familyID
                         userID:(NSString *)userID
                     completion:(void(^)(NSError *error))completion;

/**
 退出家庭: 家庭成员退出某个家庭

 @since (mainland)  (group)
 @param familyID 需要退出的家庭Id
 @param completion 异步执行返回(block)
 
  - error：error.code值为0表示执行成功；大于0表示执行失败；具体错误提示见 MSmartErrorCode 定义或error.localizedDescription
 */
- (void) quitFamilyWithFamilyID:(NSString *)familyID
                     completion:(void(^)(NSError *error))completion;

/**
 邀请用户加入家庭:家长邀请某个用户加入某个家庭，将接口调用成功，会推送一条消息给该用户，若该用户同意则加入家庭成功

 @since (mainland)  (group)
 @param familyID 家庭Id
 @param account 邀请成员的邮箱或者手机号
 @param completion 异步执行返回(block)
 
  - error：error.code值为0表示执行成功；大于0表示执行失败；具体错误提示见 MSmartErrorCode 定义或error.localizedDescription
 */
- (void) inviteFamilyMemberWithFamilyID:(NSString *)familyID
                                account:(NSString *)account
                             completion:(void(^)(NSError *error))completion;

/**
 邀请用户加入家庭应答：当用户收到邀请的推送后，调用该接口应答是否同意加入，若同意加入则该用户会成为家庭的成员，并且推送消息通知所有家庭成员

 @since (mainland)  (group)
 @param familyID 家庭ID
 @param isAccept 是否接受邀请
 @param completion 异步执行返回(block)
 
  - error：error.code值为0表示执行成功；大于0表示执行失败；具体错误提示见 MSmartErrorCode 定义或error.localizedDescription
 */
- (void) inviteFamilyMemberResponseWithFamilyID:(NSString *)familyID
                                       isAccept:(BOOL)isAccept
                                     completion:(void(^)(NSError *error))completion;

/**
 删除家庭成员

 @since (mainland)  (group)
 @param userID 用户ID
 @param familyID 家庭ID
 @param completion 异步执行返回(block)
 
  - error：error.code值为0表示执行成功；大于0表示执行失败；具体错误提示见 MSmartErrorCode 定义或error.localizedDescription
 */
- (void) deleteFamilyMemberWithUserID:(NSString *)userID
                             familyID:(NSString *)familyID
                           completion:(void(^)(NSError *error))completion;

/**
 删除一个家庭

 @since (mainland)  (group)
 @param familyID 家庭ID
 @param completion 异步执行返回(block)
 
  - error：error.code值为0表示执行成功；大于0表示执行失败；具体错误提示见 MSmartErrorCode 定义或error.localizedDescription
 */
- (void) deleteFamilyWithFamilyD:(NSString *)familyID
                     completion:(void (^)(NSError *error))completion;

/**
 创建一个家庭

 @since (mainland)  (group)
 @param familyName 家庭名称(必填)
 @param description 家庭描述(选填)
 @param address 家庭地址(选填)
 @param coordinate 地理位置(选填)
 @param completion 异步执行返回(block)
 
  - error：error.code值为0表示执行成功；大于0表示执行失败；具体错误提示见 MSmartErrorCode 定义或error.localizedDescription
 */
- (void) createFamilyWithName:(NSString *)familyName
                  description:(NSString *)description
                      address:(NSString *)address
                   coordinate:(NSString *)coordinate
                   completion:(void (^)(NSError *error))completion;

/**
 切换当前家庭

 @since (mainland)  (group)
 @param familyID 家庭ID
 @param completion 异步执行返回(block)
 
  - error：error.code值为0表示执行成功；大于0表示执行失败；具体错误提示见 MSmartErrorCode 定义或error.localizedDescription
 */
- (void)switchCurrentFamilyWithFamilyID:(NSString *)familyID
                              completion:(void(^)(NSError *error))completion;

/**
 修改家庭信息

 @since (mainland)  (group)
 @param familyID 家庭ID
 @param familyName 家庭名称
 @param familyDescription 家庭描述
 @param familyAddress 家庭地址
 @param familyCoordinate 家庭位置
 @param completion 异步执行返回(block)
  
  - error：error.code值为0表示执行成功；大于0表示执行失败；具体错误提示见 MSmartErrorCode 定义或error.localizedDescription
 */
- (void)modifyFamilyInformationWithFamilyID:(NSString *)familyID
                                  familyName:(NSString *)familyName
                           familyDescription:(NSString *)familyDescription
                               familyAddress:(NSString *)familyAddress
                            familyCoordinate:(NSString *)familyCoordinate
                                  completion:(void (^)(NSError *error))completion;

/**
 设置默认家庭

 @since (mainland)  (group)
 @param familyID 家庭ID
 @param completion 异步执行返回(block)
 
  - error：error.code值为0表示执行成功；大于0表示执行失败；具体错误提示见 MSmartErrorCode 定义或error.localizedDescription
 */
- (void)setDefaultFamilyWithFamilyID:(NSString *)familyID
                           completion:(void (^)(NSError *error))completion;

/**
 获取家庭列表

 @since (mainland)  (group)
 @param completion 异步执行返回(block)
  
  - error：error.code值为0表示执行成功；大于0表示执行失败；具体错误提示见 MSmartErrorCode 定义或error.localizedDescription
  - familyList：家庭列表
 */
- (void)getFamilyListWithCompletion:(void (^)(NSError *error, NSArray *familyList))completion;

/**
 获取家庭成员列表

 @since (mainland)  (group)
 @param familyID 家庭ID
 @param completion 异步执行返回(block)
 
  - error：error.code值为0表示执行成功；大于0表示执行失败；具体错误提示见 MSmartErrorCode 定义或error.localizedDescription
  - memberList：家庭成员列表
 */
- (void) getFamilyMemberListWithFamilyID:(NSString *)familyID
                              completion:(void (^)(NSError *error, NSArray *memberList))completion;

/**
 通过FamilyId搜索家庭

 @since (mainland)  (group)
 @param familyID 家庭ID
 @param completion 异步执行返回(block)
 
  - error：error.code值为0表示执行成功；大于0表示执行失败；具体错误提示见 MSmartErrorCode 定义或error.localizedDescription
  - dic：搜索到的家庭信息
 */
- (void)searchFamilyWithFamilyID:(NSString *)familyID
                       completion:(void(^)(NSError *error, NSDictionary *dic))completion;

/**
 通过FamilyNumber搜索家庭

 @since (mainland)  (group)
 @param familyNumber 家庭号
 @param completion 异步执行返回(block)
 
  - error：error.code值为0表示执行成功；大于0表示执行失败；具体错误提示见 MSmartErrorCode 定义或error.localizedDescription
  - dic：搜索到的家庭信息
 */
- (void) searchFamilyWithFamilyNumber:(NSString *)familyNumber
                           completion:(void(^)(NSError *error, NSDictionary *dic))completion;

/**
 通过FamilyName搜索家庭

 @since (mainland)  (group)
 @param familyName 家庭名称
 @param completion 异步执行返回(block)
 
  - error：error.code值为0表示执行成功；大于0表示执行失败；具体错误提示见 MSmartErrorCode 定义或error.localizedDescription
  - array：搜索到的家庭列表

 */
- (void) searchFamilyWithFamilyName:(NSString *)familyName
                         completion:(void(^)(NSError *error, NSArray *array))completion;

/**
 获取当前家庭组的名称. 如果用户登陆成功, 接口返回是一个中文+英文的系统默认名称.

 @since (mainland)  (group)
 @note 如果未登录则会返回 @"尚未登录,请先登录"
 @return 家庭组名称
 */
- (NSString *)getCurrentFamilyName;

/**
 获取当前家庭ID

 @since (mainland)  (group)
 @note 如果未登录则会返回 @"尚未登录,请先登录"
 @return  家庭ID,如果未登录则会返回 @"尚未登录,请先登录"
 */
- (NSString *)getCrurrentFamilyId;



@end
