#ifndef FUNCTION_TEMPERATURE_H
#define FUNCTION_TEMPERATURE_H

#include "setup.h"

#ifdef FUNCTION_TEMPERATURE
static float oilT;

const float tauOil = 0.02f;
const float R2_Oil = 220;
const float R1_Oil = OIL_R_AT_NORMAL_T; //for Coolant
const float oilB = OIL_THERMISTOR_B;

void processOilTemperature()
{
    float V0 = (float)analogRead(analogPin);
    float R2 = R2_Oil * V0 / (1023.0f - V0); //
    float temp1 = (log(R2/R1_Oil)/oilB);
    temp1 += 1/(25.0f+273.15f);
    oilT += tauOil*(1.0f/temp1 - 273.15f - oilT);
}

uint8_t countLedsLitTemperature()
{
  float res = 0;
  float temp = oilT;
  temp = constrain(temp,T_LOWER,T_UPPER);
  res = (temp-T_LOWER)/(T_UPPER-T_LOWER)*((float)DEVICE_LED_COUNT);
  return (uint8_t)res;
}
#endif

#endif
