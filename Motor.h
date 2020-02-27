
/* 
 * File:  Motor.h 
 * Author: Abdelrhman sayed 
 * Comments:
 * Revision history: 15/1/2020
 */

// This is a guard condition so that contents of this file are not included
// more than once.

#ifndef _MOTOR_H
#define	_MOTOR_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include"VC.h"
#include"Main.h"

typedef enum{
    
    Mot_normal_state,
    Mot_Switching_state
            
}Mot_states;

void MOT_Init(tVC_Motor_speed M);
void MOT_Update(void);
void MOT_SetTargetAngle(tVC_Motor_speed M);
uint8 Get_actual(void);
void Firing_Pulse(void);


#endif	/* _Motor_H */

