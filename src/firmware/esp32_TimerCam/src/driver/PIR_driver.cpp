#include "PIR_driver.h"
#include "Timer_service.h"
volatile bool PirDriver::motionDetected = false;



// constructeur
PirDriver::PirDriver(uint8_t pirPin,TimerService timer)
{
    setPirPin(pirPin);
    setTimerService(timer);
}

// Initialision
void PirDriver::begin()
{
    pinMode(getPirPin(), INPUT);
    setInterrupt();
}




// Interrupt
void PirDriver::detect_Motion()
{
    motionDetected = true;
}

void PirDriver::setInterrupt()
{
    attachInterrupt(
        digitalPinToInterrupt(getPirPin()),
        detect_Motion,
        RISING);
}



// Metier
bool PirDriver::isMotionDetected()
{
    if (motionDetected)
    {
        motionDetected = false;
        return true;
    }
    else
    {
        return false;
    }
}




/* Accesseur  */
TimerService PirDriver::getTimerService()
{
    return _timer;
}

void PirDriver::setTimerService(TimerService timer)
{
    _timer = timer;
}

uint8_t PirDriver::getPirPin()
{
    return _pirPin;
}

void PirDriver::setPirPin(uint8_t pirPin)
{
    _pirPin = pirPin;
}




