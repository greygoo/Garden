#include "command.h"

void handleSerial()
{
  String incomingString;
  while (Serial.available() > 0)
  {
    incomingString = Serial.readStringUntil('\r');
    D_PRINTLN((String)"D: Received command: "+incomingString);
    handleCommand(incomingString);
  }
}


int parseInt(char in_char)
{
  if (isDigit(in_char))
  {
    return (int(in_char) - 48);
  }
  else
  {
    return -1;
  }
}


void handleCommand(String command)
{
  int command_length = command.length()+1;
  char command_char[command_length];
  command.toCharArray(command_char, command_length);
  if (command_char[0] == 'c')
  {
    switch (command_char[1])
    {
      case 'l':
      {
        setLight(parseInt(command_char[2]), parseInt(command_char[3]));
      }
      break;

      case 'p':
      {
        setPump(parseInt(command_char[2]), parseInt(command_char[3]));
      }
      break;

      case 'f':
      {
        setFan(parseInt(command_char[2]), parseInt(command_char[3]));
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
  if (command_char[0] == 's')
  {
    switch (command_char[1])
    {
      case 't':
      {
        int sensor_num = parseInt(command_char[2]);
        printTemp(sensor_num);
      }
      break;

      case 'h':
      {
        printHumDHT();
      }
      break;

      case 'e':
      {
        getTDS();
      }
      break;

      case 'c':
      {
        calibrateTDS();
      }
      break;

      default:
        D_PRINTLN((String)"D: Unkown command: "+(String)command_char[1]);
      break; 
    }
  }
}
