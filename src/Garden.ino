#include "common.h"
#include "sensors.h"
#include "tds.h"
#include "command.h"
#include "door.h"


sensorValues currentValues = { 0,0,0,0,0,0,0 };
ShiftRegister74HC595<1> sr(DATA_PIN, CLOCK_PIN, LATCH_PIN);
Temp temp;
Door door;


void setup()
{
  Serial.begin(115200);
  while (!Serial);

  // set all relais ports to high 
  sr.setAllHigh();
  //sr.set(VALVE0_PORT, HIGH);
  //sr.set(VALVE1_PORT, HIGH);
  tdsInit();
}

void loop()
{
  handleSerial();
  door.handleDoor();
  //delay(1000);
}
