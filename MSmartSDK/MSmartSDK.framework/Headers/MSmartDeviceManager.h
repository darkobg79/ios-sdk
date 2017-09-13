//
//  MSmartDeviceManager.h
//  MSmartSDK
//
//  Created by yellowsea on 15/5/19.
//  Copyright (c) 2015年 yellowsea. All rights reserved.
//

#import "MSmartBaseManager.h"
#import "MSmartDefinition.h"

@interface MSmartDeviceManager : MSmartBaseManager

/**
 The singleton of appliance manager.

 @since (mainland/overseas)  (group/single user)
 @return the singleton of appliance manager
 
 **Example:**

 MSmartDeviceManager* manager = [MSmartDeviceManager sharedManager];
 
 [manager MSmartTestModel:@"join us!"];
 */
+ (MSmartDeviceManager *)sharedManager;

/**
 Get the SSID of the wifi network connected

 @since (mainland/overseas)  (group/single user)
 @return connected wifi SSID.
 */
- (NSString *)getCurrentSSID;

/**
 step 1. get the network configuration mode from qrcode string

 @since (mainland/overseas)  (group/single user)
 @param qrcode qrcode string
 @param completion Async call
 
  - error.code contains: 0 succeed >0 failed, detailed definition in MSmartErrorCode or error.localizedDescription
  - configType：network config mode,detailed definition in MSmartConfigType of MSmartDefinition.h
 */
- (void)getConfigureTypeByQrcode:(NSString *)qrcode
                      completion:(void (^)(NSError *error,MSmartConfigType configType))completion;

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

/**
 step 2.1.2 get available wifi list around the appliance.

 @since (mainland/overseas)  (group/single user)
 @note this API can only called after the cell phone connect to an appliance AP.
 @param completion Async call
 
  - error.code contains: 0 succeed >0 failed, detailed definition in MSmartErrorCode or error.localizedDescription
  - array:wifi list array
    
    - miType = 0; // WifiSecurityType
    - ssid = MideaTestNetwork; //wifi SSID
 */
- (void)getWifiList:(void (^)(NSError *error, NSArray *array))completion;

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

/**
 stop wifi connecting

 @since (mainland/overseas)  (group/single user)
 @param completion Async call
 
  - error.code contains: 0 succeed >0 failed, detailed definition in MSmartErrorCode or error.localizedDescription
 */
- (void)stopBindDeviceWithCompletion:(void (^)(NSError *error))completion;

/**
 step 2.2.2 use this API if the MSmartConfigType of step 1 is MSmartConfigJD. bind the appliance to a specific wifi network. there is no timeout, you need to call stopConfigureJDDevice to stop the connecting.

 @since (mainland)  (group/single user)
 @param homeSSID SSID of wifi router
 @param password the password of wifi router
 @param securityType wifi encryption mode. defined in WifiSecurityType,please use MDWifiSecurityNone if it is a open network
 @param deviceSSID the Appliance SSID
 @param tsn can be nil or empty
 @param completion Async call
 
  - error.code contains: 0 succeed >0 failed, detailed definition in MSmartErrorCode or error.localizedDescription
 */
- (void)startConfigureJDDeviceWithWifi:(NSString *)homeSSID
                              password:(NSString *)password
                          securityType:(WifiSecurityType)securityType
                            deviceSSID:(NSString *)deviceSSID
                                   tsn:(NSString *)tsn
                            completion:(void (^)(NSError *error, NSDictionary *dict))completion;

/**
 step 2.2.3 it can be use with startConfigureJDDeviceWithWifi

 @since (mainland)  (group/single user)
 @param completion Async call
 
  - error.code contains: 0 succeed >0 failed, detailed definition in MSmartErrorCode or error.localizedDescription
 */
- (void)stopConfigureJDDeviceWithCompletion:(void (^)(NSError *error))completion;

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

/**
 step 2.3.2 this api is work with startSendMSCWithDeviceSSID.

 @since (mainland/overseas)  (group/single user)
 @param completion Async call
 
  - error.code contains: 0 succeed >0 failed, detailed definition in MSmartErrorCode or error.localizedDescription
 */
- (void)stopSendMSCWithCompletion:(void (^)(NSError *error))completion;

/**
 Once MSCconfig is called, it will not stop until get a calback or manually stop it.

 @since (mainland/overseas)  (group/single user)
 @param homeSSID SSID of wifi router
 @param password password of wifi router
 @param key reserve, can be nil
 */
