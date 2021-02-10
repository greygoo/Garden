#include <FlowMeter.h>
#include "define.h"

void FlowISR();

void flowInit();

double getFlow(unsigned long period);

double getVolume();
