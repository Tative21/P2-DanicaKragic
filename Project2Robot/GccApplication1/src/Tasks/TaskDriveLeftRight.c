/*
* JoystickOptions.c
*
* Author: William and Elvin joystick logic. Michael and Martin change the joystick logic.
*
* Content: A task containing logic for turning the robot left or right.
*/

#include <asf.h>
#include "Tasks/TaskDriveLeftRight.h"
#include "Tasks/TaskPIDLeft.h"
#include "Tasks/TaskPIDRight.h"
#include "Tasks/TaskUltraljud.h"
#include "PWMFunctions/PWMFunctions.h"
#include "adc/adcFunctions.h"
#include "init_pins.h"


uint32_t joystick_x;
uint32_t joystick_y;
uint32_t standby = 0;

static uint32_t sampleTimeLeft = 100; //  task time[ms]


/**************************************************************************
Task for driving left, right or forward.
**************************************************************************/
void TaskDriveLeftRight(void *p)
{
	portTickType xLastWakeTime; //Last time the task was active.
	portTickType xSampleTime;
	
	xLastWakeTime = xTaskGetTickCount();

	while(1){
		xSampleTime = (portTickType)sampleTimeLeft;
		vTaskDelayUntil(&xLastWakeTime, xSampleTime); //Wait for the next cycle the task will be active.
		
		if((drive != 1)){
			joystick_x = ReadAnalog0();
			joystick_y = ReadAnalog1();

			if(((joystick_x > 585) && (joystick_x < 680)) && ((joystick_y > 595) && (joystick_y < 680)) ) // default(standby)
			{
				setDesiredValueLeft(0);
				setDesiredValueRight(0);
				standby = 1;
				
			}
			else if((joystick_y > 1390) && (joystick_x > 631 && joystick_x < 710))	//Drive forward at full speed.
			{
				setDesiredValueLeft(0.3);
				setDesiredValueRight(0.3);
				standby = 0;
			}
			else if((joystick_x > 1000 && joystick_x < 1200) && joystick_y > 1390)	// Drive Light Right
			{
				setDesiredValueLeft(0.3);
				setDesiredValueRight(0.2);
				standby = 0;
			}
			else if((joystick_x > 1250) && (joystick_y > 1400))						// Drive  Medium Right
			{
				setDesiredValueLeft(0.3);
				setDesiredValueRight(0.1);
				standby = 0;
				} else if((joystick_x> 1335) && (joystick_y < 1000 && joystick_y > 690)){ // Drive Hard Right
				setDesiredValueLeft(0.3);
				setDesiredValueRight(0.05);
				standby = 0;
			}
			else if((joystick_x < 565 && joystick_x > 350) && (joystick_y > 1400)) // Drive Light Left
			{
				setDesiredValueLeft(0.2);
				setDesiredValueRight(0.3);
				standby = 0;
			}
			else if((joystick_x < 340 && joystick_x >= 220) && (joystick_y > 1400)) // Drive Medium Left
			{
				setDesiredValueLeft(0.1);
				setDesiredValueRight(0.3);
				standby = 0;
			}else if((joystick_x < 215 && joystick_x >= 0) && (joystick_y < 1480 && joystick_y > 450)) // Drive Hard Left
			{
				setDesiredValueLeft(0.1);
				setDesiredValueRight(0.3);
				standby = 0;
			}
			else if((joystick_x < 750) && (joystick_y == 0)) // Backwards
			{
				setDesiredValueLeft(5);
				setDesiredValueRight(5);
				standby = 0;
			}
		}
	}
}

