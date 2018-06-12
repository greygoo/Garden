#include "sensors.h"
#include "lcd.h"

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
  Serial.print  ("Unique ID:    "); Serial.println(sensor.sensor_id);

  dht1.temperature().getSensor(&sensor);
  Serial.print  ("Unique ID:    "); Serial.println(sensor.sensor_id); 
}


float getTempWater() {
  float temp = -1;

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
      dht2.temperature().getEvent(&event);
      break;
    default :
      Serial.print("Sensor does not exist: ");
      Serial.println(sensor);
  }
  
  if (isnan(event.temperature)) {
    Serial.println("Error reading temperature!");
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
  Serial.println();
  Serial.println("-----------");
  Serial.print("tempAir1:  ");
  Serial.println(values.tempAir1);
  Serial.print("tempAir2:  ");
  Serial.println(values.tempAir2);
  Serial.print("humAir:    ");
  Serial.println(values.humAir1);
  Serial.print("humair2:   ");
  Serial.println(values.humAir2);
  Serial.print("tempWater: ");
  Serial.println(values.tempWater);
  Serial.print("pH:        ");
  Serial.println(values.pH);
  Serial.print("ecc:       ");
  Serial.println(values.ecc);
  Serial.println("-----------");
  Serial.println();  
}


void printValues(sensorValues values) {
  printValuesLCD(values);
  printValuesSerial(values);
}
