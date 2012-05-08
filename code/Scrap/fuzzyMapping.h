#ifndef FUZZYMAPPING_H
#define FUZZYMAPPING_H

#include "InitializeADC.h"

//-- Global Variables --\\
// ACD Variables storing acd values read from sensors 1-6
uint16_t adcValueS1; // side line sensors
uint16_t adcValueS2;
uint16_t adcValueS3;
uint16_t adcValueS4;
uint16_t adcValueS5; // front line sensor
uint16_t adcValueS6; // Analog object sensor
uint16_t minRight; // tells us if we need to turn right or left
uint16_t minLeft; // tells us if we need to turn right or left
uint16_t maxRight;
uint16_t maxLeft;

char colorMapping()

	adcValueS5 = readADC(0); // reads sensor 2 (ch4)
	adcValueS4 = readADC(1); // reads sensor 2 (ch4)
	adcValueS3 = readADC(2);
	adcValueS2 = readADC(3); // reads sensor 2 (ch4)
	adcValueS1 = readADC(4);

	if(adcValueS1 =


void BLACK()
{
		





char rightSensing() // W, G, and B for White, Grey and Black

	adcValueS2 = readADC(4); // reads sensor 2 (ch4)
	adcValueS3 = readADC(3);
	
	if(adcValueS2<adcValueS3)
		minRight=adcValueS2;
	else if(adcValueS2>adcValueS3)
		minRight=adcValueS3; 
	else
		//go forward

	





#endif
