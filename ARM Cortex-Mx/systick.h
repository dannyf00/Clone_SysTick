//ARMduino port for ARM family of Cortex-M chips
//software environment: gcc-arm


#ifndef _SYSTICK_H
#define _SYSTICK_H

#include "gpio.h"										//we use stm32f10x

//global defines

//global variables
//initialize the timer
void systick_init(void);

//activate the isr handler
uint32_t ticks(void);									//109 ticks

//ticks per us - arduino styled function
#define micros()					(ticks() / cyclesPerMicrosecond())	//204 ticks
#define millis()					(ticks() / cyclesPerMillisecond())	//309 ticks
#define cyclesPerMillisecond()		(F_CPU / 1000ul)
#define cyclesPerMicrosecond()		(F_CPU / 1000000ul)

//precision delays using ticks()
void systick_delayms(uint32_t ms);
void systick_delayus(uint32_t us);

#endif
