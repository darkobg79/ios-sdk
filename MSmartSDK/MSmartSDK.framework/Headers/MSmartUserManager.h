//
//  MSmartUserManager.h
//  MSmartSDK
//
//  Created by yellowsea on 15/5/19.
//  Copyright (c) 2015年 yellowsea. All rights reserved.
//

#import "MSmartBaseManager.h"
#import "MSmartDefinition.h"

@interface MSmartUserManager : MSmartBaseManager

/**
 Class of UserManager.

 @since (mainland/overseas)  (group/single user)
 @return Class of UserManager
 
 **Example:**
 
  MSmartUserManager* manager = [MSmartUserManager sharedManager];
 
  [manager MSmartTestModel:@"join us!"];
 */
+ (MSmartUserManager *)sharedManager;

#pragma mark - Login method 1. by Token.

/**
 Login with thirdToken. You can only login the SDK after the SDK initialization.

 @since (mainland)  (group/single user)
 @param account user account
 @param thirdToken authenticate token
 @param completion Async call
 
  - error.code contains: 0 succeed >0 failed, detailed definition in MSmartErrorCode or error.localizedDescription
 */
- (void)loginSDKWithAccount:(NSString *)account
                      token:(NSString *)thirdToken
                 completion:(void (^)(NSError *error))completion;

/**
 Register a new account via SDK by token.

 @since (mainland)  (group/single user)
 @param account user account(email or phone)
 @param password user password
 @param nickName user nickname
 @param thirdToken authenticate token
 @param completion Async call

  - error.code contains: 0 succeed >0 failed, detailed definition in MSmartErrorCode or error.localizedDescription
 */
- (void)registerSDKWithAccount:(NSString *)account
                       password:(NSString *)password
                       nickName:(NSString *)nickName
                          token:(NSString *)thirdToken
                     completion:(void (^)(NSError *error))completion;

#pragma mark - Login method 2. by M-cloud account.

/**
 Login with M-cloud account. You can only login the SDK after the SDK initialization.

 @since (mainland/overseas)  (group/single user)
 @param account user account(email or phone）
 @param password user password (6-12)
 @param extraDic extra parameter dictionary (Please refer to MSmartDefinition.h for detailed Dictionry key.)
 
  - kMSServerKeyPushToken    ：push token
  - kMSServerKeyAppVNum      ：app version
  - kMSServerKeyPhoneModel   ：cell phone model
  - kMSServerKeySystemVersion：system version of cell phone
 
 @param completion Async call
 
  - error.code contains: 0 succeed >0 failed, detailed definition in MSmartErrorCode or error.localizedDescription
  - dict：user information（if error.code > 0 dict = nil),please refer to MSmartDefinition.h for detailed Dictionry key.
 
    - kMSServerKeyVersionCode:the support of app minimum version
 
  - familysOrUsers：family list in family mode；user list in friend mode
  - devices：appliance list
 */
- (void)loginWithAccount:(NSString *)account
                 password:(NSString *)password
                 extraDic:(NSDictionary *)extraDic
               completion:(void (^)(NSError *error, NSDictionary *dict, NSArray *familysOrUsers, NSArray *devices))completion;

/**
 Register an account with cell phone number.

 @since (mainland)  (group/single user)
 @note call getVerifyCodeWithPhoneNum first.
 @param phoneNum user cell phone
 @param password user password
 @param verifyCode verifyCode
 @param nickName user nickname
 @param completion Async call
 
  - error.code contains: 0 succeed >0 failed, detailed definition in MSmartErrorCode or error.localizedDescription
 */
- (void) registerWithPhoneNum:(NSString *)phoneNum
                     password:(NSString *)password
                   verifyCode:(NSString *)verifyCode
                     nickName:(NSString *)nickName
                   completion:(void (^)(NSError *error))completion;

/**
 Register an account with email.

 @since (mainland/overseas)  (group/single user)
 @param email user email
 @param password user password
 @param nickName user nickname
 @param extraDic extra parameter dictionary,(Please refer to MSmartDefinition.h for detailed Dictionry key.)
 
  - kMSServerKeyNeedActive：need active flag;
 
    - kMSServerValueActiveTrue:need active；
    - kMSServerValueActiveFalse:need not active,
 @param completion Async call
 
  - error.code contains: 0 succeed >0 failed, detailed definition in MSmartErrorCode or error.localizedDescription
 */
- (void) registerWithEmail:(NSString *)email
                  password:(NSString *)password
                  nickName:(NSString *)nickName
                  extraDic:(NSDictionary *)extraDic
                completion:(void (^)(NSError *error))completion;

#pragma mark - Login method 3. by third platform token (for QQ , WeChat)

