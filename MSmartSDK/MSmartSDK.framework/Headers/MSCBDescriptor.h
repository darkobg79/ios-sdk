//
//  MSCBDescriptor.h
//  MSmartSDK
//
//  Created by CC ZHOU on 16/3/1.
//  Copyright © 2016年 yellowsea. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>

@class MSCBPeripheral;
@class MSCBDescriptor;
@class MSCBCharacteristic;

/*!
 *  MSCBDescriptor 是系统 CBDescriptor 的一个封装，主要提供一些特征管理功能，
 *  以及使用 block 的方式来替换原有系统复杂繁多的 delegate 回调的写法
 */
@interface MSCBDescriptor : NSObject

// 系统 CBDescriptor 实例
@property (nonatomic, strong) CBDescriptor *cbDescriptor;

// 记录当前特征描述是属于哪个 MSCBPeripheral 设备的
@property (nonatomic, weak) MSCBPeripheral *parent;

// 当读取某个特征描述的值时，系统会回调这个 block
@property (nonatomic, copy) void (^readCallback)(MSCBDescriptor *descriptor, NSData *data, NSError *error);

// 当给某个特征描述写数据时，系统会回调这个 block
@property (nonatomic, copy) void (^writeCallback)(MSCBDescriptor *descriptor, NSError *error);

// 给上层一个属性存储需要关联的数据
@property (nonatomic, strong) id userInfo;

/*!
 *  往特征描述发送数据
 *
 *  @param data                 需要发送的数据
 *  @param writeCallback        本次数据是否发送成功的回调, 传入 nil 表示当前写操作，不需要对端响应
 */
- (void)writeValue:(NSData *)data withBlock:(void (^)(MSCBDescriptor *descriptor, NSError *error))writeCallback;

/*!
 *  往特征描述发送数据
 *
 *  @param val                  需要发送的数据
 *  @param writeCallback        本次数据是否发送成功的回调, 传入 nil 表示当前写操作，不需要对端响应
 */
- (void)writeByte:(int8_t)val withBlock:(void (^)(MSCBDescriptor *descriptor, NSError *error))writeCallback;

/*!
 *  从特征描述读取数据
 *
 *  @param readCallback         返回从当前特征描述上读取的数据
 */
- (void)readValueWithBlock:(void (^)(MSCBDescriptor *descriptor, NSData *data, NSError *error))readCallback;

/*!
 *  当前特征描述读到数据之后的处理
 *
 *  @param character            系统 MSCBDescriptor 实例
 *  @param error                当前错误码
 */
- (void)executeReadCallback:(MSCBDescriptor *)descriptor error:(NSError *)error;

/*!
 *  当前特征描述写数据之后的处理
 *
 *  @param character            系统 MSCBDescriptor 实例
 *  @param error                当前错误码
 */
- (void)executeWriteCallback:(MSCBDescriptor *)descriptor error:(NSError *)error;

@end
