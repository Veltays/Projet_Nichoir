#include "Clock_service.h"

void ClockService::begin() {
    configTime(0, 0, "pool.ntp.org");
}

String ClockService::formatTime(const char* format) {
    struct tm timeInfo;

    if (!getLocalTime(&timeInfo))
        return "";

    char buffer[32];
    strftime(buffer, sizeof(buffer), format, &timeInfo);

    return String(buffer);
}

String ClockService::getTime() {
    return formatTime("%H:%M:%S");
}

String ClockService::getDate() {
    return formatTime("%d/%m/%Y");
}

time_t ClockService::getTimestamp() {
    return time(nullptr);
}