#include <hyperduino_library.h>

Hyperduino bob(2.4);

void setup() {
  // put your setup code here, to run once:
  bob.begin();
  bob.activateAllMotors();
  bob.speedSetMotor('B', 200);
}

void loop() {
  // put your main code here, to run repeatedly:
  bob.forward('B');

}
