# 3D Printed Robot
R2 droid driven by a PS4 controller

### Hardware :
Droid : Michael Baddeley Design

Head : Raspberry pi zero W

Motor Controller : 16-Channel 12-bit PWM/Servo Driver - I2C interface - PCA9685 

Servo : FS90-R (continuous servo)

Audio Ampli. : I2S 3W Class D Amplifier Breakout - MAX98357A

Speaker : 3 Watt 4 Ohm

Power : 4x1.5V AA Battery

Controller : PS4 compatible (Chinese clone)


### Wirings

In the Wirings folder there are all the connections among boards, the scheme and the original fritzing file


## Installing

### Prerequisites:

Add 'config.txt' content to your RasPi config file and reboot

Install the package you need to use the hardware :

```bash
sudo apt install python3-pip
sudo apt install i2c-tools
sudo apt install python3-smbus
```

Install Python3 lib :

```bash
sudo pip3 install --upgrade setuptools
sudo pip3 install RPI.GPIO
sudo pip3 install adafruit-blinka
sudo pip3 install adafruit-circuitpython-pca9685
sudo pip3 install adafruit-circuitpython-servokit
sudo pip3 install pyPS4Controller
```

### Configure :

Add # to item in these files :

```bash
/etc/modprobe.d/raspi-blacklist.conf     \\comment everything

/etc/modules                             \\comment snd_bcm2835
```


Autoconfigure the Audio Ampli :
```bash
curl -sS https://raw.githubusercontent.com/adafruit/Raspberry-Pi-Installer-Scripts/master/i2samp.sh | bash
```

Reboot the system


## Documentation

* Hardware

  https://www.facebook.com/groups/MrBaddeley/

  https://www.adafruit.com/product/815
  
  https://www.adafruit.com/product/3006
 
* Lib Reference

  https://github.com/adafruit/Adafruit_CircuitPython_PCA9685
  
  https://github.com/adafruit/Adafruit_CircuitPython_ServoKit
  
  https://pypi.org/project/pyPS4Controller/

* Tutorial

  https://learn.adafruit.com/adafruit-16-channel-servo-driver-with-raspberry-pi
  
  https://learn.adafruit.com/adafruit-max98357-i2s-class-d-mono-amp
