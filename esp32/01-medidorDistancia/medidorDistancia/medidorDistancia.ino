const int trigPin =4;
const int echoPin =18;

// define sound speed in cm/uS
#define SOUND_SPEED 0.034
#define CM_TO_INCH 0.393701


#define LED_BUILTIN 2

long duration;
float distanceCm;

void setup() {
  Serial.begin(115200); // Starts the serial comunication
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);

}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  // clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Reads the echoPin, returns the sound wave travel time in microconds
  duration = pulseIn(echoPin, HIGH);

  // calculate the distance
  distanceCm = duration * SOUND_SPEED/2;


  Serial.print("Distance (cm): ");
  Serial.println(distanceCm);

  digitalWrite(LED_BUILTIN, LOW);

  delay(1e3);

}
