//
//  MSBleCommonDevice.h
//  BlueToothDemo
//
//  Created by CC ZHOU on 16/3/16.
//  Copyright © 2016年 CC ZHOU. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MSBleCommonFrame.h"
#import "MSCBCentralManager.h"
#import "MSCBPeripheral.h"

// 蓝牙模块提供的数据互通服务和特征
FOUNDATION_EXTERN NSString *const transferServiceUUIDString;
FOUNDATION_EXTERN NSString *const transferReadCharacteristicUUIDString;
FOUNDATION_EXTERN NSString *const transferWriteCharacteristicUUIDString;

// 蓝牙模块提供的 OTA 在线升级服务和特征
FOUNDATION_EXTERN NSString *const dfuServiceUUIDString;
FOUNDATION_EXTERN NSString *const dfuControlPointCharacteristicUUIDString;
FOUNDATION_EXTERN NSString *const dfuPacketCharacteristicUUIDString;
FOUNDATION_EXTERN NSString *const dfuVersionCharacteritsicUUIDString;

FOUNDATION_EXTERN NSUInteger const PACKETS_NOTIFICATION_INTERVAL;
FOUNDATION_EXTERN NSUInteger const PACKET_SIZE;

/*!
 *  MSBleCommonDevice 是对 MSCBPeripheral 的一个封装，主要提供和 美的家电蓝牙模块 数据交互，
 *  以及 OTA 在线升级的功能，让开发者更关注上层的数据通信，而不去研究具体蓝牙连接，读取特征值这些细节。
 *
 *  如果是使用 sdk 开发和其它厂家蓝牙模块对接，不能使用该类
 */
@interface MSBleCommonDevice : NSObject

// 使用蓝牙扫描接口扫描到的 MSCBPeripheral 实例
@property (nonatomic, strong) MSCBPeripheral *peripheral;

// 家电类型
@property (nonatomic, assign) UInt8 deviceType;

// 蓝牙模块提供的数据互通服务和特征
@property (nonatomic, strong) MSCBService *transferService;
@property (nonatomic, strong) MSCBCharacteristic *transferReadCharacteristic;
@property (nonatomic, strong) MSCBCharacteristic *transferWriteCharacteristic;

// 蓝牙模块提供的 OTA 在线升级服务和特征
@property (nonatomic, strong) MSCBService *OTAService;
@property (nonatomic, strong) MSCBCharacteristic *OTAControlPointCharacteristic;
@property (nonatomic, strong) MSCBCharacteristic *OTAPacketCharacteristic;
@property (nonatomic, strong) MSCBCharacteristic *OTAVersionCharacteristic;

/**
 *  构造 MSBleCommonDevice 对象
 *
 *  @param peripheral       使用蓝牙扫描接口扫描到的 MSCBPeripheral 实例
 *  @param deviceType       家电类型
 *  @param completion       蓝牙设备初始化异步回调，error为空表示设备连接成功，可以进行后续业务
 */
- (id)initWithPeripheral:(MSCBPeripheral *)peripheral
              deviceType:(UInt8)deviceType
              completion:(void (^)(NSError *error))completion;

/**
 *  给蓝牙模块发送透传指令
 *
 *  @param data             需要透传的消息数据
 *  @param completion       操作结果异步回调
 */
- (void)transferData:(NSData *)data completion:(void (^)(NSError *error, NSData *data))completion;

/**
 *  重启蓝牙模块
 *
 *  @param reserveByte      保留字段，目前填 0
 *  @param completion       蓝牙重启后，连接会直接断开，completion 不一定响应，需要监听蓝牙断开事件
 */
- (void)reboot:(UInt8)reserveByte completion:(void (^)(NSError *error, NSUInteger result))completion;

/**
 *  蓝牙模块恢复出厂设置
 *
 *  @param reserveByte      保留字段，目前填 0
 *  @param completion       操作结果异步回调
 */
- (void)reset:(UInt8)reserveByte completion:(void (^)(NSError *error, NSUInteger result))completion;

/**
 *  查询蓝牙版本信息
 *
 *  @param reserveByte      保留字段，目前填 0
 *  @param completion       操作结果异步回调
 */
- (void)queryBleVersion:(UInt8)reserveByte completion:(void (^)(NSError *error, NSDictionary *content))completion;

/**
 *  发送手机鉴权成功通知
 *
 *  @param reserveByte      保留字段，目前填 0
 *  @param completion       操作结果异步回调
 */
- (void)mobileAuthNotify:(UInt8)reserveByte completion:(void (^)(NSError *error))completion;