- (void)sendMSCPacketWithHomeSSID:(NSString *)homeSSID
                         password:(NSString *)password
                              key:(NSString *)key;

/**
 this api is work with sendMSCPacketWithHomeSSID.
 
 @since (mainland/overseas)  (group/single user)
 */
- (void)stopSendMSCPacket;

#pragma mark - 一型一码快连

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

/**
 Get subtype of appliance

 @since (mainland/overseas)  (group/single user)
 @param deviceSSID SSID of appliance
 @param completion Async call
 
  - error.code contains: 0 succeed >0 failed, detailed definition in MSmartErrorCode or error.localizedDescription
  - subtype:subtype of appliance
 */
- (void)getDeviceSubTypeWithDeviceSSID:(NSString *)deviceSSID
                            completion:(void (^)(NSError *error,NSString *subtype))completion;

#pragma mark - 添加已配置设备

/**
 Scan appliances in current wifi network. this API must be call before any appliace related API.

 **Note:** Contain two kinds of appliances:
 
  1. configured device: this appliance is already connect to the router, but it is not added to SDK.
  2. added device: this appliance is already stored in the SDK Database.
 
 @since (mainland/overseas)  (group/single user)
 @param completion Async call
 
  - error.code contains: 0 succeed >0 failed, detailed definition in MSmartErrorCode or error.localizedDescription
  - configDeviceList：added devices
  - deviceList: configured but not added device
 
    - deviceId = 17592196255167;
    - deviceName = "\U7a7a\U8c030009";
    - deviceSn = 000000D110001234515B032B00090000;
    - deviceSsid = "midea_ac_0009";
    - identifyTime = 0;
    - identifyType = "";
 */
- (void)startScanDeviceInWifi:(void (^)(NSError* error, NSArray* deviceList, NSArray* configDeviceList))completion;

/**
 Stop scanning, this API can be use with startScanDeviceInWifi.
 
 @since (mainland/overseas)  (group/single user)
 */
- (void)stopScanDeviceInWifi;

/**
 Add the appliance to SDK by the SSID of appliance,the appliance will be called added appliance.

 @since (mainland/overseas)  (group/single user)
 @param ssid Appliance SSID
 @param completion Async call
 
  - error.code contains: 0 succeed >0 failed, detailed definition in MSmartErrorCode or error.localizedDescription
 */
- (void)addDeviceWithSSID:(NSString*)ssid completion:(void (^)(NSError* error))completion;

/**
 Cancel the appliance adding process

 @since (mainland/overseas)  (group/single user)
 @param completion Async call
 
  - error.code contains: 0 succeed >0 failed, detailed definition in MSmartErrorCode or error.localizedDescription
 */
- (void)stopAddDeviceBySSID:(void (^)(NSError* error))completion;

#pragma mark - the appliance information API

/**
 Get the appliance list already added by the SDK

 @since (mainland/overseas)  (group/single user)
 @param completion Async call
 
  - error.code contains: 0 succeed >0 failed, detailed definition in MSmartErrorCode or error.localizedDescription
  - deviceList: added appliance list
 
    - deviceId = "";     //appliance ID
    - deviceName = "";   //appliance name
    - deviceSn = "";     //appliance SN
    - deviceSsid = "";   //appliance SSID
    - deviceSubType = "";//appliance subtype
    - deviceType = "";   //appliance type
    - isActivity = "";   //appliance activity status(family mode) or bindUserId = ""(friend mode，@"":not activity，or the userId of the appliance)
    - isWanOnline = "" ; //WAN online status， 1:online , 0:offline
    - isLanOnline = "" ; //LAN online status， 1:online , 0:offline
 */
- (void)getDeviceInfoArray:(void (^)(NSError *error, NSArray *deviceList))completion;

