#include "define.h"
#include <Arduino.h>
#include "common.h"
#include <TimerOne.h>

class Fan
{
  public:
    Fan();
    void setFan(int fan, bool state);
    void setFanSpeed(int fan_pwm_pin, float dutyCycle);
  private:
    bool initialized;
    //TimerOne TimerO;
};
