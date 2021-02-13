#include <DHT.h>
#include "define.h"


class Humidity
{
  public:
    Humidity();
    void printTempDHT();
    void printHumDHT();
  private:
    float getTempDHT();
    float getHumDHT(); 
};
