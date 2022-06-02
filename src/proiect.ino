#include <Servo.h>

const int Y_pin = 0; // controleaza servo din mijloc, adica transServo
const int X_pin = 1; // controleaza main servo, adica myServo

const int pin1 = 2;
const int pin2 = 3;

Servo myServo;
int myServoPos = 0;
const int myServoStartLimit = 0; // pozitie orizontala
const int myServoEndLimit = 50;

Servo transServo;
int transServoPos = 140;
const int transServoStartLimit = 0; // pozitie verticala, capat in jos
const int transServoEndLimit = 150; // putin peste 90, unde 90 ar fii pozitie orizontala

Servo gripServo;
int gripServoPos = 0;
const int gripServoStartLimit = 0; // pozitie in care gripperul este deschis
const int gripServoEndLimit = 24; // 26 merge ok cu delay(50), si este aproape limit de holder

Servo baseServo;
int baseServoPos = 0;
const int baseServoStartLimit = 0;
const int baseServoEndLimit = 0;

void setup() {
  /* Attach all servos */
  myServo.attach(5);
  transServo.attach(6);
  gripServo.attach(9);
  baseServo.attach(10);

}

void move_middle() {
  int val;
  
  val = analogRead(Y_pin);
  if(val >= 720 && transServoPos <= 149) {
    transServoPos += 1;
  }

  if(val <= 540 && transServoPos >= 1) {
    transServoPos -= 1;
  }
  
}

void move_base() {
  int val;
  
  val = analogRead(pin2);
  if(val >= 720 && baseServoPos <= 59) {
    baseServo.write(baseServoPos + 1);
    delay(15);
    baseServoPos += 1;
  }

  if(val <= 540 && baseServoPos >= 1) {
    baseServo.write(baseServoPos - 1);
    delay(15);
    baseServoPos -= 1;
  }
  
}

void move_main() {
  int val;
  
  val = analogRead(X_pin);
  if(val >= 720 && myServoPos <= 49) {
    myServoPos += 1;
  }

  if(val <= 540 && myServoPos >= 1) {
    myServoPos -= 1;
  }
}

void move_gripper() {
  int val;
  
  val = analogRead(pin1);
  if(val >= 720 && gripServoPos <= 23) {
    gripServoPos += 1;
  }

  if(val <= 540 && gripServoPos >= 1) {
    gripServoPos -= 1;
  }
}

void loop() {
  move_base();

  move_main();

  move_middle();

  move_gripper();

  transServo.write(transServoPos);
  myServo.write(myServoPos);
  gripServo.write(gripServoPos);
  baseServo.write(baseServoPos);
  delay(15);

}
