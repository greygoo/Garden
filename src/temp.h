#include <OneWire.h>
#include <DallasTemperature.h>
#include "define.h"

#ifndef MY_TEMP_H
#define MY_TEMP_H

class Temp
{
  public:
    Temp();
    void printTemp(int sensor);
    float getTemp(int sensor);
  private:
};

#endif
