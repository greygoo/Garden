#include "fans.h"


void fanInit(){
  Timer1.initialize(40); // set to 25kHz (40us)
  pinMode(CFAN0_PIN, OUTPUT);
  setFanSpeed(CFAN0_PIN, CFAN0_CYCLE); // set fan0 to initial speed
}

void ctrlSFan(int fan, bool state, ShiftRegister74HC595<1> sr) {
  switch(fan) {
    case 0:
      // commented out temporarily. TODO: adjust for port multiplexing
      //digitalWrite(FAN0_PIN, state);
      sr.set(SFAN0_PORT, state);
    break;

    case 1:
      // commented out temporarily. TODO: adjust for port multiplexing
      //digitalWrite(FAN1_PIN, state);
      sr.set(SFAN0_PORT, state);
    break;

    default:
      D_PRINTLN((String)"D: unknown fan: "+(String)fan);
      return;
    break;
  }

  D_PRINTLN((String)"D: SFan "+(String)fan+(String)" set to: "+(String)state);
}

void setFanSpeed(int fan_pwm_pin, float dutyCycle){
  Timer1.pwm(fan_pwm_pin, (dutyCycle / 100) * 1023);

  D_PRINTLN((String)"D: CFan pwm cycle set to "+(String)dutyCycle+(String)" on pin "+(String)fan_pwm_pin);
}
