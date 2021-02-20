#include "fans.h"


Fan::Fan()
{
  initialized = 0;
  for (int i = 0; i < FAN_NUM; i++)
  {
    fanState[i] = 0;
  }
  pinMode(CFAN0_PIN, OUTPUT);
  setFanSpeed(CFAN0_PIN, CFAN0_CYCLE); // set fan0 to initial speed
  fanSpeed = CFAN0_CYCLE;
}

void Fan::setFan(int fan, bool state)
{
  switch(fan)
  {
    case 0:
      sr.set(CFAN0_PORT, !state);
      fanState[fan] = state;
    break;

    case 1:
      sr.set(SFAN0_PORT, !state);
      fanState[fan] = state;
    break;

    case 2:
      sr.set(SFAN1_PORT, !state);
      fanState[fan] = state;
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
  Timer1.initialize(40); // set to 25kHz (40us)
  float duty = (dutyCycle / 100) * 1023;
  D_PRINTLN((String)"D: duty: "+(String)duty);
  Timer1.pwm(fan_pwm_pin, int(duty));
  fanSpeed = dutyCycle;
  D_PRINTLN((String)"D: CFan pwm cycle set to "+(String)dutyCycle+(String)" on pin "+(String)fan_pwm_pin);
}


void Fan::getFanState(int fan)
{
  Serial.print("Fan ");
  Serial.print(fan);
  Serial.print(": ");
  Serial.println(fanState[fan]);
}


void Fan::getFanSpeed()
{
  Serial.print("Fan Speed: ");
  Serial.println(fanSpeed);
}
