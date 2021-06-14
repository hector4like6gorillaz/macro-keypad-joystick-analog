#pragma once

#include <stdint.h>
#include "quantum.h"

#ifdef __cplusplus
extern "C" {
#endif
void    analogReference(uint8_t mode);
int16_t analogRead(uint8_t pin);

int16_t analogReadPin(pin_t pin);
uint8_t pinToMux(pin_t pin);

int16_t adc_read(uint8_t mux);
#ifdef __cplusplus
}
#endif

#define ADC_REF_EXTERNAL 0                          // AREF, Internal Vref turned off
#define ADC_REF_POWER _BV(REFS0)                    // AVCC with external capacitor on AREF pin
#define ADC_REF_INTERNAL (_BV(REFS1) | _BV(REFS0))  // Internal 2.56V Voltage Reference with external capacitor on AREF pin (1.1V for 328P)

// These prescaler values are for high speed mode, ADHSM = 1
#if F_CPU == 16000000L || F_CPU == 12000000L
#    define ADC_PRESCALER (_BV(ADPS2) | _BV(ADPS1))  // /64
#elif F_CPU == 8000000L
#    define ADC_PRESCALER (_BV(ADPS2) | _BV(ADPS0))  // /32
#elif F_CPU == 4000000L
#    define ADC_PRESCALER (_BV(ADPS2))  // /16
#elif F_CPU == 2000000L
#    define ADC_PRESCALER (_BV(ADPS1) | _BV(ADPS0))  // /8
#elif F_CPU == 1000000L
#    define ADC_PRESCALER _BV(ADPS1)  // /4
#else
#    define ADC_PRESCALER _BV(ADPS0)  // /2
#endif