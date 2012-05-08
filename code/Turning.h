#ifndef TURNING_H
#define TURNING_H

#include "Global.h"

#include "Line_Obj.h"
#include "TimeDelay.h"
#include "Driving.h"


//-- Defining Ports --\\
// Motor Directions
#define forwardRight	PD5
#define forwardLeft		PD7
#define reverseRight	PD6
#define reverseLeft		PB0

// turning speed
#define lowest 	10
#define low 	20
#define high 	30
#define highest	40 // around 20degrees

void turnRight(uint8_t time) // pass angle as argument
{
	stop();

	PORTD &= ~(1<<forwardLeft);
	PORTD |= (1<<forwardRight);
	PORTD &= ~(1<<reverseRight);
	PORTB |= (1<<reverseLeft);

	setPWMOutputLM(150); // go
	setPWMOutputRM(150);
	
	smallDelay(time);
	
	stop();	
	//timeDelay(2);
}

void turnLeft(uint8_t time) // pass angle as argument
{
	stop();

	PORTD |= (1<<forwardLeft);
	PORTD &= ~(1<<forwardRight);
	PORTD |= (1<<reverseRight); 
	PORTB &= ~(1<<reverseLeft);

	setPWMOutputLM(150);
	setPWMOutputRM(150);

	//delayMe(time2);

	smallDelay(time);

	stop();	
	//timeDelay(2);
}

void fullTurnRight(time)//
{
	stop();


	PORTD &= ~(1<<forwardLeft);
	PORTD |= (1<<forwardRight);
	PORTD &= ~(1<<reverseRight);
	PORTB |= (1<<reverseLeft);

	setPWMOutputLM(150);
	setPWMOutputRM(150);

	delayMe(time);

	//smallDelay(time);

	stop();	
	//timeDelay(2);
}

void fullTurnLeft(time) 
{
	stop();

	PORTD |= (1<<forwardLeft);
	PORTD &= ~(1<<forwardRight);
	PORTD |= (1<<reverseRight); 
	PORTB &= ~(1<<reverseLeft);

	setPWMOutputLM(150);
	setPWMOutputRM(150);

	delayMe(time);

	//smallDelay(time);

	stop();	
	//timeDelay(2);
}

#endif
