#ifndef PIR_DRIVER_H
#define PIR_DRIVER_H

#include <Arduino.h>
#include "Timer_service.h"

class PirDriver {
private:
    uint8_t _pirPin;
    TimerService _timer;

    static volatile bool motionDetected;
    static void detect_Motion();

    uint8_t getPirPin();
    void setPirPin(uint8_t pirPin);

    void setTimerService(TimerService timer);
    TimerService getTimerService();

public:
    PirDriver(uint8_t pirPin,TimerService timer);


    void setInterrupt();
    void begin();
    bool isMotionDetected();
};

#endif