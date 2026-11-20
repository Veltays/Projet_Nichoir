#include "Timer_service.h"

void TimerService::sleep(uint32_t duration) {
    uint32_t startTime = millis();

    while (millis() - startTime < duration) {
        yield();
    }
}