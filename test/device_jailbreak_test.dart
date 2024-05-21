import 'package:flutter_test/flutter_test.dart';
import 'package:device_jailbreak/device_jailbreak.dart';
import 'package:device_jailbreak/device_jailbreak_platform_interface.dart';
import 'package:device_jailbreak/device_jailbreak_method_channel.dart';
import 'package:plugin_platform_interface/plugin_platform_interface.dart';

class MockDeviceJailbreakPlatform
    with MockPlatformInterfaceMixin
    implements DeviceJailbreakPlatform {

  @override
  Future<String?> getPlatformVersion() => Future.value('42');
}

void main() {
  final DeviceJailbreakPlatform initialPlatform = DeviceJailbreakPlatform.instance;

  test('$MethodChannelDeviceJailbreak is the default instance', () {
    expect(initialPlatform, isInstanceOf<MethodChannelDeviceJailbreak>());
  });

  test('getPlatformVersion', () async {
    DeviceJailbreak deviceJailbreakPlugin = DeviceJailbreak();
    MockDeviceJailbreakPlatform fakePlatform = MockDeviceJailbreakPlatform();
    DeviceJailbreakPlatform.instance = fakePlatform;

    expect(await deviceJailbreakPlugin.getPlatformVersion(), '42');
  });
}
