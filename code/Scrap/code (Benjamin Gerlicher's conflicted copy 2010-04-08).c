#ifndef CODE_H
#define CODE_H

#include <avr/io.h>
#include <avr/delay.h>
#include <avr/signal.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>

#include "Driving.h"
#include "SensorDetections.h"
#include "Initializations.h"
#include "InitializationPWM.h"
#include "InitializeADC.h"
#include "Line_Obj.h"
#include "Turning.h"
#include "TimeDelay.h"
//#include "Cases.h"
int slow=75;
int medium=110;
int fast=175;



int main()
{
	

	initSensors(); // initializing the sensors
	initMotors(); // initializing the motors

	//sidePosition==1;	

	while(1)
	{

		while(sensor2OnFloor() && sensor3OnFloor() && sensor5OnFloor())
			driveForward(100);
		stop();
		if((sensor2OnFloor||sensor3OnFloor)!=1)
			delayMe(2);
			int x;
			
			if(sensor2OnFloor > ShadeBorder)
				trunLeft(x);
			if(sensor3OnFloor > ShadeBorder)
				trunRight(x);			
x == 1 
			turnright(x);
		while(sensor2OnLine())
			driveBackward(100);
		stop();

	
		return 0;		
	}
}

	//uint8_t carSpeed; // car speed to be passed to drive Forward/Backward Functions

	/*if(readLine()) // readLine contains rightLineSensing() 
	{		//and leftLineSensing() to read both sides and set sidePosition
		followLine();
	}
	else
	{
		turnRight(90); // turn to look for the competing robot

		if(sensor6()) // checking if a robot is on the right
		{
			turnLeft(100);
			driveForward(100);
		}
		else
		{
			turnLeft(75);
			driveForward(100);
		}
		while(!readLine());
		followLine();
	}*/


#endif


/*		sensingObject();
		frontLineSensing();
		rightLineSensing();
		leftLineSensing();
*/
