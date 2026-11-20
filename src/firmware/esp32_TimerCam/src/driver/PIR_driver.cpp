#include "PIR_driver.h"

volatile bool PirDriver::motionDetected = false;

PirDriver::PirDriver(uint8_t pirPin)
{
    setPirPin(pirPin);
}

uint8_t PirDriver::getPirPin()
{
    return _pirPin;
}

void PirDriver::setPirPin(uint8_t pirPin)
{
    _pirPin = pirPin;
}

void PirDriver::setInterrupt()
{
    attachInterrupt(
        digitalPinToInterrupt(getPirPin()),
        detect_Motion,
        RISING);
}

void PirDriver::begin()
{
    pinMode(getPirPin(), INPUT);
    setInterrupt();
}

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

void PirDriver::detect_Motion()
{
    motionDetected = true;
}