#include "define.h"
#include <TimerOne.h>
#include <Arduino.h>

void fanInit();

void fanOn(int fan_pin);

void fanOff(int fan_pin);

void setFanSpeed(int fan_pwm_pin, float dutyCycle);
