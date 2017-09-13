//
//  MSmartBluetoothManager.h
//  MSmartSDK
//
//  Created by CC ZHOU on 16/3/1.
//  Copyright © 2016年 yellowsea. All rights reserved.
//

#import "MSmartSDK.h"
#import "MSCBCentralManager.h"
#import "MSCBPeripheral.h"
#import "MSBleCommonDevice.h"
#import "MSBleCommonFrame.h"

/*#
 *  使用[[NSNotificationCenter defaultCenter] addObserver:observer selector:@selector(yourSelector:) BluetoothNotification object:nil];
 *  
 *  来监听家电往 SDK 发送(回复)过来的命令(数据)包 和返回的错误
 *
 *  NSNotification 的 object 是一个字典，必定包含一个 key 为 @"msgType", 为 NSNumber, 可能值为以下。
 *
 *  @param msgType       推送消息类型, 请先转成 int 型使用, 详情请参见 MSmartDefinition.h 里的 BleNotifyType
 *
 *      BleNotifyType_DidUpdateCentralState                         = 0,//!< 蓝牙开关状态
 *      BleNotifyType_DidDiscoverPeripheral                         = 1,//!< 发现蓝牙设备
 *      BleNotifyType_DidConnectPeripheral                          = 2,//!< 蓝牙设备连上
 *      BleNotifyType_DidDisconnectPeripheral                       = 3,//!< 蓝牙设备断开
 *      BleNotifyType_DidFailToConnectPeripheral                    = 4,//!< 蓝牙设备连接失败
 *      BleNotifyType_DidDiscoverServices                           = 5,//!< 发现蓝牙服务
 *      BleNotifyType_DidDiscoverCharacteristicsForService          = 6,//!< 发现服务的特征
 *      BleNotifyType_DidDiscoverDescriptorsForCharacteristic       = 7,//!< 发现特征的特征描述
 *      BleNotifyType_DidUpdateValueForCharacteristic               = 8,//!< 收到特征上的数据更新
 *      BleNotifyType_DidUpdateValueForDescriptor                   = 9,//!< 收到特征描述上的数据更新
 *      BleNotifyType_DidUpdateNotificationStateForCharacteristic   = 10,//!< 订阅状态通知
 *      BleNotifyType_DidWriteValueForCharacteristic                = 11,//!< 写特征值响应
 *      BleNotifyType_DidWriteValueForDescriptor                    = 12,//!< 写特征描述响应
 *      BleNotifyType_DidUpdatePeripheralRSSI                       = 13,//!< 设备信号RSSI更新通知
 *      BleNotifyType_DidUpdatePeripheralName                       = 14,//!< 设备更名通知
 *
 *  消息类型不同，字典里包含的内容也不同
 * 
 *      BleNotifyType_DidUpdateCentralState
 *
 *              dic里包括 {
 *                      key:@"msgType"          type:NSNumber (enum BleNotifyType)          消息类型标识
 *                      key:@"state"            type:NSNumber (enum CBCentralManagerState)  蓝牙开启状态
 *                    }
 *
 *      BleNotifyType_DidDiscoverPeripheral
 *
 *              dic里包括 {
 *                      key:@"msgType"          type:NSNumber (enum BleNotifyType)  消息类型标识
 *                      key:@"peripheral"       type:MSCBPeripheral                 蓝牙设备
 *                    }
 *
 *      BleNotifyType_DidConnectPeripheral
 *
 *              dic里包括 {
 *                      key:@"msgType"          type:NSNumber (enum BleNotifyType)  消息类型标识
 *                      key:@"peripheral"       type:MSCBPeripheral                 蓝牙设备
 *                    }
 *
 *      BleNotifyType_DidDisconnectPeripheral
 *
 *              dic里包括 {
 *                      key:@"msgType"          type:NSNumber (enum BleNotifyType)  消息类型标识
 *                      key:@"peripheral"       type:MSCBPeripheral                 蓝牙设备
 *                      key:@"error"            type:NSError                        错误信息
 *                    }
 *
 *      BleNotifyType_DidFailToConnectPeripheral
 *
 *              dic里包括 {
 *                      key:@"msgType"          type:NSNumber (enum BleNotifyType)  消息类型标识
 *                      key:@"peripheral"       type:MSCBPeripheral                 蓝牙设备
 *                      key:@"error"            type:NSError                        错误信息
 *                    }
 *
 *      BleNotifyType_DidDiscoverServices
 *
 *              dic里包括 {
 *                      key:@"msgType"          type:NSNumber (enum BleNotifyType)  消息类型标识
 *                      key:@"peripheral"       type:MSCBPeripheral                 蓝牙设备
 *                      key:@"error"            type:NSError                        错误信息
 *                    }
 *
 *      BleNotifyType_DidDiscoverCharacteristicsForService
 *
 *              dic里包括 {
 *                      key:@"msgType"          type:NSNumber (enum BleNotifyType)  消息类型标识
 *                      key:@"peripheral"       type:MSCBPeripheral                 蓝牙设备
 *                      key:@"service"          type:MSCBService                    蓝牙服务
 *                      key:@"error"            type:NSError                        错误信息
 *                    }
 *
 *      BleNotifyType_DidDiscoverDescriptorsForCharacteristic
 *
 *              dic里包括 {
 *                      key:@"msgType"          type:NSNumber (enum BleNotifyType)  消息类型标识
 *                      key:@"peripheral"       type:MSCBPeripheral                 蓝牙设备
 *                      key:@"characteristic"   type:MSCBCharacteristic             蓝牙特征
 *                      key:@"error"            type:NSError                        错误信息
 *                    }
 *
 *      BleNotifyType_DidUpdateValueForCharacteristic
 *
 *              dic里包括 {
 *                      key:@"msgType"          type:NSNumber (enum BleNotifyType)  消息类型标识
 *                      key:@"peripheral"       type:MSCBPeripheral                 蓝牙设备
 *                      key:@"characteristic"   type:MSCBCharacteristic             蓝牙特征
 *                      key:@"data"             type:NSData                         蓝牙数据包
 *                      key:@"error"            type:NSError                        错误信息
 *                    }
 *
 *      BleNotifyType_DidUpdateValueForDescriptor
 *
 *              dic里包括 {
 *                      key:@"msgType"          type:NSNumber (enum BleNotifyType)  消息类型标识
 *                      key:@"peripheral"       type:MSCBPeripheral                 蓝牙设备
 *                      key:@"descriptor"       type:MSCBDescriptor                 蓝牙特征描述
 *                      key:@"data"             type:NSData                         蓝牙数据包
 *                      key:@"error"            type:NSError                        错误信息
 *                    }
 *
 *      BleNotifyType_DidUpdateNotificationStateForCharacteristic
 *
 *              dic里包括 {
 *                      key:@"msgType"          type:NSNumber (enum BleNotifyType)  消息类型标识
 *                      key:@"peripheral"       type:MSCBPeripheral                 蓝牙设备
 *                      key:@"characteristic"   type:MSCBCharacteristic             蓝牙特征
 *                      key:@"error"            type:NSError                        错误信息
 *                    }
 *
 *      BleNotifyType_DidWriteValueForCharacteristic
 *
 *              dic里包括 {
 *                      key:@"msgType"          type:NSNumber (enum BleNotifyType)  消息类型标识
 *                      key:@"peripheral"       type:MSCBPeripheral                 蓝牙设备
 *                      key:@"characteristic"   type:MSCBCharacteristic             蓝牙特征
 *                      key:@"error"            type:NSError                        错误信息
 *                    }
 *
 *      BleNotifyType_DidWriteValueForDescriptor
 *
 *              dic里包括 {
 *                      key:@"msgType"          type:NSNumber (enum BleNotifyType)  消息类型标识
 *                      key:@"peripheral"       type:MSCBPeripheral                 蓝牙设备
 *                      key:@"descriptor"       type:MSCBDescriptor                 蓝牙特征描述
 *                      key:@"error"            type:NSError                        错误信息
 *                    }
 *
 *      BleNotifyType_DidUpdatePeripheralRSSI
 *
 *              dic里包括 {
 *                      key:@"msgType"          type:NSNumber (enum BleNotifyType)  消息类型标识
 *                      key:@"peripheral"       type:MSCBPeripheral                 蓝牙设备
 *                      key:@"error"            type:NSError                        错误信息
 *                    }
 *
 *      BleNotifyType_DidUpdatePeripheralName
 *
 *              dic里包括 {
 *                      key:@"msgType"          type:NSNumber (enum BleNotifyType)  消息类型标识
 *                      key:@"peripheral"       type:MSCBPeripheral                 蓝牙设备
 *                    }
 *
 **/
