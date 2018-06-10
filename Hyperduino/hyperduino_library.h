/*
 * hyperduino_library.h
 * Library for Hyperduino
 * Henry Forsyth June 9, 2018
 */

#ifndef hyperduino_library_h
#define hyperduino_library_h

#include "Arduino.h"

class Hyperduino
{
  public:
    Hyperduino(char type, float versionNumber = 0);
    void forward();
    void backward();
    void speedSet(int pace);
    void stopAll();
    void activateAll();
    void begin();
  private:
    char _type;
    float _versionNumber;
    #define speedControlPinA 9
    #define motorPinA1 7
    #define motorPinA2 8
    #define standbyPin 6
    #define speedControlPinB 3
    #define motorPinB1 5
    #define motorPinB2 4

    // Motor A: Speed: 9, motorPinA1: 7, motorPinA2: 8, standbyPin: 6
    // Motor B: Speed: 3, motorPinA1: 4, motorPinA2: 5, standbyPin: 6
};

#endif
