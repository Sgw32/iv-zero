#ifndef FUNCTION_VOLTAGE_H
#define FUNCTION_VOLTAGE_H

#include "setup.h"

#ifdef FUNCTION_VOLTAGE

float computeInputVoltage(float v_in)
{
  float V = v_in/K_DIVIDER; //input voltage
  return V;
}

uint8_t countLedsLitVoltage(uint16_t adc_in)
{
  float res = 0;
  float Volt = computeInputVoltage(((float)adc_in)/1023.0f*5.0f);
  Volt = constrain(Volt,V_LOWER,V_UPPER);
  res = (Volt-V_LOWER)/(V_UPPER-V_LOWER)*((float)DEVICE_LED_COUNT);
  return (uint8_t)res;
}
#endif

#endif