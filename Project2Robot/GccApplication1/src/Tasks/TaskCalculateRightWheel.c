/*
* TaskCalculateLeftWheel.c
*
*  Author: Martin and Michael
*
* Content: Calculate velocity for right wheel
*/
#include <asf.h>
#include <inttypes.h>
#include "interrupts/InterruptPioRightWheel.h"
#include "Tasks/TaskCalculateRightWheel.h"
#include "Tasks/TaskPIDRight.h"

uint32_t timerRightWheel;
uint32_t counterRightWheel;
float sekRightWheel;
extern hastighetRightWheel;

float omkretsHjulRight = 0.45;
float distanceRightWheel = 0.0;
uint32_t hzforcpuRight  = 2625000;

static uint32_t sampleTimeRight = 6; // Task time [ms]

/************************************************
* Calculate velocity for right wheel
*************************************************/
void TaskCalculateRightWheel(void *p)
{

	portTickType xLastWakeTime;
	portTickType xSampleTime;
	xLastWakeTime = xTaskGetTickCount();

	while(1)
	{
		xSampleTime = (portTickType)sampleTimeRight;
		vTaskDelayUntil(&xLastWakeTime, xSampleTime);
		
		if(getDesiredValueRight() <4 && getDesiredValueRight() >= 0){//If desired value for driving forward
			if(counterRightWheel != 0){
				distanceRightWheel = (float) ((((float) counterRightWheel/36) * (float) omkretsHjulRight)*1000); //distance
				sekRightWheel += ((float)timerRightWheel/(float)hzforcpuRight) * 1000; // time
			}

			if((distanceRightWheel > 0) && (sekRightWheel > 0)){
				hastighetRightWheel = (((float)((float)distanceRightWheel/(float)sekRightWheel)*1000)); //velocity
			}
			}else{ // reset
			sekRightWheel = 0;
			distanceRightWheel = 0;
			counterRightWheel = 0;
			timerRightWheel = 0;
			tc_stop(TC2,1);
		}
	}
}