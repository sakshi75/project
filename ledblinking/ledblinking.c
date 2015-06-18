/*
 * Author List:Sakshi Gupta
 * Filename: led blinking.c
 * Functions: LED_pin_config(),glow_led1(),glow_led2(),led_off() , main()
 * Global Variables: NONE
 *
 */
#include<avr/io.h>
#include<util/delay.h>
 /*
* Function Name: main
* Input: None
* Output: int to inform the caller that the program exited correctly or incorrectly (C code standard)
* Logic: initializes the timer and enable all interrupts 
* Example Call: Called automatically by the Operating System
*
*/
void main()
{
	LED_pin_config();
	while(1)
	{
		
                  glow_led1();
		_delay_ms(1000);
		glow_led2();
		_delay_ms(1000);
		led_off();
		_delay_ms(1000);

	}
}
void LED_pin_config(void)
{
	DDRJ = 0xFF;  //Commoncathode connectetd to PJ0
	PORTJ = 0xFF;
}
void glow_led1(void);
{
	PORTJ = 0xFD;  // Setting PORTJ 1 logic low to turn on LED 1
	
}
void glow_led2(void)
{
	PORTJ = 0xEF;   // Setting PORTJ 4 logic low to turn on LED 2
}
void led_off(void)
{
	PORTJ = 0xFF;
}	