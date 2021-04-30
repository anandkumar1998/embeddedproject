#include "Activity1.h"

void peripheral_init(void)
{
	/* To Configure LED Pin */
	DDRB |= (1<<LED_PIN);
	/* To Configure Switch1 pin as Output */
	DDRD &= ~(1<<SW_PIN_0);
    SW_PORT |= (1<<SW_PIN_0);
	/* To Configure Switch2 pin as Output */
    DDRD &= ~(1<<SW_PIN_1);
    SW_PORT |= (1<<SW_PIN_1);
}

int initialize_led(){
    /* Check both Switch is closed or not; i.e Pins 0 and 1 of port D is low*/
    if(!(PIND&(1<<SW_PIN_0)) && !(PIND&(1<<SW_PIN_1))){
        /* Conditions to Turn on LED */
        LED_PORT |= (1<<LED_PIN);
        _delay_ms(2000);
        return 1;
    }
    else{
        LED_PORT &= ~(1<<LED_PIN);
        /* To Turn off LED*/
        _delay_ms(2000);
        return 0;
    }
}

