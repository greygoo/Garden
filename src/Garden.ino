#include "common.h"
#include "sensors.h"
#include "dht.h"
#include "tds.h"
#include "flow.h"
#include "command.h"


sensorValues currentValues = { 0,0,0,0,0,0,0 };
ShiftRegister74HC595<1> sr(DATA_PIN, CLOCK_PIN, LATCH_PIN);
Temp temp;


void setup()
{
  Serial.begin(115200);
  while (!Serial);

  // set all relais ports to low
  sr.setAllHigh();
  //sr.set(VALVE0_PORT, HIGH);
  //sr.set(VALVE1_PORT, HIGH);
  dhtInit();
  tdsInit();
  flowInit();
}

void loop()
{
  handleSerial();
  //delay(1000);
}
