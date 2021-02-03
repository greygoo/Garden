#include "tds.h"


GravityTDS gravityTds;

float tdsValue = 0,temperature = 25;

void tdsInit()
{
  pinMode(ECC_PIN,INPUT);
  gravityTds.setPin(ECC_PIN);
  gravityTds.setAref(ECC_VREF);
  gravityTds.setAdcRange(1024);  //1024 for 10bit ADC;4096 for 12bit ADC
  gravityTds.begin();
}


float getTDS() {
    temperature = getTemp(ECC_TEMP);
    gravityTds.setTemperature(temperature);  // execute temperature compensation
    gravityTds.update();  //sample and calculate
    tdsValue = gravityTds.getTdsValue();  // then get the value
    return tdsValue;
} 


void printTDS()
{
  float ecc = getTDS();
  Serial.print(ecc);
}
