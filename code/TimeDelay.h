#ifndef TIMEDELAY_H
#define TIMEDELAY_H

#include <avr/delay.h>
#include "Global.h"

void delayMe(uint8_t loop)
{
	// new delay implementation
	uint8_t i;
	for(i=0; i<loop; i++)
		_delay_ms(250); // max 262.14ms	
}

void smallDelay(uint8_t loop)
{
	// new smaller delay implementation
	uint8_t i;
	for(i=0; i<loop; i++)
		_delay_ms(1); // max 262.14ms	
}

void timeDelay(uint8_t time)
{
	// old delay implementation
	// used for real time
	uint8_t loop=time*1000/250;
	uint8_t j;
	for(j=0; j<loop; j++)
		_delay_ms(250); // max 262.14ms	
	// time=1, delays for 1 second
}

#endif

/*

					  -- in degrees
@200, time of 1 gives 60
@200, time of 2 gives 170
@200, time of 3 gives too much
@200, time of 4 gives too much

@200, time of 1 gives 80
@200, time of 2 gives 170
@200, time of 3 gives too much
@200, time of 4 gives too much

@220, time of 1 gives 45
@220, time of 2 gives 135
@220, time of 3 gives too much
@220, time of 4 gives too much

@250, time of 0.5 gives 0
@250, time of 1.0 gives 40
@250, time of 1.5 gives 40
@250, time of 2.0 gives 170

these tests are not good, 
therefore will need to change the delay directly

using new delay,
testing with turning left only:
@250, time of 1 gives 20
@250, time of 2 gives 30
@250, time of 3 gives 45
@250, time of 4 gives 80
@250, time of 5 gives 100
@250, time of 6 gives 120

*/


