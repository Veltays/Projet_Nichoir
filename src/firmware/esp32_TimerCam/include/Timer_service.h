#ifndef TIMER_SERVICE_H
#define TIMER_SERVICE_H

#include <Arduino.h>

class TimerService {
private:
    uint32_t _startTime;
    uint32_t _duration;
    bool _running;

public:
    TimerService();

    void start(uint32_t duration);
    void stop();
    void reset();

    bool isFinished();
    bool isRunning();

    uint32_t getElapsedTime();
};

#endif