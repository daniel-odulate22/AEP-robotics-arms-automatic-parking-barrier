
#include <Servo.h>

Servo gateServo;

const int trigPin = 9;
const int echoPin = 10;
const int servoPin = 6;

const float detectionDistance = 15.0;

long duration;
float distanceCm;

void setup() {
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  gateServo.attach(servoPin);
  gateServo.write(0);  // Gate starts closed
}

void loop() {
  // Send the ultrasonic trigger pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the echo with a timeout
  duration = pulseIn(echoPin, HIGH, 30000UL);

  if (duration == 0) {
    Serial.println("No echo detected");
    gateServo.write(0);
  } else {
    distanceCm = (duration * 0.0343) / 2.0;

    Serial.print("Distance: ");
    Serial.print(distanceCm);
    Serial.println(" cm");

    if (distanceCm <= detectionDistance) {
      gateServo.write(90);  // Open gate
      Serial.println("Vehicle detected: Gate OPEN");
    } else {
      gateServo.write(0);   // Close gate
      Serial.println("No nearby vehicle: Gate CLOSED");
    }
  }

  delay(200);
}
