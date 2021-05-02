#pragma once

#include "../Constants.hpp"
#include "../Limits.hpp"
#include "ConfigWifi.hpp"

namespace HomieInternals {
struct ConfigStruct {
  char name[MAX_FRIENDLY_NAME_LENGTH];
  char deviceId[MAX_DEVICE_ID_LENGTH];
  uint16_t deviceStatsInterval;

  ConfigWiFi currentWifi;
  ConfigWiFi listOfWifi[MAX_WIFI_CONFIG];
  uint currentWifiIdx=0;
  uint countWifiSettings=0;

  struct MQTT {
    struct Server {
      char host[MAX_HOSTNAME_LENGTH];
      uint16_t port;
#if ASYNC_TCP_SSL_ENABLED
      struct {
        bool enabled;
        bool hasFingerprint;
        uint8_t fingerprint[MAX_FINGERPRINT_SIZE];
      } ssl;
#endif
    } server;
    char baseTopic[MAX_MQTT_BASE_TOPIC_LENGTH];
    bool auth;
    char username[MAX_MQTT_CREDS_LENGTH];
    char password[MAX_MQTT_CREDS_LENGTH];
  } mqtt;

  struct OTA {
    bool enabled;
  } ota;
};
}  // namespace HomieInternals
