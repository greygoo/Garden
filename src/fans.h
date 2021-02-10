#include "define.h"
#include <TimerOne.h>
#include <Arduino.h>
#include "common.h"

class Fan
{
  public:
    Fan();
    void fanInit();
    void setFan(int fan, bool state);
    void setFanSpeed(int fan_pwm_pin, float dutyCycle);
  private:
};
