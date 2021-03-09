//
//  TIM_Single.h
//  jsh-app-message-ios
//
//  Created by 巨商汇 on 2020/6/9.
//  Copyright © 2020 巨商汇. All rights reserved.
//

//拼接方法名
/** 创建单例的方法 */
#define TIM_InterfaceSingle(name) +(instancetype)share##name;
/** 销毁单例的方法 */
#define TIM_InterfaceDestroySingle(name) +(void)destory##name;

#if __has_feature(objc_arc)
// 如果是ARC

#define TIM_ImplementationSingle(name) +(instancetype)share##name\
\
{\
return [[self alloc]init];\
}\
static id _instance;\
static dispatch_once_t onceToken;\
+(instancetype)allocWithZone:(struct _NSZone *)zone\
{\
dispatch_once(&onceToken, ^{\
_instance = [super allocWithZone:zone];\
});\
return _instance;\
}\
-(id)copyWithZone:(NSZone *)zone\
{\
return _instance;\
}\
-(id)mutableCopyWithZone:(NSZone *)zone\
{\
return _instance;\
}
#define TIM_ImplementationDestroySingle(name) +(void)destory##name\
\
{\
_instance = nil;\
onceToken = 0l;\
}
#else
//如果是MRC
#define TIM_ImplementationSingle(name) +(instancetype)share##name\
\
{\
return [[self alloc]init];\
}\
static id _instance;\
static dispatch_once_t onceToken;\
+(instancetype)allocWithZone:(struct _NSZone *)zone\
{\
dispatch_once(&onceToken, ^{\
_instance = [super allocWithZone:zone];\
});\
return _instance;\
}\
-(id)copyWithZone:(NSZone *)zone\
{\
return _instance;\
}\
-(id)mutableCopyWithZone:(NSZone *)zone\
{\
return _instance;\
}\
-(oneway void)release\
{}\
-(instancetype)retain\
{\
return _instance;\
}\
-(NSUInteger)retainCount\
{\
return MAXFLOAT;\
}
#define TIM_ImplementationDestroySingle(name) +(void)destory##name\
\
{\
_instance = nil;\
onceToken = 0l;\
}
#endif
