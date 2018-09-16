#!/usr/bin/python

import serial
import time
import sys

baudrate = 9600

ser = serial.Serial()
ser.port = sys.argv[1]
ser.baudrate = baudrate
ser.open()
time.sleep(1)
print 'Serial connection initialised'

# empty serial buffer from arduino startup
while ser.in_waiting > 0:
    print ser.readline()


def getData():
    ser.write(b'cD\r\n')
    time.sleep(0.2)
    while ser.in_waiting > 0:
        serial_line = ser.readline().split(",");
        if serial_line[0] == 'data':
            return serial_line
        

def lightOn():
    ser.write(b'cL\r\n')
    time.sleep(0.2)
    while ser.in_waiting > 0:
        print ser.readline()


def lightOff():
    ser.write(b'cl\r\n')
    time.sleep(0.2)
    while ser.in_waiting > 0:
        print ser.readline()


def pumpOn(pump):
    ser.write(b'cP%d' % pump)
    time.sleep(0.2)
    while ser.in_waiting > 0:
        print ser.readline()


def pumpOff(pump):
    ser.write(b'cp%d' % pump)
    time.sleep(0.2)
    while ser.in_waiting > 0:
        print ser.readline()


def fanOn(fan):
    ser.write(b'cF%d' % fan)
    time.sleep(0.2)
    while ser.in_waiting > 0:
        print ser.readline()


def fanOff(fan):
    ser.write(b'cf%d' % fan)
    time.sleep(0.2)
    while ser.in_waiting > 0:
        print ser.readline()


def fanSpeed(speed):
    ser.write(b'cs%d' % speed)
    time.sleep(0.2)
    while ser.in_waiting > 0:
        print ser.readline()


print getData();
