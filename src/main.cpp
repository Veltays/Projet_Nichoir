#include <Arduino.h>


#define PIR_PIN 13
#define IR_LED_PIN 4

void setup() {
    Serial.begin(115200);

    digitalWrite(IR_LED_PIN, LOW);
    pinMode(IR_LED_PIN, OUTPUT);
    pinMode(PIR_PIN, INPUT);
}

void loop() {
    if (digitalRead(PIR_PIN) == HIGH) {
        digitalWrite(IR_LED_PIN, HIGH);
        Serial.println("Mouvement détecté !");
        delay(2000); // Eclairage pendant 2 secondes
        digitalWrite(IR_LED_PIN, LOW);
    }

    delay(100);
}