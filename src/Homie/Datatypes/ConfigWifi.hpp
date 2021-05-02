#pragma once

#include "../Constants.hpp"
#include "../Limits.hpp"

namespace HomieInternals {
  struct ConfigWiFi {
    char ssid[MAX_WIFI_SSID_LENGTH];
    char password[MAX_WIFI_PASSWORD_LENGTH];
    char bssid[MAX_MAC_STRING_LENGTH + 6];
    uint16_t channel;
    char ip[MAX_IP_STRING_LENGTH];
    char mask[MAX_IP_STRING_LENGTH];
    char gw[MAX_IP_STRING_LENGTH];
    char dns1[MAX_IP_STRING_LENGTH];
    char dns2[MAX_IP_STRING_LENGTH];
  };
}