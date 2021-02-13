#include "dht.h"

DHT dht = DHT(DHT0_PIN,DHT_TYPE);

Humidity::Humidity()
{
  dht.begin();
}


float Humidity::getTempDHT()
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


float Humidity::getHumDHT()
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


void Humidity::printTempDHT()
{
  float temp = this->getTempDHT();
  Serial.print(temp);
}


void Humidity::printHumDHT()
{
  float humidity = this->getHumDHT();
  Serial.print(humidity);
}
