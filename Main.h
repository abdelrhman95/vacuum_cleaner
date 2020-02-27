/*
 * File:   Main.h
 * Author: Abdelrhman Sayed
 * Comments:File contains GPIO Configurations 
 * Revision history: 19/1/2020
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef __MAIN_H
#define	__MAIN_H

#include<xc.h>


/* Fill missing code below */
/* GPIO definitions */
/* GPIO Pins */
#define GPIO_PIN_0              (0)
#define GPIO_PIN_1              (1)
#define GPIO_PIN_2              (2)
#define GPIO_PIN_3              (3)
#define GPIO_PIN_4              (4)
#define GPIO_PIN_5              (5)
#define GPIO_PIN_6              (6)
#define GPIO_PIN_7              (7)

/* GPIO Port Registers redefinition */
#define GPIO_PORTA_DATA         (PORTA)
#define GPIO_PORTA_CONTROL      (TRISA)

#define GPIO_PORTB_DATA         (PORTB)
#define GPIO_PORTB_CONTROL      (TRISB)

#define GPIO_PORTC_DATA         (PORTC)
#define GPIO_PORTC_CONTROL      (TRISC)

#define GPIO_PORTD_DATA         (PORTD)
#define GPIO_PORTD_CONTROL      (TRISD)

#define GPIO_PORTE_DATA         (PORTE)
#define GPIO_PORTE_CONTROL      (TRISE)

/* GPIO direction setting */
#define GPIO_OUT                (0)
#define GPIO_IN                 (1)

/* GPIO port operations */
#define GPIO_InitPort(CONTROL, DIRECTION)   ((CONTROL) = ((DIRECTION)? (~0):(0)))
#define GPIO_WritePort(PORT, DATA)          ((PORT) = (DATA))
#define GPIO_ReadPort(PORT)                 (PORT)

/* GPIO port pin operations */
#define GPIO_InitPortPin(CONTROL, PIN, DIRECTION)   ((CONTROL) = (CONTROL & (~(1 << PIN)))|(DIRECTION << PIN))
#define GPIO_WritePortPin(PORT, PIN, DATA)          ((PORT) = (PORT & (~(1 << PIN)))|(DATA << PIN))
#define GPIO_TogglePortPin(PORT, PIN)          ((PORT) = ((PORT)  ^(1 << PIN)))
#define GPIO_ReadPortPin(PORT, PIN)                 (((PORT) & (1 << PIN)) >> (PIN))
/* End of code filling */

/* Timer 0 macros */
#define TMR_SET_PRESCALER_256	PS2 = 1;\
								PS1 = 1;\
								PS0 = 1;\
								PSA = 0

#define TMR_GET_FLAG			(TMR0IF)
#define TMR_CLEAR_FLAG			(TMR0IF = 0)

/*
 * Time calculation
 * timer0 is 8bit => max count is 256
 * CLKO input in the timer0 is (FOSC/4)
 * XTEL_FREQ = 8000000     => CLKO = 2000000 
 * we are using pre scaler so CLK =  ( CLKO / PRE SCALER )
 * PRE SCALER = 256  => CLK = 7812.5
 * TICK TIME = 1 / CLK   => TICK TIME = 128 us
 * OVERFLOW TIME = TICK TIME * 256  => 128 us * 256 = 32.768 ms
 * TICK TIME = 128 us
 * we need tick every 10 ms to simulate ZCD
 * 10 ms / 128 us = 78.125
 * TMR0 = 256 - (TICKS)
 */

#define ZCD_PERIOD_TICK_NUM (78)
#define TMR_LOAD_REGISTER(ZCD_PERIOD_TICK_NUM)		(TMR0 = 256 - (ZCD_PERIOD_TICK_NUM))

/* assume it's 5 ms till we make dynamic design*/
#define OS_TICK (10)

/** time*10^-3 in ms = 4/Fosc*N(256-TMR0)
where fosc: 8*10^6
     (prescaler) N: 256

*/
#define TMR_UPDATE_REGISTER(ZCD_PERIOD_TICK_NUM)		(TMR0 = 256 - (ZCD_PERIOD_TICK_NUM))

#define TMR_ENABLE_INTERRUPT	(TMR0IE = 1)
#define GLOBAL_INTERRUPT_ENABLE	(GIE = 1)

#define TMR_ENABLE_CLOCK		(T0CS = 0)
#define TMR_DISABLE_CLOCK		(T0CS = 1)



/*Timer 1 macros*/
#define TMR1_SET_PRESCALER		T1CKPS1 = 0;\
								T1CKPS0 = 1
								

#define TMR1_GET_FLAG			(TMR1IF)
#define TMR1_CLEAR_FLAG			(TMR1IF = 0)

/* 
 * Time calculation
 * timer1 is 16bit => max count is 65,536
 * CLKO input in the timer1 is (FOSC/4)
 * XTEL_FREQ = 8000000     => CLKO = 2000000 
 * we are using pre scaler so CLK =  ( CLKO / PRE SCALER )
 * PRE SCALER = 2  => CLK = 1000000 
 * TICK TIME = 1 / CLK   => TICK TIME = 1 us
 * OVERFLOW TIME = TICK TIME * max count  => 1 us * 65536 = 65.536 ms
 * TICK TIME = 1 us
 * we need to change the timer with accuracy of 1 degree
 * 1 degree = 10 ms / 180 = 55us
 * TMR1 = 65536 - ((DEGREE)* 55)
 */


#define TMR1_Load_REGISTER(Degree)		(TMR1 =65536 - ((Degree)*55))

#define TMR1_ENABLE_INTERRUPT	(TMR1IE = 1)

#define TMR1_ENABLE_CLOCK		(TMR1CS = 0)


#define TMR1_ENABLE				        (TMR1ON = 1)
#define TMR1_DISABLE			     	(TMR1ON = 0)

#define OSCILLATOR_SHUT_OFF             (T1OSCEN = 0)
#define TMR1_peripheral_Enable        (PEIE = 1)    



/* Standard data types */
typedef unsigned int tWord;
typedef unsigned char tByte;
typedef unsigned int uint16;
typedef unsigned char uint8;
#endif	

