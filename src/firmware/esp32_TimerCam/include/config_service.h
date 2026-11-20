#ifndef CONFIG_SERVICE_H
#define CONFIG_SERVICE_H

class ConfigService {
public:
    static const char* getSsid();
    static const char* getPassword();
};

#endif
