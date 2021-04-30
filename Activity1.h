/**
 * @file project-config.h
 */

#ifndef ACTIVITY1_H_INCLUDED
#define ACTIVITY1_H_INCLUDED

/**
 *Some Macro Definitions
 */
#define F_CPU 16000000UL 	/** Input Clock Frequency of MCU is 16 MHz */
#define LED_PORT (PORTB)    /** SELECT LED Port Number */
#define LED_PIN  (PB0)      /** SELECT LED Pin number  */
#define SW_PORT (PORTD)     /** SELECT SWITCH Port number */
#define SW_PIN_1 (PD0)      /** SWITCH 0 Pin number */
#define SW_PIN_2 (PD1)      /** SWITCH 1 Pin number */

#include <avr/io.h>
#include <util/delay.h>

/**
 * @brief Initialize all the Peripherals and pin configurations
 *
 */
void peripheral_init();

/**
 * @brief Main function where the code execution starts
 * @return int Return 1 if both switches are ON else returns 0
 * @note PORTB0 is in sink config. i.e when pin is Low, the LED will turn OFF
 * @note PORTB0 is in sink config. i.e when pin is High, the LED will turn ON
 * @note PORTD2 and PORTD3 have pull up register. i.e if the pins are open, the pins are inherently high
 */
int initialize_led();

#endif /* ACTIVITY1_H_INCLUDED */
