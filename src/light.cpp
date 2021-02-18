#include "light.h"

#ifndef LIGHT_REMOTE
RCSwitch powerSwitch = RCSwitch();
#elif LIGHT_REMOTE
UnitecRCSwitch mySwitch;
#endif

Light::Light()
{
  #ifndef LIGHT_REMOTE
  powerSwitch.enableTransmit(RF_PIN);
  powerSwitch.setProtocol(1);
  #elif LIGHT_REMOTE
  codes = {
    {4200304, 4467632, 4641840, 4853312}, // Button A ON codes
    {4836384, 4450832, 4993424, 4345248}, // Button A OFF codes
    {4467636, 4200308, 4853316, 4641844}, // Button B ON codes
    {4450836, 4836388, 4345252, 4993428}, // Button B OFF codes
    {4467644, 4200316, 4853324, 4641852}, // Button C ON codes
    {4450844, 4836396, 4345260, 4993436}, // Button C OFF codes
    {4993426, 4345250, 4836386, 4450834}, // Button D ON codes
    {4641842, 4853314, 4200306, 4467634}, // Button D OFF codes
  };
  mySwitch.setBtnCodes(&codes);
  mySwitch.enableTransmit(RF_PIN);
  #endif
}


void Light::setLight(int light, int state)
{
  switch (light)
  {
    case 0:
      switch(state)
      {
        case 0:
          lightOff();
          D_PRINTLN((String)"D: Light 0 set to: 0");
        break;

        case 1:
          lightOn();
          D_PRINTLN((String)"D: Light 0 set to: 1");
        break;

        default:
          D_PRINTLN((String)"D: Unknown state: "+state);
          return;
        break;
      }
    break;

    case 1:
      sr.set(LED_PORT, !state);
      D_PRINTLN((String)"D: Light 1 set to: "+state);
    break;

    default:
      D_PRINTLN((String)"D: Error unknown light: "+light);
      return;
    break;
  }
}


void Light::lightOn()
{
  #ifndef LIGHT_REMOTE
  powerSwitch.sendTriState("00000F000FFF");
  D_PRINTLN((String)"D: Sent TriState On ");
  #elif LIGHT_REMOTE
  mySwitch.switchOn(UnitecRCSwitch::SOCKET_A);                                                                    
  D_PRINTLN((String)"D: Sent Unitec On ");
  #endif
}


void Light::lightOff()
{
  #ifndef LIGHT_REMOTE
  powerSwitch.sendTriState("00000F000FF0");
  D_PRINTLN((String)"D: Sent TriState Off ");
  #elif LIGHT_REMOTE
  mySwitch.switchOff(UnitecRCSwitch::SOCKET_A);
  D_PRINTLN((String)"D: Sent Unitec Off ");
  #endif
}
