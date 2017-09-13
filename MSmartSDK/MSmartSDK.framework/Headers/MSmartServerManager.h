//
//  MSmartServerManager.h
//  MSmartSDK
//
//  Created by Ryan on 15/12/25.
//  Copyright © 2015年 yellowsea. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MSmartSDK.h"

@interface MSmartServerManager : MSmartBaseManager

/**
 Server manager.

 @since (mainland/overseas)  (group/single user)
 @return Server manager
 
 **Example:**
 
  MSmartServerManager* manager = [MSmartServerManager sharedManager];
 
  [manager MSmartTestModel:@"join us!"];
 */
+ (MSmartServerManager *) sharedManager;

/**
 Update push token

 @since (mainland/overseas)  (group/single user)
 @param pushToken new push token
 @param completion Async call
 
  - error.code contains: 0 succeed >0 failed, detailed definition in MSmartErrorCode or error.localizedDescription
 */
- (void)updateUserPushTokenWithPushToken:(NSString *)pushToken
                              completion:(void (^)(NSError *error))completion;

/**
 Get push message by push ID

 @since (mainland/overseas)  (group/single user)
 @param pushId push ID
 @param completion Async call
 
  - error.code contains: 0 succeed >0 failed, detailed definition in MSmartErrorCode or error.localizedDescription
  - content:push message
 */
- (void)pushContentGetWithPushId:(NSString *)pushId
                      completion:(void (^)(NSError *error,NSDictionary *content))completion;

/**
 M-Cloud common post request API（common/file upload),the url format is "httpHead://domainName:domainPort/version/api".

 @since (mainland/overseas)  (group/single user)
 @param httpHead 使用http/https协议传输,填nil则和初始化选择是否开启https通道一致 例：@"http"
 @param domainName 请求的主机域名或ip地址,填nil则和初始化选择的服务器的域名一致  例：@""
 @param domainPort 请求的端口号,填nil则和初始化选择的服务器的端口一致   例：@"8000"
 @param version 接口版本,填nil则默认v1      例：@"v1"
 @param api 请求的接口名
 @param postDic 接口请求参数
 @param uploadInfoDic 上传文件时填写的请求参数（注：详情参见MSmartDefinition.h文件Dictionry key说明），非上传文件请求此参数填nil
 
  - kMSServerKeyUploadInfoKey          ：待上传文件的key名称
  - kMSServerKeyUploadInfoContent      ：待上传文件的内容（NSData）
  - kMSServerKeyUploadInfoType         ：待上传文件的MIME类型
 @param completion 异步执行返回(block)
 
  - error：error.code值为0表示执行成功；大于0表示执行失败；具体错误提示见 MSmartErrorCode 定义或error.localizedDescription
  - result：服务器返回结果（注：error.code > 0 时 result为nil）
 */
- (void)requestMCloudWithHttpHead:(NSString *)httpHead
                           domain:(NSString *)domainName
                             port:(NSString *)domainPort
                          version:(NSString *)version
                              api:(NSString *)api
                          bodyDic:(NSMutableDictionary *)postDic
                       uploadInfo:(NSDictionary *)uploadInfoDic
                       completion:(void (^)(NSError *error, NSDictionary *result))completion;

/**
 上传用户头像

 @since (mainland)  (group/single user)
 @param image 头像
 @param completion 异步执行返回(block)
 
  - error：error.code值为0表示执行成功；大于0表示执行失败；具体错误提示见 MSmartErrorCode 定义或error.localizedDescription
 */
- (void)modifyUserAvatarImageWithImage:(UIImage *)image completion:(void (^)(NSError *))completion;

/**
 修改用户信息

 @since (mainland)  (group/single user)
 @param nickName 用户昵称
 @param signature 个性签名
 @param completion 异步执行返回(block)
 
  - error：error.code值为0表示执行成功；大于0表示执行失败；具体错误提示见 MSmartErrorCode 定义或error.localizedDescription
 */
- (void)modifyUserInfoWithNickName:(NSString *)nickName
                      andSignature:(NSString *)signature
                        completion:(void (^)(NSError *error))completion;

