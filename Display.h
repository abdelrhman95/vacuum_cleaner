

/* 
 * File:   DISP
 * Author: Abdelrhman Sayed
 * Comments: its a driver for The SSD modular to show speeds of the motor
 * Revision history: 15/1/2020
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef _Display_H
#define	_Display_H

#include <xc.h> // include processor files - each processor file is guarded.  



void DISP_Init(void);
void DISP_Update(void);


#endif	/* XC_HEADER_TEMPLATE_H */

