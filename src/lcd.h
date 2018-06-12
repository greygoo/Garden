#include <Arduino.h>
#include <U8x8lib.h>
#include "struct.h"
#include "time.h"

void LCDInit();

void printValuesLCD(sensorValues values);

void printTimeLCD();

void printDigitsLCD(int digits);