/**
 修改用户其他信息

 @since (mainland)  (group/single user)
 @note 三个参数选填，但不可全为空
 @param sexy 性别，@"1" 代表男性，@"2"代表女性；不改变性别可以填nil或@"",其他值会报错
 @param age 年龄，不改变可填nil;
 @param address 地址，不改变可填nil;
 @param completion 异步执行返回(block)
 
  - error：error.code值为0表示执行成功；大于0表示执行失败；具体错误提示见 MSmartErrorCode 定义或error.localizedDescription
 */
- (void)modifyUserInfoWithSexy:(NSString *)sexy
                           Age:(NSNumber *)age
                       address:(NSString *)address
                    completion:(void (^)(NSError *error))completion;

/**
 获取升级包信息

 @since (mainland)  (group/single user)
 @param appType 设备类型
 @param versionCode 版本code
 @param completion 异步执行返回(block)
 
  - error：error.code值为0表示执行成功；大于0表示执行失败；具体错误提示见 MSmartErrorCode 定义或error.localizedDescription
  - dict：升级包信息
 */
- (void)getUpdateInfoWithAppType:(NSString *)appType
                     VersionCode:(NSString *)versionCode
                      completion:(void (^)(NSError *error, NSDictionary *dict))completion;

/**
 上传条形码

 @since (mainland)  (group/single user)
 @param deviceSn 设备SN
 @param productCode 条形码
 @param completion 异步执行返回(block)
 
  - error：error.code值为0表示执行成功；大于0表示执行失败；具体错误提示见 MSmartErrorCode 定义或error.localizedDescription
 */
- (void)uploadDeviceProductCodeWithDeviceSn:(NSString *)deviceSn
                             andProductCode:(NSString *)productCode
                                 completion:(void(^)(NSError *error))completion;

/**
 查询升级包

 @since (mainland)  (group/single user)
 @param appType 设备类型
 @param version 客户端版本号
 @param completion 异步执行返回(block)
 
  - error：error.code值为0表示执行成功；大于0表示执行失败；具体错误提示见 MSmartErrorCode 定义或error.localizedDescription
 */
- (void)getUpdateCheckListWithAppType:(NSString *)appType
                              version:(NSString *)version
                           completion:(void (^)(NSError *error, NSArray *array))completion;

/**
 获取对应wifi模组的升级包信息

 @since (mainland)  (group/single user)
 @param wifiVersion Wifi版本信息 007f升级消息体转化为字符串，十六进制英文半角逗号分隔
 @param completion 异步执行返回(block)
 
  - error：error.code值为0表示执行成功；大于0表示执行失败；具体错误提示见 MSmartErrorCode 定义或error.localizedDescription
  - result：升级包信息
 */
- (void)deviceWiFiUpdateCheckWithWiFiVersion:(NSString *)wifiVersion
                                  completion:(void (^)(NSError *error, NSDictionary *result))completion;

/**
 获取家电类型下拉框列表接口

 @since (mainland)  (group/single user)
 @param completion 异步执行返回(block)
 
  - error：error.code值为0表示执行成功；大于0表示执行失败；具体错误提示见 MSmartErrorCode 定义或error.localizedDescription
  - deviceTypeArray：下拉框列表
 */
- (void)getDeviceTypeListCompletion:(void (^)(NSError *error, NSArray *deviceTypeArray))completion;

/**
 根据设备类型获取说明书

 @since (mainland)  (group/single user)
 @param deviceType 设别类型
 @param completion 异步执行返回(block)
 
  - error：error.code值为0表示执行成功；大于0表示执行失败；具体错误提示见 MSmartErrorCode 定义或error.localizedDescription
  - array：说明书列表
 */
- (void)getDeviceElectronicbookWithDeviceType:(NSString *)deviceType
                                   completion:(void (^)(NSError *error, NSArray *array))completion;

/**
 获取产品品类

 @since (mainland)  (group/single user)
 @param serviceType A：报装；B ：报修
 @param completion 异步执行返回(block)
 
  - error：error.code值为0表示执行成功；大于0表示执行失败；具体错误提示见 MSmartErrorCode 定义或error.localizedDescription
  - result：品类信息列表
 */
