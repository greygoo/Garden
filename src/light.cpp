#include "light.h"

RCSwitch powerSwitch = RCSwitch();

void ctrlLight(int state){
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
}

void lightInit() {
  powerSwitch.enableTransmit(RF_PIN);
  powerSwitch.setProtocol(1);
}

void lightOff(){
  powerSwitch.sendTriState("00000F000FF0");
  D_PRINTLN("D: Switching light off.");
}

void lightOn(){
  powerSwitch.sendTriState("00000F000FFF");
  D_PRINTLN("D: Switching light on.");
}
