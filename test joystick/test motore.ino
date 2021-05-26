#include <Servo.h>

Servo servo01;
int servo1Pos;

void setup() {
  servo01.attach(5);
  delay(20);
  servo1PPos = 90;
  servo01.write(servo1Pos);
  }

  void loop() {
//    if (servo1PPos > servo1Pos) {
//        for ( int j = servo1PPos; j >= servo1Pos; j--) {   // Run servo down
//          servo01.write(j);
//          delay(20);    // defines the speed at which the servo rotates
//        }
//
      // If previous position is smaller then current position
//      if (servo1PPos < servo1Pos) {
//        for ( int j = servo1PPos; j <= servo1Pos; j++) {   // Run servo up
//          servo01.write(j);
//          delay(20);
//        }
//      }
//      servo1PPos = servo1Pos;   // set current position as previous position

      }
