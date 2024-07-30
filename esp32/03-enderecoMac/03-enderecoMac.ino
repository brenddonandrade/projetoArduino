#include "WiFi.h"




void setup() {
  Serial.begin(115200); // Starts the serial communication
  Serial.println(WiFi.macAddress()); // Imprime o endereço MAC do ESP32

}
void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(WiFi.macAddress()); // Imprime o endereço MAC do ESP32
  delay(1e4);
}
