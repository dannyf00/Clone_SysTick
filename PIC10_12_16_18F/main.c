#include "config.h"						//configuration words
#include "gpio.h"                           //we use gpio functions
#include "systick.h"						//we use systick

//hardware configuration
#define LED_PORT		GPIO
#define LED_DDR			TRISIO
#define LED				(1<<0)			//led on GPIO0
#define LED_DLY			10				//waste some time
//end hardware configuration

//global defines

//global variables

//isr
void interrupt isr(void) {
	if (T0IF) tmr0_isr();				//tmr0 isr
	
	//other isrs here
}
	
int main(void) {
	uint32_t time0, time1;
	uint16_t msb, lsb;

	mcu_init();							//reset the mcu
	systick_init();						//initialize systick
	IO_OUT(LED_DDR, LED);				//led as output
	ei();
	while (1) {
		IO_FLP(LED_PORT, LED);			//flip the led

		time0=ticks();
		systick_delayms(LED_DLY);		//delay_ms(LED_DLY);				//waste time
		time1=ticks() - time0;
		lsb = time1; msb = time1>>16;
		if (time1>10) NOP();
	}
}

