//
//  MSCBCharacteristic.h
//  MSmartSDK
//
//  Created by CC ZHOU on 16/3/1.
//  Copyright © 2016年 yellowsea. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>

@class MSCBPeripheral;
@class MSCBCharacteristic;
@class MSCBDescriptor;

/*!
 *  MSCBCharacteristic 是系统 CBCharacteristic 的一个封装，主要提供一些特征管理功能，
 *  以及使用 block 的方式来替换原有系统复杂繁多的 delegate 回调的写法
 */
@interface MSCBCharacteristic : NSObject

// 系统 CBCharacteristic 实例
@property (atomic, strong) CBCharacteristic *cbCharacteristic;

// 记录当前特征是属于哪个 MSCBPeripheral 设备的
@property (nonatomic, weak) MSCBPeripheral *parent;

// 记录当前发现的所有特征描述 MSCBDescriptor 的数组
@property (atomic, strong) NSMutableArray *descriptorArray;

// 当订阅这个特征之后，是否订阅成功，会回调这个 block
@property (atomic, copy) void (^notificationStateCallback)(MSCBCharacteristic *characteristic, NSError *error);

// 当订阅这个特征成功之后，当这个特征上有值更新时，会回调这个 block
@property (atomic, copy) void (^notificationValueCallback)(MSCBCharacteristic *characteristic, NSData *value, NSError *error);

// 当扫描到某个特征的特征描述之后，系统会回调这个 block
@property (atomic, copy) void (^discoverDescriptorsCallback)(NSArray <MSCBDescriptor *> *array, NSError *error);

// 当读取某个特征的值时，系统会回调这个 block
@property (atomic, copy) void (^readCallback)(MSCBCharacteristic *characteristic, NSData *data, NSError *error);

// 当给某个特征写数据时，系统会回调这个 block
@property (atomic, copy) void (^writeCallback)(MSCBCharacteristic *characteristic, NSError *error);

// 给上层一个属性存储需要关联的数据
@property (nonatomic, strong) id userInfo;

/*!
 *  初始化 MSCBCharacteristic 实例
 *
 *  @param cbChar           系统 CBCharacteristic 实例
 *  @param pObj             当前特性归属的 MSCBPeripheral 实例
 */
- (instancetype)initWithCharacteristic:(CBCharacteristic *)cbCharacteristic parent:(MSCBPeripheral *)pObj;

/*!
 *  当前特征收到数据更新之后的处理
 *
 *  @param cbChar           系统 CBCharacteristic 实例
 *  @param error            当前错误码
 */
- (void)executeNotificationStateCallback:(MSCBCharacteristic *)characteristic error:(NSError *)error;

/*!
 *  当前特征读到数据之后的处理
 *
 *  @param cbChar           系统 CBCharacteristic 实例
 *  @param error            当前错误码
 */
- (void)executeReadCallback:(MSCBCharacteristic *)characteristic error:(NSError *)error;

/*!
 *  当前特征写数据之后的处理
 *
 *  @param cbChar           系统 CBCharacteristic 实例
 *  @param error            当前错误码
 */
- (void)executeWriteCallback:(MSCBCharacteristic *)characteristic error:(NSError *)error;

/*!
 *  订阅某个特征的数据，后续该特征有数据更新时，会主动通知本端
 *
 *  @param notifyValue              YES:开启订阅，NO:关闭订阅
 *  @param notifyStateCallback      本次发起订阅的操作是否成功的回调
 *  @param notifyValueCallback      订阅成功之后，后续数据更新通知的回调
 */
- (void)setNotifyValue:(BOOL)notifyValue
             withBlock:(void (^)(MSCBCharacteristic *characteristic, NSError *error))notifyStateCallback
   notifyValueCallback:(void (^)(MSCBCharacteristic *characteristic, NSData *data, NSError *error))notifyValueCallback;

/*!
 *  往特征描述发送数据
 *
 *  @param data             需要发送的数据
 *  @param writeCallback    本次数据是否发送成功的回调, 传入 nil 表示当前写操作，不需要对端响应
 */
- (void)writeValue:(NSData *)data withBlock:(void (^)(MSCBCharacteristic *characteristic, NSError *error))writeCallback;

/*!
 *  往特征描述发送数据
 *
 *  @param val              需要发送的数据
 *  @param writeCallback    本次数据是否发送成功的回调, 传入 nil 表示当前写操作，不需要对端响应
 */
- (void)writeByte:(int8_t)val withBlock:(void (^)(MSCBCharacteristic *characteristic, NSError *error))writeCallback;

/*!
 *  从特征读取数据
 *
 *  @param readCallback     返回从当前特征描述上读取的数据
 */
- (void)readValueWithBlock:(void (^)(MSCBCharacteristic *characteristic, NSData *data, NSError *error))readCallback;

/*!
 *  连接外设成功之后，扫描某个特征的特征描述
 *
 *  @param callback         返回当前扫描到的特征描述，该 block 会多次回调，扫描到一个符合条件的特征描述就回调一次
 */
- (void)discoverDescriptorsWithBlock:(void (^)(NSArray <MSCBDescriptor *> *array, NSError *error))callback;

/*!
 *  扫描到特征描述之后的回调
 *
 *  @param ydescriptors     MSCBDescriptor 数组
 *  @param error            当前错误码
 */
- (void)handleDiscoveredDescriptorsResponse:(NSArray <MSCBDescriptor *>*)ydescriptors withError:(NSError *)error;

/*!
 *  根据系统 CBDescriptor 实例，查找当前维护的 MSCBDescriptor 实例
 *
 *  @param ct               系统特征描述实例
 *
 *  @return MSCBDescriptor  实例
 */
- (MSCBDescriptor *)findDescriptor:(CBDescriptor *)cbDescriptor;

/*!
 *  同步系统特征描述到自己维护的特征描述里
 *
 *  @param foundDescriptors CBDescriptor 数组
 */
- (void)syncDescriptors:(NSArray <CBDescriptor *>*)foundDescriptors;

@end
