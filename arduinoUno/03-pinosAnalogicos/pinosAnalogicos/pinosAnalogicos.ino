int redPin=A4;

// how do we know the difference between digital and analog
// R: "A" before number
void setup() {
  // put your setup code here, to run once:
  pinMode(redPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(redPin, 255);
}
