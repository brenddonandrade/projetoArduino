#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

#define LED_BUILTIN 2

float distance;

#define pinGreen1 23
#define pinGreen2 22
#define pinGreen3 21
#define pinYellow1 19
#define pinYellow2 18
#define pinRed1 4
#define buzzer 16

void setup() {
  Serial.begin(115200); // Starts the serial communication
  SerialBT.begin("ESP32_Slave");
  Serial.println("ESP32 Slave iniciado e aguardando dados.");
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(pinGreen1, OUTPUT);
  pinMode(pinGreen2, OUTPUT);
  pinMode(pinGreen3, OUTPUT);
  pinMode(pinYellow1, OUTPUT);
  pinMode(pinYellow2, OUTPUT);
  pinMode(pinRed1, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

void highLed(int numberLeds) {
  switch (numberLeds) {
    case 1:
      digitalWrite(pinGreen1, HIGH);
      digitalWrite(pinGreen2, LOW);
      digitalWrite(pinGreen3, LOW);
      digitalWrite(pinYellow1, LOW);
      digitalWrite(pinYellow2, LOW);
      digitalWrite(pinRed1, LOW);
      digitalWrite(buzzer, LOW);
      break;
    case 2:
      digitalWrite(pinGreen1, HIGH);
      digitalWrite(pinGreen2, HIGH);
      digitalWrite(pinGreen3, LOW);
      digitalWrite(pinYellow1, LOW);
      digitalWrite(pinYellow2, LOW);
      digitalWrite(pinRed1, LOW);
      digitalWrite(buzzer, LOW);
      break;
    case 3:
      digitalWrite(pinGreen1, HIGH);
      digitalWrite(pinGreen2, HIGH);
      digitalWrite(pinGreen3, HIGH);
      digitalWrite(pinYellow1, LOW);
      digitalWrite(pinYellow2, LOW);
      digitalWrite(pinRed1, LOW);
      digitalWrite(buzzer, LOW);
      break;
    case 4:
      digitalWrite(pinGreen1, HIGH);
      digitalWrite(pinGreen2, HIGH);
      digitalWrite(pinGreen3, HIGH);
      digitalWrite(pinYellow1, HIGH);
      digitalWrite(pinYellow2, LOW);
      digitalWrite(pinRed1, LOW);
      digitalWrite(buzzer, LOW);
      break;
    case 5:
      digitalWrite(pinGreen1, HIGH);
      digitalWrite(pinGreen2, HIGH);
      digitalWrite(pinGreen3, HIGH);
      digitalWrite(pinYellow1, HIGH);
      digitalWrite(pinYellow2, HIGH);
      digitalWrite(pinRed1, LOW);
      digitalWrite(buzzer, LOW);
      break;
    case 6:
      digitalWrite(pinGreen1, HIGH);
      digitalWrite(pinGreen2, HIGH);
      digitalWrite(pinGreen3, HIGH);
      digitalWrite(pinYellow1, HIGH);
      digitalWrite(pinYellow2, HIGH);
      digitalWrite(pinRed1, HIGH);
      digitalWrite(buzzer, HIGH);
      break;
  }
}

void loop() {
  if (SerialBT.available()) {
    String received = SerialBT.readString();
    distance = received.toFloat();

    Serial.print("Distância recebida: ");
    Serial.println(distance);

    if (distance < 5.0) {
      highLed(6);
    } else if (distance < 10.0) {
      highLed(5);
    } else if (distance < 15.0) {
      highLed(4);
    } else if (distance < 20.0) {
      highLed(3);
    } else if (distance < 25.0) {
      highLed(2);
    } else if (distance < 30.0) {
      highLed(1);
    } else {
      // Desliga todos os LEDs e o buzzer se a distância for maior ou igual a 30.0
      digitalWrite(pinGreen1, LOW);
      digitalWrite(pinGreen2, LOW);
      digitalWrite(pinGreen3, LOW);
      digitalWrite(pinYellow1, LOW);
      digitalWrite(pinYellow2, LOW);
      digitalWrite(pinRed1, LOW);
      digitalWrite(buzzer, LOW);
    }
    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    Serial.println("Sinal não recebido: ");
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1e3);
    digitalWrite(LED_BUILTIN, LOW);
  }
}