FOUNDATION_EXTERN NSString *const BluetoothNotification;

@interface MSmartBluetoothManager : MSmartBaseManager

/*!
 * 服务器管理类的单例，考虑到 app 作为 Central 端使用的场景较多，目前不支持 Peripheral 端
 *
 * @return 蓝牙设备管理类的单例
 *
 * @Example:
 *
 * MSmartBluetoothManager *manager = [MSmartBluetoothManager sharedManager];
 **/
+ (MSmartBluetoothManager *)sharedManager;

/*!
 *  设置回调函数监控系统蓝牙开启状态
 *
 *  @param updateStateCallBack 系统上报蓝牙当前开启状态的 block
 */
- (void)setCentralManagerDidUpdateState:(void (^)(MSCBCentralManager *central, CBCentralManagerState state))updateStateCallBack;

/*!
 *  扫描周边蓝牙外设
 *  如果只想扫描指定类型的外设，比如只扫描小米手环，原理上是根据设备特征码来区分类型，但如果不同厂商特征码有重复，
 *  只能进一步根据设备名称或者别的参数来细化过滤，只根据 UUID 并不能确定唯一性
 *
 *  @param serviceUUIDs     UUID 数组，用于扫描携带指定服务的蓝牙外设
 *  @param options          任选参数，参考 CBCentralManagerConstants.h 文件
 *  @param filterBlock      只扫描外设名字符合某个规范的设备，如只扫描小米设备，可以只扫描 MI 开头的设备
 *  @param discoverCallback 返回当前扫描到的蓝牙外设，该 block 会多次回调，扫描到一个符合条件的设备就回调一次
 */
