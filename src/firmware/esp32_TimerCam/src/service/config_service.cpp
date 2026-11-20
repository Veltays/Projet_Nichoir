#include "config_service.h"
#include "../../.env"

namespace {
const char* const WIFI_SSIDS[] = {
    WIFI_SSID_1,
    WIFI_SSID_2,
    WIFI_SSID_3
};

const char* const WIFI_PASSWORDS[] = {
    WIFI_PASSWORD_1,
    WIFI_PASSWORD_2,
    WIFI_PASSWORD_3
};

constexpr uint8_t WIFI_COUNT = sizeof(WIFI_SSIDS) / sizeof(WIFI_SSIDS[0]);
}

const char* ConfigService::getSsid(uint8_t index) {
    if (index < 1 || index > WIFI_COUNT) {
        return "";
    }

    return WIFI_SSIDS[index - 1];
}

const char* ConfigService::getPassword(uint8_t index) {
    if (index < 1 || index > WIFI_COUNT) {
        return "";
    }

    return WIFI_PASSWORDS[index - 1];
}
