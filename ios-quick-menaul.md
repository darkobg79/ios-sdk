---
title: MideaSDK-iOS 3.0 快速集成说明
date: 2017-12-20 11:20:39
tags:
- Midea
- Midea SDK
- 说明文档
- iOS
categories:
- 文档
---

![美的智慧家居科技有限公司](http://msmart.midea.com/images/brand.png) 

## 概述

Midea SDK是美的智慧家居系统控制端接入的一套iOS系统开发工具包，第三方开发者可以使用这套工具包提供的接口接入到美的智慧家居系统中实现本地或者远程控制美的家电。  

SDK适用的场景包括：手机、机电盒、智能电视、智能硬件设备等。

<!-- more -->

## 功能

SDK主要提供的功能包括：   

1. 账号注册登陆。     
2. 设备配网和云端绑定。
3. 局域网设备扫描。
4. 设备控制命令本地/远程下发。    
5. 服务器业务请求封装。    
6. 设备协议可视化解析。    

## 业务介绍

SDK分为家庭业务模型和单用户业务模型。    
 1.单用户模型：家电设备直接与用户进行绑定，单个设备在用户之间进行分享。  
 2.家庭模型：家电和家庭进行关联，无法实现单个设备分享，用户通过加入家庭进行家庭中所有设备的全部共享。

> 推荐使用单用户模型，因为数据模型耦合度低，扩展性好。但是如果需要和美居进行数据互通，则需要使用家庭租模型。

## SDK使用前准备

1. 注册美的智慧家居开发者账号。
2. 可上网2.4G路由器一台。
3. 美的智能家电一台。
4. MideaSDK开发包。
5. 申请AppID,AppKey,AppSrc三个参数。
6. SDK提供的API文档。
7. 智能手机一台（iOS 7.0及以上）。  

> 目前美的智能家电仅支持2.4G网络。一般家电上有MSmart标识的家电为智能家电，如果不确定可以咨询售后进行确认。智能手机也可以是任何可连接网络的iOS平台硬件终端。  

 **登录美的智慧家居开发者官网申请AppID,AppKey,AppSrc：**[开发者官网](https://iot.midea.com/develop)

## 开发流程

1. 注册开发者。
2. 体检开发申请。   
3. 获取AppID等参数。
4. 下载SDK。
5. 集成配网SDK。  
6. 开发审核发布。

## MideaSDK接入文档

[英文文档](https://github.com/midea-sdk-org/ios-sdk/blob/master/README.md)

#### 1. 集成MideaSDK到你的项目中：

##### 1.1 手动集成MideaSDK到你的项目中：

1.1.1 根据需要导入`MSmartSDK.framework`至工程，如图

![](https://github.com/midea-sdk-org/ios-sdk/raw/master/pic/p1.jpg) 

1.1.2 引入所需的系统库，如图

![](https://github.com/midea-sdk-org/ios-sdk/raw/master/pic/%E5%AF%BC%E5%85%A5%E7%B3%BB%E7%BB%9F%E5%BA%93.jpeg) 

***备注：标识1（`MSmartSDK.framework`）必须放置在2（`libsqlite3.tbd`）上面***

1.1.3 进入工程`TARGETS-->Build Settings` 设置`Other Linker Flags`为`-all_load` 或者`-ObjC` 或者 `–fore_load` (sdk路径)，如图

![](https://github.com/midea-sdk-org/ios-sdk/raw/master/pic/p3.jpg) 

**1.2 Cocoapods management**

MideaSDK 已经支持 [CocoaPods](http://cocoapods.org/)。使用 [CocoaPods](http://cocoapods.org/) 可以方便的使用 MideaSDK，在你工程的Podfile添加：

```ruby
pod 'MSmartSDK'
```

#### 2. 在项目的 `info.plist` 中配置 “App Transport Security（ATS）” ：

![](https://github.com/midea-sdk-org/ios-sdk/raw/master/pic/ATS%E8%AE%BE%E7%BD%AE.jpeg) 

#### 3. 在需要使用SDK的对象中导入相应文件   

```objective-c
#import <MSmartSDK/MSmartSDK.h>
```

#### 4. 调用接口初始化SDK（无论使用哪些功能，都需保证第一个调用此接口完成初始化）

```objective-c
/*!
 * The initial API of MideaSDK must be the first called one if you intend to use the MideaSDK.
 *
 *
 * @param appID   - AppID,AppKey and AppSrc are assigned by Midea.
 * @param appKey  - 
 * @param appSrc  - 
 * @param mode    - the running mode of SDK
 *
 * @param completion - Async ACK(block)
 * "error" is the the result of this API. 
 * "error.code" contain:
 * 0     Succeed
 * >0    Failed. Detailed info is defined in "MSmartErrorCode" or "error.localizedDescription"
 *
 **/
- (void)initSDKWithAppID:(NSString*)appID
                  appKey:(NSString*)appKey
                  appSrc:(NSInteger)appSrc
                workMode:(MSmartWorkMode)mode
              completion:(void (^)(NSError* error))completion;
```

其中`workMode`参数选择使用的工作模式：

```objective-c
typedef NS_ENUM (NSInteger, MSmartWorkMode)
{
    MSmartWorkModeFamily = 0,//家庭组
    MSmartWorkModeFriend = 1,//单用户
};
```

示例：

```objective-c
[[MSmartSystemManager sharedManager] initSDKWithAppID:AppID
                        appKey:AppKey
                        appSrc:AppSrc
                       workMode:MSmartWorkModeFamily
                    completion:^(NSError *error) {
                       [MSTools printError:error];
                    }];
```

#### 5、选择环境：正式环境/测试环境：

```objective-c
/**
 *  修改服务器接口
 *
 *  @param serverAddress 服务器类型
 *
 *  @return 是否成功
 */
- (BOOL)setupServerAddress:(MSmartServer)serverAddress;
```

枚举值：

```objective-c
typedef NS_ENUM (NSInteger, MSmartServer) {
    MSmartServerDevelopment        = 0,//测试服
    MSmartServerProduction         = 1,//正式服
    MSmartServerOverseaDevelopment = 2,//海外版测试服
    MSmartServerOverseaProduction  = 3//海外版正式服
};
```

示例：

```objective-c
[[MSmartSystemManager sharedManager] setupServerAddress:MSmartServerProduction];
```

#### 6、设置http/https（必选）：

```objective-c
/**
 *  开启https通道，默认关闭
 *
 *  @param open - 打开或关闭
 */
- (void)openHttpsChanel:(BOOL)open;
```



## 核心业务介绍

### 1. 注册

#### 1.1. 手机号注册

​	通过手机号和验证码注册到MCloud

获取手机验证码

```objective-c
/**
 Get verify code with cell phone number.

 @since (mainland)  (group/single user)
 @param phoneNum cell phone number
 @param verifyType authenticate type,detailed definition in MSmartGetVerifyType
 @param completion Async call
 
  - error.code contains: 0 succeed >0 failed, detailed definition in MSmartErrorCode or error.localizedDescription
 */
- (void)getVerifyCodeWithPhoneNum:(NSString *)phoneNum
                           andType:(MSmartGetVerifyType)verifyType
                        completion:(void (^)(NSError *error))completion;
```

注册

```objective-c
/**
 Register an account with cell phone number.

 @since (mainland)  (group/single user)
 @note call getVerifyCodeWithPhoneNum first.
 @param phoneNum user cell phone
 @param password user password
 @param verifyCode verifyCode
 @param nickName user nickname
 @param completion Async call
 
  - error.code contains: 0 succeed >0 failed, detailed definition in MSmartErrorCode or error.localizedDescription
 */
- (void) registerWithPhoneNum:(NSString *)phoneNum
                     password:(NSString *)password
                   verifyCode:(NSString *)verifyCode
                     nickName:(NSString *)nickName
                   completion:(void (^)(NSError *error))completion;
```

#### 1.2 邮箱注册

​	通过邮箱账号注册到MCloud

​	海外环境可选择是否需要发送激活邮件，`extraDic`中key `kMSServerKeyNeedActive` 值为`kMSServerValueActiveTrue`表示需要发送邮件激活，值为`kMSServerValueActiveFalse`表示不需要发送邮件激活；

国内环境均为默认发送激活邮件；

​	目前海外环境以及国内环境登录时并未判断用户是否完成激活，即激活状态并不影响登录的成功与否。

```objective-c
/**
 Register an account with email.

 @since (mainland/overseas)  (group/single user)
 @param email user email
 @param password user password
 @param nickName user nickname
 @param extraDic extra parameter dictionary,(Please refer to MSmartDefinition.h for detailed Dictionry key.)
 
  - kMSServerKeyNeedActive：need active flag(only for overseas)
 
    - kMSServerValueActiveTrue:need active；
    - kMSServerValueActiveFalse:need not active,
 @param completion Async call
 
  - error.code contains: 0 succeed >0 failed, detailed definition in MSmartErrorCode or error.localizedDescription
 */
- (void) registerWithEmail:(NSString *)email
                  password:(NSString *)password
                  nickName:(NSString *)nickName
                  extraDic:(NSDictionary *)extraDic
                completion:(void (^)(NSError *error))completion;
```

### 2.登录

#### 2.1 通过注册的账号（手机号/邮箱）登录

​	若要使用推送功能，需在登录接口上传pushToken，`extraDic`参数中key `kMSServerKeyPushToken`传入pushToken的值

```objective-c
/**
 Login with M-cloud account. You can only login the SDK after the SDK initialization.

 @since (mainland/overseas)  (group/single user)
 @param account user account(email or phone）
 @param password user password (6-12)
 @param extraDic extra parameter dictionary (Please refer to MSmartDefinition.h for detailed Dictionry key.)
 
  - kMSServerKeyPushToken    ：push token
  - kMSServerKeyAppVNum      ：app version
  - kMSServerKeyPhoneModel   ：cell phone model
  - kMSServerKeySystemVersion：system version of cell phone
 
 @param completion Async call
 
  - error.code contains: 0 succeed >0 failed, detailed definition in MSmartErrorCode or error.localizedDescription
  - dict：user information（if error.code > 0 dict = nil),please refer to MSmartDefinition.h for detailed Dictionry key.
 
    - kMSServerKeyVersionCode:the support of app minimum version
 
  - familysOrUsers：family list in family mode；user list in friend mode
  - devices：appliance list
 */
- (void)loginWithAccount:(NSString *)account
                 password:(NSString *)password
                 extraDic:(NSDictionary *)extraDic
               completion:(void (^)(NSError *error, NSDictionary *dict, NSArray *familysOrUsers, NSArray *devices))completion;
```

### 2.2 第三方登录

​	目前支持QQ和微信登录，其中`accessToken`和`thirdUid`分别为第三方的授权访问token和第三方来源Id

```objective-c
/**
 Login with third platform token (for QQ , WeChat)

 @since (mainland)  (group/single user)
 @param accessToken access token
 @param thirdUid third ID
 @param nickName user nickname
 @param pushToken push token
 @param srcPlatform platform type，detailed definition in MSmartThirdPlatform
 @param paramters extra parameter dictionary
 
  - kMSServerKeyAppVNum
 @param completion Async call
 
  - error.code contains: 0 succeed >0 failed, detailed definition in MSmartErrorCode or error.localizedDescription
  - userInfo:user information
  - familysOrUsers:
 
    - family list in family mode；
    - user list in friend mode
  - devices：appliance list
 */
- (void)userThirdLoginWithAccessToken:(NSString *)accessToken
                             thirdUid:(NSString *)thirdUid
                             nickName:(NSString *)nickName
                            pushToken:(NSString *)pushToken
                          srcPlatform:(MSmartThirdPlatform)srcPlatform
                            paramters:(NSDictionary *)paramters
                           completion:(void (^)(NSError *error,NSDictionary *userInfo, NSArray *familysOrUsers, NSArray *devices))completion;
```

### 3. 配网

#### 3.1 AP配网

##### （1）连接家电AP:家电设备处于AP模式，手机和家电设备AP直连，建立连接，如图，调用接口

![](https://github.com/midea-sdk-org/ios-sdk/blob/master/pic/AP.png?raw=true) 

*备注：设备AP SSID前缀形如`midea_XX_XXXX`。*

```objective-c
/**
 step 2.1.1 connect to an appliance with MSmartConfigType equal to MSmartConfigAP or MSmartConfigJD. You can find the MSmartConfigType in th callback of API '- (void)getConfigureTypeByQrcode:(NSString *)qrcode
 completion:(void (^)(NSError *error,MSmartConfigType configType))completion'.
	
 **Note:** use tips:
 
  1. new appliance will be in AP(access point) mode.
  2. user need to connect to the appliance AP in the system setting manual if they are using iOS.
	
 @since (mainland/overseas)  (group/single user)
 @param ssid the SSID of appliance AP
 @param completion Async call
 
  - error.code contains: 0 succeed >0 failed, detailed definition in MSmartErrorCode or error.localizedDescription
*/
- (void)connectDeviceWithSSID:(NSString*)ssid
                    completion:(void (^)(NSError* error))completion;
```

*备注：调用此接口时手机必须和设备AP直连，即手机当前连接的wifi名称应该和`ssid`一致*

##### 示例

```objective-c
NSString *deviceSSID = @"midea_10_0287";
[[MSmartDeviceManager sharedManager] connectDeviceWithSSID:deviceSSID completion:^(NSError *error) {
if (error.code == ERROR_SUCCESS) {
    //连接成功
    [self printStr:[NSString stringWithFormat:@"连接热点成功"]];
    
} else {
    [self printStr:[NSString stringWithFormat:@"配网失败，error：%@",error]];
}o
}];
```

##### （2）绑定家电到指定wifi网络。前提：完成AP配网第一步，收到成功回调

```objective-c
/**
 step 2.2.1 If the MSmartConfigType equal to MSmartConfigAP, you can use this API to make the appliance connect to a specific network.

 @since (mainland/overseas)  (group/single user)
 @note there is a 90 seconds timeout. tip:wifi module is appliance can not support 5G wifi network.
 @param homeSSID SSID of the wifi router
 @param password password of the wifi router
 @param bssid BSSID of the wifi router：31:63:6B:D9:2F:45，it can be 00:00:00:00:00:00 if you can't get the BSSID.
 @param deviceName the name of the device, can be nil@""
 @param tsn can be nil or empty
 @param completion Async call
 
  - error.code contains: 0 succeed >0 failed, detailed definition in MSmartErrorCode or error.localizedDescription
  - dict：the information of the appliance.If the "isActivity" is 1 , that means the appliace is already activated.
 */
- (void)bindDeviceWithWifi:(NSString *)homeSSID
                  password:(NSString *)password
                 WiFiBSsid:(NSString *)bssid
                deviceName:(NSString *)deviceName
                       tsn:(NSString *)tsn
                completion:(void (^)(NSError *error, NSDictionary *dict))completion;
```

##### （3）激活家电。前提：完成AP配网第二步，收到成功回调

​	激活家电是指在云端激活设备的远程控制权限，未激活的设备无法实现远程控制；家庭组和单用户激活家电的方式有所区别，家庭组是建立设备和家庭之间的绑定关系，单用户是建立设备和单个用户的绑定关系。

###### 家庭组

```objective-c
//MSmartDeviceManager.h
/**
 激活家电，激活指激活家电的远程控制.通过SN激活（与[MSmartDeviceManager decryptSNWithQRCode:completion:]配套使用）
 
 @since (mainland)  (group)
 @param deviceSN 设备SN（明文）
 @param familyId 设备要绑定的家庭的familyId
 @param extraDic extraDic举例如下，一般从[MSmartDeviceManager decryptSNWithQRCode:completion:]获取
 
  - deviceName = "\U51b0\U7bb13306";
  - deviceSsid = "Midea_CA_3306";
  - deviceSubType = 2;
  - deviceType = CA;
  - expired = 600;
  - verificationCode = zIlcestl;
  - verificationCodeKey = 17e4c7000eb8469b;
 
 @param completion 异步执行返回(block)
 
  - error：error.code值为0表示执行成功；大于0表示执行失败；具体错误提示见 MSmartErrorCode 定义或error.localizedDescription
 */
- (void)activeDeviceWithDeviceSN:(NSString *)deviceSN
                        familyId:(NSString *)familyId
                        extraDic:(NSDictionary *)extraDic
                      completion:(void (^)(NSError *error, NSDictionary *dictionary))completion;
```

*备注：只有家庭的家长才有权限向家庭绑定设备，因此当前的登录用户必须是`familyId`代表的家庭的家长该操作才能成功。*

###### 单用户

```objective-c
//MSmartDeviceManager.h
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
```

*备注：此接口建立起设备与当前登录用户之间的绑定关系，并在云端激活设备的远程控制权限。*

示例

```objective-c
//家庭组模式示例
NSString *wifiSSID = @"APP_TEST";
NSString *pwdStr = @"88888888";
NSString *deviceName = @"客厅插座";
// 绑定设备至家庭WIFI:
[self.deviceMgr bindDeviceWithWifi:wifiSSID
                                  password:pwdStr
                                 WiFiBSsid:@"00:00:00:00:00:00"
                                deviceName:deviceName
                                       tsn:nil
                                completion:^(NSError *error, NSDictionary *dict) {
        if (error.code == ERROR_SUCCESS) {
            // 配网成功
            if(![dict[@"isActivity"] isEqualToString:@"1"]) {//设备未在云端完成绑定，继续完成绑定
            //家庭组模式：绑定设备到家庭
            [self.deviceMgr activeDeviceWithDeviceSN:dict[@"deviceSn"]
                                            familyId:familyId
                                            extraDic:nil
                                          completion:^(NSError *error, NSDictionary *dictionary) {
                if(error.code == ERROR_SUCCESS) {
                    [self printStr:[NSString stringWithFormat:@"配网成功，dic is %@",dict]];
                } else {
                    [self printStr:[NSString stringWithFormat:@"配网失败，error is %@",error]];
                }
            }];
            } else {
                [self printStr:[NSString stringWithFormat:@"配网成功,dict is %@",dict]];
            }
        } else {
            if (error.code == ERROR_NETWORK_NOT_CHANGE) {//当前手机未自动切换到所选择的wifi
                self.iHud.labelText = @"请将手机连接至选择的网络再返回本界面";
            } else {// 配网失败
                [self printStr:[NSString stringWithFormat:@"配网失败，error is %@",error]];
            }
        }
}];

//单用户模式示例
[self.deviceMgr bindDeviceWithWifi:wifiSSID password:pwdStr WiFiBSsid:@"00:00:00:00:00:00" deviceName:deviceName tsn:nil completion:^(NSError *error, NSDictionary *dict) {
      if (error.code == ERROR_SUCCESS) {
          if(![dict[@"isActivity"] isEqualToString:@"1"]) {//设备未在云端完成绑定，继续完成绑定
              //单用户模式：绑定设备到用户
              [self.deviceMgr bindDeviceWithDeviceSN:dict[@"deviceSn"] andTsn:nil 	 completion:^(NSError *error) {
                if(error.code == ERROR_SUCCESS) {
                    [self printStr:[NSString stringWithFormat:@"配网成功，dic is %@",dict]];
                } else {
                    [self printStr:[NSString stringWithFormat:@"配网失败，error is %@",error]];
                }
              }];

          } else {
              [self printStr:[NSString stringWithFormat:@"配网成功,dict is %@",dict]];
          }

      } else {
          if (error.code == ERROR_NETWORK_NOT_CHANGE) {//当前手机未自动切换到所选择的wifi
              self.iHud.labelText = @"请将手机连接至选择的网络再返回本界面";
          } else {// 配网失败
              [self printStr:[NSString stringWithFormat:@"配网失败，error is %@",error]];
          }
      }
 }];
```

#### 3.2 一机一码快连配网

说明：一机一码是指一个家电设备有一个唯一标识的二维码，能够明确知道待配网的家电设备的`deviceSSID`是什么，比如`midea_10_0078`

##### （1）前提：家电设备处于快连模式，手机和待配网的wifi直连，即当前连接的wifi名称应和`homeSSID`一致

![](https://github.com/midea-sdk-org/ios-sdk/blob/master/pic/wifi.jpg?raw=true) 

```objective-c
/**
 step 2.3.1 This API can be called if the MSmartConfigType of step 1 is MSmartConfigMSC. Once this api is called, it will not stop until get a calback or manually stop it.

 **Note:** use tips:
 
  1. new appliance will be in SmartConfig mode.
  2. app will connect wifi router
 
 @since (mainland/overseas)  (group/single user)
 @param deviceSSID appliance SSID
 @param homeSSID SSID of wifi router
 @param password password of wifi router
 @param tsn sn from the qrcode, can be nil or empty
 @param key reserve, can be nil
 @param completion Async call
 
  - error.code contains: 0 succeed >0 failed, detailed definition in MSmartErrorCode or error.localizedDescription
  - dict:appliance info
 
    - @"deviceSn":sn,                 //sn
    - @"deviceSsid":ssid,             //ssid
    - @"deviceType":typeStr,          //appliance type
    - @"identifyTime":identifyTime,   //identify time(minutes)
    - @"identifyType":identifyType    //identify mode，0--device identify，1--SDK
 */
- (void)startSendMSCWithDeviceSSID:(NSString *)deviceSSID
                          homeSSID:(NSString *)homeSSID
                          password:(NSString *)password
                               tsn:(NSString *)tsn
                               key:(NSString *)key
                        completion:(void (^)(NSError *error, NSDictionary *dict))completion; 
```

##### （2）激活家电。前提：完成配网第一步，收到成功回调，此步骤和AP配网的激活流程类似。

##### 示例

```objective-c
NSString *homeSSID = @"APP_TEST";
NSString *pwd = @"88888888";
NSString *deviceSSID = @"midea_10_0078";
NSString *tsn= @"";
[[MSmartDeviceManager sharedManager] startSendMSCWithDeviceSSID:deviceSSID homeSSID:homeSSID password:pwd tsn:tsn key:nil completion:^(NSError *error, NSDictionary *dict) {
    if(error.code == ERROR_SUCCESS) {
        //激活家电，参见AP配网激活家电步骤
    } else {
        [self printStr:[NSString stringWithFormat:@"配网失败，error：%@",error]];
    }
}];  
```

#### 3.3 一型一码快连配网

说明：一型一码是指一类家电设备共用同一个二维码，无法具体知道家电设备的`deviceSSID`是什么，只能确定家电的设备类型，比如空调，类型为`0xAC`

##### （1）前提：家电设备处于快连模式，手机和待配网的wifi直连，即当前连接的wifi名称应和`homeSSID`一致

![](https://github.com/midea-sdk-org/ios-sdk/blob/master/pic/wifi.jpg?raw=true) 

```objective-c
/**
step 2.3.1 This API can be called if the MSmartConfigType of step 1 is MSmartConfigMSC_OneType. Once this api is called, it will not stop until get a calback or manually stop it.

@since (mainland/overseas)  (group/single user)
@param deviceType Appliance type. eg:0xAC AC
@param homeSSID SSID of wifi router
@param password password of wifi router
@param tsn tsn from qrcode, can be nil
@param extension extension,can be nil
@param key reserve,can be nil
@param completion Async call

- error.code contains: 0 succeed >0 failed, detailed definition in MSmartErrorCode or error.localizedDescription
- dict:the information of appliance
*/
- (void)startNewSendMSCWithDeviceType:(NSString *)deviceType
                           homeSSID:(NSString *)homeSSID
                           password:(NSString *)password
                                tsn:(NSString *)tsn
                          extension:(NSString *)extension
                                key:(NSString *)key
                         completion:(void (^)(NSError *err, NSDictionary *dict))completion;
```

##### （2）激活家电。前提：完成配网第一步，收到成功回调，此步骤和AP配网的激活流程类似。

##### 示例

```objective-c
NSString *homeSSID = @"APP_TEST";
NSString *pwd = @"88888888";
NSString *deviceType = @"0xAC";
NSString *tsn= @"";
[[MSmartDeviceManager sharedManager] startNewSendMSCWithDeviceType:deviceType homeSSID:homeSSID password:pwd tsn:tsn extension:nil key:nil completion:^(NSError *err, NSDictionary *dict) {
  if(err.code == ERROR_SUCCESS) {
      //激活家电，参见AP配网激活家电步骤
  } else {
      [self printStr:[NSString stringWithFormat:@"配网失败，error：%@",err]];
  }
}]; 
```

### 4. 获取设备控制权限

#### 4.1 家庭组模式

​	家庭组模式下，设备是和一个家庭建立的绑定关系，因此获取设备的控制权限，是通过加入设备所在家庭来获取，用户加入一个家庭，可以获取该家庭下所有设备的控制权限

##### （1）家庭的家长邀请用户加入家庭，用户应答（同意/不同意）

```objective-c
/**
 邀请用户加入家庭:家长邀请某个用户加入某个家庭，接口调用成功，会推送一条消息给该用户，若该用户同意则加入家庭成功

 @since (mainland)  (group)
 @param familyID 家庭Id
 @param account 邀请成员的邮箱或者手机号
 @param completion 异步执行返回(block)
 
  - error：error.code值为0表示执行成功；大于0表示执行失败；具体错误提示见 MSmartErrorCode 定义或error.localizedDescription
 */
- (void) inviteFamilyMemberWithFamilyID:(NSString *)familyID
                                account:(NSString *)account
                             completion:(void(^)(NSError *error))completion;
```

```objective-c
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
```

##### （2）用户向家庭的家长申请加入家庭，家庭家长应答（同意/不同意）

```objective-c
/**
 加入家庭：用户申请加入某个家庭，将接口调用成功，会推送一条消息给该家庭的家长，若该家庭的家长同意则加入家庭成功

 @param familyID 申请加入的家庭Id
 @param completion 异步执行返回(block)
 
  - error：error.code值为0表示执行成功；大于0表示执行失败；具体错误提示见 MSmartErrorCode 定义或error.localizedDescription
 */
- (void)joinFamilyWithFamilyID:(NSString *)familyID
                     completion:(void(^)(NSError *error))completion;
```

```objective-c
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
```

#### 4.2 单用户模式

​	单用户模式下，设备是和单个用户建立的绑定关系，因此获取设备的控制权限，是通过设备主人对用户提供分享获取。

##### （1）设备主人主动向用户分享设备，用户应答（同意/不同意）

```objective-c
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
```

```objective-c
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
```

##### （2）用户向设备主人申请分享设备，主人应答（同意/不同意）

##### 

```objective-c
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
```

```objective-c
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
```

### 5. 推送

#### 5.1 登录时上传pushToken，参见登录接口

##### 示例

```objective-c
#pragma mark - 接收从苹果服务器返回的唯一的设备token
- (void)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken
{
    
    NSString *DeviceToken = [[deviceToken description] stringByTrimmingCharactersInSet:[NSCharacterSet characterSetWithCharactersInString:@"<>"]] ;
    NSString *pushToken = [NSString stringWithString:[DeviceToken stringByReplacingOccurrencesOfString:@" " withString:@""]];
    NSLog(@"设备推送:pushToken:%@", pushToken);
    [MSPushManager sharedMSPushManager].pushToken = pushToken;
}

- (void)login {
       NSMutableDictionary *extraDic = nil;
       if ([MSPushManager sharedMSPushManager].pushToken) {
            extraDic = [NSMutableDictionary dictionary];
            [extraDic setValue:[MSPushManager sharedMSPushManager].pushToken forKey:kMSServerKeyPushToken];
        }
        
        [self.userMgr loginWithAccount:self.usernameTF.text password:self.passwordTF.text extraDic:extraDic completion:^(NSError *error, NSDictionary *dict, NSArray *familysOrUsers, NSArray *devices) {

        }];
}
```

#### 5.2 根据pushId获取推送消息

​	应用将获取到的pushId调用此接口获取完整的推送信息

```objective-c
//MSmartServerManager.h
  
/*!
 *  根据pushId获取推送消息
 *
 *  @param pushId     推送获取的pushId
 *  @param completion  - 异步执行返回(block)
 *                     - error：error.code值为0表示执行成功；大于0表示执行失败；具体错误提示见MSmartErrorCode定义或error.localizedDescription
 *                     - content：为推送的内容字典
 */
- (void)pushContentGetWithPushId:(NSString *)pushId
                      completion:(void (^)(NSError *error,NSDictionary *content))completion;
```

*备注：用户重复登录该推送为操作推送，无须通过`pushId`去获取推送完整信息*

```
//用户重复登录推送消息示例
{"pushName":"user/login","userId":"1000"}
```

#### 5.3 处理推送消息

​	将获取到的完整的推送信息调用此接口，首先返回该信息是否有效，若返回为`NO`表示该信息无效，若返回为`YES`表示信息有效并被处理，处理结果通过通知的方式返回

```objective-c
//MSmartTransportManager.h

/*!
 * 处理推送消息
 *
 * @param message 收到的美居推送消息
 * @return true 表示传入的message有效，false表示传入的message无效
 */
- (BOOL)handlePushMessage:(NSString *)message;
```

#### 5.4 推送消息处理结果的通知`PushNotification`

```objective-c
[[NSNotificationCenter defaultCenter] addObserver:observer selector:@selector(方法名:) name:PushNotification object:nil];
```

来监听SDK推送的处理结果。

*备注：关于`PushNotification`详细说明请参见`MSmartTransportManager.h`文件*

**示例**

```objective-c
//AppDelegate.m
- (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo
{
    NSLog(@"推送消息%@",userInfo);
    if([userInfo[@"pushName"] isEqualToString:@"user/login"]) {//用户重复登录
        NSLog(@"账号在其他地方登录");
    } else {
        [[MSPushManager sharedMSPushManager] getPushContent:userInfo];
    }
}


//MSPushManager.m
- (MSPushManager *)init {
    self = [super init];
    if (self) {
      //注册推送通知
        [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(responsePushNotification:) name:PushNotification object:nil];
        
    }
    return self;
}

- (void)dealloc {
    //移除通知
    [[NSNotificationCenter defaultCenter] removeObserver:self];
}

- (void)getPushContent:(NSDictionary *)dic {
  //APP收到的服务器端推送的pushID  
  NSString *pushId = dic[@"pushId"];
  //根据pushID调用SDK接口获取完整推送信息
  [[MSmartServerManager sharedManager] pushContentGetWithPushId:pushId completion:^(NSError *error, NSDictionary *content) {
        if(error.code == ERROR_SUCCESS) {
            [self pushRemoteToSlkWithDictionary:content[@"result"][@"content"]];
        }
    }]; 
}

#pragma mark - 经过SDK的推送
- (void)pushRemoteToSlkWithDictionary:(NSString *)pushString {

    NSLog(@"经过sdk的推送:%@",pushString);
    NSString *pushContent;
    if ((pushString.length < 1)||([pushString isEqualToString:@""])||(pushString == nil))     
    {
        return ;
    } else {
        //增加SDK识别有效推送信息的前缀
        pushContent = [NSString stringWithFormat:@"%@%@",@"{\"message\":", pushString];
    }
    //处理推送信息
    BOOL result = [[MSmartTransportManager sharedManager] handlePushMessage:pushContent];
}

//收到SDK对推送处理通知后所要处理的业务
- (void)responsePushNotification:(NSNotification *)sender {
    NSMutableDictionary *pushMessageDic = [NSMutableDictionary dictionaryWithDictionary:sender.object];
  
    NSLog(@"PushNotification推送消息推送---->::%@",pushMessageDic);
}
```

### 6. 设备控制

#### 6.1 通过透传指令控制

​	将设备的控制指令（具体指令内容根据不同品类设备电控协议不同，详细需咨询对应品类事业部）透传，控制结果以通知的形式通知给应用。

```objective-c
//MSmartTransportManager.h
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
```

##### 示例

```objective-c
- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:NO];
    [self configNotification];
}

- (void)viewWillDisappear:(BOOL)animated {
    [super viewWillDisappear:NO];
    [self removeNotification];
}
// 发送指令
- (IBAction)sendCMD:(id)sender {
    
    //诸如指令内容是0xaa14e20032,
    NSString *cmdString = @"aa14e20032";
    NSArray *cmdArray = [self stringToArry:cmdString]//@[@"aa",@"14",@"e2",@"00",@"32"];
    self.tag = arc4random() % UINT16_MAX;
    [self.transportMgr sendDataWithDeviceID:self.iDevice.deviceId
                                  tempArray:cmdArray
                                        tag:self.tag];
    [MSTools showHudWithStr:@"发送指令中..." inView:self.navigationController.view];
}

#pragma mark - 透传回调
- (void)responseAfterSend:(NSNotification *)note {
    
    NSDictionary *dict = (NSDictionary *)note.object;
    NSError *error = dict[ @"error" ];
    NSString *tagStr = dict[@"tag"];
    int tagId = [tagStr intValue];
    NSString *deviceId = dict[@"deviceId"];
    
    if((tagId == self.tag) && ([deviceId isEqualToString:self.iDevice.deviceId])) {
        if(error.code == 0) {
            [MSTools showAlert:@"执行成功"];
        } else {
            [MSTools showAlert:@"执行失败"];
        }
    }
}

- (void)configNotification {
    //设置监听
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(responseAfterSend:) name:TransportNotification object:nil];
}

- (void)removeNotification {
    //移除监听
    [[NSNotificationCenter defaultCenter] removeObserver:self name:TransportNotification object:nil];
}

#pragma mark - string转化为array
- (NSArray *)stringToArry:(NSString *)str {
    NSMutableArray *array = [[NSMutableArray alloc]init];
    int length = (int)[str length];
    for (int i = 0;i < length/2;i++) {
        NSString *sub_str = [[NSString alloc]initWithString:[str substringWithRange:NSMakeRange(i*2, 2)]];
        [array addObject:sub_str];
    }
    return array;
}
```

#### 6.2 通过lua脚本控制

##### （1）将开放平台上下载的控制协议脚本放在以`lua`命名的文件夹中，如图所示。

![](https://github.com/midea-sdk-org/ios-sdk/blob/master/pic/lua%E6%96%87%E4%BB%B6%E5%A4%B9%E7%A4%BA%E4%BE%8B.png?raw=true) 

*备注：脚本文件与申请的`appId`以及`appKey`关联，必须使用对应脚本文件*

**（2）在项目工程`Copy Bundle Resources` 中添加上述的`lua`文件夹，如图所示。**

![](https://github.com/midea-sdk-org/ios-sdk/blob/master/pic/%E5%AF%BC%E5%85%A5lua%E6%96%87%E4%BB%B6%E7%A4%BA%E4%BE%8B.png?raw=true) 

##### （3）调用SDK接口

- 根据`deviceId`查询设备当前状态

```objective-c
/**
 Query appliance status

 @since (mainland/overseas)  (group/single user)
 @param deviceId appliance ID
 @param completion Async call
 
  - error.code contains: 0 succeed >0 failed, detailed definition in MSmartErrorCode or error.localizedDescription
  - dict:appliance current status
 */
- (void)queryDeviceWithId:(NSString *)deviceId
               completion:(void (^)(NSError *error, NSDictionary *dict))completion;
```

##### 示例

```objective-c
[[MSmartDeviceManager sharedManager] queryDeviceWithId:self.currentDevice.deviceId 
       completion:^(NSError *error, NSDictionary *dict) {
        if (error.code == 0) {
            NSLog(@"dict is \n%@",dict);
        }
        else {
            NSLog(@"error.code is %@",error.localizedDescription);
        }
    }]; 
```

执行结果：

![](https://github.com/midea-sdk-org/ios-sdk/blob/master/pic/%E6%9F%A5%E8%AF%A2%E8%BF%94%E5%9B%9E%E5%AD%97%E5%85%B8.jpeg?raw=true)



*备注：`dict`中key-value表示设备的属性及属性当前的值，具体参考设备属性文档*

- 根据`deviceId`和控制意图字典控制设备

```objective-c
/**
 Appliance status control

 @since (mainland/overseas)  (group/single user)
 @param deviceId appliance ID
 @param operationDic control information dictionary
 @param completion Async call
 
  - error.code contains: 0 succeed >0 failed, detailed definition in MSmartErrorCode or error.localizedDescription
  - dict:appliance new status
 */
- (void)controlDeviceWithId:(NSString *)deviceId
               operationDic:(NSDictionary *)operationDic
                 completion:(void (^)(NSError *error, NSDictionary *dict))completion;
```

##### 示例：控制（空调电源打开、模式设为制热模式、温度设为28度、左右扫风打开、上下扫风打开）

```objective-c
NSDictionary *controlDic = @{@"power":@"on",
                             @"mode":@"heat",
                             @"temperature":@(28),
                             @"wind_swing_lr":@"on",
                             @"wind_swing_ud":@"on"
                                 };
[[MSmartDeviceManager sharedManager] controlDeviceWithId:self.currentDevice.deviceId 
                         operationDic:controlDic 
                           completion:^(NSError *error, NSDictionary *dict) {
        if (error.code == 0) {
            NSLog(@"dict is \n%@",dict);
        }
        else {
            NSLog(@"error.code is %@",error.localizedDescription);
        }
    }]; 
```

执行结果：

![](https://github.com/midea-sdk-org/ios-sdk/blob/master/pic/%E6%8E%A7%E5%88%B6%E8%BF%94%E5%9B%9E%E5%AD%97%E5%85%B8.jpeg?raw=true)                 

*备注：`operationDic`以及`dict`中key-value表示设备的属性及属性的值，具体参考设备属性文档*



## 技术支持

王攀(pan.wang@midea.com)

[Issues](https://github.com/midea-sdk-org/ios-sdk/issues/new)

## API文档

[接口文档](http://htmlpreview.github.io/?https://github.com/midea-sdk-org/ios-sdk/blob/master/html/index.html) 

[改动日志](https://github.com/midea-sdk-org/ios-sdk/blob/master/ChangeLog.md)   

## SDK下载

[下载地址](https://github.com/midea-sdk-org/ios-sdk/releases) 