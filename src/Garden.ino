#include "fans.h"
#include "command.h"
#include "pump.h"
#include "light.h"
#include "test.h"
#include "sensors.h"


sensorValues currentValues = { 0,0,0,0,0,0,0 };

void setup() {
  Serial.begin(9600);
  while (!Serial);

  fanInit();
  pumpInit();
  lightInit();

}

void loop() {
  currentValues = readSensors();
  
  printValues(currentValues);
  delay(1000);  
}

void handleSerial() {
 while (Serial.available() > 0) {
    char incomingCharacter = Serial.read();
    get_command(incomingCharacter);
  }
}
