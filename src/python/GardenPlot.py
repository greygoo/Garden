#!/usr/bin/python

import matplotlib
matplotlib.use('TkAgg')

import matplotlib.pyplot as plt

sensorlog = open('/tmp/sensorlog.csv','r')

temperature_air = []
temperature_water = []
humidity = []

for line in sensorlog:
    print line
    line_array = line.split(',')
    print line_array
    temperature_air.append(line_array[0])
    temperature_water.append(line_array[2])
    humidity.append(line_array[1])

print temperature_air
print temperature_water
print humidity

plt.subplot(2, 1, 1)
plt.plot(temperature_air)
plt.plot(temperature_water)
plt.title('Garden')
plt.ylabel('Temperature')

plt.subplot(2, 1, 2)
plt.plot(humidity)
plt.xlabel('time')
plt.ylabel('Humidity')

plt.show()
