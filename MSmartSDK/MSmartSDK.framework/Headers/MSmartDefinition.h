//
//  MSmartDefinition.h
//  MSmartSDK
//
//  Created by yellowsea on 15/5/19.
//  Copyright (c) 2015年 yellowsea. All rights reserved.
//

#import <Foundation/Foundation.h>



/**
 工作模式 Work mode

 - MSmartWorkModeFamily: 家庭组模式 family mode
 - MSmartWorkModeFriend: 单用户模式 friend mode
 */
typedef NS_ENUM (NSInteger, MSmartWorkMode)
{
    MSmartWorkModeFamily = 0,
    MSmartWorkModeFriend = 1,
};


/**
 智慧云服务器地址 M-Cloud server type

 - MSmartServerDevelopment: 国内测试环境 mainland development
 - MSmartServerProduction: 国内正式环境 mainland production
 - MSmartServerOverseaDevelopment: 海外测试环境 overseas development
 - MSmartServerOverseaProduction: 海外正式环境 overseas production
 */
typedef NS_ENUM (NSInteger, MSmartServer) {
    
    MSmartServerDevelopment        = 0,
    MSmartServerProduction         = 1,
    MSmartServerOverseaDevelopment = 2,
    MSmartServerOverseaProduction  = 3
};

typedef NS_ENUM (NSInteger,MSmartNetworkState)
{
    MSmartNetUnknown      = -1,
    MSmartNetNotReachable = 0,
    MSmartNetWWAN,
    MSmartNetWiFi
};

typedef NS_ENUM (NSInteger,WifiSecurityType)
{
    MDWifiSecurityNone = 0,
    MDWifiSecurityWEP  = 1,
    MDWifiSecurityWPA  = 2
    
};

typedef NS_ENUM (NSInteger,MSmartAssistantType)
{
    MSmartAssistantType_Air       = 1,
    MSmartAssistantType_Nutrition = 2,
    MSmartAssistantType_Water     = 3,
    MSmartAssistantType_Security  = 4,
    
};

/**
 验证码类型 Verify code type

 - MSmartGetVerifyType_Register: 注册验证码 register
 - MSmartGetVerifyType_ModifyPassword: 修改密码验证码 modify password
 - MSmartGetVerifyType_BindMobile: 绑定手机验证码 bind mobile
 */
typedef NS_ENUM (NSInteger,MSmartGetVerifyType)
{
    MSmartGetVerifyType_Register        = 1,
    MSmartGetVerifyType_ModifyPassword  = 2,
    MSmartGetVerifyType_BindMobile      = 3,
};


typedef NS_ENUM (NSInteger,MSmartThirdPlatform)
{
    MSmartThirdPlatform_QQ        = 1,
    MSmartThirdPlatform_WeiChat   = 2,
    
};


typedef NS_ENUM (NSInteger,MSmartConfigType)
{
    MSmartConfigNone = 0,
    MSmartConfigAP   = 1,
    MSmartConfigMSC  = 2,
    MSmartConfigJD   = 3,
    MSmartConfigAP_OneType  = 4, //!< 一型一码AP
    MSmartConfigMSC_OneType = 5, //!< 一型一码MSC（快连）
};


