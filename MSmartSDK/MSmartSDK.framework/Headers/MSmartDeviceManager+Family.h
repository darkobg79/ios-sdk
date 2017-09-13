//
//  MSmartDeviceManager+Family.h
//  MSmartSDK
//
//  Created by Ryan on 15/11/19.
//  Copyright © 2015年 yellowsea. All rights reserved.
//

#import "MSmartDeviceManager.h"

@interface MSmartDeviceManager (Family)

/**
 获取用户所有家庭的家电列表

 @since (mainland)  (group)
 @param completion 异步执行返回(block)
 
  - error：error.code值为0表示执行成功；大于0表示执行失败；具体错误提示见 MSmartErrorCode 定义或 error.localizedDescription
  - deviceList：设备列表
 */
- (void)getMyFamilysDeviceListWithCompletion:(void (^)(NSError *error, NSArray *deviceList))completion;

/**
 获取指定家庭的家电列表

 @since (mainland)  (group)
 @param familyId 指定家庭id
 @param completion 异步执行返回(block)
 
  - error：error.code值为0表示执行成功；大于0表示执行失败；具体错误提示见 MSmartErrorCode 定义或error.localizedDescription
  - deviceList：设备列表
 */
- (void)getDeviceListWithFamilyId:(NSString *)familyId
                       completion:(void (^)(NSError* error, NSArray* deviceList))completion;

#pragma mark - 通过二维码激活家电远程控制

/**
 激活家电. 激活指激活家电的远程控制.通过二维码激活

 @since (mainland)  (group)
 @param strCode 从扫描到的家电二维码串获取的二维码
 @param familyId 设备要绑定的家庭的familyId
 @param completion 异步执行返回(block)
 
  - error：error.code值为0表示执行成功；大于0表示执行失败；具体错误提示见 MSmartErrorCode 定义或error.localizedDescription
 */
- (void)activeDeviceWithQRCode:(NSString *)strCode
                      familyId:(NSString *)familyId
                    completion:(void (^)(NSError *error))completion;

/**
 激活家电，激活指激活家电的远程控制.通过SN激活

 @since (mainland)  (group)
 @param deviceSN 设备SN（明文）
 @param familyId 设备要绑定的家庭的familyId
 @param completion 异步执行返回(block)
 
  - error：error.code值为0表示执行成功；大于0表示执行失败；具体错误提示见 MSmartErrorCode 定义或error.localizedDescription
 */
- (void)activeDeviceWithDeviceSN:(NSString *)deviceSN
                        familyId:(NSString *)familyId
                      completion:(void (^)(NSError *error))completion;

/**
 绑定2G模块通用接口，仅用于家庭组模型。

 @since (mainland)  (group)
 @param strCode 从二维码中获取的字符串
 @param familyId 设备要绑定的家庭的familyId
 @param completion 异步执行返回(block)
 
  - error：error.code值为0表示执行成功；大于0表示执行失败；具体错误提示见 MSmartErrorCode 定义或error.localizedDescription
  - deviceInfo：设备信息
    
    - deviceDescription = "";
    - deviceName = "";
    - deviceId = "";
    - isWanOnline = "";
    - isLanOnline = "";
    - deviceProtocolVersion = "";
    - deviceSn = ;
    - deviceSsid = "";
    - deviceSubType = ;
    - deviceType = ;
    - isActivity = ;
 */
- (void)add2GDeviceByQrCode:(NSString *)strCode
                   familyId:(NSString *)familyId
                 completion:(void (^)(NSError *error,NSDictionary *deviceInfo))completion;


#pragma mark - 删除家电

/**
 判断是否激活，删除本地或者服务器的家电

 @since (mainland)  (group)
 @param DeviceID 设备ID
 @param completion 异步执行返回(block)
 
  - error：error.code值为0表示执行成功；大于0表示执行失败；具体错误提示见 MSmartErrorCode 定义或error.localizedDescription
  - isSuccess：是否删除成功
 */
- (void)deleteDeviceWithDeviceID:(NSString *)DeviceID  completion:(void (^)(NSError* error, BOOL isSuccess))completion;



@end
