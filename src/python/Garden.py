#!/usr/bin/python

import serial
import time

ser = serial.Serial('/dev/ttyUSB1', 9600)
print 'Serial connection initialised'

while 1:
    ser.write(b'cD\r\n')
    time.sleep( 1 )
    print ser.readline();
