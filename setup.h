#ifndef SETUP_H
#define SETUP_H

#define VW //VW SMD board
//#define AUDI //Audi SMD board
//#define VW2 //VW THD board
//#define TESTMODE //LED scroll
#define STROBE //PWM Brightness
//#define START_BLINK //Startup blink at full brightness

#define FUNCTION_VOLTAGE
//#define FUNCTION_TEMPERATURE
//#define FUNCTION_PRESSURE

#ifdef VW
const uint8_t LEDs[] = {PIN_PD3,
PIN_PB0,
PIN_PD1,
PIN_PD0,
PIN_PD4,
PIN_PD6,
PIN_PD7,
PIN_PD2,
PIN_PB1,
PIN_PB2,
PIN_PB3,
PIN_PB4};
#define DEVICE_LED_COUNT 12
#endif


#ifdef VW2
const uint8_t LEDs[] = {PIN_PD3,
PIN_PD2,
PIN_PD1,
PIN_PD0,
PIN_PD4,


PIN_PD6,
PIN_PD7,
PIN_PB0,
PIN_PB1,
PIN_PB2,
PIN_PB3,
PIN_PB4};
#define DEVICE_LED_COUNT 12
#endif

#ifdef AUDI
const uint8_t LEDs[] = {PIN_PD3,
PIN_PD2,
PIN_PD1,
PIN_PD0,
PIN_PD4,
PIN_PD6,
PIN_PD7,
PIN_PB0,
PIN_PB1,
PIN_PB2,
PIN_PB3,
PIN_PB4,
PIN_PC1,
PIN_PC2,
PIN_PC3,
PIN_PC4};
#define DEVICE_LED_COUNT 16
#endif


const uint8_t LEDs_count = DEVICE_LED_COUNT;

#define P_UPPER 9.5f
#define P_LOWER 0.0f
#define T_UPPER 145.5f
#define T_LOWER 40.0f
#define V_UPPER 15.5f
#define V_LOWER 9.5f
#define K_DIVIDER (220.0f/1220.0f)
#define DUTY_CYCLE 253

const uint8_t analogPin = A0;

#define COOLANT_R_AT_NORMAL_T 1000.0f //VW OEM

//#define OIL_R_AT_NORMAL_T 10000.0f //Digifiz replica OEM sensors by PHL
#define OIL_R_AT_NORMAL_T 1000.0f //VW OEM
//#define AMBIENT_R_AT_NORMAL_T 10000.0f //Digifiz replica OEM sensors by PHL
#define AMBIENT_R_AT_NORMAL_T 2991.39f //AutoVAZ sensors

#define COOLANT_THERMISTOR_B 4000 //OEM VW
//#define AIR_THERMISTOR_B 4000 //OEM
#define AIR_THERMISTOR_B 3812 //AutoVAZ sensors
#define OIL_THERMISTOR_B 4000 //OEM

#endif
