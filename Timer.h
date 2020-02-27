/* 
 * File:        Timer.h
 * Author:      Abdelrhman Sayed
 * Comments:    OS module use timer ISR to simulate ZCD  
 * Revision history: 19/1/2020
 */




#ifndef __TIMER_H__
#define __TIMER_H__
#include "Main.h"


#define TMR_TICK_MS				(10) /* HCF(P1, P2, ..., PN) */

void TMR0_Init(void);
void TMR0_Start(void);
tByte TMR0_CheckOverFlow(void);
void TMR0_Stop(void);
void TMR0_ISR(void); /* ISR @  vector 0 */

#endif
