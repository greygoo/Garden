#!/usr/bin/python

import serial
import time
import sys
import schedule
import threading

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


def getData():
    ser.write(b'cD\r\n')
    time.sleep(0.5)
    while ser.in_waiting > 0:
        serial_line = ser.readline().rstrip('\r\n').split(",");
        print serial_line
        if serial_line[0] == 'data':
            serial_line.pop(0)
            return serial_line
        

def lightOn():
    ser.write(b'cL\r\n')
    time.sleep(1)
    while ser.in_waiting > 0:
        print ser.readline().rstrip('\r\n')


def lightOff():
    ser.write(b'cl\r\n')
    time.sleep(1)
    while ser.in_waiting > 0:
        print ser.readline().rstrip('\r\n')


def pumpOn(pump):
    ser.write(b'cP%d\r\n' % pump)
    time.sleep(1)
    while ser.in_waiting > 0:
        print ser.readline().rstrip('\r\n')


def pumpOff(pump):
    ser.write(b'cp%d\r\n' % pump)
    time.sleep(1)
    while ser.in_waiting > 0:
        print ser.readline().rstrip('\r\n')


def fanOn(fan):
    ser.write(b'cF%d\r\n' % fan)
    time.sleep(1)
    while ser.in_waiting > 0:
        print ser.readline().rstrip('\r\n')


def fanOff(fan):
    ser.write(b'cf%d\r\n' % fan)
    time.sleep(1)
    while ser.in_waiting > 0:
        print ser.readline().rstrip('\r\n')


def fanSpeed(speed):
    ser.write(b'cs%d\r\n' % speed)
    time.sleep(1)
    while ser.in_waiting > 0:
        print ser.readline().rstrip('\r\n')


def writeSensorData():
    sensor_data = getData()
    print('Temperature Air  : %f' % float(sensor_data[0]))
    print('Temperature Water: %f' % float(sensor_data[2]))
    print('Humidity         : %f' % float(sensor_data[1]))
    log = open(sensorlog, 'a')
    for data in sensor_data:
        log.write(data)
        log.write(',')
    log.write("\n")
    log.close


def testFan():
    fanOn(0)
    time.sleep(3)

    fanSpeed(1)
    time.sleep(3)
    fanSpeed(2)
    time.sleep(3)
    fanSpeed(3)
    time.sleep(3)
    fanSpeed(4)
    time.sleep(3)
    fanSpeed(5)
    time.sleep(3)
    fanSpeed(6)
    time.sleep(3)
    fanSpeed(7)
    time.sleep(3)
    fanSpeed(8)
    time.sleep(3)
    fanSpeed(9)
    time.sleep(3)

    fanOff()
    time.sleep(3)


def testLight():
    lightOn()
    time.sleep(3)
    lightOff()
    time.sleep(3)


def testPump():
    pumpOn(0)
    time.sleep(2)
    pumpOff(0)
    time.sleep(2)

    pumpOn(1)
    time.sleep(2)
    pumpOff(1)
    time.sleep(2)


def run_threaded(job_func):
    job_thread = threading.Thread(target=job_func)
    job_thread.start()


def pump_cycle():
    pumpOn(0)
    time.sleep(pumpintervall)
    pumpOff(0)
    time.sleep(20)
    pumpOn(1)
    time.sleep(10)
    pumpOff(1)


schedule.every().day.at('06:00').do(lightOn)
schedule.every().day.at('00:00').do(lightOff)
#schedule.every().minute.do(run_threaded, pump_cycle)


while True:
    schedule.run_pending()
    writeSensorData()
    time.sleep(60)
