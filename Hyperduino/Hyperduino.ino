#include "hyperduino_library.h"


Hyperduino bob('A', 2.4);

void setup() {
  // put your setup code here, to run once:
  bob.begin();
  bob.activateAll();
  bob.speedSet(0);
}

void loop() {
  // put your main code here, to run repeatedly:
  bob.backward();
}
