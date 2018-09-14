#include "command.h"

void get_command(char command) {
  if(command == 'c') {
  char command_char = Serial.read();
    switch(command_char) { 
      case 'l':
        //switch light off
	lightOff();
      break;

      case 'L':
        //switch light on
	lightOn();
      break;

      case 'p':
        //switch pumps off
        {
          Serial.println("pump off command received");
          char pump_num = Serial.read();
	  if (pump_num == 0 || pump_num == 1) {
	    pumpOff(pump_num);
          }
	  else {
            Serial.print("No such pump: ");
	    Serial.println(pump_num);
	  }
	}
      break;

      case 'P':
        //switch pumps on
        {
          Serial.println("pump on command received");
          char pump_num = Serial.read();
	  if (pump_num == 0 || pump_num == 1) {
	    pumpOn(pump_num);
          }
	  else {
            Serial.print("No such pump: ");
	    Serial.println(pump_num);
	  }
	}
      break; 

      case 'f':
        //switch fans off
        fanOff(FAN0_PIN);
      break;

      case 'F':
        //switch fans on
	fanOn(FAN0_PIN);
      break;

      case 's':
        {
          // set new fan0 speed
	  char fan_speed = Serial.read();
	  if (fan_speed == '1' || \
	      fan_speed == '2' || \
	      fan_speed == '3' || \
	      fan_speed == '4' || \
	      fan_speed == '5' || \
	      fan_speed == '6' || \
	      fan_speed == '7' || \
	      fan_speed == '8' || \
	      fan_speed == '9' || \
	      fan_speed == '0') {
	    setFanSpeed(FAN0_PWM_PIN, (fan_speed * 10));
    	  }
	  else {
            Serial.print("Error fan speed: ");
	    Serial.println(fan_speed);
	  }
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
    Serial.println(" cf - turn Fans off");
    Serial.println(" cF - turn Fans on");
    Serial.println(" cp - turn Pumps off");
    Serial.println(" cP - turn Pumps on");
    Serial.println(" cl - turn Lights off");
    Serial.println(" cL - turn Lights on");
  }
}
