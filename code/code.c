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
#include "Initializations.h"
#include "InitializationPWM.h"
#include "Line_Obj.h"
#include "Turning.h"
#include "TimeDelay.h"
#include "Cases.h"
#include "Global.h"

void main()
{
	initMotors(); // initializing the motors
	
	sidePosition=1; // 1 is right
	timeDelay(5);
	
	while(1)
	{

		frontLineTrigger(); // front middle sensor
		getOffLine();

		frontLineTrigger(); // front middle sensor
		searchLine(); // floor floor

		frontLineTrigger(); // front middle sensor
		getOffLine(); // right/left front side (new sensor)

		frontLineTrigger(); // front middle sensor		
		followLine(); // rear on floor - front on line	
				
		frontLineTrigger(); // front middle sensor
		getOffLine();

		frontLineTrigger(); // front middle sensor
		frontOffPathTrigger();

		frontLineTrigger(); // front middle sensor
		getOffLine();

		frontLineTrigger(); // front middle sensor
		backOffPathTrigger(); // rear on line - front on floor	

		frontLineTrigger(); // front middle sensor
		getOffLine();

		sensingObject();	
	}	
}


#endif
