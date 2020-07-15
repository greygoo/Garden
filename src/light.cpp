#include "light.h"

RCSwitch powerSwitch = RCSwitch();

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
