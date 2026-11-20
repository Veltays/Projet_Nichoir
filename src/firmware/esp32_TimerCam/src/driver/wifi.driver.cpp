#include "wifi_driver.h"
#include "Timer_service.h"




WifiService::WifiService(TimerService timer){
    _timer = timer;

}

void WifiService::connect(const char* ssid, const char* password) {
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);

    Serial.println("Connexion au Wi-Fi...");

    while (!isConnected()) {
        delay(500);
        Serial.print(".");
    }

    Serial.printf(
        "\nWi-Fi connecté !\n"
        "Adresse IP : %s\n",
        getIP().toString()
    );
}

void WifiService::disconnect() {
    WiFi.disconnect();
}

bool WifiService::isConnected() {
    return WiFi.status() == WL_CONNECTED;
}

IPAddress WifiService::getIP() {
    return WiFi.localIP();
}