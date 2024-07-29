#define PIN_GREEN 5
#define PIN_YELLOW 6
#define PIN_RED 7

#define DELAY_GREEN 5e3
#define DELAY_RED 5e3
#define DELAY_YELLOW 1e3


void setup() {
  pinMode(PIN_GREEN, OUTPUT);
  pinMode(PIN_YELLOW, OUTPUT);
  pinMode(PIN_RED, OUTPUT);
}

void loop() {
  digitalWrite(PIN_GREEN, HIGH);
  delay(DELAY_GREEN);
  digitalWrite(PIN_GREEN, LOW);
  digitalWrite(PIN_YELLOW, HIGH);
  delay(DELAY_YELLOW);
  digitalWrite(PIN_YELLOW, LOW);
  digitalWrite(PIN_RED, HIGH);
  delay(DELAY_RED);
  digitalWrite(PIN_RED, LOW);

}
