
/* 
 * File: VC header file  
 * Author:  Abdelrhman sayed
 * Comments: Pure software drives vacuum cleaner machine 
 * Revision history: 15 / 1 / 2020
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef _VC_H
#define	_VC_H

#include <xc.h> // include processor files - each processor file is guarded.  

/*
 * enum represent the speed and the Target firing angle of this speed
 * 
 * please edit this enum only if you need to 
 * modify the speed levels or firing angles 
 */

typedef enum{
    
    Min_speed = 140,
    Mid_speed = 90,
    Max_speed = 10       
    
}tVC_Motor_speed;





void VC_Init(tVC_Motor_speed speed);
void VC_update(void);
tVC_Motor_speed VC_GetSpeed(void);

#endif	/* XC_HEADER_TEMPLATE_H */

