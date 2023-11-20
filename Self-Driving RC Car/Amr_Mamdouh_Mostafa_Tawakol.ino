#include <SoftwareSerial.h>

// Define the input and output pins

#define TRIG_PIN 11
#define ECHO_PIN 12
#define CENTER_PIN 2
#define RIGHT_PIN 3
#define LEFT_PIN 4
#define HBRIDGE_IN1 5
#define HBRIDGE_IN2 6
#define HBRIDGE_IN3 7
#define HBRIDGE_IN4 8
int Time;
float distance;
int ENB1 = 9;
int ENB2 = 10;
// Define the speed of the motors
const int MotorSpeed = 90;
const int speed = 90;
// Define the minimum distance for obstacle detection
const int ObstacleDistanceThreshold = 20;

void setup() {
  // Initialize the pins
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(CENTER_PIN, INPUT);
  pinMode(RIGHT_PIN, INPUT);
  pinMode(LEFT_PIN, INPUT);
  pinMode(HBRIDGE_IN1, OUTPUT);
  pinMode(HBRIDGE_IN2, OUTPUT);
  pinMode(HBRIDGE_IN3, OUTPUT);
  pinMode(HBRIDGE_IN4, OUTPUT);
  pinMode(ENB1, OUTPUT);
  pinMode(ENB2, OUTPUT);

  // Initialize the serial communication
  Serial.begin(9600);
}

void loop() {

  // Line following
  if (digitalRead(CENTER_PIN) == 1 && digitalRead(RIGHT_PIN) == 0 && digitalRead(LEFT_PIN) == 0) {
    moveForward(MotorSpeed);
  } else if (digitalRead(CENTER_PIN) == 0 && digitalRead(RIGHT_PIN) == 1 && digitalRead(LEFT_PIN) == 0) {
    turnRight(MotorSpeed);
  } else if (digitalRead(CENTER_PIN) == 0 && digitalRead(RIGHT_PIN) == 0 && digitalRead(LEFT_PIN) == 1) {
    turnLeft(MotorSpeed);
  } else if (digitalRead(CENTER_PIN) == 0 && digitalRead(RIGHT_PIN) == 0 && digitalRead(LEFT_PIN) == 0) {
    // BackMoving(MotorSpeed);
    //delay (500);
    stopMoving();
  } else if (digitalRead(CENTER_PIN) == 1 && digitalRead(RIGHT_PIN) == 1 && digitalRead(LEFT_PIN) == 0) {
    turnRight(MotorSpeed);
  } else if (digitalRead(CENTER_PIN) == 1 && digitalRead(RIGHT_PIN) == 0 && digitalRead(LEFT_PIN) == 1) {
    turnLeft(MotorSpeed);
  } else {
    // If the sensors are reading incorrectly, stop the car
    stopMoving();
  }

  while (Serial.available()) {
    processBluetoothInput();
  }

  // Obstacle detection
  if (isObstacleDetected()) {
    stopMoving();
    Serial.println("Obstacle detected!");
  }

}

// Move the car forward
void moveForward(int speed) {
  digitalWrite(HBRIDGE_IN1, speed );
  digitalWrite(HBRIDGE_IN2, 0);
  digitalWrite(HBRIDGE_IN3, speed);
  digitalWrite(HBRIDGE_IN4, 0);
  analogWrite(ENB1, 80);
  analogWrite(ENB2, 80);
}

// Turn the car right
void turnRight(int speed) {
  digitalWrite(HBRIDGE_IN1, 0);
  digitalWrite(HBRIDGE_IN2, speed);
  digitalWrite(HBRIDGE_IN3, speed);
  digitalWrite(HBRIDGE_IN4, 0);
  analogWrite(ENB1, 80);
  analogWrite(ENB2, 80);
}

// Turn the car left
void turnLeft(int speed) {
  digitalWrite(HBRIDGE_IN1, speed);
  digitalWrite(HBRIDGE_IN2, 0 );
  digitalWrite(HBRIDGE_IN3, 0);
  digitalWrite(HBRIDGE_IN4, speed);
  analogWrite(ENB1, 80);
  analogWrite(ENB2, 80);
}

// Stop the car
void stopMoving() {

  // Stop
  digitalWrite(HBRIDGE_IN1, 0);
  digitalWrite(HBRIDGE_IN2, 0);
  digitalWrite(HBRIDGE_IN3, 0);
  digitalWrite(HBRIDGE_IN4, 0);
}
void BackMoving(int speed) {
  // Backward step first
  digitalWrite(HBRIDGE_IN1, 0 );
  digitalWrite(HBRIDGE_IN2, speed);
  digitalWrite(HBRIDGE_IN3, 0);
  digitalWrite(HBRIDGE_IN4, speed);
  analogWrite(ENB1, 80);
  analogWrite(ENB2, 80);
  delay (1000);
}

// Check if an obstacle is detected
bool isObstacleDetected() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  Time = pulseIn(ECHO_PIN, HIGH);
  distance = constrain((Time / 58.31), 4, 400);
  Serial.println("the distance between object:");
  Serial.println(distance);
  Serial.println("CM");
  int distance = pulseIn(ECHO_PIN, HIGH) / 58;
  if (distance < ObstacleDistanceThreshold) {
    return true;
  } else {
    return false;
  }
}

// Process input from Bluetooth
void processBluetoothInput() {
  while (Serial.available()) {
    char input = Serial.read();
    switch (input) {
      case 'F':
        moveForward(MotorSpeed);
        break;
      case 'R':
        turnRight(MotorSpeed);
        break;
      case 'L':
        turnLeft(MotorSpeed);
        break;
      case 'S':
        stopMoving();
        break;
      case 'B':
        BackMoving(MotorSpeed);
        break;
      default:
        // Ignore any other input
        break;
    }
  }
}
