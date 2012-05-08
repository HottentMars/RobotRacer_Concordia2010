#ifndef INIT_H
#define INIT_H

//-- Defining Ports --\\
// Motor Directions
#define forwardRight	PD5
#define forwardLeft		PD7
#define reverseRight	PD6
#define reverseLeft		PB0

void initMotors()
{	
	DDRD|=(1<<forwardLeft);
	DDRD|=(1<<forwardRight);
	DDRD|=(1<<reverseRight);
	DDRB|=(1<<reverseLeft);

	InitPWM();
}

#endif
