#pragma once

#include "Arduino.h"

#include <ArduinoJson.h>
#ifdef ESP32
#include <SPIFFS.h>
#endif // ESP32
#include "FS.h"
#include "Datatypes/Interface.hpp"
#include "Datatypes/ConfigStruct.hpp"
#include "Utils/DeviceId.hpp"
#include "Utils/Validation.hpp"
#include "Constants.hpp"
#include "Limits.hpp"
#include "../HomieBootMode.hpp"
#include "../HomieSetting.hpp"
#include "../StreamingOperator.hpp"

namespace HomieInternals {
class Config {
 public:
  Config();
  bool load();
  bool loadWifi(const JsonObject config);
  ConfigWiFi loadOneWifi(const JsonVariant reqWifi);
  bool setCurrentWifiSettings(ConfigWiFi& wifi);
  bool addWifiSetting(ConfigWiFi& wifi,int idx=0);
  ConfigWiFi& getWifiSetting(int idx=0);
  bool tryAnotherWifi();

  inline const ConfigStruct& get() const;
  char* getSafeConfigFile() const;
  void erase();
  void setHomieBootModeOnNextBoot(HomieBootMode bootMode);
  HomieBootMode getHomieBootModeOnNextBoot();
  void write(const JsonObject config);
  bool patch(const char* patch);
  void log() const;  // print the current config to log output
  bool isValid() const;

 private:
  ConfigStruct _configStruct;
  bool _spiffsBegan;
  bool _valid;

  bool _spiffsBegin();
  void _patchJsonObject(JsonObject object, JsonObject patch);
};

const ConfigStruct& Config::get() const {
  return _configStruct;
}
}  // namespace HomieInternals
