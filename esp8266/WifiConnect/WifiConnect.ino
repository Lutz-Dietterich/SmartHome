
#include <ESP8266WiFi.h>

const char *WIFI_SSID = "FRITZ!Box 7530 VF";
const char *WIFI_PASSWORD = "54084965601593359625";


WiFiClient client;
void setup() {
  Serial.begin(9600);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Verbindungsaufbau zum WLAN"); 

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
    Serial.print(".");
  }

  Serial.println(WiFi.localIP());

  WiFi.setAutoReconnect(true);
  WiFi.persistent(true);


}

void loop() {
  // put your main code here, to run repeatedly:

}
