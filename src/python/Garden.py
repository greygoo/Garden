#!/usr/bin/python

import serial

ser = serial.Serial('/dev/ttyUSB0', 9600)
print 'Serial connection initialised'

while true:
    ser.write(b'cd\r\n')
    time.sleep( 1 )
    print ser.readline();
