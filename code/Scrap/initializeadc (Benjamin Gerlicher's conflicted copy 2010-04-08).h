#ifndef INITIALIZEADC_H
#define INITIALIZEADC_H

//-- Global Variables --\\
//  used in initADC()
uint16_t shadeMinRs; 	// Rear Side
uint16_t shadeMaxRs;
uint16_t shadeMinFs;	// Front Side	
uint16_t shadeMaxFs;
uint16_t shadeMinF;		// Front
uint16_t shadeMaxF;
uint16_t objectMin;
uint16_t objectMax;
uint16_t shadeBorder;

uint16_t shadeMin;	
uint16_t shadeMax;

void initADC() // initializing ADC (Sensors)
{
	ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); // Set ADC prescaler to 128 - 125KHz sample rate @ 16MHz
	ADMUX |= (1 << REFS0); // Set ADC reference to AVCC
	ADCSRA |= (1 << ADEN);  // Enable ADC
	
	// Line Sensors reflectivity in volts,range that the car should stay between
	uint8_t reflectMinRs = 3; // On black line Values
	uint8_t reflectMaxRs = 5; 
	uint8_t reflectMinFs = 0; // Off black line Values
	uint8_t reflectMaxFs = 3;
	uint8_t reflectMinF = 3; // detect black line
	uint8_t reflectMaxF = 5;
	uint8_t reflectBorder = 3; // 3 and below

	uint8_t reflectMin = 1; // detect black line
	uint8_t reflectMax = 4;

	// Object sensor distance in volts, object detection at any of the values in between
	uint8_t distanceMin = 0.6;
	uint8_t distanceMax = 2.4;
	
	// Initializing sensor  ranges
	shadeMinRs = 1024 * reflectMinRs/5;	//Rear Side Sensors
	shadeMaxRs = 1024 * reflectMaxRs/5;	
	shadeMinFs = 1024 * reflectMinFs/5;	//Front Side Sensors
	shadeMaxFs = 1024 * reflectMaxFs/5;
	shadeMinF = 1024 * reflectMinF/5;	//Front Sensors
	shadeMaxF = 1024 * reflectMaxF/5;
	objectMin = 1024 * distanceMin/5; 	// Front Object Sensors
	objectMax = 1024 * distanceMax/5;
	shadeBorder = 1024 * reflectBorder/5; // reflection border

	shadeMin = 1024 * reflectMin/5;	//Front Sensors
	shadeMax = 1024 * reflectMax/5;
}



uint16_t readADC(uint8_t ch) // Read ADC from a Channel, ch(0-5)
{							 // ch5 is S1, ch4 is S2 and so on...
	//Select ADC Channel, ch(0-7)
	ch=ch&0b00000111;
	ADMUX|=ch;

	ADCSRA |= (1 << ADFR);  // Set ADC to Free-Running Mode
	ADCSRA |= (1 << ADSC);  // Start A2D Conversions
	//Wait for conversion to complete
   	while(!(ADCSRA & (1<<ADIF)));
	
	//Clear ADIF by writing one to it
   	ADCSRA|=(1<<ADIF);

	return(ADCW);
}

#endif
