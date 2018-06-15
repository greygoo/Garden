#include "fans.h"
#include "pump.h"
#include "time.h"
#include "light.h"
#include "alarms.h"
#include "sensors.h"
#include "lcd.h"
#include "commands.h"
#include "test.h"


sensorValues currentValues = { 0,0,0,0,0,0,0 };
int modeLCD = 0;

void setup() {
  Serial.begin(9600);
  while (!Serial);

  timeInit();
  cmdInit();

  fanInit();
  pumpInit();
  lightInit();

  LCDInit();
  //pumpTest();
}

void loop() {
  //getTime();
  currentValues = readSensors();
  
  switch(modeLCD) {
  case 0:
    printTimeLCD();
    modeLCD++;
    break;
  case 1:
    printValues(currentValues);
    modeLCD = 0;
    break;
  default:
    modeLCD = 0;
  }
  
  Alarm.delay(5000);
}
