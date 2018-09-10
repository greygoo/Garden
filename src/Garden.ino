#include "fans.h"
#include "pump.h"
#include "time.h"
#include "light.h"
#include "test.h"
#include "sensors.h"


sensorValues currentValues = { 0,0,0,0,0,0,0 };

void setup() {
  Serial.begin(9600);
  while (!Serial);

  timeInit();

  fanInit();
  pumpInit();
  lightInit();

}

void loop() {
  getTime();
  currentValues = readSensors();
  
  printValues(currentValues);
  delay(1000);  
}
