/*
 * Author List:Sakshi Gupta
 * Filename: led blinking.c
 * Functions: LED_pin_config(),glow_led1(),glow_led2(),led_off() , main()
 * Global Variables: NONE
 *
 */
#include<avr/io.h>
#include<avr/interrupt.h>
volatile uint8_t count; //global variable 
/*
 * Function Name: main
 * Input: None
 * Output: int to inform the caller that the program exited correctly or incorrectly (C code standard)
 * Logic: initializes the timer and enable all interrupts
 * Example Call: Called automatically by the Operating System
 *
 */
int main()
{
	DDRJ=0xFF;
	PORTJ=0xFF;
	TCCR0B|=(1<<CS02); //set up timer with 256 prescaling

	TIMSK0|=(1<<TOIE0); //enable overflow interrupt

	TCNT0=0;  //initialize counter
	count=0;
	sei();
	//loop forever
	while(1)
	{};
}
/****************************************************************
* Function: Interrupt Service Routine
* Input: none
* Output: none
* Logic: whenever interrupt0 occurs it executes this routine
*        and after this it returns to the main function
*****************************************************************/
ISR(TIMER0_OVF_vect)
{
	count++;
	if(count==45) //check if the count reaches 45
	{
		PORTJ=PORTJ ^ 0xFF; //toggles the led
		count=0;
	}

}



