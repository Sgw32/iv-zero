#ifndef FUNCTION_TEMPERATURE_H
#define FUNCTION_TEMPERATURE_H

#include "setup.h"

#ifdef FUNCTION_TEMPERATURE
static float oilT;

const float tauOil = 0.2f;
const float R2_Oil = 220;
const float R1_Oil = OIL_R_AT_NORMAL_T; //for Coolant
const float oilB = OIL_THERMISTOR_B;

uint8_t cnt = 0;

void processOilTemperature()
{
    float V0 = (float)analogRead(analogPin);
    if (V0<1020)
    {
      float R2 = R2_Oil * V0 / (1023.0f - V0); //
      if (R2<1.0f)
        R2=1.0f;
      float temp1 = (log(R2/R1_Oil)/oilB);
      temp1 += 1/(25.0f+273.15f);
      oilT += tauOil*(1.0f/temp1 - 273.15f - oilT);
    }
    else
    {
      oilT=-170.0f;
    }
}

uint8_t countLedsLitTemperature()
{
  float res = 0;
  float temp = oilT;
  if (temp>-170.0f)
  {
    temp = constrain(temp,T_LOWER,T_UPPER);
    res = (temp-T_LOWER)/(T_UPPER-T_LOWER)*((float)DEVICE_LED_COUNT);
  }
  else
  {
    cnt++;
    if (cnt&0b10000)
      return DEVICE_LED_COUNT;
    return 0;
  }
  return (uint8_t)res;
}
#endif

#endif
