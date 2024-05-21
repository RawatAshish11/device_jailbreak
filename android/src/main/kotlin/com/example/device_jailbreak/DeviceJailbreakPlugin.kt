package com.example.device_jailbreak

import android.content.Context
import androidx.annotation.NonNull
import com.scottyab.rootbeer.RootBeer

import io.flutter.embedding.engine.plugins.FlutterPlugin
import io.flutter.plugin.common.MethodCall
import io.flutter.plugin.common.MethodChannel
import io.flutter.plugin.common.MethodChannel.MethodCallHandler
import io.flutter.plugin.common.MethodChannel.Result
import android.provider.Settings
/** DeviceJailbreakPlugin */
class DeviceJailbreakPlugin: FlutterPlugin, MethodCallHandler {

  private lateinit var context: Context
  private lateinit var channel : MethodChannel

  override fun onAttachedToEngine(flutterPluginBinding: FlutterPlugin.FlutterPluginBinding) {
    channel = MethodChannel(flutterPluginBinding.binaryMessenger, "device_jailbreak")
    context = flutterPluginBinding.applicationContext
    channel.setMethodCallHandler(this)
  }

  private fun isDevMode(): Boolean {
    return Settings.Secure.getInt(
      context.contentResolver,
      Settings.Global.DEVELOPMENT_SETTINGS_ENABLED, 0
    ) != 0
  }
  override fun onMethodCall(call: MethodCall, result: Result) {
    if (call.method == "getPlatformVersion") {
      val rootBeer = RootBeer(context)
      val rooted : Boolean =  rootBeer.isRooted
      result.success(rooted)
    }
    else if (call.method.equals("developerMode")) {
      result.success(isDevMode())
    }
    else {
      result.notImplemented()
    }
  }

  override fun onDetachedFromEngine(binding: FlutterPlugin.FlutterPluginBinding) {
    channel.setMethodCallHandler(null)
  }
}
