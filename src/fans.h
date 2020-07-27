#include "define.h"
#include <TimerOne.h>
#include <Arduino.h>
#include <ShiftRegister74HC595.h>

void fanInit();

void ctrlSFan(int fan, bool state, ShiftRegister74HC595<1> sr);

void setFanSpeed(int fan_pwm_pin, float dutyCycle);
