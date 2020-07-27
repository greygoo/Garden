#include <Arduino.h>
#include "define.h"
#include <ShiftRegister74HC595.h>

void pumpInit(ShiftRegister74HC595<1> sr);

void ctrlWaterPump(int pump, bool state, ShiftRegister74HC595<1> sr);
