

/* 
 * File:   TIMER_1
 * Author: Abdelrhman sayed
 * Comments: Designed to make the firing angle 
 * Revision history: 19/1/2020
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef _TIMER1_H
#define	_TIMER1_H


/*
//TIMER 1 START AND STOP//
#define TMR1_START  (TMR1_START_FLAG = 1) 
#define TMR1_STOP   (TMR1_START_FLAG = 0)


//TIMER INTERUPT FLAG OPERATIONS//
#define TMR1_GET_FLAG			(TMR1_I_FLAG)
#define TMR1_CLEAR_FLAG			(TMR1_I_FLAG = 0)
*/

void TMR1_Init(void);
void TMR1_Start(uint16 Degree);
void TMR1_Stop(void);
uint8 TMR1_CheckOverflow(void);
void TMR1_ISR(void);



#endif	/* _TIMER1_H */

