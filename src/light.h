#include <Arduino.h>
#include <RCSwitch.h>
#include "define.h"
#include "common.h"


class Light
{
  public:
    Light();
    void setLight(int light, int state);
  private:
    void lightOn();
    void lightOff();
};
