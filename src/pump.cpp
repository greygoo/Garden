#include "pump.h"

void pumpInit()
{
  sr.set(PUMP0_PORT, LOW);
  sr.set(PUMP1_PORT, LOW);
}


void setPump(int pump, bool state)
{
  switch (pump) 
  {
    case 0:
      sr.set(PUMP0_PORT, state);
    break;

    case 1:
      sr.set(PUMP1_PORT, state);
    break;

    default:
      D_PRINTLN((String)"D: Error unknown pump: "+pump);
      return;
    break;
  }

  D_PRINTLN((String)"D: Waterpump "+pump+" set to: "+state);
}
