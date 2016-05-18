/*
 * TaskCalculateLeftWheel.c
 *
 * 
 *  Author: Martin and Michael
 *
 * Content: Calculate velocity for right wheel
 */ 
#include <asf.h>
#include <inttypes.h>
#include "interrupts/InterruptPioRightWheel.h"
#include "Tasks/TaskCalculateRightWheel.h"

uint32_t timerRightWheel;
uint32_t counterRightWheel;
float sekRightWheel;
extern hastighetRightWheel;
float omkretsHjulRight = 0.45;
float distanceRightWheel = 0.0;
uint32_t hzforcpuRight  = 2625000; 
static uint32_t sampleTimeRight = 6; 


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

		if(counterRightWheel != 0){
			distanceRightWheel = (float) ((((float) counterRightWheel/36) * (float) omkretsHjulRight)*1000);
			sekRightWheel += ((float)timerRightWheel/(float)hzforcpuRight) * 1000;
		}

		if((distanceRightWheel > 0) && (sekRightWheel > 0)){
			hastighetRightWheel = (((float)((float)distanceRightWheel/(float)sekRightWheel)*1000));
		}		
		printf("%d\n", counterRightWheel);	
	}
}