#ifndef WIFI_DRIVER_H
#define WIFI_DRIVER_H

#include <Arduino.h>
#include <WiFi.h>
#include "Timer_service.h"



class WifiService {

    private:
        TimerService _timer;

    public:
        WifiService(TimerService timer);
        void connect(const char* ssid, const char* password);
        void disconnect();
        bool isConnected();
        IPAddress getIP();
};

#endif