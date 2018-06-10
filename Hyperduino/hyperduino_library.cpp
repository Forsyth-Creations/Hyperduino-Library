/*
   hyperduino_library.cpp
   Library for Hyperduino
   Henry Forsyth June 9, 2018
*/

#include "Arduino.h"
#include "hyperduino_library.h"

Hyperduino::Hyperduino(float versionNumber = 0){
  _versionNumber = versionNumber;
}

void Hyperduino::forward(char whichMotor) 
{
  if (whichMotor == 'A') {
    Serial.println("A Forward");
    digitalWrite(motorPinA1, HIGH);
    digitalWrite(motorPinA2, LOW);
  }
  if (whichMotor == 'B') {
    Serial.println("B Forward");
    digitalWrite(motorPinB1, HIGH);
    digitalWrite(motorPinB2, LOW);
  }
}

void Hyperduino::backward(char whichMotor) 
{
  if (whichMotor == 'A') {
    Serial.println("A Backward");
    digitalWrite(motorPinA1, LOW);
    digitalWrite(motorPinA2, HIGH);
  }
  if (whichMotor == 'B') {
    Serial.println("B Backward");
    digitalWrite(motorPinB1, LOW);
    digitalWrite(motorPinB2, HIGH);
  }
}

void Hyperduino::speedSetMotor(char whichMotor, int pace) 
{
  if (whichMotor == 'A') {
    Serial.print("Speed Set to: ");
    Serial.println(pace);
    analogWrite(speedControlPinA, pace);
  }
  if (whichMotor == 'B') {
    Serial.print("Speed Set to: ");
    Serial.println(pace);
    analogWrite(speedControlPinB, pace);
  }
}

void Hyperduino::stopAllMotors() 
{
  digitalWrite(standbyPin, LOW);
}

void Hyperduino::activateAllMotors() 
{
  digitalWrite(standbyPin, HIGH);
}

void Hyperduino::begin() {
  pinMode(speedControlPinA, OUTPUT);
  pinMode(motorPinA1, OUTPUT);
  pinMode(motorPinA2, OUTPUT);
  pinMode(standbyPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Hyperduino Library Operational");
  Serial.print("Hyperduino Specs: ");
  Serial.println(_versionNumber);
  digitalWrite(standbyPin, HIGH);
  delay(1000);
}

