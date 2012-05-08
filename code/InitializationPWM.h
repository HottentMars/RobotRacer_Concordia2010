#ifndef INITPWM_H
#define INITPWM_H

//-- Defining Ports --\\
// Motor Directions
#define forwardRight	PD5
#define forwardLeft		PD7
#define reverseRight	PD6
#define reverseLeft		PB0

// PMW Ports
#define PWM_Right	PB1
#define PWM_Left	PB2

void InitPWM() // initiate PWM
{
	//PORTS B1,B2
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
	DDRB|=(1<<PWM_Right);
	DDRB|=(1<<PWM_Left);
}

void setPWMOutputLM(uint8_t duty) // this is Right
{
	
	
	OCR1B=duty*0.8;
	// eg: call setPWMOutput(speed); in program
}

void setPWMOutputRM(uint8_t duty) // this is LEFT
{
	
	OCR1A=duty;
	// eg: call setPWMOutput(speed); in program
}

#endif
