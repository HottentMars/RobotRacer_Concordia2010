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

//-- Program Start --\\
void main()
{
	initSensors(); // initializing the sensors
	initMotors(); // initializing the motors
	//uint8_t carSpeed; // car speed to be passed to drive Forward/Backward Functions

	if(readLine()) // readLine contains rightLineSensing() 
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
	}
	while(1)
	{
		readLine(); // sets sidePosition

		if(Case1()) // white white
			searchLine(); // search untill not white white
		else if(Case2()) // grey grey
			driveForward(150);
		else if(Case3()) // black black
			// goingOutOfCourse(); // get back on grey
		else if(Case4()) // remaining options
			// goBackToGrey();
				
				
	}
}

#endif


/*		sensingObject();
		frontLineSensing();
		rightLineSensing();
		leftLineSensing();
*/
