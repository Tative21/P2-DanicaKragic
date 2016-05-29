/*
* TaskCalculateLeftWheel.c
*
* Author: Martin and Michael. Comments by Michael and Martin
*
* Content: Calculate the velocity for left wheel.
*/
#include <asf.h>
#include <inttypes.h>
#include "interrupts/InterruptPioLeftWheel.h"
#include "Tasks/TaskCalculateLeftWheel.h"
#include "Tasks/TaskPIDLeft.h"

uint32_t timerLeftWheel;
uint32_t counterLeftWheel;
float sekLeftWheel;
extern hastighetLeftWheel;
float omkretsHjul = 0.45;
float distanceLeftWheel = 0.0;
uint32_t hzforcpu  = 2625000;
static uint32_t sampleTimeLeft = 6;  // Task time [ms]

/**********************************************
Calculate the velocity for left wheel.
***********************************************/
void TaskCalculateLeftWheel(void *p)
{

	portTickType xLastWakeTime;
	portTickType xSampleTime;
	xLastWakeTime = xTaskGetTickCount();
	
	while(1)
	{
		xSampleTime = (portTickType)sampleTimeLeft;
		vTaskDelayUntil(&xLastWakeTime, xSampleTime);
		
		if  (getDesiredValueLeft() <4 && getDesiredValueLeft() >= 0){ //If desired value for driving forward
			if(counterLeftWheel != 0){
				distanceLeftWheel = (((float)( (float)counterLeftWheel/36) * (float) omkretsHjul)*1000); //distance
				sekLeftWheel += ((float)timerLeftWheel/(float)hzforcpu) * 1000;	//time
			}

			if((distanceLeftWheel > 0) && (sekLeftWheel > 0)){
				hastighetLeftWheel = (((float)((float)distanceLeftWheel/(float)sekLeftWheel)*1000)); //velocity
			}
			}else{ //reset
			sekLeftWheel = 0;
			distanceLeftWheel = 0;
			counterLeftWheel = 0;
			timerLeftWheel = 0;
			tc_stop(TC0,0);
		}
	}
}