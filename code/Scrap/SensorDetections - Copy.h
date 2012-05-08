#ifndef SENSORDETECTIONS_H
#define SENSORDETECTIONS_H

#include "InitializeADC.h"

//-- Global Variables --\\
// ACD Variables storing acd values read from sensors 1-6
uint16_t acdValueS1; // side line sensors
uint16_t acdValueS2;
uint16_t acdValueS3;
uint16_t acdValueS4;
uint16_t acdValueS5; // front line sensor
uint16_t acdValueS6; // Analog object sensor

uint8_t sensor1() // line sensor at Motor1, on line edge  return True
{
	acdValueS1 = readADC(5);
	if(shadeMin<acdValueS1 && acdValueS1<shadeMax)
		return 1;
	else 
		return 0;
}

uint8_t sensor1Floor() // line sensor at Motor1, on floor return True
{
	initADC();
	acdValueS1 = readADC(5);
	if(acdValueS1<shadeMin)
		return 1;
	else 
		return 0;
}

uint8_t sensor1OnLine() // line sensor at Motor2, on line return True
{
	initADC();
	initSensors();
	acdValueS1 = readADC(5);
	if(acdValueS1>shadeBorder)
		return 1;
	else 
		return 0;
}

uint8_t sensor1OnFloor() // line sensor at Motor2, on floor return True
{
	initADC();
	acdValueS1 = readADC(5);
	if(acdValueS1<shadeBorder)
		return 1;
	else 
		return 0;
}
uint8_t sensor2OnLine() // line sensor at Motor2, on line return True
{
	initADC();
	acdValueS2 = readADC(4);
	if(acdValueS2>shadeBorder)
		return 1;
	else 
		return 0;
}

uint8_t sensor2OnFloor() // line sensor at Motor2, on floor return True
{
	readADC2(4);
	if(ValueS2)
		return 1;
	else 
		return 0;
}
/*
uint8_t sensor2OnFloor() // line sensor at Motor2, on floor return True
{
	acdValueS2 = readADC(4);
	if(acdValueS2<shadeBorder)
		return 1;
	else 
		return 0;
}
*/
uint8_t sensor3OnLine() // line sensor at Motor3, on black tape return True
{
	initADC();
	acdValueS3 = readADC(3);
	if(acdValueS3>shadeBorder)
		return 1;
	else 
		return 0;
}

uint8_t sensor3OnFloor() // line sensor at Motor2, on floor return True
{
	initADC();
	acdValueS3 = readADC(3);
	if(acdValueS3<shadeBorder)
		return 1;
	else 
		return 0;
}

uint8_t rightSensorsOnFloor()
{
	acdValueS2 = readADC(4);
	acdValueS3 = readADC(3);
	if(acdValueS2<shadeBorder && acdValueS3<shadeBorder)
		return 1;
	else 
		return 0;
}

uint8_t rightSensorsOnLine()
{
	acdValueS2 = readADC(4);
	acdValueS3 = readADC(3);
	if(acdValueS2>=shadeBorder && acdValueS3>=shadeBorder)
		return 1;
	else 
		return 0;
}
 
void rightSensorsOnFloor2()
{
	acdValueS2 = readADC(4);
	acdValueS3 = readADC(3);
	while(acdValueS2<=shadeBorder && acdValueS3<=shadeBorder)
	{
		acdValueS2 = readADC(4);
		acdValueS3 = readADC(3);
		driveBackward(80);
	}
}
void rightSensorsOnLine2()
{
	acdValueS2 = readADC(4);
	acdValueS3 = readADC(3);
	while(acdValueS2>=shadeBorder && acdValueS3>=shadeBorder)
	{
		acdValueS2 = readADC(4);
		acdValueS3 = readADC(3);
		driveForward(80);
	}
}





void rightSensorsOnPath() //abbs way
{
	acdValueS2 = readADC(4);
	acdValueS3 = readADC(3);
	while(acdValueS2<shadeBorder && acdValueS3>shadeBorder)
	{
		acdValueS2 = readADC(4);
		acdValueS3 = readADC(3);
		driveForward(120);
	}
}

void rightSensorsNotOnPath() //abbs way
{
	acdValueS2 = readADC(4);
	acdValueS3 = readADC(3);
	if(acdValueS2<shadeBorder && acdValueS3<shadeBorder)
	{
		turnRight(1);
	}
	else 
		turnLeft(1);
}

uint8_t sensor4() // line sensor at Motor4, on line return True
{
	acdValueS4 = readADC(2);
	if(shadeMin<acdValueS4 && acdValueS4<shadeMax)
		return 1;
	else 
		return 0;
}

uint8_t sensor4Floor() // line sensor at Motor2, on floor return True
{
	acdValueS4 = readADC(2);
	if(acdValueS4<shadeMin)
		return 1;
	else 
		return 0;
}

uint8_t sensor5() // line sensor at the front, on line return True
{
	acdValueS5 = readADC(1);
	if(shadeMin<acdValueS5 && acdValueS5<shadeMax)
		return 1;
	else 
		return 0;
}

uint8_t sensor6() // object sensor, object detected return True
{
	acdValueS6 = readADC(0);
	if(objectMin<acdValueS6 && acdValueS6<objectMax)
		return 1;
	else 
		return 0;
}

#endif
