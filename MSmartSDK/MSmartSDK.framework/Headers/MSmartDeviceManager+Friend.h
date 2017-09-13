//
//  MSmartDeviceManager_SingleUserVersion.h
//  MSmartSDK
//
//  Created by Ryan on 15/10/9.
//  Copyright (c) 2015年 yellowsea. All rights reserved.
//

#import "MSmartDeviceManager.h"

@interface MSmartDeviceManager(Friend)

/**
 Bind appliance with user

 @since (mainland/overseas)  (single user)
 @param deviceSN appliance SN
 @param tsn tsn from qrcode,it can be nil
 @param completion Async call
 
  - error.code contains: 0 succeed >0 failed, detailed definition in MSmartErrorCode or error.localizedDescription
 */
- (void)bindDeviceWithDeviceSN:(NSString *)deviceSN
                        andTsn:(NSString *)tsn
                    completion:(void (^)(NSError *error))completion;

/**
 Cancel bind appliance with user

 @since (mainland/overseas)  (single user)
 @param deviceID appliance ID
 @param completion Async call
 
  - error.code contains: 0 succeed >0 failed, detailed definition in MSmartErrorCode or error.localizedDescription
 */
- (void)unBindDeviceWithDeviceID:(NSString *)deviceID
                      completion:(void (^)(NSError *error))completion;

/**
 The Appliance owner share the appliance to another user

 @since (mainland/overseas)  (single user)
 @param deviceID appliance ID（eg:17591-17592-17593）
 @param UserId user ID of be shared （eg:1001-1002-1003）
 @param completion Async call
 
  - error.code contains: 0 succeed >0 failed, detailed definition in MSmartErrorCode or error.localizedDescription
 */
- (void)shareDeviceWithDeviceID:(NSString *)deviceID
                       toUserId:(NSString *)UserId
                     completion:(void (^)(NSError *error))completion;

/**
 Other user reply the appliance sharing from the owner

 @since (mainland/overseas)  (single user)
 @param deviceID appliance ID（eg:17591）
 @param account account of the owner
 @param accept accept or not
 @param completion Async call
 
  - error.code contains: 0 succeed >0 failed, detailed definition in MSmartErrorCode or error.localizedDescription
 */
- (void)responseToShareDeviceWithDeviceID:(NSString *)deviceID
                                  account:(NSString *)account
                                   accept:(BOOL)accept
                               completion:(void (^)(NSError *error))completion;

/**
 Cancel the appliance sharing（the owner cancel share or the user cancel the shared）

 @since (mainland/overseas)  (single user)
 @param deviceID appliance ID
 @param userId user ID
 @param completion Async call
 
  - error.code contains: 0 succeed >0 failed, detailed definition in MSmartErrorCode or error.localizedDescription
 */
- (void)cancelShareDeviceWithDeviceID:(NSString *)deviceID
                             toUserId:(NSString *)userId
                           completion:(void (^)(NSError *error))completion;

/**
 The owner reply the sharing request from other users

 @since (mainland/overseas)  (single user)
 @param deviceId appliance ID
 @param UserId request user ID
 @param accept accept or not
 @param completion Async call
 
  - error.code contains: 0 succeed >0 failed, detailed definition in MSmartErrorCode or error.localizedDescription
 */
- (void)requestDeviceShareResponseWithDeviceId:(NSString *)deviceId
                                     andUserId:(NSString *)UserId
                                     andAccept:(BOOL)accept
                                    completion:(void (^)(NSError *error))completion;

/**
 Other users ask the owner share the appliance to them

 @since (mainland/overseas)  (single user)
 @param deviceId appliance ID
 @param UserId the user ID of the owner
 @param completion Async call
 
  - error.code contains: 0 succeed >0 failed, detailed definition in MSmartErrorCode or error.localizedDescription
 */
- (void)requestDeviceShareWithDeviceId:(NSString *)deviceId
                             andUserId:(NSString *)UserId
                            completion:(void (^)(NSError *error))completion;

/**
 Query the related user list of a specific appliance

 @since (mainland/overseas)  (single user)
 @param devicesArray appliance ID list
 @param completion Async call
 
  - error.code contains: 0 succeed >0 failed, detailed definition in MSmartErrorCode or error.localizedDescription
  - usersArray:users list
 */
- (void)getShareUserListByDeviceIds:(NSArray *)devicesArray
                         completion:(void (^)(NSError *error, NSArray *usersArray))completion;

/**
 Modify appliance remarks name

 @since (mainland/overseas)  (single user)
 @param deviceId appliance ID
 @param deviceName new appliance remarks name
 @param completion Async call
  
  - error.code contains: 0 succeed >0 failed, detailed definition in MSmartErrorCode or error.localizedDescription
 */
- (void)modifyDeviceNameWithDeviceId:(NSString *)deviceId
                          deviceName:(NSString *)deviceName
                          completion:(void (^)(NSError *error))completion;
@end
