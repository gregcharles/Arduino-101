int BLUE_LED = 8;
int SWITCH = 5;
int SV = LOW;

void setup() {
  // put your setup code here, to run once:
  pinMode(BLUE_LED, OUTPUT);
  pinMode(SWITCH, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  SV = digitalRead(SWITCH);
  Serial.print("SV=");
  Serial.println(SV);
  if (SV == HIGH) {
    digitalWrite(BLUE_LED, HIGH);
  } else {
    digitalWrite(BLUE_LED, LOW);
  }
  delay(100);
}
