#ifndef FUNCTION_PRESSURE_H
#define FUNCTION_PRESSURE_H

#include "setup.h"

#ifdef FUNCTION_PRESSURE

float computeInputVoltage(float v_in)
{
  float V = v_in/K_DIVIDER; //input voltage
  return V;
}

uint8_t countLedsLitPressure(uint16_t adc_in)
{
  float res = 0;
  float Volt = computeInputVoltage(((float)adc_in)/1023.0f*5.0f);
  float Pout = (10.0f*(Volt-0.5f)/4.0f); //03C906051A sensor
  if (Pout<0.3)
      return 0;
  else if (Pout<0.5f)
      return 1;
  else if (Pout<1.0f)
      return 2;
  else if (Pout<1.5f)
      return 3;
  else if (Pout<2.0f)
      return 4;
  else if (Pout<3.0f)
      return 5;
  else if (Pout<4.0f)
      return 6;
  else if (Pout<5.0f)
      return 7;
  else if (Pout<6.0f)
      return 8;
  else if (Pout<7.0f)
      return 9;
  else if (Pout<8.0f)
      return 10;
  else if (Pout<9.0f)
      return 11;
  else if (Pout<11.0f)
      return 12;
  return 12;
}
#endif

#endif