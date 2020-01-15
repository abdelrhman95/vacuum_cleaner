

/* 
 * File:   SW.h
 * Author: Abbdelrhman Sayed
 * Comments: File contains Switch states and types
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef _SW_H
#define	_SW_H


#include <xc.h> 

typedef enum
{
    SW_PLUS,
    SW_MINUS,
    SW_PRE
}tSW;

/*state type*/
typedef enum
{
    SW_RELEASED,
    SW_PRE_PRESSED,
    SW_PRESSED,
    SW_PRE_RELEASED
}tSW_State;

void SW_Init(void);
tSW_State SW_GetState(tSW sw);
void SW_Update(void);


#endif	

