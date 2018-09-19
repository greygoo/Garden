#!/usr/bin/python


import matplotlib
matplotlib.use("GTKAgg")

import matplotlib.pyplot as plt
import os
import time

sensorlog_file = '/home/pi/sensorlog.csv'


plt.ion()

f, ((temperature_plt, lasttemp_plt), (humidity_plt, lasthum_plt)) = plt.subplots(2, 2, figsize=(20, 10))

def plot_setup():
    temperature_plt.set_title('All Time')
    temperature_plt.set_ylabel('Temperature')
    temperature_plt.set_ylim([-10,40])
    temperature_plt.grid(color='grey', linestyle='-.', linewidth=0.5)

    lasttemp_plt.grid(color='grey', linestyle='-.', linewidth=0.5)
    lasttemp_plt.margins(y=0.5)
    lasttemp_plt.set_title('Last 30min')

    humidity_plt.set_xlabel('Time')
    humidity_plt.set_ylabel('Humidity')
    humidity_plt.set_ylim([0,100])
    humidity_plt.grid(color='grey', linestyle='-.', linewidth=0.5)

    lasthum_plt.grid(color='grey', linestyle='-.', linewidth=0.5)
    lasthum_plt.margins(y=0.5)


def getData():
    temperature_air = []
    temperature_water = []
    humidity = []
    sensorlog = open(sensorlog_file,'r')
    for line in sensorlog:
        line_array = line.split(',')
        temperature_air.append(line_array[0])
        temperature_water.append(line_array[2])
        humidity.append(line_array[1])
    sensorlog.close
    return (temperature_air, temperature_water, humidity)


def plot_all(temperature_air, temperature_water, humidity):
    temperature_plt.plot(temperature_air, color = 'lightblue')
    temperature_plt.plot(temperature_water, color = 'darkblue')
    humidity_plt.plot(humidity, color = 'blue', label='Humidity')

def plot_last(temperature_air, temperature_water, humidity):
    lasttemp_plt.plot(temperature_air[-30:], color = 'lightblue')
    lasttemp_plt.plot(temperature_water[-30:], color = 'darkblue')
    lasthum_plt.plot(humidity[-30:], color = 'blue', label='Humidity')

def plot_clear():
    lasttemp_plt.cla()
    lasthum_plt.cla()
    plot_setup()

(temperature_air, temperature_water, humidity) = getData()
plot_setup()
plot_all(temperature_air, temperature_water, humidity)
plot_last(temperature_air, temperature_water, humidity)
plt.pause(0.5)

last_modified = os.stat(sensorlog_file).st_mtime

while True:
    if os.stat(sensorlog_file).st_mtime != last_modified:
        (temperature_air, temperature_water, humidity) = getData()
	plot_clear()
        plot_all(temperature_air, temperature_water, humidity)
        plot_last(temperature_air, temperature_water, humidity)
        last_modified = os.stat(sensorlog_file).st_mtime
	plt.pause(0.5)
    time.sleep(1)
