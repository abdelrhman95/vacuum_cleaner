/*
 * File:   TIMER1.c
 * Author: Abdelrhman sayed
 *
 * Created on 16 january, 2020, 08:22 PM
 */


#include "Main.h"
#include "TIMER_1.h"
#include "Port.h"
#include"Motor.h"



void TMR1_Init(void)
{
    //Set up timer1 prescaler
    TMR1_SET_PRESCALER;
    
    // shut off oscillator mode
    OSCILLATOR_SHUT_OFF;
    //Enable internal clock
    TMR1_ENABLE_CLOCK;
    //Stop timer
    TMR1_DISABLE;
}
void TMR1_Start(uint16 Degree)
{
    //update the clock flag to start
    TMR1_CLEAR_FLAG;
    //load the timer register with the tick
    TMR1_Load_REGISTER(Degree);
    
    //Enable ISR
    TMR1_ENABLE_INTERRUPT;
    TMR1_peripheral_Enable;
    
    // Start the Timer1
    TMR1_ENABLE	;
}

void TMR1_Stop(void)
{
    //Stop the Timer1
    TMR1_DISABLE;
}
uint8 TMR1_CheckOverflow(void)
{
      // CHECK IF OVERFLOW FLAG 
     return TMR1_GET_FLAG;
}   


void TMR1_ISR(void)
{
    /*generate the firing Pulse */
    Firing_Pulse();
    
    
    /*stop TMR1*/
    TMR1_DISABLE;
    
    //clear flag
    TMR1_CLEAR_FLAG;
}