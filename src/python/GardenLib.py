import time
import serial
import sys


baudrate = 9600
port = sys.argv[1]

def openSerial(port, baudrate):

    ser = serial.Serial()
    ser.port = port
    ser.baudrate = baudrate
    ser.open()

    time.sleep(2)
    print("Serial connection established")

    # empty serial buffer from arduino startup
    while ser.in_waiting > 0:
        print(ser.readline().decode())
    return ser


def getData():
    ser = openSerial(port, baudrate)
    ser.write(b'cD\r\n')
    time.sleep(0.5)
    while ser.in_waiting > 0:
        serial_line = ser.readline().decode().rstrip('\r\n').split(",");
        print(serial_line)
        if serial_line[0] == 'data':
            #serial_line.pop(0)
            serial_line[0] = str(int(time.time()))
            ser.close
            return serial_line


def lightOn():
    ser = openSerial(port, baudrate)
    ser.write(b'cL\r\n')
    time.sleep(1)
    while ser.in_waiting > 0:
        print(ser.readline().decode().rstrip('\r\n'))
    ser.close


def lightOff():
    ser = openSerial(port, baudrate)
    ser.write(b'cl\r\n')
    time.sleep(1)
    while ser.in_waiting > 0:
        print(ser.readline().decode().rstrip('\r\n'))
    ser.close


def pumpOn(pump):
    ser = openSerial(port, baudrate)
    ser.write(b'cP%d\r\n' % pump)
    time.sleep(1)
    while ser.in_waiting > 0:
        print(ser.readline().decode().rstrip('\r\n'))
    ser.close


def pumpOff(pump):
    ser = openSerial(port, baudrate)
    ser.write(b'cp%d\r\n' % pump)
    time.sleep(1)
    while ser.in_waiting > 0:
        print(ser.readline().decode().rstrip('\r\n'))
    ser.close


def fanOn(fan):
    ser = openSerial(port, baudrate)
    ser.write(b'cF%d\r\n' % fan)
    time.sleep(1)
    while ser.in_waiting > 0:
        print(ser.readline().decode().rstrip('\r\n'))
    ser.close


def fanOff(fan):
    ser = openSerial(port, baudrate)
    ser.write(b'cf%d\r\n' % fan)
    time.sleep(1)
    while ser.in_waiting > 0:
        print(ser.readline().decode().rstrip('\r\n'))
    ser.close


def fanSpeed(ser, speed):
    ser = openSerial(port, baudrate)
    ser.write(b'cs%d\r\n' % speed)
    time.sleep(1)
    while ser.in_waiting > 0:
        print(ser.readline().decode().rstrip('\r\n'))
    ser.close


def writeSensorData(sensorlog):
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
    ser = openSerial(port, baudrate)
    fanOn(ser, 0)
    time.sleep(3)
    for speed in range(0, 9):
    	fanSpeed(ser, speed)
    	time.sleep(3)
    fanOff(ser, 0)
    time.sleep(3)
    ser.close


def testLight():
    ser = openSerial(port, baudrate)
    lightOn(ser)
    time.sleep(3)
    lightOff(ser)
    time.sleep(3)
    ser.close


def testPumps():
    ser = openSerial(port, baudrate)
    for pump in range(0, 1):
    	pumpOn(ser, pump)
    	time.sleep(2)
    	pumpOff(ser, pump)
    	time.sleep(2)
    ser.close


def pump_cycle(pump, duration):
    pumpOn(pump)
    time.sleep(duration)
    pumpOff(pump)
