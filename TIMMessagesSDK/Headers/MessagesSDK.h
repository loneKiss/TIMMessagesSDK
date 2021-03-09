//
//  MessagesSDK.h
//  MessagesSDK
//
//  Created by 王青森 on 2020/4/3.
//  Copyright © 2020 jsh. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface MessagesSDK : NSObject<NSCopying,NSMutableCopying>


/** 单例 */
+(instancetype)shareMessagesSDK;

@property (strong, nonatomic) UIWindow *window;

- (void)launch;
- (void)didEnterBackground;
- (void)willEnterForeground;
- (void)didBecomeActive;

@end

NS_ASSUME_NONNULL_END
