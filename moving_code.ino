#include <AFMotor.h>

AF_DCMotor MotorFR(1);   // Right motor
AF_DCMotor MotorFL(2);   // Left motor

const int buzPin = 2;    
const int ledPin = A5;   
int valSpeed = 255;      

void setup() {
  Serial.begin(9600);

  pinMode(buzPin, OUTPUT);
  pinMode(ledPin, OUTPUT);

  MotorFL.setSpeed(valSpeed);
  MotorFR.setSpeed(valSpeed);

  MotorFL.run(RELEASE);
  MotorFR.run(RELEASE);
}

void loop() {
  while (Serial.available() > 0) {
    char command = Serial.read();
    Serial.println(command);

    switch (command) {

      case 'F':   // Forward
        SetSpeed(valSpeed);
        MotorFL.run(FORWARD);
        MotorFR.run(FORWARD);
        break;

      case 'B':   // Backward
        SetSpeed(valSpeed);
        MotorFL.run(BACKWARD);
        MotorFR.run(BACKWARD);
        break;

      case 'R':   // Right turn
        SetSpeed(valSpeed);
        MotorFL.run(FORWARD);
        MotorFR.run(BACKWARD);
        break;

      case 'L':   // Left turn
        SetSpeed(valSpeed);
        MotorFL.run(BACKWARD);
        MotorFR.run(FORWARD);
        break;

      case 'G':   // Forward left
        MotorFL.setSpeed(valSpeed / 4);
        MotorFR.setSpeed(valSpeed);
        MotorFL.run(FORWARD);
        MotorFR.run(FORWARD);
        break;

      case 'H':   // Forward right
        MotorFR.setSpeed(valSpeed / 4);
        MotorFL.setSpeed(valSpeed);
        MotorFL.run(FORWARD);
        MotorFR.run(FORWARD);
        break;

      case 'I':   // Backward left
        MotorFL.setSpeed(valSpeed / 4);
        MotorFR.setSpeed(valSpeed);
        MotorFL.run(BACKWARD);
        MotorFR.run(BACKWARD);
        break;

      case 'J':   // Backward right
        MotorFR.setSpeed(valSpeed / 4);
        MotorFL.setSpeed(valSpeed);
        MotorFL.run(BACKWARD);
        MotorFR.run(BACKWARD);
        break;

      case 'S':   // Stop
        MotorFL.run(RELEASE);
        MotorFR.run(RELEASE);
        break;

      case 'Y':   // Horn
        digitalWrite(buzPin, HIGH);
        delay(200);
        digitalWrite(buzPin, LOW);
        delay(80);
        digitalWrite(buzPin, HIGH);
        delay(300);
        digitalWrite(buzPin, LOW);
        break;

      case 'X':   // Light ON
        digitalWrite(ledPin, HIGH);
        break;

      case 'x':   // Light OFF
        digitalWrite(ledPin, LOW);
        break;

      // Speed 0–9
      case '0': SetSpeed(0); break;
      case '1': SetSpeed(25); break;
      case '2': SetSpeed(50); break;
      case '3': SetSpeed(75); break;
      case '4': SetSpeed(100); break;
      case '5': SetSpeed(125); break;
      case '6': SetSpeed(150); break;
      case '7': SetSpeed(175); break;
      case '8': SetSpeed(200); break;
      case '9': SetSpeed(255); break;
    }
  }
}

void SetSpeed(int val) {
  valSpeed = val;
  MotorFL.setSpeed(val);
  MotorFR.setSpeed(val);
}