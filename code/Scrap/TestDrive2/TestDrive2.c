// testDrive2.c back up

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

	timeDelay(3);

	while(1)
	{
		while(sensor2OnFloor())
			driveForward(100);
			//if(sensor2OnFloor())
			//	driveForward(100);
		stop();
		while(sensor2OnLine()) // sensor3OnLine())
			driveBackward(100);
		stop();
	}

}


#endif


/*
	while(1)
	{

		while(sensor2OnFloor()) // drive, car on line, sensor2OnFloor() && sensor3OnLine()
			driveForward(100);
		stop();
		timeDelay(2);
		while(sensor2OnLine()) // drive, car on line, sensor2OnFloor() && sensor3OnLine()
			driveBackward(100);
		stop();
		timeDelay(2);
		/*
		if(sensor2OnFloor() && sensor3OnFloor()) // front sensor is off
		{
			turnRight(1);
			timeDelay(1);
		}
		if(sensor3OnFloor() && sensor2OnLine()) // back sensor is off
		{
			turnLeft(1);
			timeDelay(1);
		}
		
	}

*/


/*
	while(1)
	{	
		if(sensor2())
		{
			driveForward(100);
		}
		else 
		{
					
			if(sensor2Floor()) //
				{
					turnRight(1);
					driveForward(100);
				}
			else
				{
					turnLeft(1);
					driveForward(100);
				}
		
		}
	
	}	
*/

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
