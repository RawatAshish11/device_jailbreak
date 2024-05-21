#include "include/device_jailbreak/device_jailbreak_plugin_c_api.h"

#include <flutter/plugin_registrar_windows.h>

#include "device_jailbreak_plugin.h"

void DeviceJailbreakPluginCApiRegisterWithRegistrar(
    FlutterDesktopPluginRegistrarRef registrar) {
  device_jailbreak::DeviceJailbreakPlugin::RegisterWithRegistrar(
      flutter::PluginRegistrarManager::GetInstance()
          ->GetRegistrar<flutter::PluginRegistrarWindows>(registrar));
}
