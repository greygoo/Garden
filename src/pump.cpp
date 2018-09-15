#include "pump.h"


void pumpInit(){
  pinMode(PUMP0_PIN, OUTPUT);
  pinMode(PUMP1_PIN, OUTPUT);
  digitalWrite(PUMP0_PIN, HIGH);
  digitalWrite(PUMP1_PIN, HIGH);
}


void ctrlWaterPump(int pump, bool state){
  switch (pump) {
    case '0':  
      digitalWrite(PUMP0_PIN, state);
    break;

    case '1':
      digitalWrite(PUMP1_PIN, state);
    break;

    default:
      Serial.print("Error unknown pump");
    break;
  }
  
  Serial.print("set waterpump ");
  Serial.print(pump);
  Serial.print(" to: ");
  Serial.println(state);
}


void pumpOn(int pump){
  if (pump >= 0 && pump <= 1) {
    ctrlWaterPump(pump, 0);
    Serial.println("turn on pump ");
    Serial.println(pump);
  }
  else {
    Serial.print("No such pump: ");
    Serial.println(pump);
  }
}


void pumpOff(int pump) {
  if (pump >= 0 && pump <= 1) {
    ctrlWaterPump(pump, 1);
    Serial.print("turn off pump ");
    Serial.print(pump);
  }
  else {
    Serial.print("No such pump: ");
    Serial.println(pump);
  }
}
