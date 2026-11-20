#ifndef CONFIG_SERVICE_H
#define CONFIG_SERVICE_H

#include <stdint.h>

class ConfigService {
public:
    static const char* getSsid(uint8_t wifiIndex);
    static const char* getPassword(uint8_t wifiIndex);
};

#endif
