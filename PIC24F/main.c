#include "config_c30.h"					//configuration words - for C30. Use config.h for XC16
#include "gpio.h"
#include "delay.h"					//we use software delays
#include "systick.h"					//we use systick for timing

//hardware configuration
#define LED_PORT			LATB
#define LED_DDR				TRISB
#define LED				(1<<0)
#define LED_DLY				10		//delay, in ms
//end hardware configuration

//global defines

//global variables


int main(void) {
	uint32_t time0, time1;

	mcu_init();					//reset the mcu
	systick_init();					//initialize systick
	IO_OUT(LED_DDR, LED);				//led as output
	ei();						//enable global interrupts
	while (1) {
		IO_FLP(LED_PORT, LED);			//flip the led

		time0=ticks();
		systick_delayms(LED_DLY);		//delay_ms(LED_DLY);				//waste time
		time1=ticks() - time0;
	}
}
