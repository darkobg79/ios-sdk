//
//  MSRandomNumObject.h
//  MSmartSDK
//
//  Created by hh on 16/8/22.
//  Copyright © 2016年 yellowsea. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MSRandomNumObject : NSObject

+ (MSRandomNumObject*) sharedManager;

- (NSString *)produceRandomNumWithRandomA:(int *)randomA
                                  randomB:(int *)randomB
                              routerBssid:(NSString *)bssid
                               routerSsid:(NSString *)ssid
                                routerPwd:(NSString *)pwd;


@end
