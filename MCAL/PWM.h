/******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.h
 *
 * Description: header file for the ATmega32 PWM driver
 *
 * Author: Doaa Said
 *
 *******************************************************************************/
#ifndef PWM_H_
#define PWM_H_
#include "std_types.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define TCCR0_REG  (*(volatile Timer0_TCCR0_Type*) 0x53 )

#define OCR0_REG  (*(volatile uint8*) 0x5C )

#define TCNT0_REG  (*(volatile uint8*) 0x52 )
/*select prescaler*/
#define CS00  1 /*clock = F_CPU/1024 CS00=1 CS01=0 CS02=1*/
#define CS01  0
#define CS02  1
/*select mode(inverting or non)*/
#define COM00  0 /* Clear OC0 when match occurs (non inverted mode) COM00=0 & COM01=1*/
#define  COM01  1
/*select configures of OC0(port num and pin)*/
#define PWM_OCO_PORT_ID                 PORTB_ID
#define PWM_OCO_PIN_ID                  PIN3_ID
/*Periodic time for pwm =1/61.03=0.01638 sec
 * Tick time=(1024/(16*10^6))=6.4*(10^-5) sec
 * PWM_MAX_TICKS=0.01638/6.4*(10^-5)=255
 */
#define PWM_MAX_TICKS      255

/*******************************************************************************
 *                      Types Declaration                                    *
 *******************************************************************************/
typedef union {
	uint8 Byte;
	struct {
		uint8 CS00_Bit :1;
		uint8 CS01_Bit :1;
		uint8 CS02_Bit :1;
		uint8 WGM01_Bit :1;
		uint8 COM00_Bit :1;
		uint8 COM01_Bit :1;
		uint8 WGM00_Bit :1;
		uint8 FOC0_Bit :1;
	} Bits;
} Timer0_TCCR0_Type;

/*******************************************************************************
 *                       Functions Prototypes                                 *
 *******************************************************************************/
/*
 * Description:
 * Generate a PWM signal with frequency 61.03Hz
 * Timer0 will be used with pre-scaler F_CPU/1024
 * F_PWM=(F_CPU)/(256*N) = (16*(10^6))/(256*1024) = 61.03Hz
 * Duty Cycle can be changed by updating the value
 * in The Compare Register
 */
void PWM_Timer0_Start(uint8 duty_cycle);

#endif /* PWM_H_ */

