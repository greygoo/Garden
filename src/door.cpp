#include "door.h"

Door::Door()
{
    this->doorState = digitalRead(DOOR_PIN);
}  


void Door::getDoorState()
{
    this->doorState = digitalRead(DOOR_PIN);
}

void Door::handleDoor()
{
    bool lastState = this->doorState;
    getDoorState();
    //D_PRINTLN((String)"state "+lastState);
    //D_PRINTLN((String)"doorState "+this->doorState);
    //D_PRINTLN((String)"");
    if (lastState != this->doorState)
    {
	D_PRINTLN((String)"Door state changed to "+this->doorState);
        Light light;
        light.setLight(DOOR_LIGHT, !this->doorState);
    }
}