/**
 Query the bind or active information

 @since (mainland/overseas)  (group/single user)
 @param deviceId query deviceId
 @param completion Async call
 
  - error.code contains: 0 succeed >0 failed, detailed definition in MSmartErrorCode or error.localizedDescription
  - deviceInfo:appliance information
 
    - isActivity        = "";//activity status,0:not activity,1:already activity
    - bindStatus        = "";//bind status,0:not bind,1:bind with family mode, 2:bind with friend mode
    - deviceDescription = "";//description
    - deviceSn          = "";//appliance SN
    - deviceSubType     = "";//appliance subtype
    - deviceName        = "";//appliance name
    - isWanOnline       = "" ;//WAN online status,1:online,0:offline
    - isLanOnline       = "" ;//LAN online status,1:online,0:offline
    - deviceType        = "";//appliance type
    - familyNumber      = "";//the NO. of family of appliance （bindStatus=1）
    - familyId          = "";//the ID of family of appliance  （ bindStatus=1）
    - familyName        = "";//the name of family of appliance   （bindStatus=1)
    - userAccount       = "";//the user account of the appliance  （bindStatus=2）
    - userId            = "";//the user ID of the appliance（bindStatus=2）
    - userName          = "";//the user nickname of the appliance （bindStatus=2
 
 */
- (void)getDeviceInfoAndBindInfoWithDeviceId:(NSString *)deviceId
                                  completion:(void (^)(NSError *error,NSDictionary *deviceInfo))completion;

/**
 Get the appliance default name by the appliance SSID

 @since (mainland/overseas)  (group/single user)
 @param ssid appliance SSID
 @return the appliance default name
 */
- (NSString *)getDeviceNameWithSSID:(NSString *)ssid;

/**
 Get detailed info of appliance in the LAN. (call startScanDeviceInWifi first)

 @since (mainland/overseas)  (group/single user)
 @param ssid appliance SSID
 @return the information of appliance
 
  - deviceId = XXXXXXXXX;
  - deviceSn = XXXXXXXXX;
  - deviceSsid = "midea_XX_XXXX";
  - deviceType = 0xXX;
  - identifyTime = "-1";
  - identifyType = "";
 */
- (NSDictionary *)getDeviceInfoWithSSID:(NSString *)ssid;

#pragma mark - 二维码相关接口
/**
 Check if the qrcode is valid qrcode of midea smart appliance

 @since (mainland/overseas)  (group/single user)
 @note App need to call this API after scan the qrcode.
 @param qrcode qrcode string
 @return YES:valid NO:invalid
 */
- (BOOL)isQRCodeValid:(NSString *)qrcode;

/**
 Get appliance SSID from qrcode string.

 @since (mainland/overseas)  (group/single user)
 @param qrcode qrcode string
 @return appliance SSID
 */
- (NSString *)getSSIDfromQRCode:(NSString *)qrcode;

/**
 Get appliance SN(ciphertext) from qrcode string.

 @since (mainland/overseas)  (group/single user)
 @param qrcode qrcode string
 @return appliance SN(ciphertext)
 */
- (NSString *)getSNfromQRCode:(NSString *)qrcode;

/**
 Modify the appliance info

 @since (mainland/overseas)  (group/single user)
 @param deviceId appliance ID
 @param deviceName new appliance name
 @param deviceDescription new appliance description
 @param completion Async call
 
  - error.code contains: 0 succeed >0 failed, detailed definition in MSmartErrorCode or error.localizedDescription
 */
- (void)modifyDeviceInformationWithDeviceId:(NSString *)deviceId
                               modifiedName:(NSString *)deviceName
                  modifiedDeviceDescripiton:(NSString *)deviceDescription
                                 completion:(void (^)(NSError* error))completion;

/**
 Get the name of appliance type by appliance type

 @since (mainland/overseas)  (group/single user)
 @param deviceType appliance type, use FF parameter will get all the names of appliance type
 @return type list
 
  - deviceType = 10;
  - deviceTypeChsName = "\U667a\U80fd\U63d2\U5ea7";
  - deviceTypeEngName = "";
 */
- (NSArray *)getDeviceTypeNameWithDeviceType:(NSString *)deviceType;

/**
 Set the SSID format need to support in SDK. such as midea_XX_XXXX,net_XX_XXXX,ms0001_XX_XXXX

 @since (mainland/overseas)  (group/single user)
 @param formatArray valid SSID fromat:midea_xx_xxxx,net_xx_xxxx
 */
- (void)enableSSIDFormatWithFormatArray:(NSArray *)formatArray;

#pragma mark - wifi module

/**
 Get the version info of the wifi module

 @since (mainland)  (group/single user)
 @param deviceSsid appliance SSID
 @param completion Async call
 
  - error.code contains: 0 succeed >0 failed, detailed definition in MSmartErrorCode or error.localizedDescription
  - dict:appliance information
 
    - @"deviceProtocolVersion":  wifi module version
    - @"deviceId": appliance ID
 */
