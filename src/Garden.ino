#include "fans.h"
#include "pump.h"
#include "time.h"
#include "light.h"
#include "alarms.h"
#include "sensors.h"
#include "lcd.h"
#include "commands.h"
//#include "test.h"


sensorValues currentValues = { 0,0,0,0,0,0,0 };
int display_time = 0;

void setup() {
  Serial.begin(9600);
  while (!Serial);

  timeInit();
  //cmdInit();

  fanInit();
  pumpInit();
  lightInit();

  LCDInit();
  //pumpTest();
}

void loop() {
  getSerial();
  currentValues = readSensors();
  
  if (display_time == 0) { 
    printValues(currentValues);
    digitalClockDisplay();
    display_time = 10;
  }
  else {
    display_time--;
  }

  
  Alarm.delay(100);
}
