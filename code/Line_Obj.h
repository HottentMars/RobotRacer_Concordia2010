#ifndef LINE_OBJ_H
#define LINE_OBJ_H

#include "Turning.h"
#include "Cases.h"
#include "Global.h"

void readPosition()
{
	if(HighS2)
		sidePosition=1; // right
	
	else if(HighS1)	
		sidePosition=0; // left
}

void getOffLine()
{
	while(getOffLineTrigger()) 
	{
		switch(sidePosition)
		{
			case 0: // left line (S1,S4)
				turnRight(lowest); // turningLeft(85,250,15);
				break;
			case 1: // right line (S1,S4)
				turnLeft(lowest); // turningRight(250,85,15);
				break;
		}
		
	}
}


void searchLine()
{
	while(onFloor()) // all on floor
	{
		if(countFloor<4)
		{
			//if(onFloor())
			//{
				readPosition();
				turnRight(low);
			//}
			countFloor++;
		}
		if(countFloor>=4 && countFloor<13)
		{
			//if(onFloor())
			//{
				readPosition();
				turnLeft(low);
			//}
			countFloor++;
		}
		if(countFloor>=13 && countFloor<20)
		{
			//if(onFloor())
			//{	
				readPosition();
				turnRight(low);
			//}
			countFloor++;
		}
		if(countFloor==20)
		{
			while(onFloor())
			{
				readPosition();
				driveForward(85);
			}
		}
		if(countFloor==21)
		{	
			pass++;
			switch(sidePosition)
			{
				case 0: // left 
					turnLeft(lowest); // turningLeft(85,250,15);
					break;
				case 1: // right
					turnRight(lowest); // turningRight(250,85,15);
					break;
			}
		}
		if(pass==22) // the boost
		{
			driveForward(85);
			smallDelay(40);
			stop();
			pass=0;
		}
	}
}


void followLine()
{
	while(onPath()) // rear on floor - front on line
	{
		switch(sidePosition)
		{
			case 0: // left	
				driveForward(85); // min 85
				break;
			case 1: // right
				driveForward(85); // min 85
				break;
		}
		countFloor=21;
		//countFloor=1;
	}
}

void frontOffPathTrigger()
{
	while(frontOffPath()) // rear on line - front on floor
	{
		switch(sidePosition)
		{
			case 0: // left line (S1,S4)
				turnLeft(lowest); // turningLeft(85,250,15);
				break;
			case 1: // right line (S1,S4)
				turnRight(lowest); // turningRight(250,85,15);
				break;
		}
		
	}
}

void backOffPathTrigger()
{
	while(backOffPath()) // rear on line - front on floor
	{
		switch(sidePosition)
		{
			case 0: // left line (S1,S4)
				driveForward(85);
				break;
			case 1: // right line (S1,S4)
				driveForward(85);
				break;
		}
		countFloor=21;	
	}
}

void frontLineTrigger() // middle line sens
{
	while(frontLine())
	{
		stop();
		switch(sidePosition)
		{
			case 0: // left
				while(frontLine())
					driveBackward(85);
				fullTurnRight(2);
				break;
			case 1: // right
				while(frontLine())
					driveBackward(85);
				fullTurnLeft(2);
				break;
		}
		countFloor=0;
	}
}	


void sensingObject()
{
	if(HighS6) // sensor6 is the object sensor, returns 1 if there is an obj
	{	
		switch(sidePosition)
		{
			case 0: // left
				fullTurnRight(2);
				smallDelay(50);
				countFloor=0; // reset onFloor
				while((LowS1 && LowS2) || HighS6) // while both front sensors are on floor
				{
					readPosition();
					driveForward(85);
				}
				break;
			case 1: // right
				fullTurnLeft(2);
				smallDelay(50);
				countFloor=0; // reset onFloor
				while((LowS1 && LowS2) || HighS6)
				{
					readPosition();
					driveForward(85);
				}
				break;
		}
		stop();
	}
}

#endif
