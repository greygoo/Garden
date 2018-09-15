#include <DHT_U.h>
#include <Adafruit_Sensor.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include "define.h"
#include "struct.h"


sensorValues readSensors();

void sensorsInit();

float getTempWater();

float getTempAir(int sensor);

float getHumAir(int sensor);

float getPH();

float getEcc();

void printValuesSerial(sensorValues values);

void printValues(sensorValues values);

void printSensorData();
