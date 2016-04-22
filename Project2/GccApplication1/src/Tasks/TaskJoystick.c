/*
 * TaskJoystick.c
 *
 * Created: 2016-04-10 13:35:22
 *  Author: Michael och Martin
 */ 

#include <asf.h>
#include <inttypes.h>
#include <FreeRTOS.h>
#include "TaskJoystick.h"
#include "adc/adcFunctions.h"
#include "DriveOptions/driveForwardAndBackward.h"
#include "PWMfunctions.h"
#include "DelayFunctions/DelayFunctions.h"
static uint32_t sampleTime = 100;

void TaskJoystick(void *p)
{		
	   portTickType xLastWakeTime;
	   portTickType xSampleTime;
	   
	 
	   xLastWakeTime = xTaskGetTickCount();

	   while(1){
		   
		xSampleTime = (portTickType)sampleTime;
		vTaskDelayUntil(&xLastWakeTime, xSampleTime);
		   
	   }
	
	
	
}