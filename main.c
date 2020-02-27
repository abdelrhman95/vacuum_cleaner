


#include <xc.h>

#include "Main.h"
#include "Port.h"
#include "SW.h"
#include "SSD.h"
#include "VC.h"
#include "Display.h"
#include "TIMER_1.h"
#include "Timer.h"
#include"Motor.h"
#define _XTAL_FREQ 8000000

// PIC16F877A Configuration Bit Settings

// 'C' source line config statements

// CONFIG
#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

volatile uint8 ISR_FLAG;


int main(void) {
    
   
    
    
    ISR_FLAG = 0;
    VC_Init(Mid_speed);
    TMR0_Init();
    TMR0_Start();
    TMR1_Init();
    DISP_Init();
    SW_Init();
   
   //test code
    GPIO_InitPortPin(GPIO_PORTC_CONTROL,GPIO_PIN_4 ,GPIO_OUT);
    GPIO_WritePortPin(GPIO_PORTC_DATA, GPIO_PIN_4,0);
    //end of test code
    
    while(1)
    {
        if(ISR_FLAG)
        {
            //Test code
            GPIO_TogglePortPin(GPIO_PORTC_DATA, GPIO_PIN_4);
            //tasks
            SSD_Update();
            SW_Update();
            DISP_Update();
            VC_update();
            MOT_Update();
            ISR_FLAG = 0;
        }
    }
    
 
   /* GPIO_InitPortPin(LED_4_PORT_CR, LED_4_PIN, GPIO_OUT);
   // GPIO_WritePortPin(LED_4_PORT_DR,LED_4_PIN,0) ;
    TMR0_Init();
    TMR1_Init();
    MOT_Init(Mid_speed);
    GLOBAL_INTERRUPT_ENABLE;
    TMR0_Start();
    while(1){}*/
}

void __interrupt() Generic_ISR()
{
    /* if timer1 ISR
     */
    if(TMR1_CheckOverflow())
    {
        TMR1_ISR();
    }
    
     
     /*if timer0 ISR
     */
    if(TMR0_CheckOverFlow())
    {
        TMR0_ISR();
    }
    
}  