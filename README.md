# 3D Printed Robot
R2 droid driven by a PS4 controller

## Hardware :
Droid : Michael Baddeley Design

Head : ESP32

Servo Controller : 16-Channel 12-bit PWM/Servo Driver - I2C interface - PCA9685 

Servo : FS90-R (continuous servo)

Audio Ampli. : I2S 3W Class D Amplifier Breakout - MAX98357A

Speaker : 3 Watt 4 Ohm

Power : 

Controller : PS4 compatible (Chinese clone)


## Wirings

### Audio I2S
```
Amp       ESP32 DevKit v4
Vin       3V3               (Pin )
GND       GND               (Pin 20)
DIN       PCM_DOUT (Pin )
BCLK      PCM_CLK  (Pin )
LRCLK     PCM_FS   (Pin )
```
### PWM I2C
```
MotorBoard  ESP32 DevKit v4
VCC         3V3             (Pin )
GND         GND             (Pin )
SCL         SCL     (Pin )
SDA         SDA     (Pin )
```
### Servo
```
MotorBoard  Servo
PWM         Orange
V+          Red
GND         Black
```


## Prerequisites:

Arduino IDE
Add ESP32 repository and board
Add Library/Package for Servo and Audio


## Documentation

* Hardware

  https://www.facebook.com/groups/MrBaddeley/

  https://www.adafruit.com/product/815
  
  https://www.adafruit.com/product/3006
 
* Library

  https://learn.adafruit.com/16-channel-pwm-servo-driver/
  
  https://learn.adafruit.com/adafruit-max98357-i2s-class-d-mono-amp/


## Raspberry ?

First version of this project was based on Raspberry Pi Zero W, the software was written in Python and everything worked very well. 

Why did I change the Head to ESP32 ?

The are 3 reasons. 

The first was the power supply, I didn't have the physical space for a battery to power the raspberry independently from the servos.

The second is the boot times and any bluetooth pairing problems. 

The third is the possibility of damaging the SD card with an uncontrolled shutdown.
