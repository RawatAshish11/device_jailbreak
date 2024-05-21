//
//  Generated file. Do not edit.
//

// clang-format off

#include "generated_plugin_registrant.h"

#include <device_jailbreak/device_jailbreak_plugin.h>

void fl_register_plugins(FlPluginRegistry* registry) {
  g_autoptr(FlPluginRegistrar) device_jailbreak_registrar =
      fl_plugin_registry_get_registrar_for_plugin(registry, "DeviceJailbreakPlugin");
  device_jailbreak_plugin_register_with_registrar(device_jailbreak_registrar);
}
