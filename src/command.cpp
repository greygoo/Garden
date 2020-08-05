#include "command.h"

void handleSerial() {
  String incomingString;
  while (Serial.available() > 0) {
    incomingString = Serial.readStringUntil('\n');
    D_PRINTLN((String)"D: Received command: "+incomingString);
    handleCommand(incomingString);
  }
}


int parseInt(char in_char) {
  if (isDigit(in_char)) {
    return (int(in_char) - 48);
  }
  else {
    return -1;
  }
}


void handleCommand(String command) {
  int command_length = command.length();
  char command_char[command_length];
  command.toCharArray(command_char, command_length);
  if (command_char[0] == 'c')
  {
    switch (command_char[1])
    {
      case 'l':
      {
        // we ignore light number as there only is one light for now
        int state = parseInt(command_char[3]);
        ctrlLight(state);
      }
      break;

      case 'p':
      {
        int pump_num = parseInt(command_char[2]);
        int state = parseInt(command_char[3]);
        ctrlWaterPump(pump_num, state);
      }
      break;

      case 'f':
      {
        int fan_num = parseInt(command_char[2]);
        int state = parseInt(command_char[3]);
        ctrlSFan(fan_num, state);
      }
      break;

      case 's':
      {
        int fan_speed = parseInt(command_char[2]);
        if (fan_speed >= 0 && fan_speed <= '9') {
          setFanSpeed(CFAN0_PORT, (fan_speed * 10));
        }
        else {
          D_PRINTLN((String)"D: Error fan speed: "+fan_speed);
        }
      }
      break;

      case 'd':
      {
        printSensorData();
      }
      break;

      case 'D':
      {
        printSimpleData();
      }
      break;

      default:
        D_PRINTLN((String)"D: Unkown command: "+(String)command_char[1]);
      break;
    }
  }
}
