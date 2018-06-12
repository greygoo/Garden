#include "fans.h"


void fanInit(){
  Timer1.initialize(40); // set to 25kHz (40us)
  pinMode(FAN0_PWM_PIN, OUTPUT);
  pinMode(FAN0_PIN, OUTPUT);
  
  fanOn(FAN0_PIN); //turn on fan 0
  setFanSpeed(FAN0_PWM_PIN, INITIAL_FAN_CYCLE); // set fan0 to initial speed
}


void fanOn(int fan_pin) {
  digitalWrite(fan_pin, LOW);
  
  Serial.print("Fan on pin ");
  Serial.print(fan_pin);
  Serial.println(" turned on.");
}


void fanOff(int fan_pin) {
  digitalWrite(fan_pin, HIGH);
  
  Serial.print("Fan on pin ");
  Serial.print(fan_pin);
  Serial.println(" turned off.");
}


void setFanSpeed(int fan_pwm_pin, float dutyCycle){
  Timer1.pwm(fan_pwm_pin, (dutyCycle / 100) * 1023);

  Serial.print("Fan pwm cycle set to ");
  Serial.print(dutyCycle);
  Serial.print(" on pin ");
  Serial.println(fan_pwm_pin);
}
