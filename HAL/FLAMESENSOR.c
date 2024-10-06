/******************************************************************************
 *
 * Module: FLAME SENSOR
 *
 * File Name: FLAMESENSOR.h
 *
 * Description: source file for the flame sensor driver
 *
 * Author: Doaa Said
 *
 *******************************************************************************/
#include "FLAMESENSOR.h"

#include "../MCAL/GPIO.h"
#include "../MCAL/common_macros.h"

void FlameSensor_init(void) {
	// Set the direction of the Flame Sensor pin to input
	GPIO_setupPinDirection(FLAMESENSOR_PORT_ID, FLAMESENSOR_PIN_ID, PIN_INPUT);

}
uint8 FlameSensor_getValue(void) {
	// Read and return the state of the flame sensor pin
	return GPIO_readPin(FLAMESENSOR_PORT_ID, FLAMESENSOR_PIN_ID);

}