- (void) getProductTypeWithServiceType:(NSString *)serviceType
                            completion:(void (^)(NSError *error, NSArray *result))completion;

/**
 获取地区信息

 **Note:**
  
  1. sclassifyCode为1或2时都忽略sparentRegId字段即查询出所有省级或所有市级地区
  2. 当sparentRegId不为空时根据sparentRegId查询
  3. 当level不等于1或2时必须传入sparentRegId
  4. sparentRegId :"", sclassifyCode:"1" ,返回全部的省份信息
  5. sparentRegId :"111", sclassifyCode:"2" 返回全部北京市地区信息
 @since (mainland)  (group/single user)
 @param sclassfyCode 已选地区编码，比如已选广东省，则传广东省编码过来，系统就取出广东省下面所有的市
 @param sparentRegid 地区级别：
 
  - 1：省
  - 2：市
  - 3：区县,
  - 4：街道/乡镇
 @param completion 异步执行返回(block)
 
  - error：error.code值为0表示执行成功；大于0表示执行失败；具体错误提示见 MSmartErrorCode 定义或error.localizedDescription
  - result：地区信息列表
 */
- (void)getRegionsWithSclassifyCode:(NSString *)sclassfyCode
                       sparentRegid:(NSString *)sparentRegid
                         completion:(void (^)(NSError *error, NSArray *result))completion;

/**
 上报家电位置信息

 @since (mainland)  (group/single user)
 @param deviceId 设备ID
 @param locationDic 位置信息字典（注：选填，详情参见MSmartDefinition.h文件 Dictionry key说明）
 
  - kMSServerKeyLongitudes   //家电经度
  - kMSServerKeyLatitudes    //家电纬度
  - kMSServerKeyCountryId    //国家
  - kMSServerKeyProvinceId   //省级
  - kMSServerKeyCityId       //市县级
  - kMSServerKeyStreet       //街道名
  - kMSServerKeyStreetNumber //街道门牌号
  - kMSServerKeytradeInfo    //商圈信息
 @param completion 异步执行返回(block)
 
  - error：error.code值为0表示执行成功；大于0表示执行失败；具体错误提示见 MSmartErrorCode 定义或error.localizedDescription
 */
- (void)uploadGPSInfoWithDeviceId:(NSString *)deviceId
                      locationDic:(NSDictionary *)locationDic
                       completion:(void (^)(NSError *error))completion;

/**
 获取故障类型

 @since (mainland)  (group/single user)
 @param productId 产品品类编号,参考产品品类接口
 @param completion 异步执行返回(block)
 
  - error：error.code值为0表示执行成功；大于0表示执行失败；具体错误提示见 MSmartErrorCode 定义或error.localizedDescription
  - result：故障类型列表
 */
- (void)getServiceFaultItemsWithProductId:(NSString *)productId
                               completion:(void (^)(NSError *error, NSArray *result))completion;

/**
 新建售后信息单

 @since (mainland)  (group/single user)
 @param customerName 联系人
 @param phoneNumer 联系方式
 @param areaNumber 区域号
 @param region 区域
 @param regionString 所选地区字符串
 @param address 详细地址
 @param serviceType 服务类型 （A 报装 B报修）
 @param productId 产品品类
 @param serviceItem 故障类型
 @param infoDes 服务诉求(用户自己补充的内容)
 @param pushId 推送消息ID ，点击推送消息创建售后单需要提供
 @param completion 异步执行返回(block)
 
  - error：error.code值为0表示执行成功；大于0表示执行失败；具体错误提示见 MSmartErrorCode 定义或error.localizedDescription
  - infoRecord：信息单编号
 */
- (void)addAftermarketInformationWithCustomerName:(NSString *)customerName
                                      phoneNumber:(NSString *)phoneNumer
                                       areaNumber:(NSString *)areaNumber
                                           region:(NSString *)region
                                     regionString:(NSString *)regionString
                                          address:(NSString *)address
                                      serviceType:(NSString *)serviceType
                                        productId:(NSString *)productId
                                      serviceItem:(NSString *)serviceItem
                           informationDescription:(NSString *)infoDes
                                           pushId:(NSString *)pushId
                                       completion:(void (^)(NSError *error, NSString *infoRecord))completion;

