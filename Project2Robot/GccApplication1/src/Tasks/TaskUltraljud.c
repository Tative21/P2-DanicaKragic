/*
* TaskUltraljud.c
*
* Author: William Patricia Hamoud, Michael, Martin
*
* content: This file contents the logic for avoiding obstacles
*/

#include <asf.h>
#include <inttypes.h>
#include "init_pins.h"
#include "Tasks/TaskPIDLeft.h"
#include "Tasks/TaskPIDRight.h"
#include "Tasks/TaskDriveLeftRight.h"
#include "Tasks/TaskUltraljud.h"

extern uint32_t standby;
uint32_t drive=0;						// this variable is used to override the joystick if ultrasound detects obstacle
static uint32_t sampleTimeLeft = 150; //  task time[ms]

/*
 This function contains the necessary logic for avoiding obstacles
*/
void TaskUltraLjud (void *p)
{
	portTickType xLastWakeTime; //Last time the task was active.
	portTickType xSampleTime;
	xLastWakeTime = xTaskGetTickCount(); 
	
	pinMode(pin3,INPUT);
	pinMode(pin4,INPUT);
	pinMode(pin5,INPUT);
	pinMode(pin6,INPUT);
	pinMode(pin11,OUTPUT);
	pinMode(pin12,OUTPUT);
	pinMode(pin13,OUTPUT);
	
	while (1)
	{
		xSampleTime = (portTickType)sampleTimeLeft;
		vTaskDelayUntil(&xLastWakeTime, xSampleTime);//Wait for the next cycle the task will be active.
		
		if(standby == 0){
			if((getPin(pin5) == HIGH) && (getPin(pin4) == HIGH) &&  (getPin(pin3) == HIGH)){ // All ultrasound detects obstacle
				drive=1;
				setDesiredValueLeft(5);
				setDesiredValueRight(5);
				vTaskDelay(100);
				setDesiredValueLeft(0);
				setDesiredValueRight(0);
				} else if(((getPin(pin4) == HIGH) && (getPin(pin3) == HIGH)) || ((getPin(pin3) == HIGH) && (getPin(pin5) == HIGH)) || ((getPin(pin4) == HIGH) && (getPin(pin5) == HIGH))){
				
				if((getPin(pin4) == HIGH) && (getPin(pin3) == HIGH)){  // Left and Center ultrasound detects obstacle
					drive = 1;
					setDesiredValueLeft(0);
					setDesiredValueRight(5);
					vTaskDelay(100);
					setDesiredValueLeft(0);
					setDesiredValueRight(0);
				}
				if((getPin(pin3) == HIGH) && (getPin(pin5) == HIGH)){ // Right and Center ultrasound detects obstacle
					drive = 1;
					setDesiredValueLeft(5);
					setDesiredValueRight(0);
					vTaskDelay(100);
					setDesiredValueLeft(0);
					setDesiredValueRight(0);
				}
				if((getPin(pin4) == HIGH) && (getPin(pin5) == HIGH)){ // Both Right and Left Ultrasound detects obstacle
					drive  = 0;
				}
				} else if(getPin(pin3) == HIGH){						//  Only center ultrasound detects obstacle
				drive = 1;
				setDesiredValueLeft(0.3);
				setDesiredValueRight(0);
				vTaskDelay(100);
				setDesiredValueLeft(0);
				setDesiredValueRight(0);
				} else if(getPin(pin4) == HIGH){						// Only Left ultrasound detects obstacle
				drive = 1;
				setDesiredValueLeft(0.3);
				setDesiredValueRight(0);
				vTaskDelay(100);
				setDesiredValueLeft(0);
				setDesiredValueRight(0);
				} else if( getPin(pin5) == HIGH){						// Only Right ultrasound detects obstacle
				drive = 1;
				setDesiredValueLeft(0);
				setDesiredValueRight(0.3);
				vTaskDelay(100);
				setDesiredValueLeft(0);
				setDesiredValueRight(0);
			}
			else if ((getPin(pin5) == LOW) && (getPin(pin4) == LOW) &&  (getPin(pin3) == LOW)){ // When no ultrasound detects  obstacle
				drive =0;
			}
		}
	}
};