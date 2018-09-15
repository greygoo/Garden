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
      Serial.print("Error unknown pump: ");
      Serial.println(pump);
      return;
    break;
  }
  
  Serial.print("waterpump ");
  Serial.print(pump);
  Serial.print(" set to: ");
  Serial.println(state);
}


void pumpOn(int pump){
  ctrlWaterPump(pump, 0);
  Serial.print("turn on pump ");
  Serial.println(pump);
}


void pumpOff(int pump) {
  ctrlWaterPump(pump, 1);
  Serial.print("turn off pump ");
  Serial.println(pump);
}
