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

1. systick_init():     initialize the systick module. 24-bit downcounter.
2. ei():               enable global interrupts
3. ticks():            return systick ticks, 32-bit bit
4. millis():           time stamp, in milli seconds
5. micros():           time stamp, in micro seconds
6. systick_delayms():  delay in milli seconds
7. systick_delayus():  delay in micro seconds

User needs to specify the clock input to the "SysTick" module, in F_CPU (which is remapped to SystemCoreClock on CMSIS compliant systems).

A typical of those functions is for timing / benchmarking, as shownbelow
  
```
  systick_init();     //initialize the systick timer
  ei();               //enable global interrupt
  while (1) {
    time0=ticks();    //time stamp time0
    my_task();        //run user task to be timed
    time1=ticks() - time0;  //time1 measures time elapsed / taken by my_task()
    ...
  } 
```
Another typical use is for precision timing, either blocking or non-blocking:

Blocking:
  
```  
  systick_delayms(10);    //delay 10ms, blocking
  my_task();              //execute my_task after 10ms
```  
Non-blocking:

```
  time0 = millis();       //time stamp time0
  time1 = millis();       //time stamp time1
  if (time1 - time0 >= 10) {    //if 10ms has gone by
    time0 += 10;          //advance time0 - to eliminate jitter
    my_task();            //execute user task
  }
```
    
