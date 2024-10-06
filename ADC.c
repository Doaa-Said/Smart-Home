/******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.c
 *
 * Description: Source file for the ATmega32 ADC driver
 *
 * Author: Doaa Said
 *
 *******************************************************************************/
#include "ADC.h"
#include "common_macros.h"

void ADC_init(void) {
	ADCSRA_REG.Bits.ADEN_Bit = 1;/*ADC Enable*/
	ADMUX_REG.Bits.REFS0_Bit = REFS0;/*v reference*/
	ADMUX_REG.Bits.REFS1_Bit = REFS1;
#ifdef ADC_polling
	ADCSRA_REG.Bits.ADIE_Bit = 0;/*Disable Auto Trigger*/
#else
	ADCSRA_REG.Bits.ADIE_Bit=1;

#endif
	ADCSRA_REG.Bits.ADATE_Bit = 0;/*Disable Auto Trigger*/
	ADCSRA_REG.Bits.ADPS0_Bit = ADPS0;/*prescaler*/
	ADCSRA_REG.Bits.ADPS1_Bit = ADPS1;
	ADCSRA_REG.Bits.ADPS2_Bit = ADPS2;

}
uint16 ADC_readChannel(uint8 channel_num) {
	/* Choose the correct channel by setting the channel number in MUX4:0 bits */
	ADMUX_REG.Bits.MUX0_Bit = GET_BIT(channel_num, 0);
	ADMUX_REG.Bits.MUX1_Bit = GET_BIT(channel_num, 1);
	ADMUX_REG.Bits.MUX2_Bit = GET_BIT(channel_num, 2);
	ADMUX_REG.Bits.MUX3_Bit = 0;/*max no of channels is 8 bits*/
	ADMUX_REG.Bits.MUX4_Bit = 0;
	ADCSRA_REG.Bits.ADSC_Bit = 1;/*Start conversion write '1' to ADSC */
#ifdef ADC_polling
	while (!(ADCSRA_REG.Bits.ADIF_Bit))
		;/* Wait for conversion to complete, ADIF becomes '1' */
	ADCSRA_REG.Bits.ADIF_Bit = 1;/* Clear ADIF by write '1' to it :) */

	return ADC_REG;/* Read the digital value from the data register */
#endif
}

