/*
* Author: Michael and Martin.
*
* Content: A task containing logic for driving the robot forward or backward.
*/

#include <asf.h>
#include <inttypes.h>
#include "adc/adcFunctions.h"
#include "Tasks/TaskPIDLeft.h"
#include "Tasks/TaskCalculateLeftWheel.h"
#include "DelayFunctions/DelayFunctions.h"
#include "Tasks/TaskDriveLeftRight.h"
#include "PWMFunctions/PWMFunctions.h"
#include "Tasks/TaskMatlab.h"

#define POSITIONS 6

static uint32_t sampleTimeLeft = 50;
static float filterLeft[POSITIONS] = {0};
float desiredValueLeft = 0;
static float finalULeft = 0;
static float errorLeft = 0;
static float prevErrorLeft = 0;
static float wLeft = 0;
float currentVLeft = 0;
uint32_t hastighetLeftWheel;

static float kpLeft = 1.0879;	 //0.8
static float kiLeft = 2.021;	 // 0.65
static float kdLeft = 0.098497; // 0.1425
static float samplingTimeLeft = 0.05;

/**************************************************************************
Task for driving the left wheel forward and backward. The task contains logic 
for running the wheel with a PID-regulator. It calls on a function containing 
the actual PID and another function translating actual speed values to PWM 
signals.
**************************************************************************/
void TaskPIDLeft(void *p)
{
	
	
	uint32_t joystick_y;
	uint32_t joystick_x;
	portTickType xLastWakeTime; //Last time the task was active.
	portTickType xSampleTime;
	xLastWakeTime = xTaskGetTickCount();
	uint32_t temp;
	int averageSensorValue = 0;
	while(1){
		xSampleTime = (portTickType)sampleTimeLeft;
		vTaskDelayUntil(&xLastWakeTime, xSampleTime); //Wait for the next cycle the task will be active.
		
		int32_t temp;
		if(desiredValueLeft != 0){
		filterLeft[POSITIONS-1] = hastighetLeftWheel;
		
		
		for(int i = 0; i<POSITIONS; i++)
		{
			averageSensorValue =  (averageSensorValue + filterLeft[i]);
		}
		
		averageSensorValue =  (averageSensorValue / POSITIONS);
		
		for(int i = 0; i<POSITIONS-1; i++)
		{
			filterLeft[i] = filterLeft[i+1];
		}
		
		filterLeft[POSITIONS-1] = 0;
		currentVLeft = averageSensorValue;
		errorLeft =  (float) ((float)desiredValueLeft - (float)(currentVLeft/1000));
		prevErrorLeft = errorLeft;
		wLeft = wLeft + errorLeft;

		finalULeft = (float)CalcSignal(samplingTimeLeft, kpLeft, kiLeft, kdLeft, errorLeft, prevErrorLeft, wLeft);
		temp = finalULeft*1000;

		
		
		}
		else{
			finalULeft = 0.0;
			temp = 0;
			averageSensorValue = 0;
			currentVLeft = 0;
		}
		/*if(temp<0){
			finalULeft = 0;
		}else if(temp > 300 ){
			finalULeft = 1;
		}*/
		valuesforPWM(finalULeft);
		//SendControlSignalLeftPID(temp, desiredValueLeft,errorLeft,averageSensorValue);
		
	}
}

/**************************************************************************
The PID-regulator.
**************************************************************************/
float CalcSignal(float sampTime, float k_p, float k_i, float k_d, float currErr, float prevErr, int32_t sumErr)
{
	float proportionalPart;
	float integralPart;
	float derivingPart;
	float signal;
	
	proportionalPart = (float)currErr;
	integralPart = (float)(sumErr * (sampTime/k_i));
	derivingPart = ((float)currErr - (float)prevErr) * (float)(k_d / sampTime);
	signal = (float)k_p * ((float)(proportionalPart + integralPart + derivingPart));
	
	return signal;
}

/**************************************************************************
Function for translating actual speed values to PWM signals. 
**************************************************************************/
void valuesforPWM(float finalULeft){
	
	if(finalULeft <= 0.016){
		LeftWheelPWM(1500);
	}
	else if(finalULeft >= 0.017 && finalULeft <= 0.026){
		LeftWheelPWM(1390);
	}
	else if(finalULeft >= 0.026 && finalULeft <= 0.033){
		LeftWheelPWM(1370);
	}
	else if(finalULeft >= 0.034 && finalULeft <= 0.077){
		LeftWheelPWM(1350);
	}
	else if(finalULeft >= 0.078 && finalULeft <= 0.101){
		LeftWheelPWM(1330);
	}
	else if(finalULeft >= 0.102 && finalULeft <= 0.149){
		LeftWheelPWM(1310);
	}
	else if(finalULeft >= 0.150 && finalULeft <= 0.194){
		LeftWheelPWM(1290);
	}
	else if(finalULeft >= 0.195 && finalULeft <= 0.212){
		LeftWheelPWM(1270);
	}
	else if(finalULeft >= 0.213 && finalULeft <= 0.250){
		LeftWheelPWM(1250);
	}
	else if(finalULeft >= 0.251 && finalULeft <= 0.315){
		LeftWheelPWM(1230);
	}
	else if(finalULeft >= 0.316 && finalULeft <= 0.379){
		LeftWheelPWM(1210);
	}
	else if(finalULeft > 0.38){
		LeftWheelPWM(1200);
	}
}

void SetPointLeftWheel(float setPoint){
	desiredValueLeft = setPoint;
}