#include "light.h"

RCSwitch powerSwitch = RCSwitch();

void setLight(int light, int state)
{
  switch (light)
  {
    case 0:
      switch(state)
      {
        case 0:
          lightOff();
        break;

        case 1:
          lightOn();
        break;

        default:
          D_PRINTLN("D: Unknown state: "+state);
          return;
        break;
      }
    break;

    case 1:
      sr.set(LED_PORT, state);
    break;

    default:
      D_PRINTLN((String)"D: Error unknown light: "+light);
      return;
    break;
  }
}

void lightInit()
{
  powerSwitch.enableTransmit(RF_PIN);
  powerSwitch.setProtocol(1);
}

void lightOff()
{
  powerSwitch.sendTriState("00000F000FF0");
  D_PRINTLN("D: Switching light off.");
}

void lightOn()
{
  powerSwitch.sendTriState("00000F000FFF");
  D_PRINTLN("D: Switching light on.");
}
