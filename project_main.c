/**
 * @file project_main.c

 */

#include "Activity1.h"
#include "Activity2.h"
#include "Activity3.h"
#include "Activity4.h"

int main(void)
{
	
	peripheral_init();

	while(1){
		int status = 0;
		status = initialize_led();	
		if(status == 1){
			InitADC();	
			setup_pwm();	
			USARTInit(103);	
    		uint16_t temp = 0;
			temp = ReadADC(0); 
			_delay_ms(200);
			pwm_waveform(temp);	
			_delay_ms(200);
			USARTWriteChar(temp);	
		}
    }
	return 0;
}
