#include "temp.h"


OneWire oneWire0(TMP0_PIN);
DallasTemperature temp0(&oneWire0);

OneWire oneWire1(TMP1_PIN);
DallasTemperature temp1(&oneWire1);


Temp::Temp()
{
  temp0.begin();
  temp1.begin();
}


float Temp::getTemp(int sensor)
{
  float temp = -1;
  
  switch (sensor)
  {
    case 0:
      temp0.requestTemperatures();
      temp = temp0.getTempCByIndex(0);
    break;

    case 1:
      temp1.requestTemperatures();
      temp = temp1.getTempCByIndex(0);
    break;

    default:
      D_PRINTLN((String)"D: Error unknown temp sensor: "+sensor);
      return 0;
    break;
  }

  return temp;
}


void Temp::printTemp(int sensor)
{
  float temp = getTemp(sensor);
  Serial.print(temp);
}
