#ifndef TEST_H
#define TEST_H

#include <avr/io.h>
#include <avr/delay.h>
#include <avr/signal.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>

#include "C:\Users\BombDiggady\Documents\My Dropbox\Classes\COEN 390 - Engr+TeamDesign\Final Report\code\Driving.h"
#include "C:\Users\BombDiggady\Documents\My Dropbox\Classes\COEN 390 - Engr+TeamDesign\Final Report\code\SensorDetections.h"
#include "C:\Users\BombDiggady\Documents\My Dropbox\Classes\COEN 390 - Engr+TeamDesign\Final Report\code\Initializations.h"
#include "C:\Users\BombDiggady\Documents\My Dropbox\Classes\COEN 390 - Engr+TeamDesign\Final Report\code\InitializationPWM.h"
#include "C:\Users\BombDiggady\Documents\My Dropbox\Classes\COEN 390 - Engr+TeamDesign\Final Report\code\InitializeADC.h"
#include "C:\Users\BombDiggady\Documents\My Dropbox\Classes\COEN 390 - Engr+TeamDesign\Final Report\code\Line_Obj.h"
#include "C:\Users\BombDiggady\Documents\My Dropbox\Classes\COEN 390 - Engr+TeamDesign\Final Report\code\Turning.h"
#include "C:\Users\BombDiggady\Documents\My Dropbox\Classes\COEN 390 - Engr+TeamDesign\Final Report\code\TimeDelay.h"

void main()
{
	initSensors(); // initializing the sensors
	initMotors(); // initializing the motors
	//uint8_t i=0; // car speed to be passed to drive Forward/Backward Functions

	while(1)
	{
		readLine();
		followLine();
	}	

	/*
	if(rightLineSensing()) // readLine contains rightLineSensing() 
	{		//and leftLineSensing() to read both sides and set sidePosition
		driveForward(150);
	}
	else
	{
		turnRight(1); // turn to look for the competing robot

		if(sensor6()) // checking if a robot is on the right
		{
			turnLeft(100);
			driveForward(100);
		}
		else
		{
			turnLeft(1);
			driveForward(100);
		}
		while(!readLine());
		followLine();

	}
	while(1)
	{
		followLine();
		//sensingObject();
		//frontLineSensing();
		rightLineSensing();
		leftLineSensing();
	}
	*/
}


#endif
