#!/usr/bin/python

from datetime import datetime as dt
import matplotlib
matplotlib.use("GTKAgg")

import matplotlib.pyplot as plt
import os
import time
import pandas as pd

sensorlog_file = '/tmp/sensorlog.csv'


def plot_layout():
    temperature_plt.set_title('All Time')
    temperature_plt.set_ylabel('Temperature')
    temperature_plt.set_ylim([-10,40])
    temperature_plt.grid(color='black', linestyle='-.', linewidth=0.5)
    temperature_plt.xaxis.set_ticklabels([])
    temperature_plt.xaxis.label.set_visible(False)

    lasttemp_plt.grid(color='black', linestyle='-.', linewidth=0.5)
    lasttemp_plt.margins(y=0.5)
    lasttemp_plt.set_title('Last 30min')
    lasttemp_plt.xaxis.set_ticklabels([])
    lasttemp_plt.xaxis.label.set_visible(False)

    humidity_plt.set_ylabel('Humidity')
    humidity_plt.set_ylim([0,100])
    humidity_plt.grid(color='black', linestyle='-.', linewidth=0.5)

    lasthum_plt.grid(color='black', linestyle='-.', linewidth=0.5)
    lasthum_plt.margins(y=0.5)


def readData():
    df = pd.read_csv(sensorlog_file, delimiter=',', index_col='DateTime', names=['DateTime', 'TempAir', 'HumAir', 'TempWater', 'pH', 'ECC', 'Undefined'], header=None)
    df.index = pd.to_datetime(df.index, unit='s')
    return df


def plot_data():
    # plot all available data
    df.last('3M').plot(y=['TempAir', 'TempWater'], style=['lightblue', 'darkblue'], ax=temperature_plt)
    df.last('3M').plot(y='HumAir', style='green', ax=humidity_plt)

    # plot last 30 minutes
    df.last('1800s').plot(y=['TempAir', 'TempWater'], style=['lightblue', 'darkblue'], ax=lasttemp_plt)
    df.last('1800s').plot(y='HumAir', style='green', ax=lasthum_plt)
    plot_layout()



def plot_reset():
    lasttemp_plt.cla()
    lasthum_plt.cla()
    temperature_plt.cla()
    humidity_plt.cla()


# turn on interactive mode
plt.ion()

# create named subplots
f, ((temperature_plt, lasttemp_plt), (humidity_plt, lasthum_plt)) = plt.subplots(2, 2, figsize=(20, 10))

# get timestamp of sensorlog
last_modified = os.stat(sensorlog_file).st_mtime

# draw initial plot
df = readData()
plot_data()
plt.pause(0.5)

# redraw plot whenever sensorlog gets modified
while True:
    if os.stat(sensorlog_file).st_mtime != last_modified:
        df = readData()
	plot_reset()
        plot_data()
        last_modified = os.stat(sensorlog_file).st_mtime
	plt.pause(0.5)
    time.sleep(1)
