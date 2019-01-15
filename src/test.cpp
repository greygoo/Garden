#include "test.h"

void pumpTest(int pump){
  pumpOn(pump);
  delay(200);
  pumpOff(pump);
}