/**
 推送类型 push type

 - RemotePushType_User_Login: 用户在其他地方登陆 Account login in another device
 - RemotePushType_Device_Status: 家电特殊状态上报 Special Status reporting
 - RemotePushType_Family_Delete: 家庭被家长删除 Family was deleted by owner
 - RemotePushType_Member_Add: 邀请成员加入家庭 Invite members to join the family
 - RemotePushType_Member_Add_Respond: 邀请成员加入家庭响应 The response of invite members to join the family
 - RemotePushType_Member_Delete: 删除家庭成员 Remove family members
 - RemotePushType_Member_Join_Send: 申请加入家庭 Apply to join the family
 - RemotePushType_Member_Join_Response: 申请加入家庭响应 The response of apply to join the family
 - RemotePushType_Member_Quite: 成员退出家庭 Members quit the family
 - RemotePushType_Device_On: 家电上线推送 Device online
 - RemotePushType_Device_Off: 家电离线推送 Device offline
 - RemotePushType_Device_Reactivity: 家电再次激活(家电被其他家庭激活) Device actived again
 - RemotePushType_Device_UpdateId: 家电更新DID Device update deviceId
 - RemotePushType_Device_Add: 添加家电(家长向家庭中添加家电，家庭成员收到此推送) Add device to family by owner
 - RemotePushType_Device_Delete: 删除家电(家长删除家庭中的家电，家庭成员收到此推送) Remove device from family by owner
 - RemotePushType_Device_Share: 家电分享-主人发送分享 the device share from owner
 - RemotePushType_Device_Share_Response: 家电分享响应 the reply of the device share from owner
 - RemotePushType_Beg_Device_Share: 请求家电分享 Request device to share
 - RemotePushType_Beg_Device_Share_Response: 请求家电分享响应 The reply of request device to share
 - RemotePushType_Device_Share_Cancel: 家电主人撤销分享 Cancel the share by owner
 - RemotePushType_Device_Owner_Delete: 家电主人删除家电 Delete device by owner
 - RemotePushType_Pro2Base: 应用服务器推送(主应用接收)
 - RemotePushType_B2BDevice_Alert: b2b警戒推送 B2B Alert
 - RemotePushType_B2BDevice_Dealarm: <#RemotePushType_B2BDevice_Dealarm description#>
 - RemotePushType_Device_Fault: 家电故障 Device fault
 - RemotePushType_Gas_Alarm: 警告燃气警告 Gas Alert
 - RemotePushType_Device_Update_Request: 设备升级请求 Device update request
 - RemotePushType_Device_Update_Feedback: 设备升级结果 The result of the update of device
 - RemotePushType_Mcloudbox_Msg: 美居热水器温度到达
 */
typedef NS_ENUM (NSInteger,RemotePushType)
{
    RemotePushType_User_Login                = 0,
    RemotePushType_Device_Status             = 1,
    RemotePushType_Family_Delete             = 2,
    RemotePushType_Member_Add                = 3,
    RemotePushType_Member_Add_Respond        = 4,
    RemotePushType_Member_Delete             = 5,
    RemotePushType_Member_Join_Send          = 6,
    RemotePushType_Member_Join_Response      = 7,
    RemotePushType_Member_Quite              = 8,
    RemotePushType_Device_On                 = 9,
    RemotePushType_Device_Off                = 10,
    RemotePushType_Device_Reactivity         = 11,
    RemotePushType_Device_UpdateId           = 12,
    RemotePushType_Device_Add                = 13,
    RemotePushType_Device_Delete             = 14,
    RemotePushType_Device_Share              = 15,
    RemotePushType_Device_Share_Response     = 16,
    RemotePushType_Beg_Device_Share          = 17,
    RemotePushType_Beg_Device_Share_Response = 18,
    RemotePushType_Device_Share_Cancel       = 19,
    RemotePushType_Device_Owner_Delete       = 20,
    RemotePushType_Pro2Base                  = 21,
    RemotePushType_B2BDevice_Alert           = 22,
    RemotePushType_B2BDevice_Dealarm         = 23,
    RemotePushType_Device_Fault              = 24,
    RemotePushType_Gas_Alarm                 = 25,
    RemotePushType_Device_Update_Request     = 26,
    RemotePushType_Device_Update_Feedback    = 27,
    RemotePushType_Mcloudbox_Msg             = 28
};

