//
//  MSBleCommonFrame.h
//  BlueToothDemo
//
//  Created by CC ZHOU on 16/3/11.
//  Copyright © 2016年 CC ZHOU. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, BleCommonFrameError)
{
    BleCommonFrameError_successful              = 0,    //!< 合法的消息
    BleCommonFrameError_IllegalMsg              = 1,    //!< 格式不正确的消息
    BleCommonFrameError_IncompleteMsg           = 2,    //!< 不完整的消息，有消息头，但消息长度大于实际收到的字节长度
    BleCommonFrameError_WithoutMsgHead          = 3,    //!< 不完整的消息，无消息头
};

@interface MSBleMessage : NSObject

// 设备类型
@property (nonatomic, assign) UInt8 deviceType;

//消息类型
@property (nonatomic, assign) UInt16 msgType;

//消息长度
@property (nonatomic, assign) UInt8 msgLength;

// 消息体
@property (nonatomic, strong) NSData *data;

@end

@interface MSBleCommonFrame : NSObject

/**
 *  组 UART 协议数据包
 *
 *  @param msgBody    消息体
 *  @param deviceType 设备类型
 *  @param msgType    信息类型
 *
 *  @return 协议包
 */
+ (NSData *)createBleProtocolPacket:(NSData *)msgBody deviceType:(UInt8)deviceType msgType:(UInt16)msgType;

/**
 *  根据 UART 协议包获取消息体
 *
 *  @param data 消息
 *
 *  @return UART 协议包
 */
+ (MSBleMessage *)getBleMsgBodyFromProtocolPacket:(NSData *)data error:(__autoreleasing NSError **)error;

/**
 *  计算 UART 协议包校验数据, 求和后取补码, 求和过程中若发生溢出, 直接丢弃溢出的高位
 *
 *  @param dataBytes
 *  @param length
 *
 *  @return
 */
+ (UInt8)calculateCheckCode:(UInt8 *)dataBytes withLength:(UInt8)length;

@end

// 家电操作数据透传
FOUNDATION_EXTERN UInt16 const kMSBleUartMsgFlagType_OperationTransmit_Request;
FOUNDATION_EXTERN UInt16 const kMSBleUartMsgFlagType_OperationTransmit_Response;

// 家电信息上报（无应答）
FOUNDATION_EXTERN UInt16 const kMSBleUartMsgFlagType_DeviceNotifyInfo_Request;
FOUNDATION_EXTERN UInt16 const kMSBleUartMsgFlagType_DeviceNotifyInfo_Response;

// 家电信息上报（需应答）
FOUNDATION_EXTERN UInt16 const kMSBleUartMsgFlagType_DeviceNotifyInfoNeedAck_Request;
FOUNDATION_EXTERN UInt16 const kMSBleUartMsgFlagType_DeviceNotifyInfoNeedAck_Response;

// 校时
FOUNDATION_EXTERN UInt16 const kMSBleUartMsgFlagType_CheckTime_Request;
FOUNDATION_EXTERN UInt16 const kMSBleUartMsgFlagType_CheckTime_Response;

// 手机向模块发送心跳
FOUNDATION_EXTERN UInt16 const kMSBleUartMsgFlagType_SendKeeplive_Request;
FOUNDATION_EXTERN UInt16 const kMSBleUartMsgFlagType_SendKeeplive_Response;

// 蓝牙模块重启
FOUNDATION_EXTERN UInt16 const kMSBleUartMsgFlagType_RebootBle_Request;
FOUNDATION_EXTERN UInt16 const kMSBleUartMsgFlagType_RebootBle_Response;

// 蓝牙模块恢复出厂设置
FOUNDATION_EXTERN UInt16 const kMSBleUartMsgFlagType_ResetBle_Request;
FOUNDATION_EXTERN UInt16 const kMSBleUartMsgFlagType_ResetBle_Response;

// 蓝牙模块版本查询
FOUNDATION_EXTERN UInt16 const kMSBleUartMsgFlagType_QueryBleVersion_Request;
FOUNDATION_EXTERN UInt16 const kMSBleUartMsgFlagType_QueryBleVersion_Response;

// 模块主动发起的鉴权
FOUNDATION_EXTERN UInt16 const kMSBleUartMsgFlagType_ModuleStartAuth_Request;
FOUNDATION_EXTERN UInt16 const kMSBleUartMsgFlagType_ModuleStartAuth_Response;

// 手机鉴权成功通知
FOUNDATION_EXTERN UInt16 const kMSBleUartMsgFlagType_MobileAuthNotify_Request;
FOUNDATION_EXTERN UInt16 const kMSBleUartMsgFlagType_MobileAuthNotify_Response;

// 启动鉴权计时
FOUNDATION_EXTERN UInt16 const kMSBleUartMsgFlagType_StartAuthTime_Request;
FOUNDATION_EXTERN UInt16 const kMSBleUartMsgFlagType_StartAuthTime_Response;

// 获取ADC请求
FOUNDATION_EXTERN UInt16 const kMSBleUartMsgFlagType_GetADC_Request;
FOUNDATION_EXTERN UInt16 const kMSBleUartMsgFlagType_GetADC_Response;

// 设置GPIO输出
FOUNDATION_EXTERN UInt16 const kMSBleUartMsgFlagType_SetGPIOOutput_Request;
FOUNDATION_EXTERN UInt16 const kMSBleUartMsgFlagType_SetGPIOOutput_Response;

// 获取GPIO输入
FOUNDATION_EXTERN UInt16 const kMSBleUartMsgFlagType_GetGPIOInput_Request;
FOUNDATION_EXTERN UInt16 const kMSBleUartMsgFlagType_GetGPIOInput_Response;

// 输出PWM波
FOUNDATION_EXTERN UInt16 const kMSBleUartMsgFlagType_OutputPWMWave_Request;
FOUNDATION_EXTERN UInt16 const kMSBleUartMsgFlagType_OutputPWMWave_Response;

// 切换IO口模式
FOUNDATION_EXTERN UInt16 const kMSBleUartMsgFlagType_SwitchIOMode_Request;
FOUNDATION_EXTERN UInt16 const kMSBleUartMsgFlagType_SwitchIOMode_Response;
