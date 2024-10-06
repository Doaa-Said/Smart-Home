/******************************************************************************
 *
 * Module: LED
 *
 * File Name: LED.h
 *
 * Description: header file for the LED driver
 *
 * Author: Doaa Said
 *
 *******************************************************************************/
#ifndef LED_H_
#define LED_H_
#include "../MCAL/std_types.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
/* LEDS HW Ports and Pins Ids */
#define LED_RED_PORT_ID                 PORTB_ID
#define LED_RED_PIN_ID                  PIN5_ID

#define LED_GREEN_PORT_ID                PORTB_ID
#define LED_GREEN_PIN_ID                 PIN6_ID

#define LED_BLUE_PORT_ID                 PORTB_ID
#define LED_BLUE_PIN_ID                  PIN7_ID

/* LEDS logic configurations */
#define LED_ON   1
#define LED_OFF  0

#define NUM_OF_LEDS            3

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/
typedef enum {
	RED_ID, GREEN_ID, BLUE_ID
} LED_ID;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/*
 * Description :
 * Function responsible for Initializes all Leds (red, green, blue) pins direction
 and Turn off all the Leds.
 */
void LEDS_init(void);

/*
 * Description :
 * Function responsible for Turning on the specified LED
 */

void LED_on(LED_ID id);

/*
 * Description :
 * Function responsible for Turning off the specified LED.

 */
void LED_off(LED_ID id);

#endif /* LED_H_ */
