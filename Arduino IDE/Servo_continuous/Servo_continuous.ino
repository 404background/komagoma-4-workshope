const int servoPin = 10;
int DutyMax = 2300;     //2500
int DutyMin = 700;      //500
int DutyCycle = DutyMin;
int Interval = 2000;

void setup() {
  Serial.begin(115200);
  pinMode(servoPin, OUTPUT);
}

void loop() {
  for (DutyCycle = DutyMin; DutyCycle <= DutyMax; DutyCycle += 1) {
    Serial.println(DutyCycle);
    digitalWrite(servoPin, HIGH);
    delayMicroseconds(DutyCycle);
    digitalWrite(servoPin, LOW);
    delayMicroseconds(20*1000 - DutyCycle);
  }
  delay(Interval);
  for (DutyCycle = DutyMax; DutyCycle >= DutyMin; DutyCycle -= 1) {
    Serial.println(DutyCycle);
    digitalWrite(servoPin, HIGH);
    delayMicroseconds(DutyCycle);
    digitalWrite(servoPin, LOW);
    delayMicroseconds(20*1000 - DutyCycle);
  }
  delay(Interval);
}
