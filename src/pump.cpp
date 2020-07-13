#include "pump.h"


void pumpInit(){
  pinMode(PUMP0_PIN, OUTPUT);
  pinMode(PUMP1_PIN, OUTPUT);
  digitalWrite(PUMP0_PIN, HIGH);
  digitalWrite(PUMP1_PIN, HIGH);
}


void ctrlWaterPump(int pump, bool state){
  switch (pump) {
    case 0:  
      digitalWrite(PUMP0_PIN, state);
    break;

    case 1:
      digitalWrite(PUMP1_PIN, state);
    break;

    default:
      D_PRINTLN((String)"D: Error unknown pump: "+pump);
      return;
    break;
  }
  
  D_PRINTLN((String)"D: Waterpump "+pump+" set to: "+state);
}