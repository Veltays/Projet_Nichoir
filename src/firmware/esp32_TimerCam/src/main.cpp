#include <Arduino.h>
#include "PIR_driver.h"
#include "IR_driver.h"
#include "Timer_service.h"

#define PIR_PIN 13
#define IR_LED_PIN 4

TimerService timer;
PirDriver pir(PIR_PIN,timer);
IrDriver ir(IR_LED_PIN,timer);



void setup() {
    Serial.begin(115200);

    pir.begin();
    ir.begin();
}


void loop() {

    if(pir.isMotionDetected()) {

        Serial.printf(
            "Valeur du capteur : %u\n"
            "Nombre de détections : %u\n" 
        );
        
        ir.toggle(1000);
        Serial.println("------------");
    }


    timer.sleep(2000);
}