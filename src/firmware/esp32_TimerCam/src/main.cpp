#include <Arduino.h>
#include "PIR_driver.h"
#include "IR_driver.h"

#define PIR_PIN 13
#define IR_LED_PIN 4

PirDriver pir(PIR_PIN);
IrDriver ir(IR_LED_PIN);




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


    delay(100);
}