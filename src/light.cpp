#include "light.h"


RCSwitch powerSwitch = RCSwitch();


void lightInit() {
  powerSwitch.enableTransmit(10);
  powerSwitch.setProtocol(1);
  lightOff();
}

void lightOff(){
  powerSwitch.sendTriState("00000F000FF0");
  Serial.println("debug,Switching light off.");
}


void lightOn(){
  powerSwitch.sendTriState("00000F000FFF");
  Serial.println("debug,Switching light on.");
}
