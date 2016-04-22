/*
* JoystickOptions.c
*
* Created: 2016-04-18 14:17:37
* Author: William och Elvin joysticklogiken. Michael och Martin skapade task, testade den och placera logiken i den.
*
* A task containing logic for turning the robot left or right.
*/

#include <asf.h>
#include "Tasks/TaskDriveLeftRight.h"
#include "adc/adcFunctions.h"
#include "DriveOptions/driveLeft.h"
#include "DriveOptions/driveRight.h"
#include "DriveOptions/driveForwardAndBackward.h"

uint32_t joystick_x;
uint32_t joystick_y;
static uint32_t sampleTime = 100; //Length of the task, in milliseconds.

/**************************************************************************
* Task for driving left or right.
**************************************************************************/
void TaskDriveLeftRight(void *p)
{
/*	pinMode(Analog0,Input);	//x-axeln till joysticken									Analog In 0
	pinMode(Analog1,Input);	//y-axeln till joysticken									Analog In 1

	pinMode(pin3,Output);	// digital pin för lampa									Digital Pin 3
	pinMode(pin8,Output);	// digital pin för lampa									Digital pin 8
	pinMode(pin6,Output);// Då man trycker på joysticken ska en lampa lyssna			Digital pin 6
	pinMode(pin5,Input); //Läser av switchen på joysticken(trycker på joysticken)		Digital Pin 5*/
	
	portTickType xLastWakeTime; //Last time the task was active.
	portTickType xSampleTime;
	
	xLastWakeTime = xTaskGetTickCount();


	while(1){
		setPin(pin3,HIGH);
		joystick_x =  ReadAnalog0();
		joystick_y = ReadAnalog1();
		
		
		if(((joystick_x > 585) && (joystick_x < 680)) && ((joystick_y > 585) && (joystick_y < 680)) ) // default(mitten)
		{
			standBymode();
		}
		
		else if(((joystick_x > 780) && (joystick_x < 850)) && ((joystick_y > 1340) && (joystick_y < 1370))) // 15% höger
		{
			Right_15Degrees();
		}
		else if(((joystick_x > 860) && (joystick_x < 1040)) && ((joystick_y > 1340) && (joystick_y < 1370))) // 30% höger
		{
			Right_30Degrees();
		}
		else if(((joystick_x > 1050) && (joystick_x < 1370)) && ((joystick_y > 1340) && (joystick_y < 1370))) // 45% höger
		{
			Right_45Degrees();
			
		}
		else if(((joystick_x > 1340) && (joystick_x < 1370)) && ((joystick_y > 1200) && (joystick_y < 1340))) // 60% höger
		{
			Right_60Degrees();

		}
		else if(((joystick_x > 1340) && (joystick_x < 1370)) && ((joystick_y > 800) && (joystick_y < 1190))) // 75% höger
		{
			Right_75Degrees();
		}
		else if(((joystick_x > 1340) && (joystick_x < 1370)) && ((joystick_y > 610) && (joystick_y < 790))) // 90% höger
		{
			Right_90Degrees();
		}
		else if(((joystick_x > 500) && (joystick_x < 590)) && ((joystick_y > 1340) && (joystick_y < 1370))) // 15% vänster
		{
			Left_15Degrees();
		}
		else if(((joystick_x > 300) && (joystick_x < 490)) && ((joystick_y > 1340) && (joystick_y < 1370))) // 30% vänster
		{
			Left_30Degrees();
		}
		else if(((joystick_x > 100) && (joystick_x < 290)) && ((joystick_y > 1340) && (joystick_y < 1370))) // 45% vänster
		{
			Left_45Degrees();
		}
		else if(((joystick_x >= 0) && (joystick_x < 90)) && ((joystick_y > 1340) && (joystick_y < 1370))) // 60% höger
		{
			Left_60Degrees();
		}
		else if(((joystick_x >= 0) && (joystick_x < 90)) && ((joystick_y > 1000) && (joystick_y < 1330))) // 75% höger
		{
			Left_75Degrees();
		}
		else if(((joystick_x >= 0) && (joystick_x < 90)) && ((joystick_y > 610) && (joystick_y < 990))) // 90% höger
		{
			Left_90Degrees();
		}
		else{
			setPin(pin3,LOW);
		}
	
		xSampleTime = (portTickType)sampleTime;
		vTaskDelayUntil(&xLastWakeTime, xSampleTime); //Wait for the next cycle the task will be active.
	}
}

