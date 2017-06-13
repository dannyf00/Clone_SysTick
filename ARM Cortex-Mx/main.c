#include "gpio.h"					//we use F_CPU + gpio functions
#include "systick.h"					//we use systick

//hardware configuration
#define LED_DLY			100			//counts
//end hardware configuration

//global defines

//global variables

int main(void) {
	uint32_t time0, time1;

	mcu_init();					//reset the  mcu
	systick_init();					//reset systick
	ei();
	while (1) {
		time0=ticks();				//time stamp time0
		//dhrystone();				//benchmark
		systick_delayms(LED_DLY);		//benchmark test
		time1=ticks() - time0;			//time stamp and calculate elapsed time
	};
}
