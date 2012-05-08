#ifndef CASES_H
#define CASES_H

#define PORTC 	PINC
#define PORTB 	PINB
#define PORTD 	PIND

#define S1	PB3
#define S2	PD4
#define S3	PC3
#define S4	PC2
#define S5	PC1
#define S6	PC0
#define S7	PB4
#define S8	PD3 // Right

#define LowS1	bit_is_clear(PORTB, S1)
#define LowS2	bit_is_clear(PORTD, S2)
#define LowS3	bit_is_clear(PORTC, S3)
#define LowS4	bit_is_clear(PORTC, S4)
#define LowS5	bit_is_clear(PORTC, S5)
#define LowS6	bit_is_clear(PORTC, S6)
#define LowS7	bit_is_clear(PORTB, S7)
#define LowS8	bit_is_clear(PORTD, S8)

#define HighS1	bit_is_set(PORTB, S1)
#define HighS2	bit_is_set(PORTD, S2)
#define HighS3	bit_is_set(PORTC, S3)
#define HighS4	bit_is_set(PORTC, S4)
#define HighS5	bit_is_set(PORTC, S5)
#define HighS6	bit_is_set(PORTC, S6)

#define HighS7	bit_is_set(PORTB, S7)
#define HighS8	bit_is_set(PORTD, S8)

uint8_t getOffLineTrigger()
{
	switch(sidePosition)
	{
		case 0: // left line (S1,S4)
			if(HighS7) // on floor
				return 1;
		case 1: // right line (S2,S3)
			if(HighS8)
				return 1;
	}		
	return 0;
}
	
uint8_t onFloor() // all floor check
{	
	switch(sidePosition)
	{
		case 0: // left line (S1,S4)
			if((LowS1 && LowS4)) // on floor
				return 1;
			break;
		case 1: // right line (S2,S3)
			if(LowS2 && LowS3)
				return 1;
			break;
	}		
	return 0;
}

uint8_t onPath() // front on line - rear on floor
{
	switch(sidePosition)
	{
		case 0: // left line (S1,S4)
			if(HighS1 && HighS4 && LowS7) 
				return 1;
			break;
		case 1: // right line (S2,S3)
			if(HighS2 && HighS3 && LowS8)
				return 1;
			break;
	}
	return 0;
}

uint8_t frontOffPath() // front on floor - rear on line (should never let it happen)
{
	switch(sidePosition)
	{
		case 0: // left line (S1,S4)
			if(LowS1 && HighS4) 
				return 1;
			break;
		case 1: // right line (S2,S3)
			if(LowS2 && HighS3)
				return 1;
			break;
	}
	return 0;
}

uint8_t backOffPath() // front on floor - rear on line (should never let it happen)
{
	switch(sidePosition)
	{
		case 0: // left line (S1,S4)
			if(HighS1 && LowS4) 
				return 1;
			break;
		case 1: // right line (S2,S3)
			if(HighS2 && LowS3)
				return 1;
			break;
	}
	return 0;
}

uint8_t frontLine() // front line sensor (driveBackwards abit)
{

	if(HighS5/* || (HighS1 && HighS2) || (HighS7 && HighS8)*/) 
		return 1;
	else
		return 0;
}

#endif
