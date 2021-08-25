#include "door.h"

Door::Door()
{
    this->doorState = digitalRead(DOOR_PIN);
}  


void Door::getDoorState()
{
    this->doorState = digitalRead(DOOR_PIN);
}
