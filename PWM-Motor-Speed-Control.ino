const int enablePin = 9;
const int input1Pin = 8;
const int input2Pin = 7;
const int potPin = A0;

void setup() {
  pinMode(enablePin, OUTPUT);
  pinMode(input1Pin, OUTPUT);
  pinMode(input2Pin, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  int potValue = analogRead(potPin);

  int motorSpeed = map(potValue, 0, 1023, 0, 255);

  // Motor rotates in the forward direction
  digitalWrite(input1Pin, HIGH);
  digitalWrite(input2Pin, LOW);

  analogWrite(enablePin, motorSpeed);

  Serial.print("Potentiometer: ");
  Serial.print(potValue);
  Serial.print("  PWM: ");
  Serial.println(motorSpeed);

  delay(20);
}