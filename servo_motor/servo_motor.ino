#include <Servo.h>

Servo myServo;

const int PotentiometerPin = A0;
const int ServoPin = 9;

void setup() {
  // put your setup code here, to run once:
  myServo.attach(ServoPin);
  Serial.begin(9600);
  Serial.print("Attached to Servo on pin ");
  Serial.println(ServoPin);
}

void loop() {
  // put your main code here, to run repeatedly:
  int pval = analogRead(PotentiometerPin);
  Serial.print("Pot: ");
  Serial.print(pval);

  int angle = map(pval, 0, 1023, 0, 179);
  Serial.print(", angle: ");
  Serial.println(angle);

  myServo.write(angle);
  delay(150);
}
