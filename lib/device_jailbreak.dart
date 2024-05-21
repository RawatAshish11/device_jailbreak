

import 'package:flutter/services.dart';

class DeviceJailbreak {
  final _methodChannel = const MethodChannel('device_jailbreak');


  Future<dynamic> getPlatformVersion() async {
    final version = await _methodChannel.invokeMethod('getPlatformVersion');
    print("version");
    print(version);
    return version;
  }
   Future<bool> get developerMode async {
    bool? developerMode = await _methodChannel.invokeMethod<bool>('developerMode');
    return developerMode ?? true;
  }

}
