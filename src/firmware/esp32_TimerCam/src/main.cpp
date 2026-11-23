#include <Arduino.h>
#include "PIR_driver.h"
#include "IR_driver.h"
#include "Timer_service.h"
#include "wifi_driver.h"
#include "clock_service.h"
#include "config_service.h"


#define PIR_PIN 13
#define IR_LED_PIN 4



TimerService timer;
PirDriver pir(PIR_PIN,timer);
IrDriver ir(IR_LED_PIN,timer);
WifiService wifi(timer);
ClockService clockService;


void setup() {
    Serial.begin(115200);
    
    pir.begin();
    ir.begin();
    wifi.connect(ConfigService::getSsid(1), ConfigService::getPassword(1));
    clockService.begin();

}



void loop() {

    

    if(pir.isMotionDetected()) {
        
        Serial.print("Mouvement détecté à : ");
        Serial.println(clockService.getTime());
        Serial.println("------------");
        ir.toggle(1000);
    } 
    else
    {
        Serial.print("Aucun mouvement détecté à : ");
        Serial.println(clockService.getTime());
        Serial.println("------------");
    }



    timer.sleep(2000);
}
