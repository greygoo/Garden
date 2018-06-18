#include "commands.h"

void getSerial(){
  if (Serial.available()) {
    processSerialMessage();
  }
}

void processSerialMessage(){
  long int arg;
  const unsigned long DEFAULT_TIME = 1339487940;
  char cmd_terminator;
  cmd_terminator = ' ';

  String cmd = Serial.readStringUntil(cmd_terminator);
  Serial.println(cmd);
  //if ( Serial.find("pump")) {
  if( cmd.equals("pump")) {
    arg = Serial.parseInt() ;
    switch(arg) {
      case 0:
        pumpOff();
        break;
      case 1:
        pumpOn();
        break;
      default:
        Serial.println("missing argument");
        break;
    }
  }
  //if (Serial.find("light")) {
  if (cmd.equals("light")) {
    arg = Serial.parseInt();
    switch(arg) {
      case 0:
        lightOff();
        break;
      case 1:
        lightOn();
        break;
      default:
        Serial.println("missing argument");
        break;
    }
  }
  //if (Serial.find("fan")) {
  if (cmd.equals("fan")) {
    arg = Serial.parseInt();
    switch(arg) {
      case 0:
        fanOff(FAN0_PIN);
        break;
      case 1:
        fanOn(FAN0_PIN);
        break;
      default:
        Serial.println("missing argument");
        break;
    }
  }
  //if (Serial.find("time")) {
  if (cmd.equals("time")) {
    arg = Serial.parseInt();
    if( arg >= DEFAULT_TIME) {
      setTime(arg);
      alarmInit();
    }
  }
}
