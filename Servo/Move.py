import time
from adafruit_servokit import ServoKit
kit = ServoKit(channels=16)
// go avanti
kit.continuous_servo[1].throttle = 1
time.sleep(1)
// go indietro
kit.continuous_servo[1].throttle = -1
time.sleep(1)
// mezza velocità
kit.continuous_servo[1].throttle = 0.5
time.sleep(1)
//stop
kit.continuous_servo[1].throttle = 0
time.sleep(1)
