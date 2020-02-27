
#include "Main.h"
#include "Timer.h"
#include "SW.h"
#include "Display.h"
#include "SSD.h"
#include "Motor.h"
#include "VC.h"
#include "TIMER_1.h"

extern volatile uint8  ISR_FLAG;

void TMR0_Init(void)
{
	/* Add your code here! */
	TMR_SET_PRESCALER_256;
    
    /*Stop Timer*/
	TMR_DISABLE_CLOCK;
	/* End of your code!*/
}

void TMR0_Start(void)
{
	/* Add your code here! */
	TMR_CLEAR_FLAG;
    // load the timer register with the tick
	TMR_LOAD_REGISTER(ZCD_PERIOD_TICK_NUM);
    //Enable ISR
	TMR_ENABLE_INTERRUPT;
	GLOBAL_INTERRUPT_ENABLE;
    //Enable the clock
	TMR_ENABLE_CLOCK;
	/* End of your code!*/
}
uint8 TMR0_CheckOverFlow(void)
{
	/* Add your code here! */
	return TMR_GET_FLAG;
	/* End of your code!*/
}
void TMR0_Stop(void)
{
	/* Add your code here! */
	TMR_DISABLE_CLOCK;
	/* End of your code!*/
}

void TMR0_ISR(void)
{
    
	/* Add your code here! */

    //start firing (Timer_1)
    
    TMR1_Start(Get_actual());
   //GPIO_WritePortPin(GPIO_PORTC_DATA, GPIO_PIN_4,0);

    /* Reset the overflow Flag */
	TMR_CLEAR_FLAG;
    
     // load the timer register with the tick
	TMR_LOAD_REGISTER(ZCD_PERIOD_TICK_NUM);
    
     //set flag to process tasks
    ISR_FLAG = 1;
    
	/* End of your code!*/

}        