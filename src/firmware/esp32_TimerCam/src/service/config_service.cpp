#include "config_service.h"
#include "../../.env"

const char* ConfigService::getSsid() {
    return WIFI_SSID;
}

const char* ConfigService::getPassword() {
    return WIFI_PASSWORD;
}
