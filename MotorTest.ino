// Adafruit Motor shield library
// copyright Adafruit Industries LLC, 2009
// this code is public domain, enjoy!

#include <AFMotor.h>

AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Motor test!");

  // turn on motor
  motor3.setSpeed(200);
  motor4.setSpeed(200);
 
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}

void loop() {
  uint8_t i;
  
  Serial.print("tick");
  
  motor3.run(FORWARD);
  for (i=0; i<255; i++) {
    motor3.setSpeed(i);  
    delay(10);
 }
 motor4.run(FORWARD);
  for (i=0; i<255; i++) {
    motor4.setSpeed(i);  
    delay(10);
 }
 
  for (i=255; i!=0; i--) {
    motor3.setSpeed(i);  
    delay(10);
 }
  for (i=255; i!=0; i--) {
    motor4.setSpeed(i);  
    delay(10);
 }
  
  Serial.print("tock");

  motor3.run(BACKWARD);
  for (i=0; i<255; i++) {
    motor3.setSpeed(i);  
    delay(10);
 }
   motor4.run(BACKWARD);
  for (i=0; i<255; i++) {
    motor4.setSpeed(i);  
    delay(10);
 }
 
 
  for (i=255; i!=0; i--) {
    motor3.setSpeed(i);  
    delay(10);
 }
 for (i=255; i!=0; i--) {
    motor4.setSpeed(i);  
    delay(10);
 }
  

  Serial.print("tech");
  motor3.run(RELEASE);
  motor4.run(RELEASE);
  delay(1000);
}
