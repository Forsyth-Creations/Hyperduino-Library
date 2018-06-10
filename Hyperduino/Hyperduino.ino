#include "hyperduino_library.h"

Hyperduino bob(2.4);

void setup() {
  // put your setup code here, to run once:
  bob.begin();
  bob.activateAllMotors();
  bob.speedSetMotor('A', 0);
}

void loop() {
  // put your main code here, to run repeatedly:
  bob.forward('A');
  delay(2000);
  bob.backward('A');
  delay(2000);
}
