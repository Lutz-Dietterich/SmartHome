
#include <ESP8266WiFi.h>
#include <Arduino.h>
#include <PubSubClient.h>

const char *WIFI_SSID = "FRITZ!Box 7530 VF";
const char *WIFI_PASSWORD = "54084965601593359625";


const char *MQTT_HOST = "192.168.178.11";
const int MQTT_PORT = 1883;
const char *MQTT_CLIENT_ID = "ESP8266_1";
const char *MQTT_PASSWORD = "";
const char *MQTT_USER = "ESP8266_1";
const char *MQTT_TOPIC = "house/main";

WiFiClient client;
PubSubClient mqttClient(client);


void connect() {
  while (!mqttClient.connected()) {
    Serial.print("Verbindungsaufbau zum MQTT Broker");
    if (mqttClient.connect(MQTT_CLIENT_ID, MQTT_USER, MQTT_PASSWORD)) {
      Serial.println(" verbunden");
      mqttClient.subscribe(TOPIC,1);
    } else {
      Serial.print(" fehlgeschlagen, rc=");
      Serial.print(mqttClient.state());
      Serial.println(" Versuche es in 5 Sekunden erneut");
      delay(5000);
    }
  }
}

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

mqttClient.setServer(MQTT_HOST, MQTT_PORT);
connect()

}

void loop() {
  // put your main code here, to run repeatedly:

}
