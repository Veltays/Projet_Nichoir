#ifndef TIMER_SERVICE_H
#define TIMER_SERVICE_H

#include <Arduino.h>

class TimerService {
public:
    void sleep(uint32_t duration);
};

#endif