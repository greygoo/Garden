#include <Arduino.h>
#include <TimeLib.h>
#include "define.h"

void timeInit();

void getTime();

time_t requestTimeSync();

void processTimeSyncMessage();

void digitalClockDisplay();

void printDigits(int digits);
