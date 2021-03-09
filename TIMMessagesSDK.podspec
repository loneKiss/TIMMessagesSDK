
Pod::Spec.new do |spec|

spec.name         = "TIMMessagesSDK"
spec.version      = "1.0.2"
spec.summary      = "TIMMessagesSDK for IOS"
spec.description  = "TIMMessagesSDK.framework一款用于即时视频聊天通讯的sdk"
spec.homepage     = "https://github.com/loneKiss/TIMMessagesSDK"
spec.license      = { :type => "MIT", :file => "LICENSE" }
spec.author       = { "loneKiss" => "775865767@qq.com" }
spec.platform     = :ios, "9.0"
spec.source       = { :git => "https://github.com/loneKiss/TIMMessagesSDK.git", :tag => spec.version }
spec.resources       = ['TIMMessagesSDKReadme.md']
spec.vendored_frameworks = "TIMMessagesSDK/Frameworks/*.framework"

spec.source_files = 'TIMMessagesSDK/Headers/*.h'

spec.dependency 'TXIMSDK_iOS','4.9.1' #TIMSDK中无UI库
spec.dependency 'TXLiteAVSDK_TRTC','7.8.9519' #音视频库

# 图片，其他资源文件存放的路径，需要注意的是，xib，nib也属于资源文件
spec.resource_bundles = {
    # 这是个数组，可以添加其他bundle
    'MessagesSDK' => ['TIMMessagesSDK/Resources/LocalResources/*'],
  }
  
 spec.resource = ['TIMMessagesSDK/Resources/Bundles/TUIKitFace.bundle',
                  'TIMMessagesSDK/Resources/Bundles/TUIKitResource.bundle'
                  ]

spec.requires_arc    = true

spec.pod_target_xcconfig = {
    'FRAMEWORK_SEARCH_PATHS' => '$(inherited) $(PODS_ROOT)/**',
    'HEADER_SEARCH_PATHS' => '$(inherited) $(PODS_ROOT)/**',
    'VALID_ARCHS' => 'armv7 arm64 x86_64',
    'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64'
  }
  
spec.user_target_xcconfig = {
     'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64'
     
  }
 
end
