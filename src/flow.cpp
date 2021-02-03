#include "flow.h"

FlowMeter *Flow;


void FlowISR() {
    Flow->count();
}


void flowInit()
{
  Flow = new FlowMeter(digitalPinToInterrupt(2), UncalibratedSensor, FlowISR, RISING);
}  



