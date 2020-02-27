#ifndef __PORT_H__
#define __PORT_H__

#include "Main.h"


/* Leds' pins */
#define LED_1_PORT_DR   (GPIO_PORTB_DATA)
#define LED_1_PORT_CR   (GPIO_PORTB_CONTROL)
#define LED_1_PIN       (GPIO_PIN_0)

#define LED_2_PORT_DR   (GPIO_PORTB_DATA)
#define LED_2_PORT_CR   (GPIO_PORTB_CONTROL)
#define LED_2_PIN       (GPIO_PIN_1)

#define LED_3_PORT_DR   (GPIO_PORTB_DATA)
#define LED_3_PORT_CR   (GPIO_PORTB_CONTROL)
#define LED_3_PIN       (GPIO_PIN_2)

#define LED_4_PORT_DR   (GPIO_PORTB_DATA)
#define LED_4_PORT_CR   (GPIO_PORTB_CONTROL)
#define LED_4_PIN       (GPIO_PIN_3)

/* Fill missing code below */
/* Switches */
#define SW_PLUS_PORT_DR     (GPIO_PORTB_DATA)
#define SW_PLUS_PORT_CR     (GPIO_PORTB_CONTROL)
#define SW_PLUS_PIN         (GPIO_PIN_0)

#define SW_MINUS_PORT_DR    (GPIO_PORTB_DATA)
#define SW_MINUS_PORT_CR    (GPIO_PORTB_CONTROL)
#define SW_MINUS_PIN        (GPIO_PIN_1)

/*pressure switch */
#define SW_PRE_PORT_DR      (GPIO_PORTB_DATA)
#define SW_PRE_PORT_CR      (GPIO_PORTB_CONTROL)
#define SW_PRE_PIN          (GPIO_PIN_2)

/* SSD */
#define SSD_DATA_PORT_DR        (GPIO_PORTD_DATA)
#define SSD_DATA_PORT_CR        (GPIO_PORTD_CONTROL)

#define SSD_FIRST_DR       (GPIO_PORTB_DATA)
#define SSD_FIRST_CR       (GPIO_PORTB_CONTROL)
#define SSD_FIRST_PIN      (GPIO_PIN_7)

#define SSD_SECONED_DR      (GPIO_PORTB_DATA)
#define SSD_SECONED_CR      (GPIO_PORTB_CONTROL)
#define SSD_SECONED_PIN     (GPIO_PIN_6)

#define SSD_THIRD_DR     (GPIO_PORTB_DATA)
#define SSD_THIRD_CR     (GPIO_PORTB_CONTROL)
#define SSD_THIRD_PIN    (GPIO_PIN_5)


/*Motor pins*/
#define Motor_DR (GPIO_PORTC_DATA)
#define Motor_CR (GPIO_PORTC_CONTROL)
#define Motor_PIN (GPIO_PIN_3)



//LED FOR PRESSURE ALARM  
#define  LED_PRESSURE_ALARM_DR (GPIO_PORTB_DATA)
#define  LED_PRESSURE_ALARM_CR  (GPIO_PORTB_CONTROL)
#define  LED_PRESSURE_ALARM_PIN  (GPIO_PIN_3)







#endif // __PORT_H__
