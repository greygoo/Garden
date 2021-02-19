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
    void getLightState(int light);
  private:
    UnitecRCSwitch::ButtonCodes codes;
    bool lightState[];
    void lightOn();
    void lightOff();
};