/**
 查询售后信息单列表

 @since (mainland)  (group/single user)
 @param account 第三方账号
 @param tel 手机号码
 @param cstatus 工单状态，多个状态通过引文逗号“,”分隔
  
  - -1：查询全部状态，否则根据状态查询
  - 0：未接收
  - 1：已接收
  - 2：已预约
  - 3：已派工
  - 4：已上门
  - 5、已完成
  - 6：确认完成
  - 7：已评价
  - 9：已取消
 @param pageNumber 当前页码
 @param pageSize 分页大小
 @param completion 异步执行返回(block)
 
  - error：error.code值为0表示执行成功；大于0表示执行失败；具体错误提示见 MSmartErrorCode 定义或error.localizedDescription
  - result：信息单列表
 */
- (void) getAftermarketInformationListWithAccount:(NSString *)account
                                        telephone:(NSString *)tel
                                          cstatus:(NSString *)cstatus
                                       pageNumber:(NSString *)pageNumber
                                         pageSize:(NSString *)pageSize
                                       completion:(void (^)(NSError *error, NSDictionary *result))completion;

/**
 查询售后信息单详情

 @since (mainland)  (group/single user)
 @param infoRecordId 查询售后信息单详情
 @param completion 异步执行返回(block)
 
  - error：error.code值为0表示执行成功；大于0表示执行失败；具体错误提示见 MSmartErrorCode 定义或error.localizedDescription
  - result：详情字典
 */
- (void)getAftermarketDetailInformationWithSInfoRecordId:(NSString *)infoRecordId
                                              completion:(void (^)(NSError *error, NSDictionary *result))completion;

/**
 根据推送消息ID获取报修信息

 @since (mainland)  (group/single user)
 @param pushId 推送消息ID
 @param accessToken 获取推送消息的accessToken
 @param completion 异步执行返回(block)
 
  - error：error.code值为0表示执行成功；大于0表示执行失败；具体错误提示见 MSmartErrorCode 定义或error.localizedDescription
  - result：报修信息
 */
- (void)getPushInfoWithPushId:(NSString *)pushId
                  accessToken:(NSString *)accessToken
                   completion:(void (^)(NSError *error, NSDictionary *result))completion;

/**
 用户优惠券抽取资格获取

 @since (mainland)  (group/single user)
 @param deviceId 设备ID
 @param completion 异步执行返回(block)
 
  - error：error.code值为0表示执行成功；大于0表示执行失败；具体错误提示见 MSmartErrorCode 定义或error.localizedDescription
  - result：优惠券信息，可以直接提示用户
 */
- (void)getUserActivityCouponStatusWithDeviceId:(NSString *)deviceId
                                     completion:(void (^)(NSError *error, NSString *result))completion;

/**
 奖品获取(抽奖)

 @since (mainland)  (group/single user)
 @param deviceId
 @param completion 异步执行返回(block)
 
  - error：error.code值为0表示执行成功；大于0表示执行失败；具体错误提示见 MSmartErrorCode 定义或error.localizedDescription
  - result：优惠券信息，可以直接提示用户
 */
- (void)getUserActivityCouponWithDeviceId:(NSString *)deviceId
                               completion:(void (^)(NSError *error, NSString *result))completion;

/**
 获取奖品信息

 @since (mainland)  (group/single user)
 @param completion 异步执行返回(block)
 
  - error：error.code值为0表示执行成功；大于0表示执行失败；具体错误提示见 MSmartErrorCode 定义或error.localizedDescription
  - result：优惠券信息，可以直接提示用户
 */
- (void)getUserActivityCouponInformationWithCompletion:(void (^)(NSError *error, NSString *result))completion;

/**
 获取token接口

 @since (mainland)  (group/single user)
 @param completion 异步执行返回(block)
 
  - error：error.code值为0表示执行成功；大于0表示执行失败；具体错误提示见 MSmartErrorCode 定义或error.localizedDescription
  - result：获取的token
 */
- (void)getAccessTokenFromThirdServerWithCompletion:(void (^)(NSError *error, NSString *result))completion;

