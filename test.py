# pin out pwm bcm12 - board 32 pwm direito
# pin out d bcm 16 - board 36 direito
# pin out d bcm 20 - board 38 direito
# pin out pwm bcm 13 - board 33 esquerdo
# pin out d bcm 19 - board 35 esuqerdo
# pin out d  bcm 26 - board 37 esuqerdo 
import RPi.GPIO as gpio
import time
 
gpio.setwarnings(False)
 
#Configuring GPIO
gpio.setmode(gpio.BOARD)
gpio.setup(32,gpio.OUT)
gpio.setup(36,gpio.OUT)
gpio.setup(38,gpio.OUT)
 
#Configure the pwm objects and initialize its value
p = gpio.PWM(32 , 50)
gpio.output(36,gpio.HIGH)
gpio.output(38,gpio.LOW)
p.start(0)
try:
    while 1:
        for dc in range(0,100,5):
            p.ChangeDutyCycle(dc)
            time.sleep(0.1)
        for dc in range(100,0,-5):
            p.ChangeDutyCycle(dc)
            time.sleep(0.1)
except KeyboardInterrupt:
    pass
p.stop
gpio.cleanup()

        