#include "gpio.h"							//we use gpio
#include "systick.h"						//we use systick

//hardware configuration
#define LED_PORT		GPIOD
#define LED				(1<<0)
#define LED_DLY			100					//delays, in ms
//end hardware configuration

//global defines

//global variables

void main(void) {
	uint32_t time0, time1;
	
	mcu_init();								//reset the mcu
	IO_OUT(LED_PORT, LED);					//led1 as output
	systick_init();							//initialize systick
	ei();									//enable interrupt
	while (1) {
		IO_FLP(LED_PORT, LED);				//flip the led
		
		time0=ticks();						//stampp the time
		systick_delayms(LED_DLY);			//waste some time
		time1=ticks() - time0;				//measure time elapsed
		if (time1>10) NOP();				//breakpoint
	};
}
