#include "Timer_service.h"

TimerService::TimerService()
    : _startTime(0), _duration(0), _running(false) {
}

void TimerService::start(uint32_t duration) {
    _startTime = millis();
    _duration = duration;
    _running = true;
}

void TimerService::stop() {
    _running = false;
}

void TimerService::reset() {
    _startTime = millis();
    _running = true;
}

bool TimerService::isFinished() {
    if (!_running)
        return false;

    if (millis() - _startTime >= _duration) {
        _running = false;
        return true;
    }

    return false;
}

bool TimerService::isRunning() {
    return _running;
}

uint32_t TimerService::getElapsedTime() {
    return millis() - _startTime;
}