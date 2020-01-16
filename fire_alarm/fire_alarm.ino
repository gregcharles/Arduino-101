const int Sensor = A1;
const int GREEN_LED = 2;
const int YELLOW_LED = 3;
const int RED_LED = 4;
const int Buzzer = 11;

float baselineTemp;
bool toggle = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(Buzzer, OUTPUT);
  delay(100);
  baselineTemp = computeTemp(analogRead(Sensor));
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorValue = analogRead(Sensor);
  Serial.print("Sensor value: ");
  Serial.print(sensorValue);
  float temperatureC = computeTemp(sensorValue);
  Serial.print(", temp: ");
  Serial.println(temperatureC);

  digitalWrite(GREEN_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(RED_LED, LOW);
  digitalWrite(Buzzer, LOW);

  if (temperatureC < baselineTemp + 4) {
    digitalWrite(GREEN_LED, HIGH);
  } else if (temperatureC < baselineTemp + 8) {
    digitalWrite(YELLOW_LED, HIGH);
  } else if (temperatureC < baselineTemp + 12) {
    digitalWrite(RED_LED, HIGH);
  } else {
    toggle = !toggle;
    digitalWrite(RED_LED, toggle ? HIGH : LOW);
    digitalWrite(Buzzer, HIGH);
  }
  delay(200);
}

//converting from 10 mv per degree wit 500 mV offset
//to degrees ((voltage - 500mV) times 100)
float computeTemp(int sensorValue) {
  float voltage = (sensorValue * 5.0)  / 1024.0;
  float temperatureC = (voltage - 0.5) * 100;

  return temperatureC;
}
