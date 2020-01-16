int RED_LED = 2;
int YELLOW_LED = 4;
int GREEN_LED = 7;

void setup() {
  // put your setup code here, to run once:
  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(RED_LED, HIGH);
  delay(100);
  digitalWrite(YELLOW_LED, HIGH);
  delay(100);
  digitalWrite(GREEN_LED, HIGH);
  delay(100);
  digitalWrite(RED_LED, LOW);
  delay(100);
  digitalWrite(YELLOW_LED, LOW);
  delay(100);
  digitalWrite(GREEN_LED, LOW);
  delay(100);
  digitalWrite(GREEN_LED, HIGH);
  delay(100);
  digitalWrite(YELLOW_LED, HIGH);
  delay(100);
  digitalWrite(RED_LED, HIGH);
  delay(100);
  digitalWrite(GREEN_LED, LOW);
  delay(100);
  digitalWrite(YELLOW_LED, LOW);
  delay(100);
  digitalWrite(RED_LED, LOW);
  delay(100);
}
