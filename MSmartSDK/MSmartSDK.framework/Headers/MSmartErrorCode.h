//
//  MSmartErrorCode.h
//  MSmartSDK
//
//  Created by yellowsea on 15/5/20.
//  Copyright (c) 2015年 yellowsea. All rights reserved.
//

#ifndef MSmartSDK_MSmartErrorCode_h
#define MSmartSDK_MSmartErrorCode_h

/**
 错误码定义 Error code definition
 
 @note 如出现2XXXX错误码，则为SDK未收录的服务器错误码，该错误码为XXXX.If the errorCode is 2XXXX,means that is the M-Cloud errorCode ,the errorCode is XXXX.

 - ERROR_SUCCESS: 执行成功 success
 - ERROR_INIT_SDK_FAILED: 初始化SDK失败,尚未初始化SDK或者未登录 Error initialized or didn’t login
 - ERROR_UNKNOW_ERROR: 未知错误 Unknown Error
 - ERROR_FAILD: 服务器9999错误 9999 error of server
 - ERROR_NETWORK_DISCONNECT: 无法连接网络 Network is not available
 - ERROR_REQUEST_ADDRESS_NULL: 请求的地址不存在 Request url not found
 - ERROR_PARAMS_NULL: 参数为空 Parameter Error, can’t be Null
 - ERROR_PARAMS_INVALID: 参数不合法 Invalid Parameter
 - ERROR_PARAMS_FORMAT_WRONG: 参数格式不正确 Format Error
 - ERROR_PARAMS_TOO_LONG: 参数值太长 Format too long
 - ERROR_NO_PERMISSION: 您没有权限进行该操作 Permission Denied
 - ERROR_SESSION_OUT: session失效 Invalid session
 - ERROR_APPID_NOT_EXIST: appid不存在 The appId does not exist
 - ERROR_UPDATE_FAILD: 获取更新信息失败 Failed to get update
 - ERROR_DATABASE_ERROR: 数据库错误 Database Error
 - ERROR_UPLOADLOG_FAILD: 上传错误日志失败 Failed to upload log
 - ERROR_LOGIN_FAILD: 用户登录失败,请重新登录 Login Failed, Please try again
 - ERROR_LOGIN_TOKEN: 获取登录token失败 Failed to get token
 - ERROR_LOGIN_GETTYPE: 获取设备类型失败 Failed to get device type
 - ERROR_LOGIN_HOMEGROUP: 获取家庭组失败 Failed to get home group
 - ERROR_LOGIN_MOBILENUM: 手机号不合规 Invalid Phone number
 - ERROR_LOGIN_EMAIL: 邮箱不合规 Invalid mail address
 - ERROR_LOGIN_EMAIL_OR_MOBILENUM: 密码或手机号不合规 Invalid phone number or password
 - ERROR_LOGIN_PASSWORD: 密码不合规 Invalid password
 - ERROR_LOGIN_ACCOUNT_ERROR: 美居返回账号或者密码错误 Error response (Account or Password) from M-Cloud
 - ERROR_LOGIN_ACCOUNT_NOT_EXIST: 账号不存在 Invalid Account
 - ERROR_LOGIN_TOKEN_INVALID: 验证token失败 Invalid token
 - ERROR_ANOTHER_LONIGED: 此账号在其他地方登陆 This account login on another device
 - ERROR_LOGIN_ACCOUNT_FORBIDDEN: 此账号被禁用 This Account is banned
 - ERROR_NOT_LONIGED: 没登录 You need to login first
 - ERROR_EMAIL_NOT_ACTIVE: 邮箱未激活 Account not actived
 - ERROR_EMAIL_ALREADY_REGISTER: 邮箱已经注册过了 This mail address is already registered
 - ERROR_ACCOUNT_ALREADY_ACTIVE: 账号已经激活了 The account is activated
 - ERROR_THIRD_ALREADY_BIND: 当前第三方用户已绑定 Refresh token is invalid
 - ERROR_THIRD_NOT_BIND: 当前第三方用户尚未绑定 Refresh token is expired
 - ERROR_PHONE_ALREADY_REGISTER: 手机已经注册过了 This Phone number is already registered
 - ERROR_VERTIFYCODE_WRONG: 验证码错误 Verify Code Error
 - ERROR_LOGIN_GET_DEVICE_FAILD: 登陆时同步设备列表失败 Get deviceList failed during login
 - ERROR_VERIFICATION_REPEAT: 重置密码的时候,反复调用重置接口 Verification code error,too many errors
 - ERROR_LOGINID_NULL: 服务器返回loginId为空 LoginId Null
 - ERROR_SERVER_BACKRESULT: 服务器返回result数据缺失 Error back result from M-Cloud
 - ERROR_SSID_INVALID: SSID错误 Invalid SSID
 - ERROR_QRCODE_INVALID: 二维码错误 Invalid QRCode
 - ERROR_DEVICE_TYPE_NOT_EXIST: 家电类型不存在 Device type does not exist in Midea Home
 - ERROR_SSID_PASSWORD_SEND: SSID和密码发送失败 Failed to send SSID and Password
 - ERROR_NETWORK_NOT_CHANGE: 网络未切换 Failed to change Wi-Fi network
 - ERROR_BIND_FAILED_CHECK_WIFI: 绑定失败，请检查wifi模块，请先链接上设备 AP Bind error, Please check the Wi-Fi module
 - ERROR_ACTIVE_FAILED: 远程激活失败 Active Failed
 - ERROR_DEVICE_ALREADY_IN_FAMILY: 设备已经在家庭中 Device already in family
 - ERROR_DEVICE_NOT_IN_FAMILY: 设备不在家庭中 Device not in family
 - ERROR_CONFIGURE_FAILED: 配置家电失败 Failed to configure the Appliance
 - ERROR_DEVICE_UNKNOW: 非美的设备 Unknown Device, the Wi-Fi AP SSID must start with fixed format
 - ERROR_CONNECT_FAILED: 美的设备链接失败 Failed to connect to Midea Appliance
 - ERROR_CONNECT_INIT_FAILED: 连接设备初始化失败 Failed to initialize the device connection
 - ERROR_WIFI_NETWORK_INVALID: 请先连接家庭WIFI Please connect to a Wi-Fi network first
 - ERROR_DEVICE_LIST_FAILED: 获取当前设备列表失败 Failed to get device list
 - ERROR_DEVICE_BINDINFO_FAILED: 同步设备信息失败 Failed to update the device info
 - ERROR_DEVICEID_INVALID: 设备ID错误(家电不存在) DeviceId Error, Device not exists
 - ERROR_NOT_ACTIVED: 设备没有激活(没有绑定) Device is not activated. Please bind it first
 - ERROR_DEVICE_OFFINE: 设备没有连接上广域网 Device is not connected to the WAN
 - ERROR_DEVICEINFO_ERROR: 同步家电信息失败 Synchronous device information failure
 - ERROR_DEVICEI_NOT_BELONG_FAMILY: 设备不属于家庭 Device does not belong to the family
 - ERROR_APPLIANCE_NULL: 设备ID为空 Appliance ID is null
 - ERROR_DEVICELIST_NULL_SCANLAN_FIRST: 请先扫描局域网 Please scan devices in the LAN first
 - ERROR_DEVICELIST_NOT_FOUND: 暂时找不到设备 No device found
 - ERROR_DEVICE_STARTIDENTIFY_BYDEVICE: 开始硬件鉴权 Hardware Authentication is in operation
 - ERROR_DEVICE_NEED_IDENTIFY: 设备需要鉴权 Please make the Device Authentication First
 - ERROR_DEVICE_TRANSPORT_OVERTIME: 数据透传超时 Data sending is timeout
 - ERROR_DEVICE_SN_INVALID: SN非法 DeviceSn is illegal
 - ERROR_DEVICE_IDENTIFY_TIMEOUT: 设备鉴权超时 Device authentication is timeout
 - ERROR_DEVICE_UNBIND_FAILD: 设备解绑失败 It is failed to unbind the device
 - ERROR_DEVICE_ALREADY_BIND: 设备已经被他人绑定 Device is already bound by other user
 - ERROR_DEVICE_ALREADY_YOURS: 设备已绑定过 Device is already bound
 - ERROR_DEVICE_LIST_NULL: 设备列表为空 No device found
 - ERROR_PRODUCTCODE_ALREADY_EXIST: 条形码已存在 Bar code exists
 - ERROR_DEVICE_SHARE_SELF: 设备不能分享给自己/不能向自己请求设备分享 Already your friends
 - ERROR_DEVICE_IN_HOME: 家庭中的设备不能被分享 Home device cannot be shared
 - ERROR_DEVICE_IDENTIFYBYDEVICE_FAILD: 设备主动鉴权失败 Device Authentication (issued from device) error
 - ERROR_DEVICE_IDENTIFYBYSLK_FAILD: SLK主动鉴权失败 Device Authentication (issued from SLK) error
 - ERROR_DEVICE_IDENTIFY_SUCCESSED: 鉴权成功 Authentication Successful
 - ERROR_DEVICE_UNABLE_GET_COUPONS: 该用户不能获取优惠券，没有资格获取优惠券 This user can’t get the coupons
 - ERROR_DEVICE_COUPON_RUN_OUT_OF: 优惠券已用完 No more Coupons
 - ERROR_DEVICE_COUPON_DECRYPT_ERROR: 优惠券code解密失败 Coupon code decrypt error
 - ERROR_DEVICE_COUPON_NOT_POINT: 该优惠券类型没有文案 Coupon not point
 - ERROR_DEVICE_NOT_IN_LAN: 设备不在局域网内 Device is not in LAN
 - ERROR_DEVICE_MODULEINFO_FAILED: 获取设备类型失败 Get module info failed
 - ERROR_MODULE_UPDATE_FAILED: 升级模块失败，超时 Update module failed
 - ERROR_MODULE_UPDATE_UNKNOW: 升级模块失败，未知消息 Update module unknow message
 - ERROR_MODULE_UPDATE_UNFINDFILE: 升级模块失败，升级文件未找到 Do not find file
 - ERROR_MODULE_UPDATE_DOWNLOAD_FAILED: 升级模块失败，下载错误 Download failed
 - ERROR_MODULE_UPDATE_CHECKSUM: 升级模块失败，升级Image文件checksum错误 CheckSum failed
 - ERROR_MODULE_UPDATE_TFTP_TIMEOUT: 升级模块失败，TFTP server响应超时 Tftp server is time out
 - ERROR_MODULE_UPDATE_WRONG_NAME: 升级模块失败，错误的文件名 File's name is wrong
 - ERROR_MODULE_UPDATE_PROTOCOL: 升级模块失败，协议不支持 The protocol is not supported
 - ERROR_MODULE_UPDATE_INDEX: 升级模块失败，无效的分区索引 Wrong index
 - ERROR_MODULE_UPDATE_IMAGEHDR: 升级模块失败，IMAGE_HDR错误 Image_hdr wrong
 - ERROR_MODULE_RESTART_FAILED: 重启模块失败 Restart module failed
 - ERROR_HOME_WIFI_BSSID_INVALID: 路由器Bssid不合法 Home WiFi BSSID invalid
 - ERROR_INVALID_FAMILY_ID: 家庭id不合法 Invalid Family ID
 - ERROR_USER_ALREADY_IN_FAMILY: 该用户已经是家庭成员 This user is already a member of this group
 - ERROR_USER_NOT_IN_FAMILY: 该用户不是家庭成员 This user is not a member of this group
 - ERROR_INVALID_USER_ID: 用户id不合法 Invalid User ID
 - ERROR_NOT_FAMILY_HEAD: 你不是该家庭家长，没有权限做此操作 Permission denied, you are not the owner of this group
 - ERROR_FAMILYMEMBER_GETFAILD: 获取家庭成员列表失败 Failed to get family members list
 - ERROR_FAMILY_NOT_EXIST: 家庭不存在 This Family not exists
 - ERROR_USER_NOT_INVITE_TO_FAMILY: 用户未申请加入家庭,或者未邀请用户加入家庭 The user is not invited to join the group
 - ERROR_FAMILY_HEAD_CANNOT_QUIT: 家长不能退出家庭 The owner of the group can’t leave the group
 - ERROR_CANNOT_MODIFY_CREATE_ROLE: 不能修改创建者角色 You can not modify the role of creator
 - ERROR_NONE_CREATER_ERROR: 家庭没有创建者 This family has no creator
 - ERROR_CREATOR_ERROR: 当前用户不是家庭创建者 You are not the owner of the group
 - ERROR_INVITE_REPEAT: 你已经邀请该用户了 You have already invited user
 - ERROR_FAMILYLIST_GETFAILD: 获取家庭列表失败 Failed to get family list
 - ERROR_ALEADY_SHARED: 设备已经分享给该用户了 The user have already shared the appliances
 - ERROR_DEVICE_REPORT: 家电特殊状态上报 Special Status reporting
 - ERROR_DEVICE_STATUS: 家电运行状态上报 Running status reporting
 - ERROR_BLE_OTA: 蓝牙 OTA 升级中出错 BLE OTA error
 - ERROR_B2BDEVICE_ALERT: b2b警戒推送 Alert status reporting
 - MSDevProtocolCmdError: 获取指令失败 Get command fail
 */
