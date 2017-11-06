#
# Be sure to run `pod lib lint MSmartSDK.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'MSmartSDK'
  s.version          = '0.1.6'
  s.summary          = 'MSmartSDK，集成文档见http://iot.midea.com/develop/docshow/ios'
  s.description      = 'MSmartSDK，集成文档见http://iot.midea.com/develop/docshow/ios'
  s.homepage         = 'https://github.com/midea-sdk-org/ios-sdk'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'midea-smart' => 'libing.deng@midea.com' }
  s.source           = { :git => 'https://github.com/midea-sdk-org/ios-sdk.git', :tag => s.version.to_s }

  s.ios.deployment_target = '8.0'
  s.libraries = 'z.1.2.8', 'icucore', 'sqlite3.0', 'xml2.2', 'stdc++.6.0.9'
  s.vendored_frameworks = 'MSmartSDK/MSmartSDK.framework'
  s.pod_target_xcconfig = {
      'OTHER_LDFLAGS' => '-lObjC $(inherited)',
      'FRAMEWORK_SEARCH_PATHS' => '$(inherited) $(PODS_ROOT)/MSmartSDK/MSmartSDK'
  }
end
