//
//  MSmartTools.h
//  MSmartSDK
//
//  Created by CC ZHOU on 16/4/27.
//  Copyright © 2016年 yellowsea. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MSmartTool : NSObject

/**
 获取当前连接的Wifi SSID get current Wifi SSID

 @return Wifi SSID
 */
+ (NSString *)currentWifiSSID;

/**
 获取当前Wifi MAC地址 get current Wifi BSSID

 @return 当前Wifi MAC地址
 */
+ (NSString *)currentWifiBSSID;

/**
 获得当前手机型号 get current phone model

 @return 手机型号
 */
+ (NSString *)currentPhoneModel;

/**
 获得当前手机系统版本信息 get current phone system version

 @return 系统版本信息
 */
+ (NSString *)currentMobileSystemVersion;

/**
 mac地址格式转换 "C8:0F:10:0B:FF:F5" ---> <c80f100bfff5>

 @param string mac地址字符串
 @return 转化后的数值
 */
+ (NSData *)macFromHexStringToBinary:(NSString *)string;

/**
 mac地址格式转换 <c80f100bfff5> ---> "C8:0F:10:0B:FF:F5"

 @param data mac地址
 @return 地址格式转换的 NSString
 */
+ (NSString *)macFromBinaryToHexString:(NSData *)data;

/**
 mac地址格式转换 "C80F100BFFF5" ---> <c80f100bfff5>

 @param hexStr 地址字符串
 @return 十六进制数值
 */
+ (NSData *)hexStrToNSData:(NSString *)hexStr;

/**
 mac地址格式转换 <c80f100bfff5> ---> "C80F100BFFF5"

 @param hexData 十六进制数值
 @return 十六进制字符串
 */
+ (NSString *)hexDataToNSString:(NSData *)hexData;

/**
 十进制数组转换成十六进制数组

 @param intArray 十进制数组
 @return 十六进制数组
 */
+ (NSMutableArray *)getHexArray:(NSArray *)intArray;

/**
 URL 解码，解决乱码的问题

 @param stringURL URL字符串
 @return UTF-8 编码的 url
 */
+ (NSString *)decodeURL:(NSString *)stringURL;

/**
 把空转换成空字符串 nil to @""

 @param str 目标字符串
 @return 非空串
 */
+ (NSString *)valueOfString:(NSString *)str;

/**
 获取日期格式化后的字符串

 @param date 日期
 @param format 格式字符串
 @return 格式化的日期字符串
 */
+ (NSString *)getNSStringFromNSDate:(NSDate *)date withFormat:(NSString *)format;

/**
 是否有效的手机号码格式

 @param string 手机号码
 @return YES or NO
 */
+ (BOOL)isValidPhoneNumber:(NSString *)string;

/**
 是否有效的邮箱格式

 @param string 邮箱地址
 @return YES or NO
 */
+ (BOOL)isValidEmail:(NSString *)string;

@end
