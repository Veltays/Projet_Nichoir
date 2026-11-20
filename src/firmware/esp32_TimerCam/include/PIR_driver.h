#ifndef PIR_DRIVER_H
#define PIR_DRIVER_H

#include <Arduino.h>

class PirDriver {
private:
    uint8_t _pirPin;

    static volatile bool motionDetected;
    static void IRAM_ATTR detect_Motion();

public:
    PirDriver(uint8_t pirPin);

    uint8_t getPirPin();
    void setPirPin(uint8_t pirPin);
    void setInterrupt();
    void begin();
    bool isMotionDetected();
};

#endif