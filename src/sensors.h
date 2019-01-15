#include <DHT_U.h>
#include <Adafruit_Sensor.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include "define.h"
#include "struct.h"
#include <GravityTDS.h>


sensorValues readSensors();

void sensorsInit();

float getPPM();

float getTempWater();

float getTempAir(int sensor);

float getHumAir(int sensor);

float getPH();

float getEcc();

void printValuesSerial(sensorValues values);

void printSimpleSerial(sensorValues values);

void printSensorData();

void printSimpleData();
