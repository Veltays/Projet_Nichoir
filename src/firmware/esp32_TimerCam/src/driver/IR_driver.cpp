
#include "IR_driver.h"

/* CONSTRUCTEUR */

IrDriver::IrDriver(uint8_t irPin)
{
    setIrPin(irPin);
}   





/** INITIALISATION */

void IrDriver::begin()
{
    pinMode(getIrPin(), OUTPUT);
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


/* METIER */

void IrDriver::On()
{
    digitalWrite(getIrPin(), HIGH);
}


void IrDriver::toggle(uint16_t duration)
{
    On();
    delay(duration);
    Off();
}

void IrDriver::Off()
{
    digitalWrite(getIrPin(), LOW);
}