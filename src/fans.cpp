#include "fans.h"


void fanInit(){
  Timer1.initialize(40); // set to 25kHz (40us)
  pinMode(FAN0_PWM_PIN, OUTPUT);
  pinMode(FAN0_PIN, OUTPUT);
  pinMode(FAN1_PIN, OUTPUT);
  
  //fanOn(FAN0_PIN); //turn on fan 0
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
      Serial.print("Error unknown fan: ");
      Serial.println(fan);
      return;
    break;
  }

  Serial.print("set Fan ");
  Serial.print(fan);
  Serial.print(" to: ");
  Serial.println(state);
}


void fanOn(int fan) {
  ctrlFan(fan, 1);
  
  Serial.print("turn on fan ");
  Serial.print(fan);
}


void fanOff(int fan) {
  ctrlFan(fan, 0);
  
  Serial.print("turn off fan ");
  Serial.print(fan);
}


void setFanSpeed(int fan_pwm_pin, float dutyCycle){
  Timer1.pwm(fan_pwm_pin, (dutyCycle / 100) * 1023);

  Serial.print("Fan pwm cycle set to ");
  Serial.print(dutyCycle);
  Serial.print(" on pin ");
  Serial.println(fan_pwm_pin);
}
