//
//  MSCBService.h
//  MSmartSDK
//
//  Created by CC ZHOU on 16/3/1.
//  Copyright © 2016年 yellowsea. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>

@class MSCBService;
@class MSCBDescriptor;
@class MSCBCharacteristic;
@class MSCBPeripheral;

/*!
 *  MSCBService 是系统 CBService 的一个封装，主要提供一些服务管理功能，
 *  以及使用 block 的方式来替换原有系统复杂繁多的 delegate 回调的写法
 */
@interface MSCBService : NSObject

// 系统 CBService 实例
@property (nonatomic, strong) CBService *cbService;

// 记录当前服务是属于哪个 MSCBPeripheral 设备的
@property (nonatomic, weak) MSCBPeripheral *parent;

// 记录当前扫描到的特征
@property (atomic, strong) NSMutableArray *characteristicArray;

// 扫描外设特征的回调，该回调会回调多次 block
@property (nonatomic, copy) void (^discoverCharacteristicsCallback)(MSCBService *service, NSArray <MSCBCharacteristic * > *chArray, NSError *error);

// 给上层一个属性存储需要关联的数据
@property (nonatomic, strong) id userInfo;

/*!
 *  初始化 MSCBService 实例
 *
 *  @param cbChar           系统 CBService 实例
 *  @param pObj             当前特性归属的 MSCBPeripheral 实例
 */
- (instancetype)initWithCBService:(CBService *)cbService parent:(MSCBPeripheral *)pObj;

/*!
 *  获取当前外设下所有扫描到的特征
 *
 *  @return MSCBCharacteristic 数组
 */
- (NSArray *)characteristicUUIDs;

/*!
 *  同步系统特征到自己维护的特征里
 *
 *  @param foundCharacteristics MSCBCharacteristic 数组
 */
- (void)syncCharacteristics:(NSArray *)foundCharacteristics;

/*!
 *  根据系统 CBCharacteristic 实例，查找当前维护的 MSCBCharacteristic 实例
 *
 *  @param ct       系统 CBCharacteristic 实例
 *
 *  @return MSCBCharacteristic 实例
 */
- (MSCBCharacteristic *)findCharacteristic:(CBCharacteristic *)cbCharacteristic;

/*!
 *  收到特征值更新之后的处理
 *
 *  @param yc               系统 CBCharacteristic 实例
 *  @param error            当前错误码
 */
- (void)notifyCharacteristicHandler:(MSCBCharacteristic *)characteristic error:(NSError *)error;

/*!
 *  连接外设成功之后，扫描某个服务的特征
 *
 *  @param characteristicUUIDs  UUID 数组，用于扫描携带指定的特征
 *  @param callback             返回当前扫描到的特征，该 block 会多次回调，扫描到一个符合条件的特征就回调一次
 */
- (void)discoverCharacteristics:(NSArray *)characteristicUUIDs
                      withBlock:(void (^)(MSCBService *service, NSArray <MSCBCharacteristic * > *chArray, NSError *error))callback;

/*!
 *  扫描到特征之后的回调
 *
 *  @param MSCBService      MSCBService 实例
 *  @param chArray          MSCBCharacteristic 数组
 *  @param error            当前错误码
 */
- (void)handleDiscoveredCharacteristicsResponse:(MSCBService *)service chArray:(NSArray <MSCBCharacteristic * >*)chArray withError:(NSError *)error;

@end
