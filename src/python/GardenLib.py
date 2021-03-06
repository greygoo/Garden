import time
from datetime import datetime

def getData(ser):
    ser.write(b'cD\r\n')
    while True:
        serial_line = ser.readline().decode().rstrip('\r\n').split(",")
        if serial_line[0] == 'data':
            serial_line[0] = str(int(time.time()))
            return serial_line


def lightOn(ser):
    ser.write(b'cL\r\n')
    time.sleep(1)
    while ser.in_waiting > 0:
        print(ser.readline().decode().rstrip('\r\n'))


def lightOff(ser):
    ser.write(b'cl\r\n')
    time.sleep(1)
    while ser.in_waiting > 0:
        print(ser.readline().decode().rstrip('\r\n'))


def pumpOn(ser, pump):
    ser.write(b'cP%d\r\n' % pump)
    time.sleep(1)
    while ser.in_waiting > 0:
        print(ser.readline().decode().rstrip('\r\n'))


def pumpOff(ser, pump):
    ser.write(b'cp%d\r\n' % pump)
    time.sleep(1)
    while ser.in_waiting > 0:
        print(ser.readline().decode().rstrip('\r\n'))


def fanOn(ser, fan):
    ser.write(b'cF%d\r\n' % fan)
    time.sleep(1)
    while ser.in_waiting > 0:
        print(ser.readline().decode().rstrip('\r\n'))


def fanOff(ser, fan):
    ser.write(b'cf%d\r\n' % fan)
    time.sleep(1)
    while ser.in_waiting > 0:
        print(ser.readline().decode().rstrip('\r\n'))


def fanSpeed(ser, speed):
    ser.write(b'cs%d\r\n' % speed)
    time.sleep(1)
    while ser.in_waiting > 0:
        print(ser.readline().decode().rstrip('\r\n'))


def writeSensorData(ser, sensorlog):
    sensor_data = getData(ser)
    # sensor_data: [time, Temp_Air, Humidity, Temp_Water, PH, TDS]
    print('debug: sensor_data: ')
    print(sensor_data)
    print('Time             : %s' % datetime.utcfromtimestamp(int(sensor_data[0])).strftime('%Y-%m-%d %H:%M:%S'))
    print('Temperature Air  : %f' % float(sensor_data[1]))
    print('Temperature Water: %f' % float(sensor_data[3]))
    print('Humidity         : %f' % float(sensor_data[2]))
    print('TDS(ppm)         : %f' % float(sensor_data[5]))
    # check if water temperature read failed
    if float(sensor_data[3]) < 0:
        sensor_data[3] = '0'
    log = open(sensorlog, 'a')
    for data in sensor_data:
        log.write(data)
        log.write(',')
    log.write("\n")
    log.close


def testFan():
    fanOn(ser, 0)
    time.sleep(3)
    for speed in range(0, 9):
    	fanSpeed(ser, speed)
    	time.sleep(3)
    fanOff(ser, 0)
    time.sleep(3)


def testLight(ser):
    lightOn(ser)
    time.sleep(3)
    lightOff(ser)
    time.sleep(3)


def testPumps(ser):
    for pump in range(0, 1):
    	pumpOn(ser, pump)
    	time.sleep(2)
    	pumpOff(ser, pump)
    	time.sleep(2)


#def run_threaded(job_func):
#    job_thread = threading.Thread(target=job_func)
#    job_thread.start()


def pump_cycle(ser, pump, duration):
    pumpOn(ser, pump)
    time.sleep(duration)
    pumpOff(ser, pump)
