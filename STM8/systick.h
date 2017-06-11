#ifndef _SYSTICK_H
#define _SYSTICK_H

//Using TIM4/6 as a timebase (cloning SysTick)
//Code does not rely on STM8S Standard Peripheral Library
//but it utilizes the STM8S.h file in the SPL
//TIMx prescaler configuration in systick.c

#include "gpio.h"							//we use systick

//hardware configuration
//end hardware configuration

//global defines

//global variables


//initialize the timer
void systick_init(void);

uint32_t ticks(void);

//ticks per us - arduino styled function
#define cyclesPerMicrosecond()		(F_CPU / 1000000ul)
#define millis()					(ticks() / (F_CPU / 1000))
#define micros()					(ticks() / (F_CPU / 1000000ul))

//precision delays using ticks()
void systick_delayms(uint32_t ms);
void systick_delayus(uint32_t us);


#endif
