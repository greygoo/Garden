#include "pump.h"

unsigned long PumpStart;
unsigned long PumpStop;
unsigned long PumpTime;

void pumpInit()
{
  sr.set(PUMP0_PORT, HIGH);
  sr.set(PUMP1_PORT, HIGH);
}


void setPump(int pump, bool state)
{
  if (state == 1) 
  {
     PumpStart = millis();
  }

  switch (pump) 
  {
    case 0:
      sr.set(PUMP0_PORT, !state);
    break;

    case 1:
      sr.set(PUMP1_PORT, !state);
    break;

    default:
      D_PRINTLN((String)"D: Error unknown pump: "+pump);
      return;
    break;
  }

  if (state == 0)
  {
    PumpStop = millis();
    PumpTime = PumpStop - PumpStart;
    double flowRate = getFlow(PumpTime);
    double totalVolume = getVolume();
    D_PRINTLN((String)"Flow rate: "+flowRate+" l/min");
    D_PRINTLN((String)"D: Pump time: "+PumpTime); 
  }


  D_PRINTLN((String)"D: Waterpump "+pump+" set to: "+state);
}
