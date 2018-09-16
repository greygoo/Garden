#!/usr/bin/python

import serial
import time

ser = serial.Serial('/dev/ttyUSB1', 9600)
print 'Serial connection initialised'


def getData():
    ser.write(b'cD\r\n')
    time.sleep(0.2)
    return ser.readline().split(",");

def lightOn():
    ser.write(b'cL\r\n')
    time.sleep(0.2)

def lightOff():
    ser.write(b'cl\r\n')
    time.sleep(0.2)

def pumpOn(pump):
    ser.write(b'cP%d' % pump)
    time.sleep(0.2)

def pumpOff(pump):
    ser.write(b'cp%d' % pump)
    time.sleep(0.2)

def fanOn(fan):
    ser.write(b'cF%d' % fan)
    time.sleep(0.2)

def fanOff(fan):
    ser.write(b'cf%d' % fan)
    time.sleep(0.2)

def fanSpeed(speed):
    ser.write(b'cs%d' % speed)
    time.sleep(0.2)
