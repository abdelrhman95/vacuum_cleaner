/*
 * File:   Motor.c
 * Author: Abdelrhman Sayed
 *
 * Created on 15 JAN, 2020, 10:57 PM
 */


#include <xc.h>
#include "Motor.h"
#include"Port.h"
#include "VC.h"
#include "Main.h"
#include "Timer.h"

#define _XTAL_FREQ 8000000
 
#define FIRING_PULSE_WIDTH (100)

/*start-up*/
#define Intial_firing_angle (170)

/*Time between to invokation to update function*/
#define MOTOR_UPDATE_TICK (20)

/* KURZ NUMBER TO REDUCE HERMONICS*/
#define KURZ_CONST (10)

/*every 40ms Actual angle would move towards target angle by one degree 
 * on switching mode to achieve soft starting*/

#define SOFT_SW_TIME (40)


static uint8 Actual_angle;

/*static variable speed target*/
static tVC_Motor_speed Target_firing_angle;

/*static variable for motor state */
static Mot_states motor_state;

/* count the number of ms elapsed between two addition process 
 * to actual angle in soft switching mode*/
static uint8 Switching_Counter ;


void MOT_Init(tVC_Motor_speed M)
{
  
    //init motor pin
    GPIO_InitPortPin(Motor_DR, Motor_PIN, GPIO_OUT);
    GPIO_WritePortPin(Motor_CR,Motor_PIN, 0);
    
    
    //init motor initial actual firing angle 
    Actual_angle = Intial_firing_angle;
   
    //initialize initial target angle 
    Target_firing_angle = M;    
    
    //initialize current state
    motor_state = Mot_Switching_state;

    // reset the switching counter
    Switching_Counter = 0;
    
}


void MOT_Update(void)
{
    /* create static variable to count time*/
    static uint8 motor_tick_counter = 10;   

    // increment motor tick counter
    motor_tick_counter += TMR_TICK_MS;

    // check if it's my tick
    if(motor_tick_counter != MOTOR_UPDATE_TICK) return;

    //reset counter
    motor_tick_counter = 0;
    
    //in case of normal mode
    switch(motor_state)
    {   
        case   Mot_normal_state:
              //NORMAL STATE
              //Kurz algorithm
               //if actual > target   
            if(Actual_angle > Target_firing_angle)
            {                
                //true
                // actual speed -10
                Actual_angle -= KURZ_CONST;
            }   
            
            else
            {   
                //false 
                 //actual speed +10
                Actual_angle += KURZ_CONST;
            }   
            
            break;
            
        case    Mot_Switching_state:
                //switching mode
                //if actual angle = target angle
            if(Actual_angle == Target_firing_angle)
            {   /* true
                 * actual speed +=5
                 * current mode = normal mode 
                 */ 
                Actual_angle +=5;
                motor_state = Mot_normal_state;
            }    
            else
            {
                
                    //False
                    //increment soft switch counter
                 Switching_Counter += MOTOR_UPDATE_TICK;
                    // if soft switch counter = soft switch time 
                if(SOFT_SW_TIME == Switching_Counter)
                {  
                    /* true
                     * if target > actual 
                     * true increment actual
                     * false decrement actual
                     */
                     if(Actual_angle < Target_firing_angle)
                     {
                         Actual_angle ++ ;

                     }   

                     else
                     {
                            //false, decrement actual angle
                         Actual_angle --;
                     }     
                        // Reset counter
                     Switching_Counter = 0 ;
                }   
                
            }
                 break;
        default:
          break;
            
    } 
           
}




void MOT_SetTargetAngle(tVC_Motor_speed M)
{
    
    // set speed in target speed
   
    //if target angle == Target_firing_angle
    //true
    if(Target_firing_angle == M)
    {
        return;
    }
    
    
    //false
    //change the mode to Switching mode
    motor_state = Mot_Switching_state;
    Target_firing_angle = M;
        
}


//fun return actual

uint8 Get_actual(void)
{
    return Actual_angle;
}


void Firing_Pulse(void)
{
    //set motor pin is high
    GPIO_WritePortPin(Motor_DR,Motor_PIN, 1);
    //then delay 100us
    __delay_us(FIRING_PULSE_WIDTH);
    //and turn it off
     GPIO_WritePortPin(Motor_DR,Motor_PIN, 0);
    
}
