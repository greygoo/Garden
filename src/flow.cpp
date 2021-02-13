#include "flow.h"

FlowMeter *FlowM;


Flow::Flow()
{
  FlowM = new FlowMeter(digitalPinToInterrupt(2), UncalibratedSensor, this->FlowISR, RISING);
}  


static void Flow::FlowISR()
{
    FlowM->count();
}


double Flow::getFlow(unsigned long period)
{
  FlowM->tick(period);
  return(FlowM->getCurrentFlowrate());
}


double Flow::getVolume()
{
  return(FlowM->getTotalVolume());
}