/**
 *  启动鉴权计时
 *
 *  @param time             计时时长
 *  @param completion       操作结果异步回调
 */
- (void)startAuthTime:(UInt8)time completion:(void (^)(NSError *error, NSData *data))completion;

/**
 *  获取 ADC 参数
 *
 *  @param lowByte          低字节
 *  @param highByte         高字节
 *  @param reserveByte      保留字段，目前填 0
 *  @param completion       操作结果异步回调
 */
- (void)getADC:(UInt8)lowByte highByte:(UInt8)highByte reserveByte:(UInt16)reserveByte completion:(void (^)(NSError *error, NSData *data))completion;

/**
 *  获取 GPIO 参数
 *
 *  @param flag             flag
 *  @param completion       操作结果异步回调
 */
- (void)getGPIOInput:(UInt8)flag completion:(void (^)(NSError *error, NSUInteger result))completion;

/**
 *  设置 GPIO 参数
 *
 *  @param flag             flag
 *  @param completion       操作结果异步回调
 */
- (void)setGPIOOutput:(UInt8)flag completion:(void (^)(NSError *error, NSUInteger result))completion;

/**
 *  获取 PWM 参数
 *
 *  @param reserveByte      保留字段，目前填 0
 *  @param completion       操作结果异步回调
 */
- (void)getPWMWave:(UInt8)reserveByte completion:(void (^)(NSError *error, NSUInteger result))completion;

/**
 *  响应家电信息上报
 *
 *  @param data             家电响应数据
 */
- (void)sendDeviceNotifyAck:(NSData *)data;

/**
 *  响应蓝牙模块发起的时钟同步
 *
 *  @param date             当前时间
 */
- (void)sendCheckTimeResult:(NSData *)data;

/**
 *  回应蓝牙模块主动发起的鉴权
 *
 *  @param reserveByte      保留字段，目前填 0
 */
- (void)sendModuleStartAuthAck:(UInt8)reserveByte;

/**
 *  蓝牙 OTA 升级
 *
 *  @param filePath         蓝牙固件本地路径
 *  @param start            升级开始回调
 *  @param progress         升级进度回调（1 ~ 100）
 *  @param completion       升级完成回调，升级失败，返回 error
 *
 *  说明：蓝牙 OTA 升级完成（或者异常中断）之后，蓝牙模块都会断开连接，此时上层持有的 MSBleCommonDevice 
 *  需要释放，然后重新发现设备，重新创建新的 MSBleCommonDevice 对象。
 */
- (void)updateBleByFirmware:(NSString *)filePath
                      start:(void (^)(NSError *error))start
                   progress:(void (^)(NSUInteger percentage))progress
                 completion:(void (^)(NSError *error))completion;

/**
 *  取消蓝牙 OTA 升级
 */
- (void)cancelUpdataBle;

