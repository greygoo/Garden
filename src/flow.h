#include <FlowMeter.h>
#include "define.h"


class Flow
{
  public:
    Flow();
    double getFlow(unsigned long period);
    double getVolume();
  private:
    static void FlowISR();
};
