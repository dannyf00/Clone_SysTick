#include "config.h"						//configuration words
#include "gpio.h"
#include "systick.h"					//we use systick

//hardware configuration
#define LED_PORT			LATB
#define LED_DDR				TRISB
#define LED					(1<<5)	//led on PB5
#define LED_DLY				100		//waste some time, in ms
//end hardware configuration

//global defines

//global variables

int main(void) {
	uint32_t time0, time1;
	
	mcu_init();						//reset the mcu
	systick_init();					//initialize systick time base
	IO_CLR(LED_PORT, LED); IO_OUT(LED_DDR, LED);		
	ei();							//enable global interrupts
	while (1) {
		IO_FLP(LED_PORT, LED);		//flip led

		time0=ticks();				//stamp time0
		systick_delayms(LED_DLY);	//waste some time
		time1=ticks() - time0;		//calculate time elapsed
		if (time1>10) NOP();		//break point
	}
}
