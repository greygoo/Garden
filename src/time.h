#include <Arduino.h>
#include "alarms.h"
#include <TimeLib.h>
#include "define.h"
#include "pump.h"

void timeInit();

/*void getTime();*/

time_t requestTimeSync();

/*void processTimeSyncMessage();*/

void digitalClockDisplay();

void printDigits(int digits);
