#!/usr/bin/env python3

import threading
import serial
import time
import sys
import schedule
from GardenControlLib import *


baudrate = 9600

ser = serial.Serial()
ser.port = sys.argv[1]
ser.baudrate = baudrate
ser.open()

time.sleep(2)
print("Serial connection established")

# empty serial buffer from arduino startup
while ser.in_waiting > 0:
    print(ser.readline().decode())


class GardenLoop(threading.Thread):

    def __init__ (self, ser):
        threading.Thread.__init__(self)

        self.ser = ser
        self.sensorlog = '/home/pi/sensorlog.csv'

        spray_duration = 4
        empty_duration = 8

        # define pump ids
        spray_pump = 0
        empty_pump = 1


        schedule.every().minute.do(writeSensorData, self.ser, self.sensorlog)
        schedule.every().day.at('06:00').do(lightOn, ser)
        schedule.every().day.at('00:00').do(lightOff, ser)
        schedule.every(10).minutes.do(pump_cycle, ser, spray_pump, spray_duration)
        schedule.every(100).minutes.do(pump_cycle, ser, empty_pump, empty_duration)

    def run(self):
        while True:
            schedule.run_pending()
            print("tick")
            time.sleep(1)


# main Garden loop to control arduino
class GtkMain(threading.Thread):

    def __init__ (self, ser):
        threading.Thread.__init__(self)
        self.ser = ser

    def run(self):
        while True:
            win = MyWindow(ser)
            win.connect("destroy", Gtk.main_quit)
            win.show_all()
            Gtk.main()


thread = GtkMain(ser)
thread.start()
thread = GardenLoop(ser)
thread.start()
