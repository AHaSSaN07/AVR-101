#include <avr/io.h>
#define F_CPU 4000000UL
#include <util/delay.h>
#include <avr/sfr_defs.h>
int main(void)
{
	DDRB =0b11111111;
	DDRC &= 0b11111100;
	PORTC |=0b00000011;
	uint8_t x =1;
	while(1)
	{
		if((PINC&0b00000011) ==0b00000011)
		{
			PORTB =0b00000000;
		}
		else if((PINC&0b00000011) ==0b000000001)
		{
			PORTB =x;
			_delay_ms(500);
			x= x<<1;
			if(x==0)x=1;
		}
		else if((PINC&0b00000011) ==0b00000010)
		{
			PORTB =x;
			_delay_ms(500);
			x= x>>1;
			if(x==0)x=128;
		}
	}
}
