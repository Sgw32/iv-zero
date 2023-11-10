#include "setup.h"
#include "function_voltage.h"
#include "function_temperature.h"
#include "function_pressure.h"

uint8_t timeCount = 0;

uint32_t LEDs_set;


#ifdef STROBE
ISR(TIMER1_COMPA_vect) //Timer 0 overflow vector - this run every time timer0 overflows
{
  timeCount++;
  if(timeCount > DUTY_CYCLE) //Timer overflown for the 61th time
  {
    for (int i=0;i!=DEVICE_LED_COUNT;i++)
    {
      digitalWrite(LEDs[i], (LEDs_set & (1<<i)) ? HIGH : LOW);
    }
  }
  else
  {
    for (int i=0;i!=DEVICE_LED_COUNT;i++)
    {
      digitalWrite(LEDs[i], LOW);
    }
  }
}
#endif 

void setup() {
  LEDs_set=0;
  //If we need a startup blink with max intensity:
  #ifdef START_BLINK
  for (int i=0;i!=LEDs_count;i++)
  {
    pinMode(LEDs[i],OUTPUT);
    digitalWrite(LEDs[i], HIGH);
  }
  delay(100);
  for (int i=0;i!=LEDs_count;i++)
  {
    digitalWrite(LEDs[i], LOW);
  }
  #else
  for (int i=0;i!=LEDs_count;i++)
  {
    pinMode(LEDs[i],OUTPUT);
    
  }
  #endif
  
  
  analogReference(0);
  //PWM Brightness
  #ifdef STROBE
  cli(); // stop interrupts
  TCCR1A = 0; // set entire TCCR1A register to 0
  TCCR1B = 0; // same for TCCR1B
  TCNT1  = 0; // initialize counter value to 0
  // set compare match register for 1000 Hz increments
  OCR1A = 159; // = 16000000 / (1 * 1000) - 1 (must be <65536)
  // turn on CTC mode
  TCCR1B |= (1 << WGM12);
  // Set CS12, CS11 and CS10 bits for 1 prescaler
  TCCR1B |= (0 << CS12) | (0 << CS11) | (1 << CS10);
  // enable timer compare interrupt
  TIMSK1 |= (1 << OCIE1A);
  sei(); // allow interrupts
  #endif
  #ifdef STROBE
  LEDs_set = 0xFFF;
  delay(100);
  LEDs_set = 0x0;
  delay(100);
  #endif
}

void loop() 
{
  #ifndef TESTMODE
  
  uint8_t leds_lit = 0;
  
  //Voltmeter
  #ifdef FUNCTION_VOLTAGE
  uint16_t adc_res=0;
  for (int i=0;i!=16;i++)
  {
    adc_res+=analogRead(analogPin);
  }
  adc_res=adc_res>>4; // div by 16
  leds_lit = countLedsLitVoltage(adc_res);
  #endif

  #ifdef FUNCTION_PRESSURE
  uint16_t adc_res=0;
  for (int i=0;i!=16;i++)
  {
    adc_res+=analogRead(analogPin);
  }
  adc_res=adc_res>>4; // div by 16
  leds_lit = countLedsLitPressure(adc_res);
  #endif
  
  
  //Temperature sensor
  #ifdef FUNCTION_TEMPERATURE
  processOilTemperature();
  leds_lit = countLedsLitTemperature();
  #endif
  
  leds_lit = constrain(leds_lit,0,DEVICE_LED_COUNT);
  
  //Set LEDs active
  for (int i=0;i!=leds_lit;i++)
  {
    #ifndef STROBE
    digitalWrite(LEDs[i], HIGH);
    #else
    LEDs_set|=(1<<i);
    #endif
  }
  //Reset LEDs which are not active
  for (int i=leds_lit;i!=DEVICE_LED_COUNT;i++)
  {
    #ifndef STROBE
    digitalWrite(LEDs[i], LOW);
    
    #else
    LEDs_set&=~(1<<i);
    #endif
  }
  
  #else
  
  for (int i=0;i!=DEVICE_LED_COUNT;i++)
  {
    #ifndef STROBE
    digitalWrite(LEDs[i], HIGH);
    #else
    LEDs_set|=(1<<i);
    #endif
    delay(300);
  }
  for (int i=0;i!=DEVICE_LED_COUNT;i++)
  {
    #ifndef STROBE
    digitalWrite(LEDs[i], LOW);
    #else
    LEDs_set&=~(1<<i);
    #endif
    delay(300);
  }
  #endif

}
