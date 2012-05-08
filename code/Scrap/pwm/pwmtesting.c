
#include <avr/io.h>
#include <avr/delay.h>
#include <avr/signal.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>
//#include <avr/timer8.h>

// Motor Directions
#define forwardRight	PD5
#define reverseRight	PD6
#define forwardLeft		PD7
#define reverseLeft		PB0

void InitPWM()
{
	/*
	TCCR0 - Timer Counter Control Register (TIMER0)
	-----------------------------------------------
	BITS DESCRIPTION
	
	NO: 	NAME   DESCRIPTION
	--------------------------
	BIT 7 : FOC0   Force Output Compare [Not used in this example]
	BIT 6 : WGM00  Wave form generartion mode [SET to 1]
	BIT 5 : COM01  Compare Output Mode        [SET to 1]
	BIT 4 : COM00  Compare Output Mode        [SET to 0]
	BIT 3 : WGM01  Wave form generartion mode [SET to 1]
	BIT 2 : CS02   Clock Select               [SET to 0]
	BIT 1 : CS01   Clock Select               [SET to 0]
	BIT 0 : CS00   Clock Select               [SET to 1]

	The above settings are for
	--------------------------
	Timer Clock = CPU Clock (No Prescalling)
	Mode        = Fast PWM
	PWM Output  = Non Inverted

	*/


	//TCCR2|=(1<<WGM20)|(1<<WGM21)|(1<<COM21)|(1<<COM20)|(1<<CS20);

	//timer1SetPrescaler(3); // TIMER_CLK_DIV8
	//TCNT1 = 0;
	//ICR1 = 0x8000;
	//PORTB1
	//TCCR1A|=(1<<WGM10)|(1<<WGM11)|(1<<COM1A0)|(1<<COM1A1) |(1<<CS10);


	//PORTB2
	//TCCR1B|=(1<<WGM12)|(1<<WGM13)|(1<<COM1B0)|(1<<COM1B1)|(1<<CS12);

	TCCR1A=0xA1;
	TCCR1B=0x0A;
	TCNT1H=0x00;
	TCNT1L=0x00;
	ICR1H=0x00;
	ICR1L=0x00;
	OCR1AH=0x00;
	OCR1AL=0x7D;
	OCR1BH=0x00;
	OCR1BL=0x7D; 

	//Set OC0 PIN as output. It is  PB3 on ATmega16 ATmega32
	DDRB|=(1<<PB3);
	DDRB|=(1<<PB2);
	DDRB|=(1<<PB1);

	DDRD|=(1<<PD7);
	DDRD|=(1<<PD5);
	DDRD|=(1<<PD6);
	DDRB|=(1<<PB0);


	PORTD|=(0<<PD7);
	PORTD|=(0<<PD5);

	PORTD|=(1<<PD6);
	PORTB|=(1<<PB0);

	PORTB|=(1<<PB3);
	//PORTB|=(1<<PB1);
	Wait();
	//PORTB&=(0<<PB3);
	//PORTB &=(0<<PB2);
//	PORTB &=(0<<PB1);
	
}

/******************************************************************
Sets the duty cycle of output. 

Arguments
---------
duty: Between 0 - 255

0= 0%
255= 100%

The Function sets the duty cycle of pwm output generated on OC0 PIN
The average voltage on this output pin will be

         duty
 Vout=  ------ x 5v
	      255 

This can be used to control the brightness of LED or Speed of Motor.
*********************************************************************/

void SetPWMOutput(uint8_t duty)
{
	
	OCR1A=duty*0.70;
	OCR1B=duty;
}

/******************************************************************** 

Simple Wait Loop

*********************************************************************/

void Wait()
{
 _delay_loop_2(3200);
}

void main()
{
	uint8_t brightness=0;

	//Initialize PWM Channel 0
	InitPWM();

	//Do this forever
	while(1)
	{
		//Now Loop with increasing brightness
		while (brightness<5 )
		{
			brightness=153;
		}
		/*
		for(brightness=0;brightness<255;brightness++)
		{
			//Now Set The Brighness using PWM
			SetPWMOutput(brightness);

			//Now Wait For Some Time
			Wait();
		}
		*/

		//Now Loop with decreasing brightness
		SetPWMOutput(brightness);
		/*
		for(brightness=255;brightness>0;brightness--)
		{
			//Now Set The Brighness using PWM
			SetPWMOutput(brightness);
	
			//Now Wait For Some Time
			Wait();
		}
		*/
	}
}




