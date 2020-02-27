/*
 * File:   VC.c
 * Author: Abdelrhman Sayed
 *
 * Created on 15 JAN , 2020, 01:39 PM
 */


#include <xc.h>
#include "VC.h"
#include"SW.h"
#include "Main.h"
#include"Motor.h"
#include"Timer.h"
#include "Port.h"

/*Periodic Tick for Update*/
#define VC_Tick_time (20)

/* Number of m seconds to triger the event of pressure switch*/
#define Presuure_seconds_TRIGER (30000)


/*create static variable for speed type*/
static tVC_Motor_speed Motor_speed ; 

/*Function to handle switches state*/
static void handling_switch_events(void);

/*static variables to count 30 sec*/
static uint16 PRESSURE_COUNTER ;



void VC_Init(tVC_Motor_speed speed)
{
    
    /*initialize speed type [enum] variable*/
    Motor_speed = speed;
    
    /*set intial speed of the motor (motor module)*/
    MOT_Init(speed);
    
    //Initialize  alarm Led
    GPIO_InitPortPin(LED_PRESSURE_ALARM_DR,GPIO_PIN_3,GPIO_OUT);
    GPIO_WritePortPin(LED_PRESSURE_ALARM_CR,GPIO_PIN_3,0);
    //initialize the counter of pressure switch
    PRESSURE_COUNTER = 0;
    
}






void VC_update(void)
{
    
    
     static uint8 VC_counter = 10;
     
     /* Check if it is time for the VC_Update to run */
     VC_counter += TMR_TICK_MS;
     
     /*return if is not my tick */
     if(VC_counter != VC_Tick_time)
     {
         return;
     }
    
     VC_counter = 0;
    
     //handle the switch state change
    /*
     * update the speed depend on the state machine
     * 
     * If (+) is pre=pressed & speed is not max, speed increases by 1 step
     * If (-) is pre=pressed & speed is not min, speed decreases by 1 step
     * If(P) is pressed & press time == 30 seconds & speed is not min, speed decreases by 1 step. 
     * 
     */
   handling_switch_events();    
    
    // set the motor speed at motor module
   MOT_SetTargetAngle(Motor_speed);
}




tVC_Motor_speed VC_GetSpeed(void)
{
    /*return the current speed of the vacuum cleaner*/
    return Motor_speed;
    
}


 static void handling_switch_events(void)
{
    
     /*handle switch state change */
    if(SW_GetState(SW_PLUS) == SW_PRE_PRESSED)
    {
        switch(Motor_speed)
        {
            case Min_speed:
            {
                Motor_speed = Mid_speed;
                break;
            }
            
            case Mid_speed:
            {
                Motor_speed = Max_speed;
                break;
            }
            
            case Max_speed:
            {
                // Do nothing
                break;
            }
            
           /* Should not be here */
            default: 
                break;
            
            
        }
                
        // increase the speed (+)
    }
    
    if(SW_GetState(SW_MINUS) == (SW_PRE_PRESSED))
    {
            // decrease the speed (-)
        switch (Motor_speed)
        {
            case Min_speed:
            {
                // do noting
                break;
            }
            
            case Mid_speed:
            {
                Motor_speed = Min_speed;
                break;
            }
            
            case Max_speed:
            {
                Motor_speed = Mid_speed;
                break;
            }
            
           /* Should not be here */
            default: 
                break;
            
            
        }
         
    }
    
     if(SW_GetState(SW_PRE) == (SW_PRESSED))
       { 

                /* Check if it is time for the PRE to run */

                PRESSURE_COUNTER += VC_Tick_time;

                /*return if is not my tick */
             if(PRESSURE_COUNTER != Presuure_seconds_TRIGER)
             {
                 return;
             }

              PRESSURE_COUNTER = 0;


             switch(Motor_speed)
             {
                 case Min_speed:
                 {
                   /*Do nothing*/
                     break;
                 }

                 case Mid_speed:
                 {
                     Motor_speed = Min_speed;
                     break;
                 }

                 case Max_speed:
                 {
                     Motor_speed = Mid_speed;
                     break;
                 }

                 /*should not be here*/
                 default:
                     break;
             }
         
         
         
       }
    
     else
     {
           PRESSURE_COUNTER = 0;
           //Turn off Alarm led
           GPIO_WritePortPin(LED_PRESSURE_ALARM_CR,GPIO_PIN_3,0);
     }
        
 }
 