- (void)scanPeripheralsWithServices:(NSArray <CBUUID *> *)serviceUUIDs
                            options:(NSDictionary *)options
                        filterBlock:(BOOL (^)(NSString *peripheralName))filterBlock
                   discoverCallback:(void (^)(MSCBPeripheral *peripheral, NSError *error))discoverCallback;

/*!
 *  停止扫描蓝牙外设，如果已经找到需要连接的外设，就停止扫描，系统并不会自己停止，会一直扫描下去
 */
- (void)stopScanPeripherals;

/*!
 *  连接到指定的蓝牙外设
 *
 *  @param peripheral         之前扫描设备时，返回的 MSCBPeripheral 对象
 *  @param options            任选参数，参考 CBCentralManagerConstants.h 文件
 *  @param connectCallBack    本次连接是否成功的回调
 *  @param disconnectCallBack 设备连接成功之后，如果后续是设备端主动断开，从这里返回
 */
- (void)connectToPeripheral:(MSCBPeripheral *)peripheral
                    options:(NSDictionary *)options
            connectCallBack:(void (^)(MSCBPeripheral *peripheral, NSError *error))connectCallBack
         disconnectCallBack:(void (^)(MSCBPeripheral *peripheral, NSError *error))disconnectCallBack;

/*!
 *  本端主动断开外设
 *
 *  @param peripheral         之前扫描设备时，返回的 MSCBPeripheral 对象
 *  @param disconnectCallBack 本次断开是否成功的回调
 */
