import RPi.GPIO as GPIO
import time

def detection():
    GPIO.output(GPIO.sender, True)
    time.sleep(0.00001)
    GPIO.output(GPIO.sender, False)
    
    while GPIO.input(GPIO_receiver) == 0:
        start = time.time()
    while GPIO.input(GPIO_receiver) == 1:
        stop = time.time()
    timeTekken = stop-start
    distMeasured = (timetekken*34000)/2
    
    return distMeasured

def measure():
    iter1 = detection()
    time.sleep(0.1)
    iter2 = detection()
    time.sleep(0.1)
    iter3 = detection()
    distance = (iter1 + iter2 + iter3)/3
    
    return distance

GPIO.setmode(GPIO.BCM)
GPIO_sender = 23
GPIO_receiver = 24
GPIO.setup(GPIO_sender,GPIO.OUT)
GPIO.setup(GPIO_receiver, GPIO.IN)
GPIO.output(GPIO_sender, False)

try:
    while True:
        distance = measure()
        print "Distance to obstruction : %.1f" % distance
        time.sleep(1)
except KeyboardInterrupt:
    GPIO.cleanup()
