// #define PIN_SET 7
#define DELAY 1e3
void setup() {
  // pinMode(PIN_SET, OUTPUT);
  pinMode(7, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // digitalWrite(PIN_SET, HIGH); // turn to 5V or on
  digitalWrite(7, HIGH); // turn to 5V or on
  // HIGH means 5V
  delay(DELAY); 

  // digitalWrite(PIN_SET, LOW); // turn to 0V or off
  digitalWrite(7, LOW); // turn to 0V or off
  delay(DELAY);

}
