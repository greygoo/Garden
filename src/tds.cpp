#include "tds.h"


GravityTDS gravityTds;

float tdsValue = 0,ecValue = 0,temperature = 25;

void tdsInit()
{
  pinMode(ECC_PIN,INPUT);
  gravityTds.setPin(ECC_PIN);
  gravityTds.setAref(ECC_VREF);
  gravityTds.setAdcRange(1024);  //1024 for 10bit ADC;4096 for 12bit ADC
  gravityTds.begin();
}


float getTDS() {
    temperature = temp.getTemp(ECC_TEMP);
    gravityTds.setTemperature(temperature);  // execute temperature compensation
    gravityTds.update();  //sample and calculate
    tdsValue = gravityTds.getTdsValue();  // then get the value
    ecValue = gravityTds.getEcValue();  // then get the value
    Serial.print("O: TDS: ");
    Serial.println(tdsValue);
    Serial.print("O: EC: ");
    Serial.println(ecValue);
    return tdsValue;
    //return ecValue;
} 


void calibrateTDS() {
    temperature = temp.getTemp(ECC_TEMP);
    gravityTds.setTemperature(temperature);  // execute temperature compensation
    gravityTds.update();  //sample and calculate
    gravityTds.ecCalibration(1);
    strcpy(gravityTds.cmdReceivedBuffer, "CAL:707");
    gravityTds.ecCalibration(2);
    gravityTds.ecCalibration(3);
}


void printTDS()
{
  Serial.print("O: TDS: ");
  Serial.print("O: EC: ");
}
