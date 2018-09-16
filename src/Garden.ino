#include "fans.h"
#include "command.h"
#include "pump.h"
#include "light.h"
#include "test.h"
#include "sensors.h"


sensorValues currentValues = { 0,0,0,0,0,0,0 };

void setup() {
  Serial.begin(9600);
  while (!Serial);

  fanInit();
  pumpInit();
  lightInit();

}

void loop() {
  handleSerial();
//  delay(1000);
}
