const int ServoPin1 = D1;
const int ServoPin2 = D2;
#define DutyMax 2300
#define DutyMin 700

void ServoSpeed(int pin, int speed) {
  int Duty = map(speed, -10, 10, DutyMin, DutyMax);
  digitalWrite(pin, HIGH);
  delayMicroseconds(Duty);
  digitalWrite(pin, LOW);
  delayMicroseconds(20 * 1000 - Duty);
}

void setup() {
  pinMode(ServoPin1, OUTPUT);
  pinMode(ServoPin2, OUTPUT);
  ServoSpeed(ServoPin1, 5);
  ServoSpeed(ServoPin2, 5);
}

void loop() {
  ServoSpeed(ServoPin1, 1);
  ServoSpeed(ServoPin2, -1);
}
