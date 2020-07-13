#include "define.h"
#include <TimerOne.h>
#include <Arduino.h>

void fanInit();

void ctrlFan(int fan, bool state);

void setFanSpeed(int fan_pwm_pin, float dutyCycle);
