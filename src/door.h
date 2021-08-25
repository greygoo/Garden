#include <Arduino.h>
#include "define.h"
#include "light.h"

class Door 
{
  public:
    Door();
    void getDoorState(); 
    bool doorState; 
};
