#include "command.h"

void handleSerial() {
 while (Serial.available() > 0) {
    char incomingCharacter = Serial.read();
    get_command(incomingCharacter);
  }
}


void get_command(char command) {
  if(command == 'c') {
  char command_char = Serial.read();
    switch(command_char) { 
      case 'l':
	lightOff();
      break;

      case 'L':
	lightOn();
      break;

      case 'p':
      {
	int pump_num = Serial.parseInt();
	pumpOff(pump_num);
      }
      break;

      case 'P':
      {
	int pump_num = Serial.parseInt();
	pumpOn(pump_num);
      }
      break; 

      case 'f':
	fanOff(FAN0_PIN);
      break;

      case 'F':
	fanOn(FAN0_PIN);
      break;

      case 's':
      {
	char fan_speed = Serial.parseInt();
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
	Serial.print("Command not known: ");
	Serial.println(command_char);
      break;
    }
  }
  else {
    Serial.print("Unknown input: ");
    Serial.println(command);
    Serial.println();
    Serial.println("Usage: ");
    Serial.println(" cf      - turn Fans off");
    Serial.println(" cF      - turn Fans on");
    Serial.println(" cp<0|1> - turn Pump 0|1 off");
    Serial.println(" cP<0|1> - turn Pump 0|1 on");
    Serial.println(" cl      - turn Lights off");
    Serial.println(" cL      - turn Lights on");
    Serial.println(" cs<0-9> - set Fan speed to 0-9");
  }
}
