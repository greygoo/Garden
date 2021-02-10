#include "pump.h"


Pump::Pump()
{
  sr.set(PUMP0_PORT, HIGH);
  sr.set(PUMP1_PORT, HIGH);
}


void Pump::setPump(int pump, bool state)
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
    this->PumpStop = millis();
    this->PumpTime = this->PumpStop - this->PumpStart;
    this->flowRate = getFlow(this->PumpTime);
    this->totalVolume = getVolume();
    D_PRINTLN((String)"Flow rate: "+flowRate+" l/min");
    D_PRINTLN((String)"D: Pump time: "+PumpTime); 
  }


  D_PRINTLN((String)"D: Waterpump "+pump+" set to: "+state);
}


void Pump::getFlowRate()
{
  Serial.print("Flow rate: ");
  Serial.print(this->flowRate);
  Serial.println(" l/min");
}


void Pump::getTotalVolume()
{
  Serial.print("Total Volume: ");
  Serial.print(this->totalVolume);
  Serial.println(" l");
}