- (void)deviceWifiModuleVersionInfoWithDeviceSsid:(NSString *)deviceSsid
                                       completion:(void (^)(NSError *error, NSDictionary *dict))completion;

/**
 Upgrade wifi module

 @since (mainland)  (group/single user)
 @param deviceId appliance ID
 @param progress uploading progress 1:100%
 @param completion Async call
 
  - error.code contains: 0 succeed >0 failed, detailed definition in MSmartErrorCode or error.localizedDescription
 */
- (void)deviceWifiModuleUpdateWithDeviceId:(NSString *)deviceId
                                  progress:(void (^)(float progress))progress
                                completion:(void (^)(NSError *error))completion;

/**
 Reboot the wifi module

 @since (mainland)  (group/single user)
 @param deviceId appliance ID
 @param completion Async call
 
  - error.code contains: 0 succeed >0 failed, detailed definition in MSmartErrorCode or error.localizedDescription
 */
- (void)restartModuleWithDeviceId:(NSString *)deviceId
                       completion:(void (^)(NSError *error))completion;

/**
 Check if wifi module upgrade available

 @since (mainland)  (group/single user)
 @param wifiVersion current wifi module version
 @return YES or NO
 */
- (BOOL)isDesignatedVersion:(NSString *)wifiVersion;

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

/**
  Query appliance OTA state

 @since (mainland/overseas)  (group/single user)
 @param deviceId appliance ID
 @param completion Async call
 
  - error.code contains: 0 succeed >0 failed, detailed definition in MSmartErrorCode or error.localizedDescription
  - deviceInfo：appliance information
 */
- (void)queryDeviceOTAState:(NSString *)deviceId
                 completion:(void (^)(NSError *error,NSDictionary *deviceInfo))completion;

/**
 Start the upgrade of appliance OTA

 @since (mainland/overseas)  (group/single user)
 @param deviceId appliance ID
 @param completion Async call
 
  - error.code contains: 0 succeed >0 failed, detailed definition in MSmartErrorCode or error.localizedDescription
 */
- (void)startDeviceOTAState:(NSString *)deviceId
                 completion:(void (^)(NSError *error))completion;

/**
 Decrypted the appliance SN by qrcode string

 @since (mainland)  (group/single user)
 @param qrcode qrcode string
 @param completion Async call
 
  - error.code contains: 0 succeed >0 failed, detailed definition in MSmartErrorCode or error.localizedDescription
  - categoryStr:appliance type
  - deviceSn:appliance SN
  - ssid:appliance SSID
 */
- (void)decryptSNWithQRCode:(NSString *)qrcode
                 completion:(void (^)(NSError *error, NSString *deviceSn, NSString *categoryStr, NSString *ssid))completion;

- (void)identifyBySLKWithDeviceSN:(NSString *)deviceSN
                       completion:(void (^)(NSError *error))completion __deprecated_msg("the API is deprecated");

- (void)identifyByDeviceWithDeviceSN:(NSString *)deviceSN
                             timeout:(int)timeout
                          completion:(void (^)(NSError *))completion __deprecated_msg("the API is deprecated");

- (void)stopIdentifyBySLK __deprecated_msg("the API is deprecated");

- (void)bindDeviceWithWifi:(NSString *)homeSSID
                  password:(NSString *)password
                deviceName:(NSString *)deviceName
                       tsn:(NSString *)tsn
                completion:(void (^)(NSError* error, NSDictionary *dict))completion __deprecated_msg("Use `- (void)bindDeviceWithWifi:(NSString*)homeSSID password:(NSString*)password WiFiBSsid:(NSString *)bssid deviceName:(NSString*)deviceName tsn:(NSString *)tsn completion:(void (^)(NSError* error, NSDictionary *dict))completion;` instead.");

- (void)startNewSendMSCWithDeviceType:(NSString *)deviceType
                             homeSSID:(NSString *)homeSSID
                             password:(NSString *)password
                                  tsn:(NSString *)tsn
                                  key:(NSString *)key
                           completion:(void (^)(NSError *err, NSDictionary *dict))completion __deprecated_msg("Use `- (void)startNewSendMSCWithDeviceType:(NSString *)deviceType homeSSID:(NSString *)homeSSID password:(NSString *)password tsn:(NSString *)tsn extension:(NSString *)extension key:(NSString *)key completion:(void (^)(NSError *err, NSDictionary *dict))completion;` instead.");


@end
