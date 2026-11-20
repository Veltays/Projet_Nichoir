#ifndef CLOCK_SERVICE_H
#define CLOCK_SERVICE_H

#include <Arduino.h>
#include <time.h>

class ClockService {
private:
    String formatTime(const char* format);

public:
    void begin();
    String getTime();
    String getDate();
    time_t getTimestamp();
};

#endif