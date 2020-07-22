#include "fans.h"


void fanInit(){
  Timer1.initialize(40); // set to 25kHz (40us)
  pinMode(CFAN0_PIN, OUTPUT);
  pinMode(CFAN0_PIN, OUTPUT);
  pinMode(CFAN0_PIN, OUTPUT);

  setFanSpeed(CFAN0_PORT, CFAN0_CYCLE); // set fan0 to initial speed
}


void ctrlFan(int fan, bool state) {
  switch(fan) {
    case 0:
      // commented out temporarily. TODO: adjust for port multiplexing
      //digitalWrite(FAN0_PIN, state);
    break;

    case 1:
      // commented out temporarily. TODO: adjust for port multiplexing
      //digitalWrite(FAN1_PIN, state);
    break;

    default:
      D_PRINTLN((String)"D: unknown fan: "+(String)fan);
      return;
    break;
  }

  D_PRINTLN((String)"D: Fan "+(String)fan+(String)" set to: "+(String)state);
}

void setFanSpeed(int fan_pwm_pin, float dutyCycle){
  Timer1.pwm(fan_pwm_pin, (dutyCycle / 100) * 1023);

  D_PRINTLN((String)"D: Fan pwm cycle set to "+(String)dutyCycle+(String)" on pin "+(String)fan_pwm_pin);
}
