/*
 * TaskMatlab.c
 *
 *  Author: Michael and Martin
 *
 * Content: Send necessary values to matlab.
 */ 
#include <asf.h>
#include <inttypes.h>
#include "Tasks/TaskMatlab.h"


static uint32_t sampleTimeLeft = 50; 
uint32_t sendmatlab = 0;
uint32_t bv = 0;
int32_t errortomat = 0;
uint32_t averagehastighet = 0;

/************************************
* Sends values to matlab using printf
*************************************/
void TaskMatLab(void *p)
{

	portTickType xLastWakeTime;
	portTickType xSampleTime;
	xLastWakeTime = xTaskGetTickCount();

	while(1)
	{
		xSampleTime = (portTickType)sampleTimeLeft;
		vTaskDelayUntil(&xLastWakeTime, xSampleTime);
		
		printf("%d\n",sendmatlab);
		printf("%d\n",bv);
		printf("%d\n",errortomat);
		printf("%d\n",averagehastighet);
	
	}
}

/**********************************
* Sets the variables                            
***********************************/
void SendControlSignalLeftPID(uint32_t signal, float desiredValue,float error,uint32_t averageSensorValue){
	sendmatlab = signal;
	bv = desiredValue * 1000;	
	errortomat = error*1000;
	averagehastighet = averageSensorValue;
}