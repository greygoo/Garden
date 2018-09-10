#include "pump.h"


void pumpInit(){
  pinMode(PUMP_PIN, OUTPUT);
  digitalWrite(PUMP_PIN, HIGH);
}


void ctrlWaterPump(bool state){
  digitalWrite(PUMP_PIN, state);
  Serial.print("set waterpump to: ");
  Serial.println(state);
}


void pumpOn(){
  ctrlWaterPump(0);
  Serial.println("turn pump on.");
}


void pumpOff(){
  ctrlWaterPump(1);
  Serial.println("turn pump off.");
}
