#ifndef DRIVING_H
#define DRIVING_H

//-- Defining Ports --\\
// Motor Directions
#define forwardRight	PD5
#define forwardLeft		PD7
#define reverseRight	PD6
#define reverseLeft		PB0

// speed 1 to 5 as arguments, 5=fastest speed
void driveForward(uint8_t speed)	
{

	PORTD &= ~(1<<forwardLeft);
	PORTD &= ~(1<<forwardRight);
	PORTD |= (1<<reverseRight);
	PORTB |= (1<<reverseLeft);

	setPWMOutputLM(speed);
	setPWMOutputRM(speed);			
}

// speed 1 to 5 as arguments, 5=fastest speed
void driveBackward(uint8_t speed)	
{

	PORTD |= (1<<forwardLeft);
	PORTD |= (1<<forwardRight);
	PORTD &= ~(1<<reverseRight);
	PORTB &= ~(1<<reverseLeft);

	setPWMOutputLM(speed);
	setPWMOutputRM(speed);			
}

void stop()
{
	setPWMOutputLM(0); // stop
	setPWMOutputRM(0);
}

#endif
