#!/usr/bin/python

import serial
import time

ser = serial.Serial('/dev/ttyUSB0', 9600)
print 'Serial connection initialised'

while 1:
    ser.write(b'cd\r\n')
    time.sleep( 1 )
    print ser.readline();
