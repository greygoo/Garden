#include <Arduino.h>
#include "define.h"
#include "flow.h"
#include "common.h"

class Pump
{
  public:
    Pump();
    void setPump(int pump, bool state);
    void getFlowRate();
    void getTotalVolume();
  private:
    unsigned long PumpStart;
    unsigned long PumpStop;
    unsigned long PumpTime;
    double flowRate;
    double totalVolume;
};
