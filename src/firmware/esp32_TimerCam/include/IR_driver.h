#ifndef IR_DRIVER_H
#define IR_DRIVER_H

#include <Arduino.h>

class IrDriver
{
    private:
        uint8_t _IrPin;


        uint8_t getIrPin();
        void setIrPin(uint8_t irPin);

    public:
        IrDriver(uint8_t irPin);
        
        void begin();

        void toggle(uint16_t duration);

        void On();
        void Off();







      
};

#endif