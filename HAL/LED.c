/******************************************************************************
 *
 * Module: LED
 *
 * File Name: lED.c
 *
 * Description: Source file for the LED driver
 *
 * Author: Doaa Said
 *
 *******************************************************************************/
#include "LED.h"

#include "../MCAL/GPIO.h"

void LEDS_init(void) {
	// Set the direction of the LED pins to output
	GPIO_setupPinDirection(LED_RED_PORT_ID, LED_RED_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(LED_GREEN_PORT_ID, LED_GREEN_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(LED_BLUE_PORT_ID, LED_BLUE_PIN_ID, PIN_OUTPUT);
	// Turn off all LEDs initially
	GPIO_writePin(LED_RED_PORT_ID, LED_RED_PIN_ID, LED_OFF);
	GPIO_writePin(LED_GREEN_PORT_ID, LED_GREEN_PIN_ID, LED_OFF);
	GPIO_writePin(LED_BLUE_PORT_ID, LED_BLUE_PIN_ID, LED_OFF);

}
void LED_on(LED_ID id) {
	// Check if the LED ID is valid
	if (id >= NUM_OF_LEDS) {
		/* Do Nothing */
	} else {
		// Turn on the specified LED based on the id
		switch (id) {
		case RED_ID:
			GPIO_writePin(LED_RED_PORT_ID, LED_RED_PIN_ID, LED_ON);
			break;
		case GREEN_ID:
			GPIO_writePin(LED_GREEN_PORT_ID, LED_GREEN_PIN_ID, LED_ON);
			break;
		case BLUE_ID:
			GPIO_writePin(LED_BLUE_PORT_ID, LED_BLUE_PIN_ID, LED_ON);
			break;
		}

	}

}
void LED_off(LED_ID id) {
	// Check if the LED ID is valid
	if (id >= NUM_OF_LEDS) {
		/* Do Nothing */
	} else {
		// Turn off the specified LED based on the id
		switch (id) {
		case RED_ID:
			GPIO_writePin(LED_RED_PORT_ID, LED_RED_PIN_ID, LED_OFF);
			break;
		case GREEN_ID:
			GPIO_writePin(LED_GREEN_PORT_ID, LED_GREEN_PIN_ID, LED_OFF);
			break;
		case BLUE_ID:
			GPIO_writePin(LED_BLUE_PORT_ID, LED_BLUE_PIN_ID, LED_OFF);
			break;
		}

	}

}

