#include "fans.h"


void fanInit(){
  Timer1.initialize(40); // set to 25kHz (40us)
  pinMode(FAN0_PWM_PIN, OUTPUT);
  pinMode(FAN0_PIN, OUTPUT);
  pinMode(FAN1_PIN, OUTPUT);
  
  setFanSpeed(FAN0_PWM_PIN, INITIAL_FAN_CYCLE); // set fan0 to initial speed
}


void ctrlFan(int fan, bool state) {
  switch(fan) {
    case 0:
      digitalWrite(FAN0_PIN, state);
    break;

    case 1:
      digitalWrite(FAN1_PIN, state);
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