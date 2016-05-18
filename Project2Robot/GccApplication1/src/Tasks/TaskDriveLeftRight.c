/*
* JoystickOptions.c
*
* Created: 2016-04-18 14:17:37
* Author: William and Elvin joysticklogic. Michael and Martin created the task.
*
* Content: A task containing logic for turning the robot left or right.
*/

#include <asf.h>
#include "Tasks/TaskDriveLeftRight.h"
#include "adc/adcFunctions.h"
#include "Tasks/TaskPIDLeft.h"
#include "Tasks/TaskPIDRight.h"

uint32_t joystick_x;
uint32_t joystick_y;
uint32_t driveflag = 0;
static uint32_t sampleTimeLeft = 100; //Length of the task, in milliseconds.

extern float desiredValueLeft;
extern float desiredValueRight;

uint32_t temp = 0;

/**************************************************************************
* Task for driving left or right.
**************************************************************************/
void TaskDriveLeftRight(void *p)
{
	portTickType xLastWakeTime; //Last time the task was active.
	portTickType xSampleTime;
	
	xLastWakeTime = xTaskGetTickCount();


	while(1){
		joystick_x = ReadAnalog0();
		joystick_y = ReadAnalog1();

		if(((joystick_x > 585) && (joystick_x < 680)) && ((joystick_y > 595) && (joystick_y < 680)) ) // default(mitten)
		{
			driveflag = 0;
			SetPointLeftWheel(0,driveflag);
			SetPointRightWheel(0,driveflag);
		}
		else if((joystick_y > 1300) && (joystick_x > 605)) //Drive forward at full speed.
		{
			driveflag = 2;
			SetPointLeftWheel(0.2,driveflag);
			SetPointRightWheel(0.2,driveflag);
		}
		else if((joystick_y <= 10)) //Drive backward at 50% speed.
		{
			driveflag = 1;
			SetPointLeftWheel(0.2,driveflag);
			SetPointRightWheel(0.2,driveflag);

		}		
		else if(((joystick_x > 780) && (joystick_x < 850)) && ((joystick_y > 1340) && (joystick_y < 1370))) // 15% höger
		{
			driveflag = 2;
			SetPointLeftWheel(0.22,driveflag);
			SetPointRightWheel(0.2,driveflag);
		}
		else if(((joystick_x > 860) && (joystick_x < 1040)) && ((joystick_y > 1340) && (joystick_y < 1370))) // 30% höger
		{
			driveflag = 2;
			SetPointLeftWheel(0.24,driveflag);
			SetPointRightWheel(0.2,driveflag);
		}
		else if(((joystick_x > 1050) && (joystick_x < 1370)) && ((joystick_y > 1340) && (joystick_y < 1370))) // 45% höger
		{
			driveflag = 2;
			SetPointLeftWheel(0.26,driveflag);
			SetPointRightWheel(0.2,driveflag);		
		}
		else if(((joystick_x > 1340) && (joystick_x < 1370)) && ((joystick_y > 1200) && (joystick_y < 1340))) // 60% höger
		{
			driveflag = 2;
			SetPointLeftWheel(0.28,driveflag);
			SetPointRightWheel(0.2,driveflag);
		}
		else if(((joystick_x > 1340) && (joystick_x < 1370)) && ((joystick_y > 800) && (joystick_y < 1190))) // 75% höger
		{
			driveflag = 2;
			SetPointLeftWheel(0.30,driveflag);
			SetPointRightWheel(0.2,driveflag);
		}
		else if(((joystick_x > 1340) && (joystick_x < 1370)) && ((joystick_y > 610) && (joystick_y < 790))) // 90% höger
		{
			driveflag = 2;
			SetPointLeftWheel(0.2,driveflag);
			SetPointRightWheel(0.32,driveflag);
		}
		/*LEFT WHEEL!!!!!*/
		else if(((joystick_x > 500) && (joystick_x < 590)) && ((joystick_y > 1340) && (joystick_y < 1370))) // 15% vänster
		{
			driveflag = 2;
			SetPointLeftWheel(0.2,driveflag);
			SetPointRightWheel(0.22,driveflag);
		}
		else if(((joystick_x > 300) && (joystick_x < 490)) && ((joystick_y > 1340) && (joystick_y < 1370))) // 30% vänster
		{
			driveflag = 2;
			SetPointLeftWheel(0.2,driveflag);
			SetPointRightWheel(0.24,driveflag);	
		}
		else if(((joystick_x > 100) && (joystick_x < 290)) && ((joystick_y > 1340) && (joystick_y < 1370))) // 45% vänster
		{
			driveflag = 2;
			SetPointLeftWheel(0.2,driveflag);
			SetPointRightWheel(0.26,driveflag);	
		}
		else if(((joystick_x >= 0) && (joystick_x < 90)) && ((joystick_y > 1340) && (joystick_y < 1370))) // 60% vänster
		{
			driveflag = 2;
			SetPointLeftWheel(0.2,driveflag);
			SetPointRightWheel(0.28,driveflag);
		}
		else if(((joystick_x >= 0) && (joystick_x < 90)) && ((joystick_y > 1000) && (joystick_y < 1330))) // 75% vänster
		{
			driveflag = 2;
			SetPointLeftWheel(0.2,driveflag);
			SetPointRightWheel(0.30,driveflag);
		}
		else if(((joystick_x >= 0) && (joystick_x < 90)) && ((joystick_y > 610) && (joystick_y < 990))) // 90% vänster
		{
			driveflag = 2;
			SetPointLeftWheel(0.2,driveflag);
			SetPointRightWheel(0.32,driveflag);	
		}
	
		xSampleTime = (portTickType)sampleTimeLeft;
		vTaskDelayUntil(&xLastWakeTime, xSampleTime); //Wait for the next cycle the task will be active.
	}
}

