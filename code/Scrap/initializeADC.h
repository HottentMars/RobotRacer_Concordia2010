#ifndef INITIALIZEADC_H
#define INITIALIZEADC_H

#include "Global.h"

//-- Global Variables --\\
// ACD Variables storing acd values read from sensors 1-6


void initADC() // initializing ADC (Sensors)
{
	ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0) ; // Set ADC prescaler to 128 - 125KHz sample rate @ 16MHz
	ADMUX |= (1 << REFS0); // Set ADC reference to AVCC
	ADCSRA |= (1 << ADEN);  // Enable ADC
	
	// Line Sensors reflectivity in volts,range that the car should stay between


	uint8_t reflectBorder = 3; // In volts :3 and below
	uint8_t reflectRear = 4.5;
	

	uint8_t reflectMin = 1; // detect black line
	uint8_t reflectMax = 4.5;

	// Object sensor distance in volts, object detection at any of the values in between
	uint8_t distanceMin = 0.6;
	uint8_t distanceMax = 2.4;
	
	// Initializing sensor  ranges


	shadeBorder = 1024 * reflectBorder/5; // reflection border
	shadeRear = 1024 * reflectRear/5; // reflection border


	shadeMin = 1024 * reflectMin/5;	//Front Sensors
	shadeMax = 1024 * reflectMax/5;

	objectMin = 1024 * distanceMin/5;	//Front Obj Sensors
	objectMax = 1024 * distanceMax/5;

}

uint16_t readADC(uint8_t ch) // Read ADC from a Channel, ch(0-5)
{							 // ch5 is S1, ch4 is S2 and so on...

	ADMUX &=0b11111000;
	//Select ADC Channel, ch(0-7)
	ch=ch&0b00000111;
	ADMUX|=ch;

	ADCSRA |= (1 << ADFR);  // Set ADC to Free-Running Mode
	ADCSRA |= (1 << ADIE);
	
	ADCSRA |= (1 << ADSC);  // Start A2D Conversions
	//Wait for conversion to complete
   	while(!(ADCSRA & (1<<ADIF)));
	//smallDelay(30);
	//Clear ADIF by writing one to it
   	ADCSRA|=(1<<ADIF);

	return(ADCW); 
}

#endif
