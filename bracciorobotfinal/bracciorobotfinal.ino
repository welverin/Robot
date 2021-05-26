#include <Servo.h>

Servo base;
Servo spalla;
Servo gomito;
Servo polso_rotazione;
Servo polso_movimento;
Servo pinza;

int newPos;

int basePos;
int JoyStick1_X=0;
int spallaPos;
int JoyStick1_Y=1;
int gomitoPos;
int JoyStick2_X=4;
int polsoRotazionePos;
int JoyStick2_Y=5;
int polsoMovimentoPos;
int JoyStick3_X=2;
int pinzaPos;
int JoyStick3_Y=3;

void setup() {
  base.attach(5);
  spalla.attach(6);
  gomito.attach(7);
  polso_rotazione.attach(8);
  polso_movimento.attach(9);
  pinza.attach(10);
  delay(20);

  basePos = 90;
  base.write(basePos);
  delay(100);
  spallaPos = 90;
  spalla.write(spallaPos);
  delay(100);
  gomitoPos = 90;
  gomito.write(gomitoPos);
  delay(100);
  polsoRotazionePos = 90;
  polso_rotazione.write(polsoRotazionePos);
  delay(100);
  polsoMovimentoPos = 90;
  polso_movimento.write(polsoMovimentoPos);
  delay(100);
  pinzaPos = 90;
  pinza.write(pinzaPos);
  delay(100);

}

void loop() {
int x
x=analogRead(JoyStick1_X);
    newpos = 60;
    if (newpos > servo1Pos) {
        for ( int j = newpos; j >= servo1Pos; j--) {   // Run servo down
          servo01.write(j);
          delay(20);    // defines the speed at which the servo rotates
        }

      // If previous position is smaller then current position
      if (newpos < servo1Pos) {
        for ( int j = newpos; j <= servo1Pos; j++) {   // Run servo up
          servo01.write(j);
          delay(20);
        }
      }
      servo1Pos = newpos;   // set current position as previous position

      }
      }
