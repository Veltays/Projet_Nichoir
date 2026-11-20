
#include "IR_driver.h"
#include "Timer_service.h"
/* CONSTRUCTEUR */

IrDriver::IrDriver(uint8_t irPin,TimerService timer)
{
    setIrPin(irPin);
    setTimerService(timer);
}   





/** INITIALISATION */

void IrDriver::begin()
{
    pinMode(getIrPin(), OUTPUT);
}


/* METIER */

void IrDriver::On()
{
    digitalWrite(getIrPin(), HIGH);
}


void IrDriver::toggle(uint16_t duration)
{
    On();
    getTimerService().sleep(duration);
    Off();
}

void IrDriver::Off()
{
    digitalWrite(getIrPin(), LOW);
}


/* ACCESSEUR */

uint8_t IrDriver::getIrPin()
{
    return _IrPin;
}

void IrDriver::setIrPin(uint8_t irPin)
{
    _IrPin = irPin;
}



void IrDriver::setTimerService(TimerService timer)
{
    _timerService = timer;
}


TimerService IrDriver::getTimerService()
{
    return _timerService;
}