typedef NS_ENUM(NSInteger, MSmartErrorCode)
{

    ERROR_SUCCESS                       = 0,
    ERROR_INIT_SDK_FAILED               = -1,
    ERROR_UNKNOW_ERROR                  = 1000,
    ERROR_FAILD                         = 1001,
    ERROR_NETWORK_DISCONNECT            = 1002,
    ERROR_REQUEST_ADDRESS_NULL          = 1003,
    ERROR_PARAMS_NULL                   = 1004,
    ERROR_PARAMS_INVALID                = 1005,
    ERROR_PARAMS_FORMAT_WRONG           = 1006,
    ERROR_PARAMS_TOO_LONG               = 1007,
    ERROR_NO_PERMISSION                 = 1009,
    ERROR_SESSION_OUT                   = 1010,
    ERROR_APPID_NOT_EXIST               = 2002,
    ERROR_UPDATE_FAILD                  = 2003,
    ERROR_DATABASE_ERROR                = 2004,
    ERROR_UPLOADLOG_FAILD               = 2005,
    ERROR_LOGIN_FAILD                   = 3001,
    ERROR_LOGIN_TOKEN                   = 3002,
    ERROR_LOGIN_GETTYPE                 = 3003,
    ERROR_LOGIN_HOMEGROUP               = 3004,
    ERROR_LOGIN_MOBILENUM               = 3005,
    ERROR_LOGIN_EMAIL                   = 3006,
    ERROR_LOGIN_EMAIL_OR_MOBILENUM      = 3007,
    ERROR_LOGIN_PASSWORD                = 3008,
    ERROR_LOGIN_ACCOUNT_ERROR           = 3010,
    ERROR_LOGIN_ACCOUNT_NOT_EXIST       = 3011,
    ERROR_LOGIN_TOKEN_INVALID           = 3012,
    ERROR_ANOTHER_LONIGED               = 3013,
    ERROR_LOGIN_ACCOUNT_FORBIDDEN       = 3014,
    ERROR_NOT_LONIGED                   = 3015,
    ERROR_EMAIL_NOT_ACTIVE              = 3016,
    ERROR_EMAIL_ALREADY_REGISTER        = 3017,
    ERROR_ACCOUNT_ALREADY_ACTIVE        = 3020,
    ERROR_THIRD_ALREADY_BIND            = 3021,
    ERROR_THIRD_NOT_BIND                = 3022,
    ERROR_PHONE_ALREADY_REGISTER        = 3023,
    ERROR_VERTIFYCODE_WRONG             = 3024,
    ERROR_LOGIN_GET_DEVICE_FAILD        = 3026,
    ERROR_VERIFICATION_REPEAT           = 3027,
    ERROR_LOGINID_NULL                  = 3028,
    ERROR_SERVER_BACKRESULT             = 3029,
    ERROR_SSID_INVALID                  = 4001,
    ERROR_QRCODE_INVALID                = 4002,
    ERROR_DEVICE_TYPE_NOT_EXIST         = 4005,
    ERROR_SSID_PASSWORD_SEND            = 4010,
    ERROR_NETWORK_NOT_CHANGE            = 4011,
    ERROR_BIND_FAILED_CHECK_WIFI        = 4018,
    ERROR_ACTIVE_FAILED                 = 4020,
    ERROR_DEVICE_ALREADY_IN_FAMILY      = 4022,
    ERROR_DEVICE_NOT_IN_FAMILY          = 4023,
    ERROR_CONFIGURE_FAILED              = 4025,
    ERROR_DEVICE_UNKNOW                 = 4026,
    ERROR_CONNECT_FAILED                = 4027,
    ERROR_CONNECT_INIT_FAILED           = 4028,
    ERROR_WIFI_NETWORK_INVALID          = 4029,
    ERROR_DEVICE_LIST_FAILED            = 4030,
    ERROR_DEVICE_BINDINFO_FAILED        = 4031,
    ERROR_DEVICEID_INVALID              = 4032,
    ERROR_NOT_ACTIVED                   = 4033,
    ERROR_DEVICE_OFFINE                 = 4034,
    ERROR_DEVICEINFO_ERROR              = 4035,
    ERROR_DEVICEI_NOT_BELONG_FAMILY     = 4036,
    ERROR_APPLIANCE_NULL                = 4037,
    ERROR_DEVICELIST_NULL_SCANLAN_FIRST = 4038,
    ERROR_DEVICELIST_NOT_FOUND          = 4039,
    ERROR_DEVICE_STARTIDENTIFY_BYDEVICE = 4040,
    ERROR_DEVICE_NEED_IDENTIFY          = 4041,
    ERROR_DEVICE_TRANSPORT_OVERTIME     = 4042,
    ERROR_DEVICE_SN_INVALID             = 4044,
    ERROR_DEVICE_IDENTIFY_TIMEOUT       = 4047,
    ERROR_DEVICE_UNBIND_FAILD           = 4048,
    ERROR_DEVICE_ALREADY_BIND           = 4049,
    ERROR_DEVICE_ALREADY_YOURS          = 4050,
    ERROR_DEVICE_LIST_NULL              = 4052,
    ERROR_PRODUCTCODE_ALREADY_EXIST     = 4053,
    ERROR_DEVICE_SHARE_SELF             = 4054,
    ERROR_DEVICE_IN_HOME                = 4055,
    ERROR_DEVICE_IDENTIFYBYDEVICE_FAILD = 4056,
    ERROR_DEVICE_IDENTIFYBYSLK_FAILD    = 4057,
    ERROR_DEVICE_IDENTIFY_SUCCESSED     = 4058,
    ERROR_DEVICE_UNABLE_GET_COUPONS     = 4059,
    ERROR_DEVICE_COUPON_RUN_OUT_OF      = 4060,
    ERROR_DEVICE_COUPON_DECRYPT_ERROR   = 4061,
    ERROR_DEVICE_COUPON_NOT_POINT       = 4062,
    ERROR_DEVICE_NOT_IN_LAN             = 4063,
    ERROR_DEVICE_MODULEINFO_FAILED      = 4064,
    ERROR_MODULE_UPDATE_FAILED          = 4065,
    ERROR_MODULE_UPDATE_UNKNOW          = 4067,
    ERROR_MODULE_UPDATE_UNFINDFILE      = 4068,
    ERROR_MODULE_UPDATE_DOWNLOAD_FAILED = 4069,
    ERROR_MODULE_UPDATE_CHECKSUM        = 4070,
    ERROR_MODULE_UPDATE_TFTP_TIMEOUT    = 4071,
    ERROR_MODULE_UPDATE_WRONG_NAME      = 4072,
    ERROR_MODULE_UPDATE_PROTOCOL        = 4073,
    ERROR_MODULE_UPDATE_INDEX           = 4074,
    ERROR_MODULE_UPDATE_IMAGEHDR        = 4075,
    ERROR_MODULE_RESTART_FAILED         = 4076,
    ERROR_HOME_WIFI_BSSID_INVALID       = 4078,
    ERROR_INVALID_FAMILY_ID             = 6002,
    ERROR_USER_ALREADY_IN_FAMILY        = 6003,
    ERROR_USER_NOT_IN_FAMILY            = 6004,
    ERROR_INVALID_USER_ID               = 6005,
    ERROR_NOT_FAMILY_HEAD               = 6006,
    ERROR_FAMILYMEMBER_GETFAILD         = 6007,
    ERROR_FAMILY_NOT_EXIST              = 6009,
    ERROR_USER_NOT_INVITE_TO_FAMILY     = 6010,
    ERROR_FAMILY_HEAD_CANNOT_QUIT       = 6011,
    ERROR_CANNOT_MODIFY_CREATE_ROLE     = 6013,
    ERROR_NONE_CREATER_ERROR            = 6014,
    ERROR_CREATOR_ERROR                 = 6015,
    ERROR_INVITE_REPEAT                 = 6016,
    ERROR_FAMILYLIST_GETFAILD           = 6017,
    ERROR_ALEADY_SHARED                 = 7006,
    ERROR_DEVICE_REPORT                 = 9001,
    ERROR_DEVICE_STATUS                 = 9002,
    ERROR_BLE_OTA                       = 10001,
    ERROR_B2BDEVICE_ALERT               = 11001,
    MSDevProtocolCmdError               = 30012,
    
};

#endif
