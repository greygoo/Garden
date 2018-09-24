#!/usr/bin/python

from datetime import datetime as dt
import matplotlib
matplotlib.use("TKAgg")

import matplotlib.pyplot as plt
import os
import time
import pandas as pd

sensorlog_file = '/tmp/sensorlog.csv'


def format_date(time_in_secs):
    return dt.fromtimestamp(float(time_in_secs))


def plot_layout():
    temperature_plt.set_title('All Time')
    temperature_plt.set_ylabel('Temperature')
    temperature_plt.set_ylim([-10,40])
    temperature_plt.grid(color='black', linestyle='-.', linewidth=0.5)

    lasttemp_plt.grid(color='black', linestyle='-.', linewidth=0.5)
    lasttemp_plt.margins(y=0.5)
    lasttemp_plt.set_title('Last 30min')

    humidity_plt.set_xlabel('Time')
    humidity_plt.set_ylabel('Humidity')
    humidity_plt.set_ylim([0,100])
    humidity_plt.grid(color='black', linestyle='-.', linewidth=0.5)

    lasthum_plt.grid(color='black', linestyle='-.', linewidth=0.5)
    lasthum_plt.margins(y=0.5)


def readData():
    df = pd.read_csv('/tmp/sensorlog.csv_unixtime', names=['Date', 'TempAir', 'HumAir', 'TempWater', 'pH', 'ECC', 'Undefine'])
    df['Date'] = df['Date'].apply(format_date)
    print df
    return df


def plot_data():
    df.plot(x='Date', y=['TempAir', 'TempWater'], style=['lightblue', 'darkblue'], x_compat=True, ax=temperature_plt)
    df[-30:].plot(x='Date', y=['TempAir', 'TempWater'], style=['lightblue', 'darkblue'], x_compat=True, ax=lasttemp_plt)
    df.plot(x='Date', y='HumAir', style='green', x_compat=True, ax=humidity_plt)
    df[-30:].plot(x='Date', y='HumAir', style='green', x_compat=True, ax=lasthum_plt)
    plot_layout()


def plot_reset():
    lasttemp_plt.cla()
    lasthum_plt.cla()
    plot_setup()



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
