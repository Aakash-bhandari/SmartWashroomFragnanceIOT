#include <WiFiClient.h>
#include <ESP8266WiFi.h>
#include <Wire.h>
const char* ssid = "kNox"; // Replace with your WiFi SSID
const char* password = "bhandar1"; // Replace with your WiFi password
const char* server = "api.thingspeak.com";
String apiKey = "VQJ51G06QLWKGZZS"; // Replace with your ThingSpeak channel's Write API Key

WiFiClient client;



void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi");
}

void loop() {
  char gasSensor[10] = ""; 
  if(Serial.available() > 0) {
    // char data = Serial.read();
    Serial.readBytesUntil('\n', gasValue, 10);

      String postData = "field1=" + String(gasSensor) + "&field2=" + String(temeratureValue);
    Serial.println(postData);

    if (client.connect(server, 80)) {
      client.print("POST /update HTTP/1.1\n");
      client.print("Host: api.thingspeak.com\n");
      client.print("Connection: close\n");
      client.print("X-THINGSPEAKAPIKEY: " + apiKey + "\n");
      client.print("Content-Type: application/x-www-form-urlencoded\n");
      client.print("Content-Length: ");
      client.print(postData.length());
      client.print("\n\n");
      client.print(postData);
      client.stop();
      Serial.println("Data sent to ThingSpeak");
    } else {
      Serial.println("Error connecting to ThingSpeak");
    }
  }
}