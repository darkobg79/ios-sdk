//
//  MSCBCentralManager.h
//  MSmartSDK
//
//  Created by CC ZHOU on 16/3/1.
//  Copyright © 2016年 yellowsea. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "MSCBPeripheral.h"
#import "MSCBService.h"
#import "MSCBCharacteristic.h"

@class MSCBPeripheral;
@class MSCBCentralManager;

/*!
 *  MSCBCentralManager 是系统 CBCentralManager 的一个封装，主要提供一些外设管理功能，
 *  以及使用 block 的方式来替换原有系统复杂繁多的 delegate 回调的写法
 */
@interface MSCBCentralManager : NSObject <CBCentralManagerDelegate>

// 系统 CBCentralManagerDelegate 回调，用了 block 之后，基本不会用这个
@property (nonatomic, weak) id<CBCentralManagerDelegate> delegate;

// 系统 CBCentralManager 实例
@property (nonatomic, strong) CBCentralManager *manager;

// 用于判断当前蓝牙是否已经在扫描中
@property (nonatomic, assign) BOOL isScanning;

// 记录当前已经发现的外设
@property (atomic, strong) NSMutableDictionary *findPeripherals;

// 记录当前已经连接上的外设
@property (atomic, strong) NSMutableArray *ymsPeripherals;

// 当开启扫描外设之后，一旦系统发现外设，会回调这个 block，这个 block 会回调多次
@property (nonatomic, copy) void (^discoveredCallback)(MSCBPeripheral *peripheral, NSError *error);

// 提供一个 block 根据扫描到的设备名称来过滤外设，比如 只扫描 MI 开头的小米设备
@property (nonatomic, copy) BOOL (^filterOnDiscoverPeripherals)(NSString *peripheralName);

// 监听蓝牙开关状态的 block，比如当前蓝牙开启，蓝牙关闭
@property (nonatomic, copy) void (^updateStateCallback)(MSCBCentralManager *central, CBCentralManagerState state);

// 蓝牙重连的 bloc
@property (nonatomic, copy) void (^retrievedCallback)(MSCBPeripheral *peripheral);

// 给上层一个属性存储需要关联的数据
@property (nonatomic, strong) id userInfo;

#pragma mark - Constructors

/*!
 *  初始化 MSCBCentralManager 实例
 *
 *  @param queue            回调函数在哪个队列里处理
 *  @param delegate         delegate
 */
- (instancetype)initWithQueue:(dispatch_queue_t)queue delegate:(id)delegate;

#pragma mark - Peripheral Management

/*!
 *  初始化 MSCBCentralManager 实例
 *
 *  @param queue            回调函数在哪个队列里处理
 *  @param delegate         delegate
 */
- (void)handleFoundPeripheral:(MSCBPeripheral *)peripheral;

/*!
 *  将需要连接的外设 MSCBPeripheral 实例添加到 ymsPeripherals 数组里
 *
 *  @param yperipheral      发现的蓝牙外设
 */
- (void)addPeripheral:(MSCBPeripheral *)peripheral;

/*!
 *  将需要断开的外设 MSCBPeripheral 实例从 ymsPeripherals 数组里移除
 *
 *  @param yperipheral      发现的蓝牙外设
 */
- (void)removePeripheral:(MSCBPeripheral *)peripheral;

/*!
 *  删除 ymsPeripherals 数组里所有连接中的外设
 */
- (void)removeAllPeripherals;

/*!
 *  根据系统 CBPeripheral 实例，查找当前维护的 MSCBPeripheral 实例
 *
 *  @param peripheral       系统外设实例
 *
 *  @return MSCBPeripheral 实例
 */
- (MSCBPeripheral *)findPeripheral:(CBPeripheral *)cbPeripheral;

/*!
 *  根据外设名称，查找当前维护的 MSCBPeripheral 实例
 *
 *  @param peripheralName   外设名称
 *
 *  @return MSCBPeripheral 实例
 */
- (MSCBPeripheral *)findPeripheralByName:(NSString *)peripheralName;

#pragma mark - Scan Methods

/*!
 *  扫描周边蓝牙外设
 *
 *  @param serviceUUIDs         UUID 数组，用于扫描携带指定服务的蓝牙外设
 *  @param options              任选参数，参考 CBCentralManagerConstants.h 文件
 */
- (void)scanForPeripheralsWithServices:(NSArray *)serviceUUIDs options:(NSDictionary *)options;

/*!
 *  扫描周边蓝牙外设
 *  如果只想扫描指定类型的外设，比如只扫描小米手环，原理上是根据设备特征码来区分类型，但如果不同厂商特征码有重复，
 *  只能进一步根据设备名称或者别的参数来细化过滤，只根据 UUID 并不能确定唯一性
 *
 *  @param serviceUUIDs         UUID 数组，用于扫描携带指定服务的蓝牙外设
 *  @param options              任选参数，参考 CBCentralManagerConstants.h 文件
 *  @param filterBlock          只扫描外设名字符合某个规范的设备，如只扫描小米设备，可以只扫描 MI 开头的设备
 *  @param discoverCallback     返回当前扫描到的蓝牙外设，该 block 会多次回调，扫描到一个符合条件的设备就回调一次
 */
- (void)scanForPeripheralsWithServices:(NSArray *)serviceUUIDs
                               options:(NSDictionary *)options
                           filterBlock:(BOOL (^)(NSString *peripheralName))filterBlock
                             withBlock:(void (^)(MSCBPeripheral *peripheral, NSError *error))discoverCallback;

/*!
 *  停止扫描蓝牙外设，如果已经找到需要连接的外设，就停止扫描，系统并不会自己停止，会一直扫描下去
 */
- (void)stopScan;

#pragma mark - Retrieve Methods

/*!
 *  获取已知 peripheral 设备的列表，这些设备是我们已经搜索并连接过的设备。
 *  如果我们查找的 peripheral 在列表中，则尝试重新连接
 *
 *  @param identifiers   CBPeripheral UUID 数组
 *
 *  @return NSArray CBPeripheral数组
 */
- (NSArray *)retrievePeripheralsWithIdentifiers:(NSArray *)identifiers;

/*!
 *  获取当前连接到系统的peripheral设备的列表。如果我们查找的peripheral设备在列表中，则连接它
 *
 *  @param serviceUUIDS   CBService UUID 数组
 *
 *  @return NSArray CBPeripheral数组
 */
- (NSArray *)retrieveConnectedPeripheralsWithServices:(NSArray *)serviceUUIDS;

@end

