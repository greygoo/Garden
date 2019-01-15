#include <EEPROM.h>
#include "GravityTDS.h"
#include <OneWire.h>
#include <DallasTemperature.h>

#define TdsSensorPin A1
#define DS18B20Pin 3

OneWire oneWire(DS18B20Pin);
DallasTemperature sensors(&oneWire);

GravityTDS gravityTds;

float temperature = 25,tdsValue = 0, ecValue = 0;

void setup()
{
    Serial.begin(115200);
    sensors.begin();
//    sensor_t sensor;
    gravityTds.setPin(TdsSensorPin);
    gravityTds.setAref(5.0);  //reference voltage on ADC, default 5.0V on Arduino UNO
    gravityTds.setAdcRange(1024);  //1024 for 10bit ADC;4096 for 12bit ADC
    gravityTds.begin();  //initialization
}

void loop()
{
    sensors.requestTemperatures(); 
    //temperature=sensors.getTempCByIndex(0);
    float temperature = 17.5;
    gravityTds.setTemperature(temperature);  // set the temperature and execute temperature compensation
    gravityTds.update();  //sample and calculate 
    tdsValue = gravityTds.getTdsValue();  // then get the value
    ecValue = gravityTds.getEcValue();
    Serial.print(tdsValue,0);
    Serial.print("ppm, ");
    Serial.print(ecValue,0);
    Serial.print("ec, ");
    Serial.print(temperature);
    Serial.println(" C");
    delay(1000);
}