/**
 获取验证code接口

 @since (mainland)  (group/single user)
 @param token 获取验证code接口
 @param mobile 手机号
 @param completion 异步执行返回(block)
 
  - error：error.code值为0表示执行成功；大于0表示执行失败；具体错误提示见 MSmartErrorCode 定义或error.localizedDescription
  - result：获取的code申请码
 */
- (void)getConsumeVerifyCodeWithAccessToken:(NSString *)token
                                     mobile:(NSString *)mobile
                                 completion:(void (^)(NSError *error, NSString *result))completion;

/**
 家电的家长或家电主人确认是否允许家电升级

 @since (mainland)  (group/single user)
 @param deviceId 家电ID
 @param newVersion 家电新版本号
 @param confirm 是否允许升级
 @param completion 异步执行返回(block)
 
  - error：error.code值为0表示执行成功；大于0表示执行失败；具体错误提示见 MSmartErrorCode 定义或error.localizedDescription
 */
- (void)confirmDevicePackUpdateWithDeviceId:(NSString *)deviceId
                             newPackVersion:(NSString *)newVersion
                                    confirm:(BOOL)confirm
                                 completion:(void (^)(NSError *error))completion;

/**
 家电配网耗时上传

 @since (mainland)  (group/single user)
 @param deviceId 家电ID
 @param time 配网总耗时，单位为毫秒
 @param completion 异步执行返回(block)
 
  - error：error.code值为0表示执行成功；大于0表示执行失败；具体错误提示见 MSmartErrorCode 定义或error.localizedDescription
  - result：耗时结果
 
    - ”rank”:”14”,
    - “title”:” 配网高手”,
    - “beatRate”:”91%”
 */
- (void)uploadConnectionTimeWithDeviceId:(NSString *)deviceId
                                    time:(double)time
                              completion:(void (^)(NSError *error,NSDictionary *result))completion;

/**
 应用服务器和智慧云透传接口

 @since (mainland)  (group/single user)
 @param serverType 应用服务器服务器类型
 @param queryString 拼接的接口
 @param jsonData 数据
 @param completion 异步执行返回(block)
 
  - error：error.code值为0表示执行成功；大于0表示执行失败；具体错误提示见 MSmartErrorCode 定义或error.localizedDescription
  - result：回调
 */
- (void)sendDataMessageAppToBaseWithServerType:(NSString *)serverType
                            queryString:(NSString *)queryString
                               jsonData:(NSString *)jsonData
                             completion:(void (^)(NSError *error,NSDictionary *result))completion;

/**
 获取插件版本信息

 @since (mainland)  (group/single user)
 @param appMainVersion 主应用版本
 @param completion 异步执行返回(block)
 
  - error：error.code值为0表示执行成功；大于0表示执行失败；具体错误提示见 MSmartErrorCode 定义或error.localizedDescription
  - pluginInfoArray：插件信息数组
 */
- (void)pluginUpdateInfoWithAppMainVersion:(NSString *)appMainVersion
                                completion:(void (^)(NSError *error, NSArray *pluginInfoArray))completion;



/**
 美的付请求签名

 @since (mainland)  (group/single user)
 @param md5 需要签名的md5值
 @param completion 异步执行返回(block)
 
  - error：error.code值为0表示执行成功；大于0表示执行失败；具体错误提示见 MSmartErrorCode 定义或error.localizedDescription
  - sign：返回的sign
 */
- (void)requestSignForWalletH5WithMd5:(NSString *)md5 completion:(void (^)(NSError *error, NSString *sign))completion;

/**
 根据家电类型获取码库

 @since (mainland)  (group/single user)
 @param applianceType 家电品类
 @param completion 异步执行返回(block)
 
  - error：error.code值为0表示执行成功；大于0表示执行失败；具体错误提示见 MSmartErrorCode 定义或error.localizedDescription
 */
- (void)getApplianceLibraryWithType:(NSString *)applianceType
                         completion:(void (^)(NSError *error, NSDictionary *result))completion;

/**
 用户主动上报家电型号

 @since (mainland)  (group/single user)
 @param applianceType 家电品类
 @param applianceName 家电名称
 @param applianceModel 家电型号
 @param completion 异步执行返回(block)
 
  - error：error.code值为0表示执行成功；大于0表示执行失败；具体错误提示见 MSmartErrorCode 定义或error.localizedDescription
 */
