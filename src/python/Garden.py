#!/usr/bin/env python3

import threading
import time
import schedule
from GardenControlLib import *


class GardenLoop(threading.Thread):

    def __init__ (self):
        threading.Thread.__init__(self)

        self.sensorlog = '/home/pi/sensorlog.csv'

        spray_duration = 4
        empty_duration = 8

        # define pump ids
        spray_pump = 0
        empty_pump = 1


        schedule.every().minute.do(writeSensorData, self.sensorlog)
        schedule.every().day.at('06:00').do(lightOn)
        schedule.every().day.at('00:00').do(lightOff)
        schedule.every(10).minutes.do(pump_cycle, spray_pump, spray_duration)
        schedule.every(100).minutes.do(pump_cycle, empty_pump, empty_duration)

    def run(self):
        while True:
            schedule.run_pending()
            time.sleep(1)


# main Garden loop to control arduino
class GtkMain(threading.Thread):

    def __init__ (self):
        threading.Thread.__init__(self)

    def run(self):
        while True:
            win = GardenControlWindow()
            win.connect("destroy", Gtk.main_quit)
            win.show_all()
            Gtk.main()


thread = GtkMain()
thread.start()
thread = GardenLoop()
thread.start()
