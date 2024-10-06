/******************************************************************************
 *
 * File Name: Smart_Home.c
 *
 * Description: Source file for the smart home application
 *
 * Author: Doaa Said
 *
 *******************************************************************************/

#include "../HAL/LCD.h"
#include "../HAL/LDR.h"
#include "../HAL/LED.h"
#include "../HAL/lm35_sensor.h"
#include "../HAL/FLAMESENSOR.h"
#include "../HAL/DC_MOTOR.h"
#include "../MCAL/ADC.h"
#include "../HAL/BUZZER.h"

// Main function
int main(void) {
	// Initialize peripherals
	ADC_init();            // Initialize ADC for sensor readings
	LCD_init();            // Initialize the LCD display
	DcMotor_Init();        // Initialize the DC motor
	LEDS_init();           // Initialize LEDs
	FlameSensor_init();    // Initialize flame sensor
	Buzzer_init();         // Initialize buzzer for alerts

	// Declare variables for light intensity, temperature, and flame status
	uint16 intensity;      // To store light intensity from LDR
	uint8 temp;            // To store temperature from LM35
	uint8 flame_flag;      // To indicate if flame is detected

	// Clear the LCD screen and set initial messages
	LCD_clearScreen();
	LCD_displayStringRowColumn(0, 4, "FAN is   ");  // Display fan status
	LCD_displayStringRowColumn(1, 0, "Temp=  ");    // Display temperature label
	LCD_displayStringRowColumn(1, 7, " LDR=   %"); // Display LDR intensity label

	for (;;) {
		// Read values from sensors
		intensity = LDR_getLightIntensity(); // Get light intensity
		temp = LM35_getTemperature();        // Get temperature
		flame_flag = FlameSensor_getValue(); // Get flame sensor value

		if (!flame_flag) // If no flame is detected
		{
			Buzzer_off(); // Turn off the buzzer

			// Control LEDs and display light intensity
			if (intensity <= (0.15 * LDR_SENSOR_MAX_LIGHT_INTENSITY)) {
				LED_on(RED_ID);     // Turn on red LED
				LED_on(GREEN_ID);   // Turn on green LED
				LED_on(BLUE_ID);    // Turn on blue LED
				LCD_moveCursor(1, 12); // Move cursor to display intensity

				// Display LDR intensity as a percentage
				if (intensity >= 100) {
					LCD_intgerToString(
							((float) intensity / LDR_SENSOR_MAX_LIGHT_INTENSITY)
									* 100.0);
				} else {
					LCD_intgerToString(
							((float) intensity / LDR_SENSOR_MAX_LIGHT_INTENSITY)
									* 100.0);
					// Print space for alignment
					LCD_displayCharacter(' ');
				}
			} else if ((intensity >= (0.16 * LDR_SENSOR_MAX_LIGHT_INTENSITY))
					&& (intensity <= (0.5 * LDR_SENSOR_MAX_LIGHT_INTENSITY))) {
				LED_on(RED_ID);     // Turn on red LED
				LED_on(GREEN_ID);   // Turn on green LED
				LED_off(BLUE_ID);   // Turn off blue LED
				LCD_moveCursor(1, 12); // Move cursor to display intensity

				// Display LDR intensity as a percentage
				if (intensity == 100) {
					LCD_intgerToString(
							((float) intensity / LDR_SENSOR_MAX_LIGHT_INTENSITY)
									* 100.0);
				} else {
					LCD_intgerToString(
							((float) intensity / LDR_SENSOR_MAX_LIGHT_INTENSITY)
									* 100.0);
					/* In case the digital value is  two or one digits print space in the next digit place */
					LCD_displayCharacter(' ');
				}
			} else if ((intensity >= (0.51 * LDR_SENSOR_MAX_LIGHT_INTENSITY))
					&& (intensity <= (0.7 * LDR_SENSOR_MAX_LIGHT_INTENSITY))) {
				LED_on(RED_ID);     // Turn on red LED
				LED_off(GREEN_ID);  // Turn off green LED
				LED_off(BLUE_ID);   // Turn off blue LED
				LCD_moveCursor(1, 12); // Move cursor to display intensity

				// Display LDR intensity as a percentage
				if (intensity == 100) {
					LCD_intgerToString(
							((float) intensity / LDR_SENSOR_MAX_LIGHT_INTENSITY)
									* 100.0);
				} else {
					LCD_intgerToString(
							((float) intensity / LDR_SENSOR_MAX_LIGHT_INTENSITY)
									* 100.0);
					/* In case the digital value is  two or one digits print space in the next digit place */
					LCD_displayCharacter(' ');
				}
			} else if (intensity > (0.7 * LDR_SENSOR_MAX_LIGHT_INTENSITY)) {
				LED_off(RED_ID);   // Turn off red LED
				LED_off(GREEN_ID); // Turn off green LED
				LED_off(BLUE_ID);  // Turn off blue LED
				LCD_moveCursor(1, 12); // Move cursor to display intensity

				// Display LDR intensity as a percentage
				if (intensity == 100) {
					LCD_intgerToString(
							((float) intensity / LDR_SENSOR_MAX_LIGHT_INTENSITY)
									* 100.0);
				} else {
					LCD_intgerToString(
							((float) intensity / LDR_SENSOR_MAX_LIGHT_INTENSITY)
									* 100.0);
					/* In case the digital value is  two or one digits print space in the next digit place */
					LCD_displayCharacter(' ');
				}
			}

			// Control fan speed based on temperature
			if (temp >= 40) {
				DcMotor_Rotate(A_CW, 100); // Full speed
				// fan_state=FAN_ON;
				LCD_displayStringRowColumn(0, 11, "ON "); // Display fan is ON
				LCD_moveCursor(1, 5);

				// Display temperature
				if (temp >= 100) {
					LCD_intgerToString(temp);
				} else {
					LCD_intgerToString(temp);
					/* In case the digital value is  two or one digits print space in the next digit place */
					LCD_displayCharacter(' ');
				}
			} else if (temp >= 35 && temp < 40) {
				DcMotor_Rotate(A_CW, 75); // Medium speed
				// fan_state=FAN_ON;
				LCD_displayStringRowColumn(0, 11, "ON "); // Display fan is ON
				LCD_moveCursor(1, 5);

				// Display temperature
				if (temp >= 100) {
					LCD_intgerToString(temp);
				} else {
					LCD_intgerToString(temp);
					/* In case the digital value is  two or one digits print space in the next digit place */
					LCD_displayCharacter(' ');
				}
			} else if ((temp >= 30) && (temp < 35)) {
				DcMotor_Rotate(A_CW, 50); // Low speed
				// fan_state=FAN_ON;
				LCD_displayStringRowColumn(0, 11, "ON "); // Display fan is ON
				LCD_moveCursor(1, 5);

				// Display temperature
				if (temp >= 100) {
					LCD_intgerToString(temp);
				} else {
					LCD_intgerToString(temp);
					/* In case the digital value is  two or one digits print space in the next digit place */
					LCD_displayCharacter(' ');
				}
			} else if ((temp >= 25) && (temp < 30)) {
				DcMotor_Rotate(A_CW, 25); // Very low speed
				// fan_state=FAN_ON;
				LCD_displayStringRowColumn(0, 11, "ON "); // Display fan is ON
				LCD_moveCursor(1, 5);

				// Display temperature
				if (temp >= 100) {
					LCD_intgerToString(temp);
				} else {
					LCD_intgerToString(temp);
					/* In case the digital value is  two or one digits print space in the next digit place */
					LCD_displayCharacter(' ');
				}
			} else if (temp < 25) {
				DcMotor_Rotate(Stop, 0); // Stop the motor
				// fan_state=FAN_OFF;
				LCD_displayStringRowColumn(0, 11, "OFF"); // Display fan is OFF
				LCD_moveCursor(1, 5);

				// Display temperature
				if (temp >= 100) {
					LCD_intgerToString(temp);
				} else {
					LCD_intgerToString(temp);
					/* In case the digital value is  two or one digits print space in the next digit place */
					LCD_displayCharacter(' ');
				}
			}
		} else // If flame is detected
		{
			LCD_clearScreen(); // Clear the screen
			LCD_displayStringRowColumn(0, 1, "Critical alert!"); // Display alert message
			Buzzer_on(); // Activate buzzer for alert
             flame_flag=FlameSensor_getValue();
			// Wait until the flame is no longer detected
			while (flame_flag){
				flame_flag=FlameSensor_getValue();
			}

			LCD_clearScreen(); // Clear the screen again
			LCD_displayStringRowColumn(0, 4, "FAN is    "); // Reset fan status display
			LCD_displayStringRowColumn(1, 0, "Temp=  "); // Reset temperature label
			LCD_displayStringRowColumn(1, 7, " LDR=   %"); // Reset LDR intensity label
		}
	}
}
