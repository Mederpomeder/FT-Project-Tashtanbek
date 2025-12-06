#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define PANEL_TRIG 2
#define PANEL_ECHO 3
#define INNER_TRIG 4
#define INNER_ECHO 5
#define LED_FULL 8
#define SERVO_LID 6
#define SERVO_TIE1 7
#define SERVO_TIE2 10
#define SERVO_TIE3 11
#define SERVO_TIE4 9
#define PANEL_TRIGGER_DISTANCE 20
#define BIN_FULL_DISTANCE 15
#define HOLD_THRESHOLD 3000    

Servo lidServo;
Servo tie1, tie2, tie3, tie4;
LiquidCrystal_I2C lcd(0x27, 16, 2);

bool handPresent = false;
unsigned long handStartTime = 0;
bool sequenceRunning = false;

long getDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  return pulseIn(echoPin, HIGH) / 58;
}

void lidOpen() {
  lcd.clear();
  lcd.print("LID OPENING");
  for (int pos = 0; pos <= 120; pos++) {
    lidServo.write(pos);
    delay(10); 
  }
}

void lidClose() {
  lcd.clear();
  lcd.print("LID CLOSING");
  for (int pos = 120; pos >= 0; pos--) {
    lidServo.write(pos);
    delay(10);
  }
  lcd.clear();
  lcd.print("READY");
}

void runQuartet() {
  lcd.clear();
  lcd.print("QUARTET...");
  tie1.write(0);     // пин 7 перед мусорки лево
  tie4.write(180);   // пин 9 перед мусорки право
  tie2.write(180);   // пин 10 зад мусорки лево
  tie3.write(0);     // пин 11 зад мусорки право
  delay(800);

  tie1.write(90);
  tie4.write(90);
  tie2.write(90);
  tie3.write(90);
  delay(800);
}

void setup() {
  Serial.begin(9600);

  pinMode(PANEL_TRIG, OUTPUT);
  pinMode(PANEL_ECHO, INPUT);
  pinMode(INNER_TRIG, OUTPUT);
  pinMode(INNER_ECHO, INPUT);
  pinMode(LED_FULL, OUTPUT);

  lidServo.attach(SERVO_LID);
  tie1.attach(SERVO_TIE1);
  tie2.attach(SERVO_TIE2);
  tie3.attach(SERVO_TIE3);
  tie4.attach(SERVO_TIE4);

  lidServo.write(0);
  tie1.write(90);
  tie2.write(90);
  tie3.write(90);
  tie4.write(90);

  lcd.init();
  lcd.backlight();
  lcd.print("SMART BIN");
  delay(1000);
  lcd.clear();
  lcd.print("READY");
}

void loop() {
  long handDist = getDistance(PANEL_TRIG, PANEL_ECHO);
  long innerDist = getDistance(INNER_TRIG, INNER_ECHO);
  if (innerDist > 0 && innerDist <= BIN_FULL_DISTANCE) {
    digitalWrite(LED_FULL, HIGH);
  } else {
    digitalWrite(LED_FULL, LOW);
  }

  bool handDetected = (handDist > 0 && handDist <= PANEL_TRIGGER_DISTANCE);

  if (handDetected && !handPresent && !sequenceRunning) {
    handPresent = true;
    handStartTime = millis();
    Serial.println("HAND DETECTED - START TIMER");
  }

  if (handDetected && handPresent && !sequenceRunning) {
    unsigned long holdTime = millis() - handStartTime;
    if (holdTime >= HOLD_THRESHOLD) {
      sequenceRunning = true;
      Serial.println("LONG HOLD - QUARTET START");
      lidOpen();              
      delay(2000);            
      runQuartet();           
      delay(1000);            
      lidClose();             
      sequenceRunning = false;
      handPresent = false;
      return;
    }
  }

  if (!handDetected && handPresent && !sequenceRunning) {
    unsigned long holdTime = millis() - handStartTime;
    handPresent = false;
    if (holdTime < HOLD_THRESHOLD) {
      sequenceRunning = true;
      Serial.println("SHORT HOLD - LID ONLY");

      lidOpen();
      delay(700);
      lidClose();

      sequenceRunning = false;
    }
  }
  
  delay(30);
}