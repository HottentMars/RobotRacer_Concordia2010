#include <avr/io.h>
#include <avr/interrupt.h>

void initADC(void);
uint16_t ReadADC(uint8_t);

int main (void)
{

	DDRD|=(1<<PD7);
	DDRD|=(1<<PD5);
	DDRD|=(1<<PD6);
	DDRB|=(1<<PB0);

	DDRB|=(1<<PB2);
	DDRB|=(1<<PB1);

	PORTD &= ~(1<<PD7);
	PORTD &= ~(1<<PD5);

	PORTD|=(1<<PD6);
	PORTB|=(1<<PB0);

	 //DDRB |= (1<<PB1); // Set LED1 as output
   //PORTB &= (0<<PB1);
 	
	uint16_t acdValue;
	initADC();
	
	PORTB |= (1<<PB1);
	PORTB |= (1<<PB2);
	
   //uint16_t shade1 = 1024 * 1.20/5;

	//uint16_t shade2 = 1024 * 4/5;
	
	uint16_t objectMin = 1024 * 0.6/5;

	uint16_t objectMax = 1024 * 4/5;


   for(;;)  // Loop Forever
   {
   		acdValue = ReadADC(4);
   	if(acdValue>objectMax) //
	{ 		PORTB &= ~(1<<PB1);
			PORTB &= ~(1<<PB2);
	    

	}else
		{
		PORTB |= (1<<PB1);
		PORTB |= (1<<PB2);

		}
   }
}


void initADC()
{
	ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); // Set ADC prescaler to 128 - 125KHz sample rate @ 16MHz
	ADMUX |= (1 << REFS0); // Set ADC reference to AVCC
	ADCSRA |= (1 << ADEN);  // Enable ADC
}

uint16_t ReadADC(uint8_t ch)
{
	//Select ADC Channel ch must be 0-7
	ch=ch&0b00000111;
	ADMUX|=ch;

	ADCSRA |= (1 << ADFR);  // Set ADC to Free-Running Mode
	ADCSRA |= (1 << ADSC);  // Start A2D Conversions
	return(ADCW);
}
