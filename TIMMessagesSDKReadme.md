# TIMMessagesSDK
一款用于即时视频聊天通讯的sdk

一、即时通讯sdk
TIMMessagesSDK.framework为即时通讯的组件
pod 'TIMMessagesSDK' 

TIMMessagesSDK依赖于TIMSDK中的
pod 'TXIMSDK_iOS',
pod 'TXLiteAVSDK_TRTC'
TXIMSDK_iOS无UI库以及TXLiteAVSDK_TRTC 音视频库

二、会议系统sdk
TVMeetingSDK.framework为会议系统组件
pod 'TVMeetingSDK' 
TVMeetingSDK依赖于NemoSDK,所以不需要下载NemoSDK,直接pod 'TVMeetingSDK' 即可
即时通讯sdk在会议系统sdk基础上开发出的即时通讯,与会议系统共用一套通讯录,因此需要自行导入会议系统sdk,为了方便单独升级即时通讯sdk和会议系统sdk,所以不直接导入两者的依赖关系

三、小鱼sdk
NemoSDK.framework

(1)在Xcode的Build Phases页面中，将NemoSDK.framework添加到Link Binary With Libraries；

(2)并将NemoSDK.framework添加到Copy Files，Destination选择Frameworks。

三、cocoapods依赖库

#聊天通讯相关pod
pod 'ISVImageScrollView' , '~> 0.1.2'
pod 'MMLayout', '~> 0.2.0'
pod 'ReactiveObjC'
pod 'Toast', '~> 4.0.0'
pod 'TXIMSDK_iOS', '~>4.8.10'
pod 'TXLiteAVSDK_TRTC'
#聊天通讯相关pod

#会议系统相关pod
pod 'AFNetworking', '~> 3.2.1'
pod 'MBProgressHUD', '~> 1.1.0'
pod 'LBXScan/LBXNative','~> 2.3' #只安装系统原生API封装库
pod 'LBXScan/LBXZXing','~> 2.3'  #只安装ZXing封装库
pod 'LBXScan/LBXZBar','~> 2.3'   #只安装ZBar封装库
pod 'LBXScan/UI','~> 2.3'        #只安装UI
pod 'SDAutoLayout'
pod 'HDAlertView'                #自定义alertView
pod 'MJRefresh'
pod 'IQKeyboardManager'
pod 'SDWebImage','5.1.1'
pod 'MJExtension'
pod 'Masonry'
pod 'TZImagePickerController'
pod 'PPBadgeView','~> 2.1.0'
pod 'TVMeetingSDK' #会议系统sdk
#会议系统相关pod
四、组件的使用
1、#import <TVMeetingSDK/MT_TabBarController.h>
      #import <TVMeetingSDK/MT_UserManager.h>
      #import <MessagesSDK/TIM_UserManager.h>
     
2、先初始化会议系统主控制器MT_TabBarController
3、再调用初始化会议系统的方法
4、如果要切换不同的环境，修改projectVersion这个参数的传入值，0：代表生产环境； 1代表pre环境；-1代表测试环境；

if (!TARGET_IPHONE_SIMULATOR) { ///仅支持真机调试
    /** 初始化消息sdk主控制器*/
    [[MT_UserManager shareUserManager]initMeetingSDK:[[NSClassFromString(@"ConversationController") alloc]init]];
    MT_TabBarController *meetTabBar = [[MT_TabBarController alloc]init];
    [self.navigationController pushViewController:meetTabBar animated:YES];
    // 初始化小鱼sdk
    // 在这里调用会议系统初始化方法
    [[TIM_UserManager shareUserManager] TIM_saveAccountId:@"会议系统用户id" andAccountName:@" 会议系统用户名字" andFishAccountId:@"小鱼id" andAccessToken:@"登录会议系统的token" andRefreshToken:@" 刷新会议系统的token" andProjectToken:@"集成项目的token" withProjectVerson:0];
    //初始化旋转屏幕block代码块
    AppDelegate *appDelegate = (AppDelegate *)[UIApplication sharedApplication].delegate;
    [MT_UserManager shareUserManager].didRotatingScreen = ^(BOOL allowRotation) {
        appDelegate.allowRotation = allowRotation;
    };
    
}
