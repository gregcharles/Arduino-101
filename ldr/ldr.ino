int WHITE_PWM_LED = 9;
int LDR = A0;
int ldr_level = 0;
int brightness = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(WHITE_PWM_LED, OUTPUT);
  pinMode(LDR, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  ldr_level = analogRead(LDR);
  Serial.print("LDR (raw) = ");
  Serial.print(ldr_level);

  brightness = map(ldr_level, 0, 1023, 0, 255);
  Serial.print(", brightness = ");
  Serial.println(brightness);

  analogWrite(WHITE_PWM_LED, brightness);
  
  delay(200);
}
