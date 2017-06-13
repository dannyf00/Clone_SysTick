# Clone_SysTick
Create SysTick clones on popular MCUs

Code snippets and examples are provided for the following chip:
1. PIC24F/dsPIC
2. AVR
3. PIC10/12/16/18F
4. STM8
5. PIC32MX1xx/2xx
6. Cortex-M0/1/2/3/4/4F

General usage:

systick_init():     initialize the systick module. 24-bit downcounter.
ei():               enable global interrupts
ticks():            return systick ticks, 32-bit bit
millis():           time stamp, in milli seconds
micros():           time stamp, in micro seconds
systick_delayms():  delay in milli seconds
systick_delayus():  delay in micro seconds

User needs to specify the clock input to the "SysTick" module, in F_CPU (which is remapped to SystemCoreClock on CMSIS compliant systems).
