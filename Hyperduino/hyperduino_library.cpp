/*
   hyperduino_library.cpp
   Library for Hyperduino
   Henry Forsyth June 9, 2018
*/

#include "Arduino.h"
#include "hyperduino_library.h"

Hyperduino::Hyperduino(char type, float versionNumber = 0)
{
  _type = type;
  _versionNumber = versionNumber;
}

void Hyperduino::forward() {
  if (_type == 'A') {
    Serial.println("A Forward");
    digitalWrite(motorPinA1, HIGH);
    digitalWrite(motorPinA2, LOW);
  }
  if (_type == 'B') {

  }
}
void Hyperduino::backward() {
  if (_type == 'A') {
    Serial.println("A Backward");
    digitalWrite(motorPinA1, LOW);
    digitalWrite(motorPinA2, HIGH);
  }
  if (_type == 'B') {

  }
}
void Hyperduino::speedSet(int pace) {
    if (_type == 'A') {
    Serial.print("Speed Set to: ");
    Serial.println(pace);
    analogWrite(speedControlPinA, pace);
  }
  if (_type == 'B') {
    Serial.print("Speed Set to: ");
    Serial.println(pace);
    analogWrite(speedControlPinB, pace);
  }
}
void Hyperduino::stopAll() {
  digitalWrite(standbyPin, LOW);
}
void Hyperduino::activateAll() {
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
  Serial.print(_type);
  Serial.print(" , ");
  Serial.print(_versionNumber);
}
