#include <avr/io.h>
#define F_CPU 4000000UL
#include <util/delay.h>

int main(void)
{
	DDRB |= 1<<PINB0;	
	while (1)
	{
		PORTB ^= 1<<PINB0;  //XOR op.
		_delay_ms(100);
	}
}
