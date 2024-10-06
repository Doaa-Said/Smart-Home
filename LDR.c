/******************************************************************************
 *
 * Module: LDR
 *
 * File Name: LDR.h
 *
 * Description: source file for the LDR driver
 *
 * Author: Doaa Said
 *
 *******************************************************************************/
#include "LDR.h"
#include "../MCAL/ADC.h"

uint16 LDR_getLightIntensity(void) {
	uint8 intensity_value = 0;

	uint16 adc_value = 0;

	/* Read ADC channel where the LDR is connected */
	adc_value = ADC_readChannel(LDR_SENSOR_CHANNEL_ID);

	/* Calculate intensity from the ADC value*/
	intensity_value = (uint16) (((uint32) adc_value
			* LDR_SENSOR_MAX_LIGHT_INTENSITY * ADC_REF_VOLT_VALUE)
			/ (ADC_MAXIMUM_VALUE * LDR_SENSOR_MAX_VOLT_VALUE));

	return intensity_value;

}