- (void)disconnectToPeripheral:(MSCBPeripheral *)peripheral
            disconnectCallBack:(void (^)(MSCBPeripheral *peripheral, NSError *error))disconnectCallBack;


/**
 *  连接外设成功之后，扫描外设的服务
 *
 *  @param peripheral       之前扫描设备时，返回的 MSCBPeripheral 对象
 *  @param serviceUUIDs     UUID 数组，用于扫描携带指定的服务
 *  @param discoverCallBack 返回当前扫描到的服务，该 block 会多次回调，扫描到一个符合条件的服务就回调一次
 */
- (void)discoverServicesOnPeripheral:(MSCBPeripheral *)peripheral
                        serviceUUIDs:(NSArray <CBUUID *> *)serviceUUIDs
                    discoverCallBack:(void (^)(NSArray <MSCBService *> *array, NSError *error))discoverCallBack;

/*!
 *  连接外设成功之后，扫描某个服务的特征
 *
 *  @param service             之前扫描外设服务时，返回的 MSCBService 对象
 *  @param characteristicUUIDs UUID 数组，用于扫描携带指定的特征
 *  @param discoverCallBack    返回当前扫描到的特征，该 block 会多次回调，扫描到一个符合条件的特征就回调一次
 */
- (void)discoverCharacteristicsInService:(MSCBService *)service
                     characteristicUUIDs:(NSArray <CBUUID *> *)characteristicUUIDs
                        discoverCallBack:(void (^)(MSCBService *service, NSArray <MSCBCharacteristic *> *chArray, NSError *error))discoverCallBack;

/*!
 *  连接外设成功之后，扫描某个特征的特征描述
 *
 *  @param characteristics  之前扫描特征时，返回的 MSCBCharacteristic 对象
 *  @param discoverCallBack 返回当前扫描到的特征描述，该 block 会多次回调，扫描到一个符合条件的特征描述就回调一次
 */
- (void)discoverDescriptorsInCharacteristics:(MSCBCharacteristic *)characteristics
                            discoverCallBack:(void (^)(NSArray <MSCBDescriptor *> *array, NSError *error))discoverCallBack;

/*!
 *  从特征读取数据, 最大 MTU 目前测试发现在不同系统版本上表现不同
 *
 *  在 iOS 7 上，一次读的数据最大只能读到 134 个字节（包括 134），大于 134 的，系统直接截断，导致数据丢失
 *  在 iOS 9 上，一次读的最大数据只能读到 628 个字节（包括 628），大于 628 的，系统直接截断，导致数据丢失
 *
 *  如果是 iOS 9 和 iOS 7 蓝牙互通，iOS 9 上读取数据范围在（156，628）之间的，iOS 7 系统会自己拆分为 157 字节一个包后，
 *  再发往 iOS 9 这边，所以 iOS 7 这边会收到多次读请求，但请求里的 offset 不同，所以 iOS 7 这边需要根据 offset 来计算
 *  偏移并多次发送数据，iOS 9 那边并不会多次收到读数据回调，只会收到一次回调
 *
 *  @param characteristics  之前扫描特征时，返回的 MSCBCharacteristic 对象
 *  @param readCallback     返回从当前特征上读取的数据
 */
- (void)readValueFromCharacteristics:(MSCBCharacteristic *)characteristics
                        readCallback:(void (^)(MSCBCharacteristic *character, NSData *value, NSError *error))readCallback;

