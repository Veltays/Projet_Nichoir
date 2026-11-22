#include "config_service.h"
#include "../../.env"

const char* ConfigService::getSsid(uint8_t wifiIndex) {
    switch (wifiIndex) {
        case 1:
            return WIFI_SSID_1;

        case 2:
            return WIFI_SSID_2;

        case 3:
            return WIFI_SSID_3;

        default:
            return "";
    }
}

const char* ConfigService::getPassword(uint8_t wifiIndex) {
    switch (wifiIndex) {
        case 1:
            return WIFI_PASSWORD_1;

        case 2:
            return WIFI_PASSWORD_2;

        case 3:
            return WIFI_PASSWORD_3;

        default:
            return "";
    }
}
