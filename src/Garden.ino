#include "fans.h"
#include "command.h"
#include "pump.h"
#include "light.h"
#include "sensors.h"
#include <ShiftRegister74HC595.h>

sensorValues currentValues = { 0,0,0,0,0,0,0 };
ShiftRegister74HC595<1> sr(0, 1, 2);

void setup() {
  Serial.begin(9600);
  while (!Serial);

  // set all relais ports to low
  sr.setAllLow();
  fanInit();
  pumpInit(sr);
  lightInit();
  sensorsInit();

}

void loop() {
  handleSerial(sr);
//  delay(1000);
}
