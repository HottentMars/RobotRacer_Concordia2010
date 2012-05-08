#ifndef SENSORDETECTIONS_H
#define SENSORDETECTIONS_H

#include "Global.h"
#include "InitializeADC.h"





uint8_t sensorLine(uint8_t sensor) // on line return True
{
	uint8_t channel;
	switch (sensor)
	{

		case 1:
			channel=5;
			break;
		case 2:
			channel=4;
			break;
		case 3:
			channel=3;
			break;
		case 4:
			channel=2;
			break;
		case 5:
			channel=1;
			break;
	}

	adcValue = readADC(channel);
	if(adcValue>shadeMax) // shade set at 4.5V
		return 1;
	else 
		return 0;
}

uint8_t sensorFloor(uint8_t sensor) // on floor return True
{
	uint8_t channel;
	switch (sensor)
	{

		case 1:
			channel=5;
			break;
		case 2:
			channel=4;
			break;
		case 3:
			channel=3;
			break;		
		case 4:
			channel=2;
			break;	
		case 5:
			channel=1;
			break;
	}

	adcValue = readADC(channel);
	if(adcValue<shadeMin) // shade set at 1V
		return 1;
	else 
		return 0;
}

uint8_t sensorObject() // Object infront return True (Sensor5)
{
	uint8_t channel=0;

	adcValue = readADC(channel);
	if(adcValue>objectMin && adcValue<objectMax) // shade set at 2.4V
		return 1;
	else 
		return 0;
}


uint8_t sensorPath(uint8_t sensor) // on line return True
{
	uint8_t channel;
	switch (sensor)
	{

		case 1:
			channel=5;
			break;
		case 2:
			channel=4;
			break;
		case 3:
			channel=3;
			break;		
		case 4:
			channel=2;
			break;
		case 5:
			channel=1;
			break;
	}

	adcValue = readADC(channel);
	if(adcValue>shadeMin && adcValue<shadeMax) // path set between 1V and 4.5V
		return 1;
	else 
		return 0;
}


// things to name fix in the program
uint8_t sensor1(){return 1;}
uint8_t sensor4(){return 1;}
uint8_t sensor5(){return 1;}
uint8_t sensor2OnFloor(){return 1;}
uint8_t sensor3OnLine(){return 1;}


#endif


