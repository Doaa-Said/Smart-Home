/******************************************************************************
 *
 * Module: FLAME SENSOR
 *
 * File Name: FLAMESENSOR.h
 *
 * Description: header file for the flame sensor driver
 *
 * Author: Doaa Said
 *
 *******************************************************************************/
#ifndef FLAMESENSOR_H_
#define FLAMESENSOR_H_
#include "../MCAL/std_types.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
/*flame sensor HW Port and Pin Id */
#define FLAMESENSOR_PORT_ID  PORTD_ID
#define FLAMESENSOR_PIN_ID   PIN2_ID


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :Function responsible for Initializing
 *  the flame sensor pin direction.
 */
void FlameSensor_init(void);


/*
 * Description :Function responsible for Reading
 *  the value from the flame sensor and returns it.
 */

uint8 FlameSensor_getValue(void);



#endif /* FLAMESENSOR_H_ */
