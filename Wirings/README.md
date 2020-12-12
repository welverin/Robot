# Wirings


## Audio I2S
```
Amp       Raspberry Pi
Vin       5V                (Pin 2)
GND       GND               (Pin 20)
DIN       GPIO #21 PCM_DOUT (Pin 40)
BCLK      GPIO #18 PCM_CLK  (Pin 12)
LRCLK     GPIO #19 PCM_FS   (Pin 35)
```
## PWM I2C
```
MotorBoard  Raspberry Pi
VCC         3V3             (Pin 1)
GND         GND             (Pin 9)
SCL         GPIO #3 SCL     (Pin 5)
SDA         GPIO #2 SDA     (Pin 3)
```
## Servo
```
MotorBoard  Servo
PWM         Orange
V+          Red
GND         Black
```

![Wirings](R2D2_bb.jpg)
