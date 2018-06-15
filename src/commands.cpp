#include "commands.h"

SerialCommand SCmd;

void cmdInit(){
  SCmd.addCommand("pump", pumpCmd);
  SCmd.addCommand("light", lightCmd);
  SCmd.addCommand("fan", fanCmd);
  SCmd.addCommand("fanspeed", fanSpeedCmd);
  SCmd.addCommand("time", timeCmd);
  SCmd.addDefaultHandler(unrecognizedCmd);
  Serial.println("Commands initialized");
}


void pumpCmd(){
  int state;  
  char *arg; 

  arg = SCmd.next(); 
  if (arg != NULL) {
    state = atoi(arg);    // Converts a char string to an integer
    if (state == 1)
      pumpOn();
    else if (state == 0)
      pumpOff();
    else
      Serial.println("Invalid argument");
      usageCmd();
  } 
  else {
    Serial.println("No arguments"); 
    usageCmd();
  }
}


void lightCmd(){
  int state;
  char *arg;

  arg = SCmd.next();
  if (arg != NULL) {
    state = atoi(arg);    // Converts a char string to an integer
    if (state == 1)
      lightOn();
    else if (state == 0)
      lightOff();
    else
      Serial.println("Invalid argument");
      usageCmd();
  }
  else {
    Serial.println("No arguments");
    usageCmd();
  }
}


void fanCmd(){
  int state;
  char *arg;

  arg = SCmd.next();
  if (arg != NULL) {
    state = atoi(arg);    // Converts a char string to an integer
    if (state == 1)
      fanOn(FAN0_PIN);
    else if (state == 0)
      fanOff(FAN0_PIN);
    else
      Serial.println("Invalid argument");
      usageCmd();
  }
  else {
    Serial.println("No arguments");
    usageCmd();
  }
}


void fanSpeedCmd(){
  int speed;
  char *arg;

  arg = SCmd.next();
  if (arg != NULL) {
    speed = atoi(arg);    // Converts a char string to an integer
    if (speed >= 0 && speed <=9) {
      map(speed, 0, 9, 30, 100);
      setFanSpeed(FAN0_PWM_PIN, speed);
    }
    else {
      Serial.println("Invalid argument");
      usageCmd();
    }
  }
  else {
    Serial.println("No arguments");
    usageCmd();
  }
}


void timeCmd(){
  unsigned long pctime;
  char *arg;

  arg = SCmd.next();
  if (arg != NULL) {
    pctime = atoi(arg);
    setTime(pctime);
    alarmInit();
  }
  else
  {
    Serial.println("No arguments");
    usageCmd();
  }
}


void unrecognizedCmd(){
  Serial.println("Command not recognized.");
  usageCmd();
}


void usageCmd(){
  Serial.println("Commands: ");
  Serial.println("  pump | light | fan  <mode>");
  Serial.println("    mode 0: turn off");
  Serial.println("    mode 1: turn on");
  Serial.println("  fanspeed <speed>");
  Serial.println("    speed: 0 - 9 (0 ist slowest)");
  Serial.println("  time <pctime>");
  Serial.println("    pctime: time to be set in unix time format");
}