/**
 Login with third platform token (for QQ , WeChat)

 @since (mainland)  (group/single user)
 @param accessToken access token
 @param thirdUid third ID
 @param nickName user nickname
 @param pushToken push token
 @param srcPlatform platform type，detailed definition in MSmartThirdPlatform
 @param paramters extra parameter dictionary
 
  - kMSServerKeyAppVNum
 @param completion Async call
 
  - error.code contains: 0 succeed >0 failed, detailed definition in MSmartErrorCode or error.localizedDescription
  - userInfo:user information
  - familysOrUsers:
 
    - family list in family mode；
    - user list in friend mode
  - devices：appliance list
 */
- (void)userThirdLoginWithAccessToken:(NSString *)accessToken
                             thirdUid:(NSString *)thirdUid
                             nickName:(NSString *)nickName
                            pushToken:(NSString *)pushToken
                          srcPlatform:(MSmartThirdPlatform)srcPlatform
                            paramters:(NSDictionary *)paramters
                           completion:(void (^)(NSError *error,NSDictionary *userInfo, NSArray *familysOrUsers, NSArray *devices))completion;

/**
 Get verify code with cell phone number.

 @since (mainland)  (group/single user)
 @param phoneNum cell phone number
 @param verifyType authenticate type,detailed definition in MSmartGetVerifyType
 @param completion Async call
 
  - error.code contains: 0 succeed >0 failed, detailed definition in MSmartErrorCode or error.localizedDescription
 */
- (void)getVerifyCodeWithPhoneNum:(NSString *)phoneNum
                           andType:(MSmartGetVerifyType)verifyType
                        completion:(void (^)(NSError *error))completion;

/**
 Data storage after engineer account login

 @since (mainland)  (group)
 @param result the dictionary after login {sessionId, userId, nickName, accessToken}
 @param completion Async call
 
  - error.code contains: 0 succeed >0 failed, detailed definition in MSmartErrorCode or error.localizedDescription
 */
- (void)saveDataWithResultAfterLogin:(NSDictionary *)result completion:(void (^)(NSError *error))completion;

/**
 Logout

 @since (mainland/overseas)  (group/single user)
 @param completion Async call
 
  - error.code contains: 0 succeed >0 failed, detailed definition in MSmartErrorCode or error.localizedDescription
 */
- (void)logoutWithCompletion:(void (^)(NSError *error))completion;

/**
 Reset password by email

 @since (mainland/overseas)  (group/single user)
 @param email user email
 @param completion Async call
 
  - error.code contains: 0 succeed >0 failed, detailed definition in MSmartErrorCode or error.localizedDescription
 */
- (void)resetUserPasswordWithEmail:(NSString *)email
                        completion:(void (^)(NSError *error))completion;

/**
 Reset password by phone

 @since (mainland)  (group/single user)
 @param phoneNum user phone
 @param verifyCode verification code
 @param newPassword new password
 @param completion Async call
 
  - error.code contains: 0 succeed >0 failed, detailed definition in MSmartErrorCode or error.localizedDescription
 */
- (void)resetUserPasswordWithPhoneNum:(NSString *)phoneNum
                        andVerifyCode:(NSString *)verifyCode
                       andNewPassword:(NSString *)newPassword
                           completion:(void (^)(NSError *error))completion;

/**
 Modify password

 @since (mainland/overseas)  (group/single user)
 @param newPwd new password
 @param oldPwd old password
 @param completion Async call
 
  - error.code contains: 0 succeed >0 failed, detailed definition in MSmartErrorCode or error.localizedDescription
 */
- (void)modifyUserPassword:(NSString *)newPwd
                    oldPwd:(NSString *)oldPwd
                completion:(void (^)(NSError *error))completion;

/**
 Modify the binded cell phone number

 @since (mainland)  (group/single user)
 @param newMobile new cell phone number
 @param password user password
 @param veryfyCode verification code
 @param completion Async call
 
  - error.code contains: 0 succeed >0 failed, detailed definition in MSmartErrorCode or error.localizedDescription
 */
- (void)userMobileModifyWithNewMobile:(NSString *)newMobile
                          andPassword:(NSString *)password
                        andVerifyCode:(NSString *)veryfyCode
                           completion:(void (^)(NSError *error))completion;

/**
 Get the "userID" of the current account

 @since (mainland/overseas)  (group/single user)
 @return the logined user ID,if not login return @"0"
 */
- (NSString *)loginUserId;

/**
 Search user information of a specific account

 @since (mainland/overseas)  (group/single user)
 @param account user account
 @param completion Async call
 
  - error.code contains: 0 succeed >0 failed, detailed definition in MSmartErrorCode or error.localizedDescription
  - userInfo：user information
 */
- (void)searchUserByLoginAccount:(NSString *)account
                      completion:(void (^)(NSError *error,NSDictionary *userInfo))completion;

/**
 The session is valid for two hours after login. You need to update session every two hours.

 @since (mainland/overseas)  (group/single user)
 @param completion Async call
 
  - error.code contains: 0 succeed >0 failed, detailed definition in MSmartErrorCode or error.localizedDescription
 */