typedef NS_ENUM(NSInteger, BleNotifyType)
{
    BleNotifyType_DidUpdateCentralState                         = 0,//!< 蓝牙开关状态
    BleNotifyType_DidDiscoverPeripheral                         = 1,//!< 发现蓝牙设备
    BleNotifyType_DidConnectPeripheral                          = 2,//!< 蓝牙设备连上
    BleNotifyType_DidDisconnectPeripheral                       = 3,//!< 蓝牙设备断开
    BleNotifyType_DidFailToConnectPeripheral                    = 4,//!< 蓝牙设备连接失败
    BleNotifyType_DidDiscoverServices                           = 5,//!< 发现蓝牙服务
    BleNotifyType_DidDiscoverCharacteristicsForService          = 6,//!< 发现服务的特征
    BleNotifyType_DidDiscoverDescriptorsForCharacteristic       = 7,//!< 发现特征的特征描述
    BleNotifyType_DidUpdateValueForCharacteristic               = 8,//!< 收到特征上的数据更新
    BleNotifyType_DidUpdateValueForDescriptor                   = 9,//!< 收到特征描述上的数据更新
    BleNotifyType_DidUpdateNotificationStateForCharacteristic   = 10,//!< 订阅状态通知
    BleNotifyType_DidWriteValueForCharacteristic                = 11,//!< 写特征值响应
    BleNotifyType_DidWriteValueForDescriptor                    = 12,//!< 写特征描述响应
    BleNotifyType_DidUpdatePeripheralRSSI                       = 13,//!< 设备信号RSSI更新通知
    BleNotifyType_DidUpdatePeripheralName                       = 14,//!< 设备更名通知
};

typedef NS_ENUM(NSInteger, BindDeviceInWiFiResultType)
{
    BindDeviceInWiFiResultType_SUCC           = 0,//!< 成功
    BindDeviceInWiFiResultType_VID_ERROR      = 1,//!< 设备id错误
    BindDeviceInWiFiResultType_SSID_ERROR     = 2,//!< 写入WiFi的ssid错误
    BindDeviceInWiFiResultType_PWD_ERROR      = 3,//!< 写入WiFi的密码错误
    BindDeviceInWiFiResultType_PWD_SSID_ERROR = 4,//!< 写入WiFi的ssid错误或密码错误
};


typedef NS_ENUM(NSInteger,MSmartIFlyDeviceType)
{
    MSmartIFlyDeviceUnknown,
    MSmartIFlyDevicePlug                = 0x10,/**< 智能插座*/
    MSmartIFlyDeviceRemoteController    = 0x11,/**< 远程中控*/
    MSmartIFlyDeviceAirBox              = 0x12,
    MSmartIFlyDeviceLight               = 0x13,/**< 智彩灯*/
    MSmartIFlyDeviceCurtain             = 0x14,/**< 窗帘*/
    MSmartIFlyDeviceMBox                = 0x1B,
    
    MSmartIFlyDeviceAirDryer            = 0xA1,/**< 除湿器*/
    MSmartIFlyDeviceAirCondition        = 0xAC,/**< 空调*/
    
    MSmartIFlyDeviceMicroWaveOven       = 0xB0,/**< 微波炉*/
    MSmartIFlyDeviceBigOven             = 0xB1,/**< 大烤箱*/
    MSmartIFlyDeviceSteamerOven         = 0xB2,/**< 蒸汽炉*/
    MSmartIFlyDeviceSterilizer          = 0xB3,/**< 消毒柜*/
    MSmartIFlyDeviceToaster             = 0xB4,/**< 小烤箱/面包机*/
    MSmartIFlyDeviceHood                = 0xB6,/**< 抽油烟机*/
    MSmartIFlyDeviceHob                 = 0xB7,/**< 铁板烧*/
    MSmartIFlyDeviceVacuumCleaner       = 0xB8,/**< 吸尘器*/
    MSmartIFlyDeviceInduction           = 0xB9,/**< 多头炉*/
    
    MSmartIFlyDeviceRefrigerator        = 0xCA,/**< 冰箱*/
    MSmartIFlyDeviceMDV                 = 0xCC,/**< 中央空调、风管机*/
    MSMartIFlyDeviceAirWaterHeater      = 0xCD,/**< 空气能热水器*/
    
    MSmartIFlyDevicePulsatorWasher      = 0xDA,/**< 波轮洗衣机*/
    MSmartIFlyDeviceDurmWasher          = 0xDB,/**< 滚筒洗衣机*/
    MSmartIFlyDeviceClothesDryer        = 0xDC,/**< 干衣机*/
    
    MSmartIFlyDeviceDishWasher          = 0xE1,/**< 洗碗机*/
    MSmartIFlyDeviceElectricWaterHeater = 0xE2,/**< 电热水器*/
    MSmartIFlyDeviceGasWaterHeater      = 0xE3,/**< 电热水器*/
    MSmartIFlyDeviceRiceCooker          = 0xEA,/**< 电饭煲*/
    MSmartIFlyDeviceInductionCooker     = 0xEB,/**< 电磁炉*/
    MSmartIFlyDevicePressureCooker      = 0xEC,/**< 压力锅*/
    MSmartIFlyDeviceWaterPurifier       = 0xED,/**< 净饮机*/
    MSmartIFlyDeviceSoybeanMachine      = 0xEF,/**< 豆浆机*/
    
    
    MSmartIFlyDeviceElectricFanner      = 0xFA,/**< 电风扇*/
    MSmartIFlyDeviceElectricHeater      = 0xFB,/**< 电暖器*/
    MSmartIFlyDeviceAirPurifier         = 0xFC,/**< 空气净化器*/
    MSmartIFlyDeviceHumidiffer          = 0xFD,/**< 加湿器*/
    MSmartIFlyDeviceAirConditionFanner  = 0xFE,/**< 空调扇*/
    
    MSmartIFlyDeviceAllType             = 0xFF,/**< 广播地址*/
};