/*!
 *  使用  [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(recvMsgBleDevice:) name:MSBleCommonDeviceNotification object:nil];;
 *
 *  来监听家电往 SDK 发送(回复)过来的命令(数据)包 和返回的错误
 *
 *  NSNotification 的 object 是一个字典，必定包含一个 key 为 @"msgType", 为 NSNumber, 可能值为以下。
 *
 *  @param msgType       消息类型, 请先转成 int 型使用, 详情请参见 MSBleCommonFrame.h 里的指令
 *
 *  消息类型不同，字典里包含的内容也不同
 *
 *      kMSBleUartMsgFlagType_OperationTransmit_Request     模块上报的数据透传
 *
 *              dic里包括 {
 *                      key:@"msgType"          type:NSNumber           消息类型标识
 *                      key:@"device"           type:MSBleCommonDevice  蓝牙设备
 *                      key:@"data"             type:NSData             透传的数据
 *                    }
 *
 *      kMSBleUartMsgFlagType_OperationTransmit_Response    模块上报的数据透传应答
 *
 *              dic里包括 {
 *                      key:@"msgType"          type:NSNumber           消息类型标识
 *                      key:@"device"           type:MSBleCommonDevice  蓝牙设备
 *                      key:@"data"             type:NSData             透传的数据
 *                    }
 *
 *      kMSBleUartMsgFlagType_DeviceNotifyInfo_Request    家电信息上报（无应答）
 *
 *              dic里包括 {
 *                      key:@"msgType"          type:NSNumber           消息类型标识
 *                      key:@"device"           type:MSBleCommonDevice  蓝牙设备
 *                      key:@"data"             type:NSData             透传的数据
 *                    }
 *
 *      kMSBleUartMsgFlagType_DeviceNotifyInfoNeedAck_Request    家电信息上报（需应答）
 *
 *              dic里包括 {
 *                      key:@"msgType"          type:NSNumber           消息类型标识
 *                      key:@"device"           type:MSBleCommonDevice  蓝牙设备
 *                      key:@"data"             type:NSData             透传的数据
 *                    }
 *
 *      kMSBleUartMsgFlagType_CheckTime_Request    校时
 *
 *              dic里包括 {
 *                      key:@"msgType"          type:NSNumber           消息类型标识
 *                      key:@"device"           type:MSBleCommonDevice  蓝牙设备
 *                      key:@"data"             type:NSData             保留数据
 *                    }
 *
 *      kMSBleUartMsgFlagType_RebootBle_Response    蓝牙模块重启
 *
 *              dic里包括 {
 *                      key:@"msgType"          type:NSNumber           消息类型标识
 *                      key:@"device"           type:MSBleCommonDevice  蓝牙设备
 *                      key:@"result"           type:NSNumber           0:成功，1:失败
 *                    }
 *
 *      kMSBleUartMsgFlagType_ResetBle_Response     蓝牙模块恢复出厂设置
 *
 *              dic里包括 {
 *                      key:@"msgType"          type:NSNumber           消息类型标识
 *                      key:@"device"           type:MSBleCommonDevice  蓝牙设备
 *                      key:@"result"           type:NSNumber           0:成功，1:失败
 *                    }
 *
 *      kMSBleUartMsgFlagType_QueryBleVersion_Response     蓝牙模块版本查询
 *
 *              dic里包括 {
 *                      key:@"msgType"          type:NSNumber           消息类型标识
 *                      key:@"device"           type:MSBleCommonDevice  蓝牙设备
 *                      key:@"data"             type:NSData             版本信息
 *                    }
 *
 *      kMSBleUartMsgFlagType_ModuleStartAuth_Request     模块主动发起的鉴权
 *
 *              dic里包括 {
 *                      key:@"msgType"          type:NSNumber           消息类型标识
 *                      key:@"device"           type:MSBleCommonDevice  蓝牙设备
 *                      key:@"data"             type:NSData             保留数据
 *                    }
 *
 *      kMSBleUartMsgFlagType_MobileAuthNotify_Response     手机鉴权成功通知
 *
 *              dic里包括 {
 *                      key:@"msgType"          type:NSNumber           消息类型标识
 *                      key:@"device"           type:MSBleCommonDevice  蓝牙设备
 *                      key:@"data"             type:NSData             保留数据
 *                    }
 *
 *      kMSBleUartMsgFlagType_StartAuthTime_Response     启动鉴权计时应答
 *
 *              dic里包括 {
 *                      key:@"msgType"          type:NSNumber           消息类型标识
 *                      key:@"device"           type:MSBleCommonDevice  蓝牙设备
 *                      key:@"data"             type:NSData             保留数据
 *                    }
 *
 *      kMSBleUartMsgFlagType_GetADC_Response     获取ADC请求应答
 *
 *              dic里包括 {
 *                      key:@"msgType"          type:NSNumber           消息类型标识
 *                      key:@"device"           type:MSBleCommonDevice  蓝牙设备
 *                      key:@"data"             type:NSData             ADC采样值
 *                    }
 *
 *      kMSBleUartMsgFlagType_SetGPIOOutput_Response     设置GPIO输出应答
 *
 *              dic里包括 {
 *                      key:@"msgType"          type:NSNumber           消息类型标识
 *                      key:@"device"           type:MSBleCommonDevice  蓝牙设备
 *                      key:@"result"           type:NSNumber           0:低电平   1：高电平   2：悬空    0xFF：失败
 *                    }
 *
 *      kMSBleUartMsgFlagType_GetGPIOInput_Response     获取GPIO输入应答
 *
 *              dic里包括 {
 *                      key:@"msgType"          type:NSNumber           消息类型标识
 *                      key:@"device"           type:MSBleCommonDevice  蓝牙设备
 *                      key:@"result"           type:NSNumber           0:成功，1:失败
 *                    }
 *
 *      kMSBleUartMsgFlagType_OutputPWMWave_Response     输出PWM波应答
 *
 *              dic里包括 {
 *                      key:@"msgType"          type:NSNumber           消息类型标识
 *                      key:@"device"           type:MSBleCommonDevice  蓝牙设备
 *                      key:@"result"           type:NSNumber           0:成功，1:失败
 *                    }
 *
 **/
FOUNDATION_EXTERN NSString *const MSBleCommonDeviceNotification;

@end
