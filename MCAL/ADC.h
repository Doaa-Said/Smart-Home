/******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.h
 *
 * Description: header file for the ATmega16 ADC driver
 *
 * Author: Doaa Said
 *
 *******************************************************************************/
#ifndef ADC_H_
#define ADC_H_
#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56
#define ADMUX_REG  (*(volatile ADC_ADMUX_Type*) 0x27 )
#define ADCSRA_REG  (*(volatile ADC_ADCSRA_Type*) 0x26 )
#define ADC_REG     (*(volatile uint16*) 0x24 )
#define ADC_polling /*polling or interrupts*/

#define ADPS2 1 /*configuration to determine prescaler(128)*/
#define ADPS1 1
#define ADPS0 1
#define REFS1 1/*configuration to determine v_reference
(internal 2.56)*/
#define REFS0 1

/*******************************************************************************
 *                      Types Declaration                                    *
 *******************************************************************************/
typedef union {
	uint8 Byte;
	struct {
		uint8 MUX0_Bit :1;
		uint8 MUX1_Bit :1;
		uint8 MUX2_Bit :1;
		uint8 MUX3_Bit :1;
		uint8 MUX4_Bit :1;
		uint8 ADLAR_Bit :1;
		uint8 REFS0_Bit :1;
		uint8 REFS1_Bit :1;
	} Bits;
} ADC_ADMUX_Type;

typedef union {
	uint8 Byte;
	struct {
		uint8 ADPS0_Bit :1;
		uint8 ADPS1_Bit :1;
		uint8 ADPS2_Bit :1;
		uint8 ADIE_Bit :1;
		uint8 ADIF_Bit :1;
		uint8 ADATE_Bit :1;
		uint8 ADSC_Bit :1;
		uint8 ADEN_Bit :1;
	} Bits;
} ADC_ADCSRA_Type;
/*******************************************************************************
 *                       Functions Prototypes                                 *
 *******************************************************************************/
/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */
void ADC_init(void);

/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */
uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */

