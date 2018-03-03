#include <avr/io.h>
#define F_CPU 4000000UL
#include <util/delay.h>
#include <avr/sfr_defs.h>
int main(void)
{
	DDRB |= 1<< PINB0; // pin0 =1
	DDRB &= ~(1<<PINB1); // pin1 =0
	PORTB |= 1<<PINB1;
	while(1)
	{
		//PORTB ^= 1<<PINB0;
		if(bit_is_clear(PINB,1))
		{
			PORTB = 1<<PINB0;
		}
		else 
		{
			PORTB = 0<<PINB0;
		}
	}
}
