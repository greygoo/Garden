#include "test.h"

void pumpTest(int pump){
  ctrlWaterPump(pump, 1);
  delay(200);
  ctrlWaterPump(pump, 0);
}

