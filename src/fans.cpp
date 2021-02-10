#include "fans.h"


Fan::Fan()
{
  Timer1.initialize(40); // set to 25kHz (40us)
  pinMode(CFAN0_PIN, OUTPUT);
  setFanSpeed(CFAN0_PIN, CFAN0_CYCLE); // set fan0 to initial speed
}

void Fan::setFan(int fan, bool state)
{
  switch(fan)
  {
    case 0:
      sr.set(CFAN0_PORT, !state);
    break;

    case 1:
      sr.set(SFAN0_PORT, !state);
    break;

    case 2:
      sr.set(SFAN1_PORT, !state);
    break;

    default:
      D_PRINTLN((String)"D: unknown fan: "+(String)fan);
      return;
    break;
  }

  D_PRINTLN((String)"D: SFan "+(String)fan+(String)" set to: "+(String)state);
}

void Fan::setFanSpeed(int fan_pwm_pin, float dutyCycle)
{
  Timer1.pwm(fan_pwm_pin, (dutyCycle / 100) * 1023);

  D_PRINTLN((String)"D: CFan pwm cycle set to "+(String)dutyCycle+(String)" on pin "+(String)fan_pwm_pin);
}
