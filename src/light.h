#include <Arduino.h>
#include <RCSwitch.h>
#include <UnitecRCSwitch.h>
#include "define.h"
#include "common.h"


class Light
{
  public:
    Light();
    void setLight(int light, int state);
  private:
    UnitecRCSwitch::ButtonCodes codes;
    void lightOn();
    void lightOff();
};
