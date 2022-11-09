int Distancia = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  pinMode(10, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop()
{
  Distancia = 0.01723 * readUltrasonicDistance(6, 7);
  if (Distancia <= 50) {
    digitalWrite(10, HIGH);
    digitalWrite(12, LOW);
  } else {
    digitalWrite(12, HIGH);
    digitalWrite(10, LOW);
  }

  Distancia = 0.01723 * readUltrasonicDistance(4, 5);
  if (Distancia <= 50) {
    digitalWrite(11, LOW);
    digitalWrite(13, HIGH);
  } else {
    digitalWrite(13, LOW);
    digitalWrite(11, HIGH);
  }
  delay(10);
}