#ifndef __SDD_H__
#define __SDD_H__

#include "Main.h"
#include "Port.h"

/* Number of SSDs */
/**num of 7-segment*/
#define N_SSD           (3)

/**7seg current state*/
/*power levels*/
typedef enum
{
    SSD_FIRST,
    SSD_SECONED,
    SSD_THIRD
}tSSD;

/* SSD states */
typedef enum
{
    SSD_OFF = 0,
    SSD_ON = 1
}tSSD_State;

/* SSD symbols */
typedef enum
{
    SSD_Low = 0,
    SSD_Mid,
    SSD_High,
    SSD_NULL /**when i want to blink*/
}tSSD_Symbol;

void SSD_Init(tSSD ssd);
void SSD_Update(void);
/**set symbol*/
void SSD_SetValue(tSSD ssd, tSSD_Symbol ssd_symbol);
/**get symbol*/
tSSD_Symbol SSD_GetValue(tSSD ssd);
tSSD_State SSD_GetState(tSSD ssd);
void SSD_SetState(tSSD ssd, tSSD_State state);
/**do blinking*/
void SSD_SetDotState(tByte state);


#endif // __SDD_H__