#pragma mark -------------------- Dictionary key --------------------

FOUNDATION_EXTERN NSString *const kMSServerKeyLongitudes;    //!< 家电经度
FOUNDATION_EXTERN NSString *const kMSServerKeyLatitudes;     //!< 家电纬度
FOUNDATION_EXTERN NSString *const kMSServerKeyCountryId;     //!< 国家
FOUNDATION_EXTERN NSString *const kMSServerKeyProvinceId;    //!< 省级
FOUNDATION_EXTERN NSString *const kMSServerKeyCityId;        //!< 市县级
FOUNDATION_EXTERN NSString *const kMSServerKeyStreet;        //!< 街道名
FOUNDATION_EXTERN NSString *const kMSServerKeyStreetNumber;  //!< 街道门牌号
FOUNDATION_EXTERN NSString *const kMSServerKeytradeInfo;     //!< 商圈信息
FOUNDATION_EXTERN NSString *const kMSServerKeyAppVNum;       //!< 用户使用的软件版本号
FOUNDATION_EXTERN NSString *const kMSServerKeyPhoneModel;    //!< 用户使用的手机型号
FOUNDATION_EXTERN NSString *const kMSServerKeySystemVersion; //!< 用户使用的手机系统版本
FOUNDATION_EXTERN NSString *const kMSServerKeyVersionCode;   //!< 强制升级配置,美居app 最低版本要求
FOUNDATION_EXTERN NSString *const kMSServerKeyPushToken;     //!< 推送token
FOUNDATION_EXTERN NSString *const kMSServerKeyNeedActive;    //!< 邮箱注册是否需要激活
FOUNDATION_EXTERN NSString *const kMSServerKeyUploadInfoKey;//!<待上传文件的key名称
FOUNDATION_EXTERN NSString *const kMSServerKeyUploadInfoContent;//!<待上传文件的内容（NSData）
FOUNDATION_EXTERN NSString *const kMSServerKeyUploadInfoType;//!<待上传文件的MIME类型

FOUNDATION_EXTERN NSString *const kMSSDKSubAccount;//!<子账号
FOUNDATION_EXTERN NSString *const kMSSDKRkey;//!<随机码
FOUNDATION_EXTERN NSString *const kMSSDKUuid;//!<uuid
FOUNDATION_EXTERN NSString *const kMSSDKQRCode;//!<二维码字符串
    
#pragma mark -------------------- Dictionary value --------------------
FOUNDATION_EXTERN NSString *const kMSServerValueActiveTrue;    //!< 邮箱注册需要激活
FOUNDATION_EXTERN NSString *const kMSServerValueActiveFalse;   //!< 邮箱注册不需要激活
