#ifndef FUNCTION_TDS18B20_H
#define FUNCTION_TDS18B20_H

#include "setup.h"


#ifdef FUNCTION_TEMPERATURE_DS18B20

#include "DS18B20_light.h" //https://github.com/matmunk/DS18B20
DS18B20_light ds(analogPin);
static int16_t oilT;
uint8_t cnt = 1;

void processOilTemperature()
{
  if (ds.selectNext()) {
    oilT = ds.getTempC();
    cnt = 0;
  }
}

uint8_t countLedsLitTemperature()
{
  int16_t temp = oilT;
  if ((temp>-170.0f)&&(cnt==0))
  {
    temp = constrain(temp,T_LOWER_DS18B20,T_UPPER_DS18B20);
    if (temp>60)
      return 12;
    else if (temp>55)
      return 11;
    else if (temp>50)
      return 10;
    else if (temp>45)
      return 9;
    else if (temp>40)
      return 8;
    else if (temp>35)
      return 7;
    else if (temp>30)
      return 6;
    else if (temp>25)
      return 5;
    else if (temp>20)
      return 4;
    else if (temp>15)
      return 3;
    else if (temp>10)
      return 2;
    else if (temp>5)
      return 1;
    return 7;
  }
  else
  {
    return 3;
  }
  return 2;
}
#endif

#endif
