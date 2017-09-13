//
//  MSCBPeripheral.h
//  MSmartSDK
//
//  Created by CC ZHOU on 16/3/1.
//  Copyright © 2016年 yellowsea. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "MSCBCentralManager.h"
#import "MSCBService.h"
#import "MSCBCharacteristic.h"
#import "MSCBDescriptor.h"

@class MSCBPeripheral;
@class MSCBCentralManager;
@class MSCBService;

/*!
 *  MSCBPeripheral 是系统 CBPeripheral 的一个封装，主要提供一些设备管理功能，
 *  以及使用 block 的方式来替换原有系统复杂繁多的 delegate 回调的写法
 */
@interface MSCBPeripheral : NSObject <CBPeripheralDelegate>

// 系统 CBPeripheralDelegate 回调，用了 block 之后，基本不会用这个
@property (nonatomic, weak) id<CBPeripheralDelegate> delegate;

// 记录当前连接断开是否因为长时间连接不成功，最后超时而断开
@property (nonatomic, assign) BOOL watchdogRaised;

// 记录当前扫描到的服务
@property (atomic, strong) NSMutableArray *serviceArray;

// 系统 CBPeripheral 实例
@property (nonatomic, strong) CBPeripheral *cbPeripheral;

// 记录当前设备是属于哪个 MSCBCentralManager 中心扫描的
@property (nonatomic, weak) MSCBCentralManager *central;

// 记录当前设备的广告信息
@property (nonatomic, copy) NSDictionary *advertisementData;

// 记录当前设备的信号 RSSI 值，可以用来估算距离
@property (nonatomic, copy) NSNumber *RSSI;

// 设置外设连接的超时的保护定时器
@property (nonatomic, strong) NSTimer *watchdogTimer;

// 设置外设连接的超时时长
@property (nonatomic, assign) NSTimeInterval watchdogTimerInterval;

// 外设连接之后，是否成功的回调 block
@property (nonatomic, copy) void (^connectCallback)(MSCBPeripheral *peripheral, NSError *error);

// 断开外设连接之后，是否成功的回调 block
@property (nonatomic, copy) void (^disconnectCallback)(MSCBPeripheral *peripheral, NSError *error);

// 扫描外设服务的回调，该回调会回调多次 block
@property (nonatomic, copy) void (^discoverServicesCallback)(NSArray *, NSError *error);

// 给上层一个属性存储需要关联的数据
@property (nonatomic, strong) id userInfo;

/*!
 *  初始化 MSCBPeripheral 实例
 *
 *  @param peripheral           系统 CBPeripheral 实例
 *  @param owner                当前外设属于哪个中心扫描到的
 *  @param advertisementData    当前外设发布的广告
 *  @param RSSI                 当前外设的信号强度
 */
- (instancetype)initWithPeripheral:(CBPeripheral *)cbPeripheral
                           central:(MSCBCentralManager *)owner
                 advertisementData:(NSDictionary *)advertisementData
                              RSSI:(NSNumber *)RSSI;

/*!
 *  获取当前外设下所有扫描到的服务
 *
 *  @return MSCBService 数组
 */
- (NSArray *)serviceUUIDs;

/*!
 *  根据系统 CBService 实例，查找当前维护的 MSCBService 实例
 *
 *  @param service       系统 CBService 实例
 *
 *  @return MSCBService 实例
 */
- (MSCBService *)findService:(CBService *)cbService;

/*!
 *  连接当前外设
 */
- (void)connect;

/*!
 *  判断当前外设是否连接
 */
- (BOOL)isConnected;

/*!
 *  断开当前外设
 *
 *  @param disconnectCallBack   本次断开是否成功的回调
 */
- (void)disconnect:(void (^)(MSCBPeripheral *peripheral, NSError *error))disconnectCallBack;

/*!
 *  读取当前外设的 RSSI 信号值
 */
- (void)readRSSI;

/*!
 *  重置 watchDog 定时器
 */
- (void)resetWatchdog;

/*!
 *  关闭 watchDog 定时器
 */
- (void)invalidateWatchdog;

/*!
 *  如果 watchDog 超时，就断开连接
 */
- (void)watchdogDisconnect;

/*!
 *  连接到指定的蓝牙外设
 *
 *  @param options              任选参数，参考 CBCentralManagerConstants.h 文件
 *  @param connectCallBack      本次连接是否成功的回调
 *  @param disconnectCallBack   设备连接成功之后，如果后续是设备端主动断开，从这里返回
 */
- (void)connectWithOptions:(NSDictionary *)options
              connectBlock:(void (^)(MSCBPeripheral *peripheral, NSError *error))connectCallback
           disconnectBlock:(void (^)(MSCBPeripheral *peripheral, NSError *error))disconnectCallback;

/*!
 *  断开当前外设的连接
 */
- (void)cancelConnection;

/*!
 *  外设连接之后的处理
 *
 *  @param error                当前错误码
 */
- (void)handleConnectionResponse:(NSError *)error;

/*!
 *  外设断开之后的处理
 *
 *  @param error                当前错误码
 */
- (void)handleDisconnectionResponse:(NSError *)error;

/*!
 *  外设断开之后的缺省处理
 */
- (void)defaultConnectionHandler;

/*!
 *  连接外设成功之后，扫描外设的服务
 *
 *  @param serviceUUIDs         UUID 数组，用于扫描携带指定的服务
 *  @param callback             返回当前扫描到的服务，该 block 会多次回调，扫描到一个符合条件的服务就回调一次
 */
- (void)discoverServices:(NSArray *)serviceUUIDs withBlock:(void (^)(NSArray <MSCBService *> *services, NSError *error))callback;

@end

