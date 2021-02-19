#include "command.h"

Pump pump;
Fan fan;
Light light;
Humidity humidity;


void handleSerial()
{
  String incomingString;
  while (Serial.available() > 0)
  {
    incomingString = Serial.readStringUntil('\r');
    D_PRINTLN((String)"D: Received command: "+(String)incomingString);
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
        light.setLight(parseInt(command_char[2]), parseInt(command_char[3]));
      }
      break;

      case 'p':
      {
        pump.setPump(parseInt(command_char[2]), parseInt(command_char[3]));
      }
      break;

      case 'f':
      {
        fan.setFan(parseInt(command_char[2]), parseInt(command_char[3]));
      }
      break;

      case 's':
      {
        int fan_speed = (parseInt(command_char[2]) * 10) + parseInt(command_char[3]);
        D_PRINTLN((String)"D: fanSpeed: "+(String)fan_speed);
        if (fan_speed >= 0 && fan_speed <= '99') {
          fan.setFanSpeed(CFAN0_PIN, fan_speed);
        }
        else {
          D_PRINTLN((String)"D: Error fan speed: "+(String)fan_speed);
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
        temp.printTemp(sensor_num);
      }
      break;

      case 'h':
      {
        humidity.printHumDHT();
      }
      break;

      case 'd':
      {
        humidity.printTempDHT();
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

      case 'v':
      {
        pump.getTotalVolume();
      }
      break;

      case 'r':
      {
        pump.getFlowRate();
      }
      break;

      case 'p':
      {
        pump.getPumpState(parseInt(command_char[2]));
      }
      break;

      case 'f':
      {
        fan.getFanState(parseInt(command_char[2]));
      }
      break;

      case 'l':
      {
        light.getLightState(parseInt(command_char[2]));
      }
      break;

      default:
        D_PRINTLN((String)"D: Unkown command: "+(String)command_char[1]);
      break; 
    }
  }
}
