//#include <lpc122x.h>				//we use lpc122x
#include "gpio.h"					//we use F_CPU + gpio functions
#include "delay.h"					//we use software delays
#include "systick.h"				//we use systick
#include "dhry.h"					//we use dhrystone benchmark
#include "tmr32b1_pwm.h"

//hardware configuration
#define LED_DLY			100			//counts
//end hardware configuration

//global defines

//global variables
uint32_t tmp;

//flip led
void led_flp(void) {
	//static int count=0;							//count
	FIO_FLP(LED_PORT, LED);					//flip the led
}

//set led
void led_set(void) {
	//static int count=0;							//count
	FIO_SET(LED_PORT, LED);					//flip the led
}

//clr led
void led_clr(void) {
	//static int count=0;							//count
	FIO_CLR(LED_PORT, LED);					//flip the led
}


int main(void) {
	uint32_t time0, time1;

	mcu_init();									//reset the  mcu
	systick_init();								//reset systick
	//tmr32b1_pwminit(1);
	//tmr32b1_setdc1(10);
	//IO_OUT(LED_PORT, LED);						//led3/4 as output
	//tmp=F_CPU;									//read f_cpu - for debugging
	ei();
	while (1) {
		//IO_FLP(LED_PORT, LED);				//flip led

		time0=ticks();							//time stamp time0
		//dhrystone();							//benchmark
		systick_delayms(LED_DLY);				//benchmark test
		time1=ticks() - time0;					//time stamp and calculate elapsed time
		if (time1>10) NOP();					//break point
	};
}
