//
//  MSmartSystemManager.h
//  MSmartSDK
//
//  Created by Ryan on 16/9/8.
//  Copyright © 2016年 yellowsea. All rights reserved.
//

#import <MSmartSDK/MSmartSDK.h>

@interface MSmartSystemManager : MSmartBaseManager

/**
 The singleton of system settings.
 
 **Example:**
 
  MSmartSystemManager *manager = [MSmartSystemManager sharedManager];
 
  [manager MSmartTestModel:@"join us!"];
 
 @since (mainland/overseas)  (group/single user)
 @return The singleton of system settings
 */
+ (MSmartSystemManager *) sharedManager;

/**
 Initialization SDK,it must be the first called API

 @since (mainland/overseas)  (group/single user)
 @param appID the ID of APP, Apply from Midea
 @param appKey the key of APP,Apply from Midea
 @param appSrc the source of APP,Apply from Midea
 @param mode sdk mode,detailed definition in MSmartWorkMode
 @param completion Async call
 
  - error.code contains: 0 succeed >0 failed, detailed definition in MSmartErrorCode or error.localizedDescription

 */
- (void)initSDKWithAppID:(NSString*)appID
                  appKey:(NSString*)appKey
                  appSrc:(NSInteger)appSrc
                workMode:(MSmartWorkMode)mode
              completion:(void (^)(NSError* error))completion;

/**
 Set server address

 @since (mainland/overseas)  (group/single user)
 @param serverAddress the enum of the server address,detailed definition in MSmartServer of MSmartDefinition.h
 @return succeed or not
 */
- (BOOL)setupServerAddress:(MSmartServer)serverAddress;

/**
 Print log or not，the log file will be saved in Document/log of sandbox.

 @since (mainland/overseas)  (group/single user)
 @param enable YES:Print LOG NO:Not print LOG
 */
- (void) printLogEnable:(BOOL)enable;

/**
 Log switch is on or off

 @since (mainland/overseas)  (group/single user)
 @return Log switch is on or off.
 */
- (BOOL) currentLogEnable;

/**
 Open https, it is closed by default.

 @since (mainland/overseas)  (group/single user)
 @param open open or not
 */
- (void)openHttpsChanel:(BOOL)open;

/**
 Using encrypted lua files or not,encrypted by default.

 @since (mainland/overseas)  (group/single user)
 @param flag YES：encrypted, NO：not encrypted
 */
- (void)isLuaScriptCryptograph:(BOOL)flag ;

/**
 Get the version of the SDK

 @since (mainland/overseas)  (group/single user)
 @return the version of the SDK
 */
- (NSString *)getMSmartSDKVersion;

@end
