/*
 * JoystickOptionsYAxis.c
 *
 * Created: 2016-04-18 14:58:47
 * Author: Michael och Martin skrev task och placerade logik i den. William och Elvin skrev logiken.
 *
 * Content: A task containing logic for driving the robot forward or backward. 
 */ 

#include <asf.h>
#include <inttypes.h>
#include "adc/adcFunctions.h"
#include "Tasks/TaskDriveForward.h"
#include "DriveOptions/driveForwardAndBackward.h"

static uint32_t sampleTime = 100; //Length of the task, in milliseconds.

/**************************************************************************
* Task for driving forward and backward.
**************************************************************************/
void TaskDriveForward(void *p)
{
	uint32_t joystick_y;
	
	
	/*pinMode(Analog0,Input);	//x-axeln till joysticken									Analog In 0
	pinMode(Analog1,Input);	//y-axeln till joysticken									Analog In 1
	
	pinMode(pin3,Output);	// digital pin för lampa									Digital Pin 3
	pinMode(pin8,Output);	// digital pin för lampa									Digital pin 8
	pinMode(pin6,Output);// Då man trycker på joysticken ska en lampa lyssna			Digital pin 6
	pinMode(pin5,Input); //Läser av switchen på joysticken(trycker på joysticken)		Digital Pin 5
	pinMode(pin11,Output);*/
	
	portTickType xLastWakeTime; //Last time the task was active.
	portTickType xSampleTime; 
	xLastWakeTime = xTaskGetTickCount();
	
	while(1){
		xSampleTime = (portTickType)sampleTime;
		vTaskDelayUntil(&xLastWakeTime, xSampleTime); //Wait for the next cycle the task will be active.

		joystick_y = ReadAnalog1();
		
		if((joystick_y > 585)) //Drive forward at full speed.
		{
			Forward_100();
		}
		if((joystick_y <= 585)) //Drive backward at 50% speed.
		{
			Backward_50();
	
			
		}
		

	}
	
}