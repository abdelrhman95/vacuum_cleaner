/*
 * File:   Display.c
 * Author: Abdelrhman Sayed
 *
 * Created on 15 JAN, 2020, 08:11 PM
 */


#include <xc.h>
#include "VC.h"
#include"SSD.h"
#include "Main.h"
#include "Display.h"
#include"Timer.h"
#define DISP_Time_Tick (20)


void DISP_Init(void)
{
    
    // init the SSD 
    
    SSD_Init(SSD_FIRST, SSD_NULL);
    SSD_Init(SSD_SECONED, SSD_NULL);
    SSD_Init(SSD_THIRD, SSD_NULL);
    
}



void DISP_Update(void)
{
    
    static uint16 DISP_counter = 0;
    
    /*Check if the time of the DISP_update to run*/
    DISP_counter += TMR_TICK_MS;
    
    if(DISP_counter != DISP_Time_Tick)
    {
        return ; 
    }
    
    DISP_counter = 0;
    
    
    
    
     switch(VC_GetSpeed())
        {
            case Min_speed:
            {
                 SSD_SetValue(SSD_FIRST, SSD_Low);
                 SSD_SetValue(SSD_SECONED, SSD_NULL);
                 SSD_SetValue(SSD_THIRD, SSD_NULL); 

                  break;
            }

            case Mid_speed:
            {
                 SSD_SetValue(SSD_FIRST, SSD_Low);
                 SSD_SetValue(SSD_SECONED, SSD_Mid);
                 SSD_SetValue(SSD_THIRD, SSD_NULL);
                 break;
            }

            case Max_speed:
            {
                SSD_SetValue(SSD_FIRST,SSD_Low);
                SSD_SetValue(SSD_SECONED,SSD_Mid);
                SSD_SetValue(SSD_THIRD,SSD_High);
                break;
            }

            default:
                break;

        }
    
}    
    
    


