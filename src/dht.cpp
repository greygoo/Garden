#include "dht.h"

DHT dht = DHT(DHT0_PIN,DHT_TYPE);

void dhtInit()
{
  dht.begin();
}


float getTempDHT()
{
  float temp = -1;

  float t = dht.readTemperature();

  if (isnan(t))
  {                                                                                  
    D_PRINTLN((String)"D: Error reading temperature!");                                                            
  }                                                                                                                
  else
  {                                                                                                           
    temp = t;                                                                                      
  }                                                                                                                
  return temp;
}


float getHumDHT()
{
  float humidity = -1;

  float h = dht.readHumidity();                                                                         
                                                                                                                   
  if (isnan(h))
  {                                                                            
    D_PRINTLN((String)"D: Error reading humidity!");                                                               
  }                                                                                                                
  else
  {                                                                                                           
    humidity = h;                                                                      
  }                                                                                                                
  return humidity;
}


void printTempDHT()
{
  float temp = getTempDHT();
  Serial.print(temp);
}


void printHumDHT()
{
  float humidity = getHumDHT();
  Serial.print(humidity);
}