- (void)updateSessionIdCompletion:(void (^)(NSError *error))completion;

/**
 Create sub account by uuid

 @since (mainland)  (group/single user)
 @param uuid uuid(a uniquely identify of a device)
 @param completion Async call,Please refer to MSmartDefinition.h for detailed Dictionry key
 
  - error.code contains: 0 succeed >0 failed, detailed definition in MSmartErrorCode or error.localizedDescription
  - dic:user information
 
   - kMSSDKQRCode:a qrcode string with uuid and sub account
 */
- (void)createSubAccountWithUuid:(NSString *)uuid completion:(void (^)(NSError *error,NSDictionary *dic))completion;

/**
 Bind sub account

 @since (mainland)  (group/single user)
 @param uuid uuid(a uniquely identify of a device)(ciphertext)
 @param subAccount sub account
 @param completion Async call
 
  - error.code contains: 0 succeed >0 failed, detailed definition in MSmartErrorCode or error.localizedDescription
 */
- (void)bindSubAccountWithUuid:(NSString *)uuid subAccout:(NSString *)subAccount completion:(void (^)(NSError *error))completion;


- (void) loginWithPhoneNum:(NSString*)phoneNum
                  password:(NSString*)password
                completion:(void (^)(NSError* error))completion __deprecated_msg("Use `- (void) loginWithAccount:(NSString *)account password:(NSString *)password extraDic:(NSDictionary *)extraDic completion:(void (^)(NSError *error, NSDictionary *dict, NSArray *familysOrUsers, NSArray *devices))completion;` instead.");


- (void) registerWithEmail:(NSString *)email
                  password:(NSString *)password
                  nickName:(NSString *)nickName
                completion:(void (^)(NSError *error))completion __deprecated_msg("Use `- (void) registerWithEmail:(NSString *)email password:(NSString *)password nickName:(NSString *)nickName extraDic:(NSDictionary *)extraDic completion:(void (^)(NSError *error))completion` instead.");


- (void) loginWithEmail:(NSString *)email
               password:(NSString *)password
             completion:(void (^)(NSError *error))completion __deprecated_msg("Use `- (void) loginWithAccount:(NSString *)account password:(NSString *)password extraDic:(NSDictionary *)extraDic completion:(void (^)(NSError *error, NSDictionary *dict, NSArray *familysOrUsers, NSArray *devices))completion;` instead.");

#pragma mark - 带pushToken的登陆

- (void)loginWithAccount:(NSString *)account
            hashPassword:(NSString *)hashPassword
               pushToken:(NSString *)pushToken
              completion:(void (^)(NSError *error))completion __deprecated_msg("Use `- (void) loginWithAccount:(NSString *)account password:(NSString *)password extraDic:(NSDictionary *)extraDic completion:(void (^)(NSError *error, NSDictionary *dict, NSArray *familysOrUsers, NSArray *devices))completion;` instead.");

#pragma mark - 带pushToken 的登录

- (void)loginWithAccount:(NSString *)account
      SHA256HashPassword:(NSString *)SHA256HashPassword
         MD5HashPassword:(NSString *)MD5HashPassword
               pushToken:(NSString *)pushToken
              appInfoDic:(NSDictionary *)appInfoDic
              completion:(void (^)(NSError *error,NSDictionary *userInfo))completion __deprecated_msg("Use `- (void) loginWithAccount:(NSString *)account password:(NSString *)password extraDic:(NSDictionary *)extraDic completion:(void (^)(NSError *error, NSDictionary *dict, NSArray *familysOrUsers, NSArray *devices))completion;` instead.");

- (void)loginWithAccount:(NSString *)account
      SHA256HashPassword:(NSString *)SHA256HashPassword
         MD5HashPassword:(NSString *)MD5HashPassword
               pushToken:(NSString *)pushToken
              appInfoDic:(NSDictionary *)appInfoDic
      completionWithInfo:(void (^)(NSError *error, NSDictionary *dict, NSArray *familysOrUsers, NSArray *devices))completion __deprecated_msg("Use `- (void) loginWithAccount:(NSString *)account password:(NSString *)password extraDic:(NSDictionary *)extraDic completion:(void (^)(NSError *error, NSDictionary *dict, NSArray *familysOrUsers, NSArray *devices))completion;` instead.");


- (void)loginWithAccount:(NSString *)account
            hashPassword:(NSString *)hashPassword
               pushToken:(NSString *)pushToken
              appInfoDic:(NSDictionary *)appInfoDic
              completion:(void (^)(NSError *error,NSDictionary *userInfo))completion __deprecated_msg("Use `- (void) loginWithAccount:(NSString *)account password:(NSString *)password extraDic:(NSDictionary *)extraDic completion:(void (^)(NSError *error, NSDictionary *dict, NSArray *familysOrUsers, NSArray *devices))completion;` instead.");

@end
