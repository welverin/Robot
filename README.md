# Robot
R2 droid piloted by a PS4 controller

### Hardware :
Droid : Michael Baddeley Design

Head : Raspberry pi zero W

Motor Controller : 16-Channel 12-bit PWM/Servo Driver - I2C interface - PCA9685 

Servo : FS90-R (continuous servo)

Audio Ampli. : I2S 3W Class D Amplifier Breakout - MAX98357A

Speaker : 3 Watt 4 Ohm

Power : 5V 2.4A Powerbank for RasPi & 4*1,5V Battery Holder for Servo Motor

Controller : PS4 compatible / Chinese clone


## Installing

### Installing Prerequisites:

Add 'config.txt' content to your RasPi config file and reboot

Install the package you need to use the hardware :

```bash
sudo apt-get install smbus
sudo apt-get install python3-pip
sudo apt-get install python-smbus
sudo apt-get install i2c-tools
```

Install Python3 lib :

```bash
sudo pip3 install setuptools
sudo pip3 install RPI.GPIO
sudo pip3 install adafruit-blinka
sudo pip3 install adafruit-circuitpython-pca9685
sudo pip3 install adafruit-circuitpython-servokit
sudo pip3 install pyPS4Controller
```

### Configure :

Add comment to line in this file :

'/etc/modprobe.d/raspi-blacklist.conf  \\comment everything'

'/etc/modules                          \\comment snd_bcm2835'

Show code of the pwm board
```bash
sudo i2cdetect -y 1
```

Autoconfigure the Audio Ampli :
```bash
curl -sS https://raw.githubusercontent.com/adafruit/Raspberry-Pi-Installer-Scripts/master/i2samp.sh | bash
```


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
