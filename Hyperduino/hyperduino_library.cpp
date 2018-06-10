/*
   hyperduino_library.cpp
   Library for Hyperduino
   Henry Forsyth June 9, 2018
*/

#include "Arduino.h"
#include "hyperduino_library.h"

Hyperduino::Hyperduino(String type)
{
  type = _type;
}

void Hyperduino::forward() {
  if (_type == 'A') {
    digitalWrite(motorPinA1, HIGH);
    digitalWrite(motorPinB1, LOW);
  }
  if (_type == 'B') {

  }
}
void Hyperduino::backward() {
  if (_type == 'A') {
    digitalWrite(motorPinA1, LOW);
    digitalWrite(motorPinB1, HIGH);
  }
  if (_type == 'B') {

  }
}
void Hyperduino::speedSet(int pace){
}
void Hyperduino::stopAll() {
  digitalWrite(standbyPin, LOW);
}
void Hyperduino::activateAll() {
  digitalWrite(standbyPin, HIGH);
}
void Hyperduino::begin(){
  pinMode(speedControlPinA, OUTPUT);
  pinMode(motorPinA1, OUTPUT);
  pinMode(motorPinA2, OUTPUT);
  pinMode(standbyPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Hyperduino Library Operational");
  Serial.print("Hyperduino Specs:");
  Serial.println(_type);
}
