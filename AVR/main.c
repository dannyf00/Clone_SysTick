#include "gpio.h"						//we use gpio functions
#include "systick.h"					//we use systick
//hardware configuration
//end hardware configuration

//global defines
#define LED_PORT		PORTB
#define LED_DDR			DDRB
#define LED				(1<<0)			//led on PB0
#define LED_DLY			10				//delays, in ms

//global variables


int main(void) {
	uint32_t time0, time1;

	mcu_init();							//reset the mcu
	systick_init();						//initialize systick
	IO_OUT(LED_DDR, LED);				//led as output
	ei();
	while (1) {
		IO_FLP(LED_PORT, LED);			//flip the led

		time0=ticks();
		systick_delayms(LED_DLY);		//delay_ms(LED_DLY);				//waste time
		time1=ticks() - time0;
		if (time1>10) NOP();
	}
}
