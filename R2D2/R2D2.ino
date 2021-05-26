#include <Ps3Controller.h>
#include <ESP32Servo.h>

// servo FS90R
int P_MIN = 700;
int P_MAX = 2300;
int FREQ = 50;

// pin
int pin_M_TESTA = 12;
int pin_M_DESTRA = 14;
int pin_M_SINISTRA = 27;

// comando
int M_FERMO = 90;
int M_AVANTI = 70;
int M_INDIETRO = 110;

int lxpos = 0;
int lypos = 0;
int rxpos = 0;

int pos = 0;

Servo servoT; 
Servo servoD; 
Servo servoS; 

// callback, le funzioni vengono attivate via trigger
void notify()
{   
    //--- Digital cross/square/triangle/circle button events ---
    if ( Ps3.event.button_down.cross )
      playaudio(1);
    if ( Ps3.event.button_down.square )
      playaudio(2);
    if ( Ps3.event.button_down.triangle )
      playaudio(3);
    if ( Ps3.event.button_down.circle )
      playaudio(4);
    //---------- Digital playstation button events ---------
    if ( Ps3.event.button_down.ps )
      fermatutto();
    //---------------- Left stick - muove il robot ---------------
    if ( abs ( Ps3.event.analog_changed.stick.lx ) + abs ( Ps3.event.analog_changed.stick.ly ) > 2 )
    {
      lxpos = Ps3.data.analog.stick.lx;
      lypos = Ps3.data.analog.stick.ly;
      if (lxpos >= -10 && lxpos <= 10 )
      {
        if (lypos < -10)
          avanti();
        if (lypos > 10)
          indietro();
        if (lypos >= -10 && lypos <= 10)
          fermatutto();
      }
      if (lypos >= -10 && lypos <= 10)
      {
        if (lxpos <-10) 
          sinistra();
        if (lxpos > 10)
          destra();
        if (lxpos >= -10 && lxpos <= 10)
          fermatutto();    
      }
    }
    if ( abs ( Ps3.event.analog_changed.stick.rx ) + abs ( Ps3.event.analog_changed.stick.ry ) > 2 )
    {
      rxpos = Ps3.data.analog.stick.rx;
      if (rxpos < -10) 
        testasx();
      if (rxpos > 10)
        testadx();
      if (rxpos <= 10 && rxpos >= -10)
        testastop();
    }
}

void onConnect(){
    playaudio(5);
}

void playaudio(int traccia)
{
  
}

void fermatutto()
{
  pos = M_FERMO;
  servoD.write(pos);
  servoS.write(pos);
}

void avanti()
{
  servoD.write(M_AVANTI);
  servoS.write(M_INDIETRO);
}

void indietro()
{
  servoS.write(M_AVANTI);
  servoD.write(M_INDIETRO);
}

void sinistra()
{
  servoS.write(M_AVANTI);
  servoD.write(M_AVANTI);
}

void destra()
{
  servoS.write(M_INDIETRO);
  servoD.write(M_INDIETRO);
}

void testasx()
{
  servoT.write(M_AVANTI);
}

void testadx()
{
  servoT.write(M_INDIETRO);
}

void testastop()
{
  pos = M_FERMO;
  servoT.write(pos);
}

void setup()
{
    Serial.begin(115200);
    Ps3.attach(notify);
    Ps3.attachOnConnect(onConnect);
    Ps3.begin("01:02:03:04:05:06");
    ESP32PWM::allocateTimer(0);
    ESP32PWM::allocateTimer(1);
    ESP32PWM::allocateTimer(2);
    ESP32PWM::allocateTimer(3);
    servoT.setPeriodHertz(FREQ);
    servoD.setPeriodHertz(FREQ);
    servoS.setPeriodHertz(FREQ);
    servoT.attach(pin_M_TESTA, P_MIN, P_MAX);
    servoD.attach(pin_M_DESTRA, P_MIN, P_MAX);
    servoS.attach(pin_M_SINISTRA, P_MIN, P_MAX);
}

void loop()
{
    if(!Ps3.isConnected())
        return;
    delay(2000);
}
