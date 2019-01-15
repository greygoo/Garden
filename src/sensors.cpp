#include "sensors.h"

DHT_Unified dht1(DHT_PIN1, DHT_TYPE);
//DHT_Unified dht2(DHT_PIN2, DHT_TYPE);

OneWire oneWire(DS18B20PIN);
DallasTemperature sensors(&oneWire);

GravityTDS gravityTds;

float tdsValue = 0,temperature = 25;


sensorValues readSensors() {
  sensorValues current;
  current.tempWater = getTempWater();
  current.tempAir1  = getTempAir(1);
  //current.tempAir2  = getTempAir(2);
  current.humAir1   = getHumAir(1);
  //current.humAir2  = getHumAir(2);
  current.pH        = getPH();
  current.tds 	    = getTDS();
  return current;
}


void sensorsInit(){
  //init oneWire for Water Temperature	
  sensors.begin();

  //init dht
  dht1.begin();
  //dht2.begin();

  //init TDS 
  pinMode(TDS_PIN,INPUT);
  gravityTds.setPin(TDS_PIN);
  gravityTds.setAref(VREF);  //reference voltage on ADC, default 5.0V on Arduino UNO
  gravityTds.setAdcRange(1024);  //1024 for 10bit ADC;4096 for 12bit ADC
  gravityTds.begin();

  //Water temperature sensor
  sensor_t sensor;

  dht1.temperature().getSensor(&sensor);
  Serial.print  ("debug,Unique ID:    "); Serial.println(sensor.sensor_id);

  dht1.temperature().getSensor(&sensor);
  Serial.print  ("deubg,Unique ID:    "); Serial.println(sensor.sensor_id); 
}


float getTDS() {
    temperature = getTempWater();
    gravityTds.setTemperature(temperature);  // execute temperature compensation
    gravityTds.update();  //sample and calculate 
    tdsValue = gravityTds.getTdsValue();  // then get the value
    return tdsValue;
}


float getTempWater() {
  float temp = 25;

  sensors.requestTemperatures();
  temp = sensors.getTempCByIndex(0);
  
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
      //dht2.temperature().getEvent(&event);
      break;
    default :
      Serial.print("debug,Sensor does not exist: ");
      Serial.println(sensor);
  }
  
  if (isnan(event.temperature)) {
    Serial.println("debug,Error reading temperature!");
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
      //dht2.humidity().getEvent(&event);
      break;
    default :
      Serial.print("debug,Sensor does not exist: ");
      Serial.println(sensor);
  }
  
  if (isnan(event.relative_humidity)) {
    Serial.println("debug,Error reading humidity!");
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
  Serial.print("output,tds:       ");
  Serial.println(values.tds);
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
  Serial.println(values.tds);
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
