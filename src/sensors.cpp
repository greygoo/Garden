#include "sensors.h"

DHT_Unified dht1(DHT_PIN1, DHT_TYPE);
DHT_Unified dht2(DHT_PIN2, DHT_TYPE);

OneWire oneWire(DS18B20PIN);
DallasTemperature sensors(&oneWire);


sensorValues readSensors() {
  sensorValues current;
  current.tempWater = getTempWater();
  current.tempAir1  = getTempAir(1);
  //current.tempAir2  = getTempAir(2);
  current.humAir1  = getHumAir(1);
  //current.humAir2  = getHumAir(2);
  current.pH        = getPH();
  current.ecc       = getEcc();
  return current;
}


void sensorsInit(){
  sensors.begin();
  dht1.begin();
  dht2.begin();

  //Water temperature sensor
  sensor_t sensor;

  dht1.temperature().getSensor(&sensor);
  Serial.print  ("debug,Unique ID:    "); Serial.println(sensor.sensor_id);

  dht1.temperature().getSensor(&sensor);
  Serial.print  ("deubg,Unique ID:    "); Serial.println(sensor.sensor_id); 
}


float getTempWater() {
  float temp = -1;

  for (int retry = 5; retry > 5; retry--) {
    sensors.requestTemperatures();
    temp = sensors.getTempCByIndex(0);
    if (temp == -127) {
      Serial.println("Error reading water temperature");
    }
    else {
      break;
    }
  }
  
  return temp;
}


float getTempAir(int sensor) {
  float temp = -1;
  
  sensors_event_t event;
  
  switch(sensor) {
    case 1 :
      dht1.temperature().getEvent(&event);
      break;
    case 2 :
      dht2.temperature().getEvent(&event);
      break;
    default :
      Serial.print("Sensor does not exist: ");
      Serial.println(sensor);
  }
  
  if (isnan(event.temperature)) {
    Serial.println("Error reading air temperature!");
  }
  else {
    temp = event.temperature;
  }
  
  return temp;
}


float getHumAir(int sensor) {
  float hum = -1;

  sensors_event_t event;
  
  switch(sensor) {
    case 1 :
      dht1.humidity().getEvent(&event);
      break;
    case 2 :
      dht2.humidity().getEvent(&event);
      break;
    default :
      Serial.print("Sensor does not exist: ");
      Serial.println(sensor);
  }
  
  if (isnan(event.relative_humidity)) {
    Serial.println("Error reading humidity!");
  }
  else {
    hum = event.relative_humidity;
  }
  
  return hum;
}


float getPH() {
  float ph = 0;
  return ph;
}


float getEcc() {
  float ecc = 0;
  return ecc;
}


void printValuesSerial(sensorValues values) {
  Serial.println("output,-----------");
  Serial.print("output,tempAir1:  ");
  Serial.println(values.tempAir1);
  Serial.print("output,tempAir2:  ");
  Serial.println(values.tempAir2);
  Serial.print("output,humAir:    ");
  Serial.println(values.humAir1);
  Serial.print("output,humair2:   ");
  Serial.println(values.humAir2);
  Serial.print("output,tempWater: ");
  Serial.println(values.tempWater);
  Serial.print("output,pH:        ");
  Serial.println(values.pH);
  Serial.print("output,ecc:       ");
  Serial.println(values.ecc);
  Serial.println("output,-----------");
}


void printSimpleSerial(sensorValues values) {
  Serial.print("data,");
  Serial.print(values.tempAir1);
  Serial.print(",");
  Serial.print(values.humAir1);
  Serial.print(",");
  Serial.print(values.tempWater);
  Serial.print(",");
  Serial.print(values.pH);
  Serial.print(",");
  Serial.println(values.ecc);
}


void printSensorData() {
  sensorValues currentValues = { 0,0,0,0,0,0,0 };
  currentValues = readSensors();
  printValuesSerial(currentValues);
}


void printSimpleData() {
  sensorValues currentValues = { 0,0,0,0,0,0,0 };
  currentValues = readSensors();
  printSimpleSerial(currentValues);
}
