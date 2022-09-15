
#include <Servo.h>

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT); 
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);

  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);

  return pulseIn(echoPin, HIGH);
}

Servo servo_4;

void setup()
{
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(2, OUTPUT);
  servo_4.attach(4, 500, 2500);
  pinMode(3, INPUT);
  pinMode(5, OUTPUT);
}

void loop()
{
  Serial.println("light level=");
  Serial.println(analogRead(A0));
  if (analogRead(A0) < 865) {
    digitalWrite(2, HIGH);
  } else {
    digitalWrite(2, LOW);
  }
  Serial.println("distance=");
  Serial.println(0.01723 * readUltrasonicDistance(11, 10));
  if (0.01723 * readUltrasonicDistance(11, 10) < 150) {
    servo_4.write(90);
  } else {
    servo_4.write(0);
  }
  Serial.println("motion=");
  Serial.println(digitalRead(3));
  if (digitalRead(3) == 1) {
    digitalWrite(5, HIGH);
  } else {
    digitalWrite(5, LOW);
  }
  delay(10); 
}