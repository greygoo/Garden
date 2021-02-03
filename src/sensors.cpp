#include "sensors.h"


//DHT_Unified dht[DHT_NUM] = {DHT_Unified(DHT0_PIN, DHT_TYPE)};
//OneWire oneWire0(TMP0_PIN);
//OneWire oneWire1(TMP1_PIN);
//DallasTemperature sensors0(&oneWire0);
//DallasTemperature sensors1(&oneWire1);

//GravityTDS gravityTds;

//float tdsValue = 0,temperature = 25;


sensorValues readSensors() {
  sensorValues current;
  //current.tempWater = getTempWater();
  //current.tempAir1  = getTempAir(1);
  //current.tempAir2  = getTempAir(2);
  //current.humAir1   = getHumAir(1);
  //current.humAir2  = getHumAir(2);
  current.pH        = getPH();
  //current.tds 	    = getTDS();
  return current;
}


//void sensorsInit(){
  //init oneWire for Water Temperature
  //sensors0.begin();
  //sensors1.begin();

  //init dht

  //init ECC
  //pinMode(ECC_PIN,INPUT);
  //gravityTds.setPin(ECC_PIN);
  //gravityTds.setAref(ECC_VREF);  //reference voltage on ADC, default 5.0V on Arduino UNO
  //gravityTds.setAdcRange(1024);  //1024 for 10bit ADC;4096 for 12bit ADC
  //gravityTds.begin();

   //init dht
  //dht[0].begin();
  //dht[1].begin();

  //Water temperature sensor
  //sensor_t sensor;

  //Humidity sensors
  //dht[0].temperature().getSensor(&sensor);
  //D_PRINTLN((String)"D: Unique ID: "+(String)sensor.sensor_id);

  //dht[1].temperature().getSensor(&sensor);
  //D_PRINTLN((String)"D: Unique ID: "+(String)sensor.sensor_id);
//}


//float getTDS() {
    // disabled as split into temp.cpp
    //temperature = getTempWater();
    //gravityTds.setTemperature(temperature);  // execute temperature compensation
    //gravityTds.update();  //sample and calculate
    //tdsValue = gravityTds.getTdsValue();  // then get the value
    //return tdsValue;
//}

// TODO - manage multiple sensors
/*float getTempWater() {
  float temp = 25;

  sensors0.requestTemperatures();
  temp = sensors0.getTempCByIndex(0);

  return temp;
}*/


/*float getTempAir(int sensor) {
  float temp = -1;

  if(sensor >= DHT_NUM) {
    D_PRINTLN((String)"D: Sensor does not exist: "+(String)sensor);
    return temp;
  }

  sensors_event_t event;

  dht[sensor].temperature().getEvent(&event);

  if (isnan(event.temperature)) {
    D_PRINTLN((String)"D: Error reading temperature!");
  }
  else {
    temp = event.temperature;
  }

  return temp;
}*/


/*float getHumAir(int sensor) {
  float hum = -1;

  if(sensor >= DHT_NUM) {
    D_PRINTLN((String)"D: Sensor does not exist: "+(String)sensor);
    return hum;
  }

  sensors_event_t event;

  dht[sensor].humidity().getEvent(&event);

  if (isnan(event.relative_humidity)) {
    D_PRINTLN((String)"D: Error reading humidity!");
  }
  else {
    hum = event.relative_humidity;
  }

  return hum;
}*/


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
