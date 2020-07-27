#include "define.h"
#include <TimerOne.h>
#include <Arduino.h>
#include "common.h"

void fanInit();

void ctrlSFan(int fan, bool state);

void setFanSpeed(int fan_pwm_pin, float dutyCycle);
