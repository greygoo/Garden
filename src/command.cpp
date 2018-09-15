#include "command.h"

void handleSerial() {
  String incomingString;
  while (Serial.available() > 0) {
    incomingString = Serial.readStringUntil('\n');
    Serial.println("Received command: " + incomingString);
  }
  handleCommand(incomingString);
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
  if (command_char[0] == 'c') {
    switch (command_char[1]) {
      case 'l':
	lightOff();
      break;

      case 'L':
        lightOn();
      break;

      case 'p':
      {
	int pump_num = parseInt(command_char[2]);
	pumpOff(pump_num);
      }
      break;

      case 'P':
      {
	int pump_num = parseInt(command_char[2]);
	pumpOn(pump_num);
      }
      break; 

      case 'f':
      {
	int fan_num = parseInt(command_char[2]);
	fanOff(fan_num);
      }
      break;

      case 'F':
      {
        int fan_num = parseInt(command_char[2]);
	fanOn(fan_num);
      }
      break;

      case 's':
      {
	int fan_speed = parseInt(command_char[2]);
	if (fan_speed >= 0 && fan_speed <= '9') {
	  setFanSpeed(FAN0_PWM_PIN, (fan_speed * 10));
	}
	else {
	  Serial.print("Error fan speed: ");
	  Serial.println(fan_speed);
	}
      }
      break;

      case 'd':
      {
        printSensorData();
      }
      break;

      default:
        Serial.print("Unkown command: ");
	Serial.println(command_char[1]);
      break;
    }
  }
}
