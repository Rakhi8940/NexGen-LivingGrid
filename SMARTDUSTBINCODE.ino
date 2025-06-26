// SMART DUSTBIN

#include <Servo.h>

const int trigPin = 10;
const int echoPin = 11;
const int servoPin = 9;
Servo servoMotor;

long duration;
int distance;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  servoMotor.attach(servoPin);
}

void loop() {
  // Trigger ultrasonic sensor
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

  // Read ultrasonic sensor
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2; // Calculate distance in cm

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Open dustbin lid if an object is close
  if (distance < 10) { // Adjust this threshold as needed
    servoMotor.write(180); // Open position
    delay(3000); // Adjust delay as needed
    servoMotor.write(0); // Close position
    delay(3000); // Adjust delay as needed
  }

  delay(100); // Adjust delay between readings
}