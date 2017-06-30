#include "gpio.h"					//we use gpio
#include "delay.h"					//we use software delays
//#include "tmr0_mr.h"				//we use tmr0/compare match
#include "systick.h"				//we emulate systick using TMR0->MR0

//hardware configuration
#define LED_DLY			100			//waste some cycles
//end hardware configuration


int main() {
	uint32_t time0, time1;
	uint32_t tmp;

	mcu_init();						//reset the mcu
	IO_OUT(LED_DDR, LED);			//led as output
	systick_init();					//initialize systick
	ei();
	while (1) {
		IO_FLP(LED_PORT, LED);		//flip the led

		time0=ticks();				//time stamp time0
		systick_delayms(LED_DLY);	//waste sometime
		//delayms(LED_DLY);			//waste sometime
		time1=ticks() - time0;		//calculate time elapsed
		if (time1) NOP();			//break point

	}
  	return 0;
}
