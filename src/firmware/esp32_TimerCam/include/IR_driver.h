#ifndef IR_DRIVER_H
#define IR_DRIVER_H

#include <Arduino.h>
#include "Timer_service.h"
class IrDriver
{
    private:
        uint8_t _IrPin;
        TimerService _timerService;


        uint8_t getIrPin();
        void setIrPin(uint8_t irPin);

        void setTimerService(TimerService timer);
        TimerService getTimerService();


    public:
        IrDriver(uint8_t irPin,TimerService timer);
        
        void begin();

        void toggle(uint16_t duration);

        void On();
        void Off();

      
};

#endif