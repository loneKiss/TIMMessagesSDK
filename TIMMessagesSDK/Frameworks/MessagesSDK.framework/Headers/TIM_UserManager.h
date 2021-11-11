//
//  TIM_UserManager.h
//  jsh-app-message-ios
//
//  Created by 巨商汇 on 2020/6/9.
//  Copyright © 2020 巨商汇. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TIM_Single.h"

NS_ASSUME_NONNULL_BEGIN

@interface TIM_UserManager : NSObject

TIM_InterfaceSingle(UserManager)

TIM_InterfaceDestroySingle(UserManager)

@property (nonatomic, strong) UIViewController *controller;

/**
 *  初始化会议系统
 *
 *  @param accountId                 用户id
 *  @param accountName               用户名字
 *  @param fishAccountId             小鱼id
 *  @param accessToken               登录token
 *  @param refreshToken              刷新登录token
 *  @param projectToken              集成项目的token
 *  @param versonType                项目环境配置
 *  @param parentVC                  父控制器
 */
- (void)TIM_saveAccountId:(NSString *)accountId andAccountName:(NSString *)accountName andFishAccountId:(NSString *)fishAccountId andAccessToken:(NSString *)accessToken andRefreshToken:(NSString *)refreshToken andProjectToken:(NSString *)projectToken andProjectVerson:(NSInteger)versonType
    withParentVC:(UIViewController *)parentVC;

/**
 *  极光推送初始化会议系统
 *
 *  @param userInfo                  极光推送进入会议系统初始化字典
 *  @param versonType                项目环境配置
 *  @param parentVC                  父控制器
 */
- (void)setUpMessageSDKWithDictionary:(NSMutableDictionary *)userInfo andProjectVerson:(NSInteger)versonType withParentVC:(UIViewController *)parentVC;

- (void)saveDepartmentType:(NSString *)departmentType;
/** 保存开发环境 */
- (void)saveMT_Version_Type:(NSInteger)versonType;
/** source 会议:1 群聊:2 */
- (void)saveSource:(NSString *)source;
- (NSString *)getSource;
- (void)saveTimDeviceToken:(NSData *)deviceToken;
- (NSData *)getTimDeviceToken;

/** 刷新会议系统登录token */
- (void)getMeetingRefreshToken;
/** 取值 */
-(NSString *)getAccountId;
- (NSString *)getAccessToken;
- (NSString *)getRefreshToken;
- (NSString *)getProjectToken;
-(NSString *)getDepartmentType;

-(int)getTimSdkAppid;
-(NSString *)getTimSecretkey;

/** 是否显示首字母索引条状态 */
- (void)saveIsIndexes:(BOOL)indexes;
- (BOOL)getIsIndexes;
 /** 登录会议系统 */
-(void)loginMeetingAction;
/** 退出登录 */
-(void)logOutTIM;

/** 获取项目环境配置请求地址 */
-(NSString *)getMeetingCommonUrlWithProjectName:(NSString *)projectName;

/** 获取项目环境配置外置项目工程请求地址 */
-(NSString *)getOutSideProjectCommonUrlWithProjectName:(NSString *)projectName;

/**
 @brief 获取sdk版本号
 */
+ (NSString *)getSDKVersion;

@end

NS_ASSUME_NONNULL_END
