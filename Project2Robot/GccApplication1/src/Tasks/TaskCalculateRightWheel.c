/*
 * TaskCalculateLeftWheel.c
 *
 * Created: 2016-05-04 23:28:56
 *  Author: Martin och Martin
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
uint32_t hzforcpuRight  = 2625000; // . ÄNDRA HÄR OM VI ANVÄNDER "TC_CMR_TCCLKS_TIMER_CLOCK3" I INTERRUPTPIO.C
static uint32_t sampleTimeRight = 6; //GLÖM INTE ATT DEN ÄR KORT. RÄKNA INTE UTANFÖR TASKEN!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


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