#ifndef SYSTICK_H_
#define SYSTICK_H_

//#include <p32xxxx.h>					//we use c32 compiler
#include "gpio.h"


//initialize the timer
void systick_init(void);

//activate the isr handler
uint32_t ticks(void);

//ticks per us - arduino styled function
#define cyclesPerMicrosecond()		(F_PHB / 1000000ul)
#define millis()					(ticks() / (F_PHB / 1000))
#define micros()					(ticks() / (F_PHB / 1000000ul))

//precision delays using ticks()
void systick_delayms(uint32_t ms);
void systick_delayus(uint32_t us);


#endif //tmr1_h_
