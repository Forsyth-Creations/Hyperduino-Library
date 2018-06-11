/*
   hyperduino_library.cpp
   Library for Hyperduino
   Henry Forsyth June 9, 2018
*/

#include "Arduino.h"
#include "hyperduino_library.h"

Hyperduino::Hyperduino(float versionNumber = 0)
{
  _versionNumber = versionNumber;
}

void Hyperduino::forward(char whichMotor)
{
  if (_versionNumber == 2.40)
  {
    HypeForward2_4R(whichMotor);
  }
  else if (_versionNumber == 3.50) {
    HypeForward3_5R(whichMotor);
  }
}

void Hyperduino::backward(char whichMotor)
{
  if (_versionNumber == 2.40)
  {
    HypeBackward2_4R(whichMotor);
  }
  else if (_versionNumber == 3.50) {
    HypeBackward3_5R(whichMotor);
  }
}

void Hyperduino::speedSetMotor(char whichMotor, int pace)
{
  if (_versionNumber == 2.40)
  {
    HypeSetSpeed2_4R(whichMotor, pace);
  }
  else if (_versionNumber == 3.50) {
    HypeSetSpeed3_5R(whichMotor, pace);
  }
}

void Hyperduino::stopAllMotors()
{
  if (_versionNumber == 2.40)
  {
    digitalWrite(Hyperduino2_4R[3], LOW);
  }
  else if (_versionNumber == 3.50) {
    //No such capabilities with the 3.5 version
  }
}

void Hyperduino::activateAllMotors()
{
  if (_versionNumber == 2.40)
  {
    digitalWrite(Hyperduino2_4R[3], HIGH);
  }
  else if (_versionNumber == 3.50) {
    //No such capabilities with the 3.5 version
  }
}

void Hyperduino::begin() {
  Serial.begin(9600);
  Serial.println("Hyperduino Library Operational");
  Serial.print("Hyperduino Specs: ");
  Serial.println(_versionNumber);
  if (_versionNumber == 2.40)
  {
    digitalWrite(Hyperduino2_4R[3], HIGH);
    analogWrite(Hyperduino2_4R[6], 0);
    analogWrite(Hyperduino2_4R[0], 0);
  }
  else if (_versionNumber == 3.50) {
    //Unsure
  }
  //delay(1000);
}

//------------------------------------------ All Private Motor Functions Below -----------------------------------------------

void Hyperduino::HypeForward2_4R(char whichMotor)
{
  if (whichMotor == 'A') {
    Serial.println("A Forward");
    digitalWrite(Hyperduino2_4R[4], HIGH);
    digitalWrite(Hyperduino2_4R[5], LOW);
  }
  if (whichMotor == 'B') {
    Serial.println("B Forward");
    digitalWrite(Hyperduino2_4R[1], HIGH);
    digitalWrite(Hyperduino2_4R[2], LOW);
  }
}

void Hyperduino::HypeBackward2_4R(char whichMotor)
{
  if (whichMotor == 'A') {
    Serial.println("A Backward");
    digitalWrite(Hyperduino2_4R[4], LOW);
    digitalWrite(Hyperduino2_4R[5], HIGH);
  }
  if (whichMotor == 'B') {
    Serial.println("B Backward");
    digitalWrite(Hyperduino2_4R[1], LOW);
    digitalWrite(Hyperduino2_4R[2], HIGH);
  }
}

void Hyperduino::HypeSetSpeed2_4R(char whichMotor, int pace)
{
  if (whichMotor == 'A') {
    Serial.print("Speed Set to: ");
    Serial.println(pace);
    analogWrite(Hyperduino2_4R[6], pace);
  }
  if (whichMotor == 'B') {
    Serial.print("Speed Set to: ");
    Serial.println(pace);
    analogWrite(Hyperduino2_4R[0], pace);
  }
}

void Hyperduino::HypeForward3_5R(char whichMotor)
{
  if (whichMotor == 'A') {
    Serial.println("A Forward");
    digitalWrite(Hyperduino3_5R[0], HIGH);
    digitalWrite(Hyperduino3_5R[1], LOW);
  }
  if (whichMotor == 'B') {
    Serial.println("B Forward");
    digitalWrite(Hyperduino3_5R[4], HIGH);
    digitalWrite(Hyperduino3_5R[5], LOW);
  }
}

void Hyperduino::HypeBackward3_5R(char whichMotor)
{
  if (whichMotor == 'A') {
    Serial.println("A Forward");
    digitalWrite(Hyperduino3_5R[0], LOW);
    digitalWrite(Hyperduino3_5R[1], HIGH);
  }
  if (whichMotor == 'B') {
    Serial.println("B Forward");
    digitalWrite(Hyperduino3_5R[4], LOW);
    digitalWrite(Hyperduino3_5R[5], HIGH);
  }
}

void Hyperduino::HypeSetSpeed3_5R(char whichMotor, int pace)
{
if (whichMotor == 'A') {
    Serial.print("Speed Set to: ");
    Serial.println(pace);
    analogWrite(Hyperduino3_5R[2], pace);
  }
  if (whichMotor == 'B') {
    Serial.print("Speed Set to: ");
    Serial.println(pace);
    analogWrite(Hyperduino3_5R[5], pace);
  }
}

