#include "common.h"
#include "fans.h"
#include "command.h"
#include "pump.h"
#include "light.h"
#include "sensors.h"
#include "dht.h"
#include "temp.h"
#include "tds.h"
#include "flow.h"


sensorValues currentValues = { 0,0,0,0,0,0,0 };
ShiftRegister74HC595<1> sr(DATA_PIN, CLOCK_PIN, LATCH_PIN);

void setup()
{
  Serial.begin(115200);
  while (!Serial);

  // set all relais ports to low
  sr.setAllLow();
  fanInit();
  pumpInit();
  lightInit();
  tempInit();
  dhtInit();
  tdsInit();
  flowInit();
}

void loop()
{
  handleSerial();
//  delay(1000);
}
