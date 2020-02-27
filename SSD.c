
/*
 * File:   SSD.c
 * Author: Abdelrhman Sayed
 *
 * Created on 14 JAN, 2020, 08:11 PM
 */

#include "Main.h"
#include "Port.h"
#include "SSD.h"
#include"Timer.h"
/* SSD_Update period */
#define SSD_PERIOD_MS   (10)

/* Number of SSD symbols */
#define N_SSD_SYMBOLS   (4)


/* SSD Symbols port data values */
/**look-up table*/
static tByte SSD_Data[N_SSD_SYMBOLS] =
{
    0b00001000,
    0b01001000,
    0b01001001,
    0b00000000
};

/* Current SSD to be updated */
static tSSD SSD_current = SSD_FIRST;

/* SSD values */
/** Buffer*/
static tSSD_Symbol SSD_Values[N_SSD] = {SSD_NULL};

static tByte SSD_DotState = SSD_OFF;

static void SSD_Out(tSSD ssd, tSSD_Symbol ssd_symbol);

void SSD_Init(tSSD ssd,tSSD_Symbol symbol)
{
    /* Add your code here! */
    /* Initialize SSD data pins */
    GPIO_InitPort(SSD_DATA_PORT_CR, GPIO_OUT);
    SSD_Out(ssd, SSD_NULL);

    /* Initialize SSD control pin and turn SSD OFF*/
    switch (ssd)
    {
        case SSD_FIRST:
            GPIO_InitPortPin(SSD_FIRST_CR, SSD_FIRST_PIN, GPIO_OUT);
            SSD_Values[SSD_FIRST] = SSD_Low;
            break;
        case   SSD_SECONED:
            GPIO_InitPortPin(SSD_SECONED_CR, SSD_SECONED_PIN, GPIO_OUT);
            SSD_Values[SSD_SECONED] = SSD_Mid;
            break;
        case   SSD_THIRD:
            GPIO_InitPortPin(SSD_THIRD_CR, SSD_THIRD_PIN, GPIO_OUT);
            SSD_Values[SSD_THIRD] = SSD_High;
            break;
        /* Should not be here */
        default:
            break;
    }
    SSD_SetState(ssd, SSD_OFF);
    /* End of your code!*/
}

void SSD_Update(void)
{
    static tWord SSD_counter = 0;


    /* Check if it is time for the SSD_Update to run */
    SSD_counter += TMR_TICK_MS;

    if (SSD_counter != SSD_PERIOD_MS){
        return;
    }

    SSD_counter = 0;

    /* display current SSD value of the current SSD */
    /* Add your code here! */
    SSD_Out(SSD_current, SSD_Values[SSD_current]);

    if (SSD_current == SSD_THIRD)
    {
        SSD_current = SSD_FIRST;
    } else
    {
        SSD_current++;
    }
    /* End of your code!*/
}


void SSD_SetValue(tSSD ssd, tSSD_Symbol ssd_symbol)
{
    /* Add your code here! */
    SSD_Values[ssd] = ssd_symbol;
    /* End of your code!*/
}

tSSD_State SSD_GetState(tSSD ssd)
{
    tSSD_State ret = SSD_OFF;
    /* Add your code here! */
    switch (ssd)
    {
        case SSD_FIRST:
            ret = GPIO_ReadPortPin(SSD_FIRST_DR, SSD_FIRST_PIN);
            break;
        case   SSD_SECONED:
            ret = GPIO_ReadPortPin(SSD_SECONED_DR, SSD_SECONED_PIN);
            break;
        case   SSD_THIRD:
            ret = GPIO_ReadPortPin(SSD_THIRD_DR, SSD_THIRD_PIN);
            break;
        /* Should not be here */
        default:
            break;
    }
     /* End of your code!*/
     return ret;

}

void SSD_SetState(tSSD ssd, tSSD_State state)
{
    /* Add your code here! */
    switch (ssd)
    {
        case SSD_FIRST:
            GPIO_WritePortPin(SSD_FIRST_DR, SSD_FIRST_PIN,state);
            break;
        case  SSD_SECONED:
            GPIO_WritePortPin(SSD_SECONED_DR, SSD_SECONED_PIN,state);
            break;
        case   SSD_THIRD:
            GPIO_WritePortPin(SSD_THIRD_DR, SSD_THIRD_PIN,state);
            break;
        /* Should not be here */
        default:
            break;
    }
     /* End of your code!*/
}




static  void SSD_Out(tSSD ssd, tSSD_Symbol ssd_symbol)
{
    /* Add your code here! */
    /* Turn off SSDs */
    SSD_SetState(SSD_FIRST, SSD_OFF);
    SSD_SetState(SSD_SECONED, SSD_OFF);
    SSD_SetState(SSD_THIRD, SSD_OFF);
    /* Output ssd_symbol on selected ssd */
    GPIO_WritePort(SSD_DATA_PORT_DR, SSD_Data[ssd_symbol]);

    /* Turn ssd ON */
    SSD_SetState(ssd, SSD_ON);

    /* End of your code!*/

}
