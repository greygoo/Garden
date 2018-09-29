#!/usr/bin/python

import serial
import time
import sys
import schedule
import threading
import time
from GardenLib import *

baudrate = 9600
sensorlog = '/home/pi/sensorlog.csv'
pumpintervall = 10


ser = serial.Serial()
ser.port = sys.argv[1]
ser.baudrate = baudrate
ser.open()
time.sleep(10)
print 'Serial connection initialised'


# empty serial buffer from arduino startup
while ser.in_waiting > 0:
    print ser.readline()

schedule.every().day.at('06:00').do(lightOn, ser)
schedule.every().day.at('00:00').do(lightOff, ser)
schedule.every().minute.do(run_threaded, lightOn(ser))

while True:
    schedule.run_pending()
    writeSensorData(ser, sensorlog)
    time.sleep(60)
