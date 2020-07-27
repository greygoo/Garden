#include <Arduino.h>
#include "pump.h"
#include "light.h"
#include "fans.h"
#include "sensors.h"

void handleSerial(ShiftRegister74HC595<1> sr);
int parseInt(char in_char);
void handleCommand(String command, ShiftRegister74HC595<1> sr);