/*!
 *  往特征发送数据，最大 MTU 目前测试发现在不同系统版本上表现不同
 *  
 *  在 iOS 7 上，一次写的数据最大只能写 155 个字节（包括 155），大于 155 的，系统直接返回错误 Unknown error
 *  在 iOS 9 上，一次写的最大数据只能写 512 个字节（包括 512），大于 512 的，系统直接返回错误 Unknown error
 *
 *  如果是 iOS 9 和 iOS 7 蓝牙互通，iOS 9 上发送数据范围在（155，512）之间的，iOS 7 系统收到之后会自己拆分为 153 字节
 *  一个包再报给上层，所以 iOS 7 这边会收到多次写请求，但请求里的 offset 不同，iOS 7 这边需要根据 offset 来合并数据
 *
 *  实际测试蓝牙传输速度:两个iPhone手机，一个做中心，一个做外设，平均传输速度只有 1.8k/s
 *
 *  @param characteristics 之前扫描特征时，返回的 MSCBCharacteristic 对象
 *  @param data            需要发送的数据
 *  @param writeCallback   本次数据是否发送成功的回调，传入 nil 表示当前写操作，不需要对端响应
 */
- (void)writeValueToCharacteristics:(MSCBCharacteristic *)characteristics
                               data:(NSData *)data
                      writeCallback:(void (^)(MSCBCharacteristic *character, NSError *error))writeCallback;

/*!
 *  订阅某个特征的数据，后续该特征有数据更新时，会主动通知本端
 *
 *  @param characteristics     之前扫描特征时，返回的 MSCBCharacteristic 对象
 *  @param notifyValue         YES:开启订阅，NO:关闭订阅
 *  @param notifyStateCallback 本次发起订阅的操作是否成功的回调
 *  @param notifyValueCallback 订阅成功之后，后续数据更新通知的回调
 */
- (void)setNotifyValueForCharacteristics:(MSCBCharacteristic *)characteristics
                             notifyValue:(BOOL)notifyValue
                     notifyStateCallback:(void (^)(MSCBCharacteristic *character, NSError *error))notifyStateCallback
                     notifyValueCallback:(void (^)(MSCBCharacteristic *character, NSData *value, NSError *error))notifyValueCallback;

/*!
 *  从特征读取数据
 *
 *  @param descriptor   之前扫描特征描述时，返回的 MSCBDescriptor 对象
 *  @param readCallback 返回从当前特征描述上读取的数据
 */
- (void)readValueFromDescriptor:(MSCBDescriptor *)descriptor
                   readCallback:(void (^)(MSCBDescriptor *descrip, NSData *value, NSError *error))readCallback;

/*!
 *  往特征描述发送数据
 *
 *  @param descriptor    之前扫描特征描述时，返回的 MSCBDescriptor 对象
 *  @param data          需要发送的数据
 *  @param writeCallback 本次数据是否发送成功的回调, 传入 nil 表示当前写操作，不需要对端响应
 */
- (void)writeValueToDescriptor:(MSCBDescriptor *)descriptor
                          data:(NSData *)data
                 writeCallback:(void (^)(MSCBDescriptor *descrip, NSError *error))writeCallback;

/*!
 *  断开所有目前已经连接上的外设
 */
- (void)disconnectAllPeripheralsConnection;

/*!
 *  获取当前连接中的设备
 *
 *  @return 当前连接中的设备 MSCBPeripheral 对象数组
 */
- (NSArray<MSCBPeripheral *> *)findAllPeripherals;

/**
 *  mac地址格式转换 C8:0F:10:0B:FF:F5 ---> <c80f100bfff5>
 *
 *  @param string mac地址
 *
 *  @return mac地址格式转换的NSData
 */
+ (NSData *)macFromHexStringToBinary:(NSString *)string;

/**
 *   mac地址格式转换 <c80f100bfff5> ---> C8:0F:10:0B:FF:F5
 *
 *  @param data mac地址
 *
 *  @return mac地址格式转换的NSData
 */
+ (NSString *)macFromBinaryToHexString:(NSData *)data;

@end