- (void)reportApplianceModel:(NSString *)applianceType
               applianceName:(NSString *)applianceName
              applianceModel:(NSString *)applianceModel
                  completion:(void (^)(NSError *error, NSDictionary *result))completion;

/**
 敏感数据加密

 @since (mainland/overseas)  (group/single user)
 @param string 需要加密的数据
 @return 返回加密后的结果
 */
- (NSString *)sensitiveDataEncryptionWithString:(NSString *)string;

/**
 敏感数据解密

 @since (mainland/overseas)  (group/single user)
 @param string 需要解密的数据
 @return 返回解密后的结果
 */
- (NSString *)sensitiveDataDecryptionWithString:(NSString *)string;

/**
 未登录条件下M-Cloud 业务通用post请求接口（普通请求以及文件上传）完整url为 httpHead://domainName:domainPort/version/api.

 @since (mainland)  (group)
 @param httpHead 使用http/https协议传输,填nil则和初始化选择是否开启https通道一致 例：@"http"
 @param domainName 请求的主机域名或ip地址,填nil则和初始化选择的服务器的域名一致  例：@""
 @param domainPort 请求的端口号,填nil则和初始化选择的服务器的端口一致   例：@"8000"
 @param version 接口版本,填nil则默认v1      例：@"v1"
 @param api 请求的接口名
 @param postDic 接口请求参数
 @param uploadInfoDic 上传文件时填写的请求参数（注：详情参见MSmartDefinition.h文件Dictionry key说明），非上传文件请求此参数填nil
 
  - kMSServerKeyUploadInfoKey          ：待上传文件的key名称
  - kMSServerKeyUploadInfoContent      ：待上传文件的内容（NSData）
  - kMSServerKeyUploadInfoType         ：待上传文件的MIME类型
 @param completion 异步执行返回(block)
 
  - error：error.code值为0表示执行成功；大于0表示执行失败；具体错误提示见 MSmartErrorCode 定义或error.localizedDescription
  - result：服务器返回结果（注：error.code > 0 时 result为nil）
 */
- (void)requestMCloudWithoutLoginWithHttpHead:(NSString *)httpHead
                                       domain:(NSString *)domainName
                                         port:(NSString *)domainPort
                                      version:(NSString *)version
                                          api:(NSString *)api
                                      bodyDic:(NSMutableDictionary *)postDic
                                   uploadInfo:(NSDictionary *)uploadInfoDic
                                   completion:(void (^)(NSError *error, NSDictionary *result))completion;


- (void)requestForVariableInterfaceWithName:(NSString *)interfaceName
                                     server:(NSString *)server
                                     params:(NSDictionary *)params
                                       post:(BOOL)post
                              versionString:(BOOL)versionString
                                 completion:(void (^)(NSError *error, NSDictionary *result))completion __deprecated_msg("Use `- (void)requestMCloudWithHttpHead:(NSString *)httpHead domain:(NSString *)domainName port:(NSString *)domainPort version:(NSString *)version api:(NSString *)api bodyDic:(NSMutableDictionary *)postDic uploadInfo:(NSDictionary *)uploadInfoDic completion:(void (^)(NSError *error, NSDictionary *result))completion` instead.");


- (void)requestForVariableRestfulInterfaceWithName:(NSString *)interfaceName
                                            server:(NSString *)server
                                            params:(NSDictionary *)params
                                              post:(BOOL)post
                                     versionString:(BOOL)versionString
                                        completion:(void (^)(NSError *error, NSDictionary *result))completion __deprecated_msg("Use `- (void)requestMCloudWithHttpHead:(NSString *)httpHead domain:(NSString *)domainName port:(NSString *)domainPort version:(NSString *)version api:(NSString *)api bodyDic:(NSMutableDictionary *)postDic uploadInfo:(NSDictionary *)uploadInfoDic completion:(void (^)(NSError *error, NSDictionary *result))completion` instead.");


- (void)requestAuthTokenForH5WithCompletion:(void (^)(NSError *error, NSString *token))completion __deprecated;
@end

