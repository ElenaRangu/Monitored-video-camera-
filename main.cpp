#include <Servo.h>

// Define the pins for PIR sensors
const int pirPins[] = {2, 3, 4, 5, 6}; // Adjust pins as needed
const int numSensors = sizeof(pirPins) / sizeof(pirPins[0]);

// Define servo motor pin
const int servoPin = 9;

Servo servoMotor;

void setup() {
  // Initialize PIR sensors
  for (int i = 0; i < numSensors; ++i) {
    pinMode(pirPins[i], INPUT);
  }

  // Initialize servo motor
  servoMotor.attach(servoPin);
}

void loop() {
  // Check each PIR sensor for motion
  for (int i = 0; i < numSensors; ++i) {
    if (digitalRead(pirPins[i]) == HIGH) {
      // Motion detected by PIR sensor i
      int angle = map(i, 0, numSensors - 1, 0, 180); // Map sensor index to servo angle
      rotateServo(angle);
      delay(500); // Wait for servo to move (adjust delay as needed)
    }
  }
}

void rotateServo(int angle) {
  servoMotor.write(angle);
  delay(15); // Wait for servo to reach position (adjust delay as needed)
}
