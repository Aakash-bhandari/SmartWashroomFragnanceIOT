const int gasSensor = A0;  // Connect the moisture sensor to digital pin 8
const int relayPin = 8;     // Connect the relay to digital pin 3
const int temperaturPin = 7;
#include <DHT.h>
#define DHT_PIN 7
#define DHT_TYPE DHT11

DHT dht(DHT_PIN, DHT_TYPE);

void setup() {
  pinMode(gasSensor, INPUT);  // Set moisture sensor pin as an input
  pinMode(relayPin, OUTPUT);    // Set relay pin as an output
  digitalWrite(relayPin, LOW); // Turn off the relay initially
  Serial.begin(9600);          // Initialize the serial communication for debugging
}

void loop() {
  
  int gasValue = analogRead(gasSensor); // Read the gas sensor value (0 or 1)
  int temeratureValue = digitalRead(temperaturPin);

  Serial.println( gasValue);
  
  // Serial.println( humidity );
  // Serial.println(temperature);
  // If moisture value is less than 10, turn on the relay, else turn it off
  if (gasValue < 100) {
    digitalWrite(relayPin, HIGH); // Turn on the relay
    // Serial.println("Moisture level is low. Relay is Off.");
  } else {
    digitalWrite(relayPin, LOW);  // Turn off the relay
    // Serial.println("Moisture level is sufficient. Relay is on .");
  }

  delay(1000); // Delay for 1 second to avoid rapid relay state changes
}
