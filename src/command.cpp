#include "command.h"

void handleSerial(ShiftRegister74HC595<1> sr) {
  String incomingString;
  while (Serial.available() > 0) {
    incomingString = Serial.readStringUntil('\n');
    D_PRINTLN((String)"D: Received command: "+incomingString);
    handleCommand(incomingString, sr);
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


void handleCommand(String command, ShiftRegister74HC595<1> sr) {
  int command_length = command.length();
  char command_char[command_length];
  command.toCharArray(command_char, command_length);
  if (command_char[0] == 'c')
  {
    switch (command_char[1])
    {
      case 'l':
        lightOff();
      break;

      case 'L':
        lightOn();
      break;

      case 'p':
      {
        int pump_num = parseInt(command_char[2]);
        ctrlWaterPump(pump_num, 0, sr);
      }
      break;

      case 'P':
      {
        int pump_num = parseInt(command_char[2]);
        ctrlWaterPump(pump_num, 1, sr);
      }
      break;

      case 'f':
      {
        int fan_num = parseInt(command_char[2]);
        ctrlFan(fan_num, 0);
      }
      break;

      case 'F':
      {
        int fan_num = parseInt(command_char[2]);
        ctrlFan(fan_num, 0);
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
  if (command_char[0] == 'p') // programming
  {
    switch (command_char[1])
    {
      case 'p':
      {
        int pump_num = parseInt(command_char[2]);
        int run_time = parseInt(command_char[3]);
        int stop_time = parseInt(command_char[4]);
      }
      break;

      case 'l':
      {
        int run_time = parseInt(command_char[2]);
        int stop_time = parseInt(command_char[3]);
      }
      break;

      default:
        D_PRINTLN((String)"D: Unkown programming command: "+(String)command_char[1]);
      break;
    }
  }
}
