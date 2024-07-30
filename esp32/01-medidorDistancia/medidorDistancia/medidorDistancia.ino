#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

const int trigPin = 4;
const int echoPin = 18;

// define sound speed in cm/us
#define SOUND_SPEED 0.034
#define CM_TO_INCH 0.393701

#define LED_BUILTIN 2

long duration;
float distanceCm;

void setup() {
  Serial.begin(115200); // Starts the serial communication
  SerialBT.begin("ESP32_Master"); // Define device name as master
  Serial.println("ESP32 Master iniciado e aguardando conexões.");
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);

  // Tente se conectar ao endereço MAC do escravo (substitua pelo endereço MAC correto do seu ESP32 escravo)
  const char *slaveAddress = "00:00:00:00:00:00"; // Coloque o endereço MAC do Slave aqui
  if (SerialBT.connect(slaveAddress)) {
    Serial.println("Conectado ao escravo");
  } else {
    Serial.println("Falha ao conectar ao escravo");
  }
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);

  // Calculate the distance
  distanceCm = duration * SOUND_SPEED / 2;

  Serial.print("Distance (cm): ");
  Serial.println(distanceCm);

  SerialBT.println(distanceCm); // Envia a distância como string

  digitalWrite(LED_BUILTIN, LOW);

  delay(1000); // Delay de 1 segundo
}
