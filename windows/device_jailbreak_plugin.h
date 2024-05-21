#ifndef FLUTTER_PLUGIN_DEVICE_JAILBREAK_PLUGIN_H_
#define FLUTTER_PLUGIN_DEVICE_JAILBREAK_PLUGIN_H_

#include <flutter/method_channel.h>
#include <flutter/plugin_registrar_windows.h>

#include <memory>

namespace device_jailbreak {

class DeviceJailbreakPlugin : public flutter::Plugin {
 public:
  static void RegisterWithRegistrar(flutter::PluginRegistrarWindows *registrar);

  DeviceJailbreakPlugin();

  virtual ~DeviceJailbreakPlugin();

  // Disallow copy and assign.
  DeviceJailbreakPlugin(const DeviceJailbreakPlugin&) = delete;
  DeviceJailbreakPlugin& operator=(const DeviceJailbreakPlugin&) = delete;

  // Called when a method is called on this plugin's channel from Dart.
  void HandleMethodCall(
      const flutter::MethodCall<flutter::EncodableValue> &method_call,
      std::unique_ptr<flutter::MethodResult<flutter::EncodableValue>> result);
};

}  // namespace device_jailbreak

#endif  // FLUTTER_PLUGIN_DEVICE_JAILBREAK_PLUGIN_H_
