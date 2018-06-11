/*
   hyperduino_library.h
   Library for Hyperduino
   Henry Forsyth June 9, 2018
*/

#ifndef hyperduino_library_h
#define hyperduino_library_h

#include "Arduino.h"

class Hyperduino
{
  public:
    Hyperduino(float versionNumber = 0);
    void forward(char whichMotor);
    void backward(char whichMotor);
    void speedSetMotor(char whichMotor, int pace);
    void stopAllMotors();
    void activateAllMotors();
    void begin();
  private:
    char _type;
    float _versionNumber;
    int Hyperduino2_4R[7] = {3, 4, 5, 6, 7 , 8, 9};
    /* Hyperduino 2.4R
       Motor B: Speed: 3, motorPinB1: 4, motorPinA2: 5, standbyPin: 6
       Motor A: Speed: 9, motorPinA1: 7, motorPinA2: 8, standbyPin: 6
    */
    int Hyperduino3_5R[6] = {8, 9, 10, 11, 12, 13};
    /* Hyperduino 3.5 R
       Motor A: pins 8, 9, speed = 10
       Motor B: pins 12, 13, speed = 11
    */
    void HypeForward2_4R(char whichMotor);
    void HypeBackward2_4R(char whichMotor);
    void HypeSetSpeed2_4R(char whichMotor, int pace);
    void HypeForward3_5R(char whichMotor);
    void HypeBackward3_5R(char whichMotor);
    void HypeSetSpeed3_5R(char whichMotor, int pace);
};

#endif
