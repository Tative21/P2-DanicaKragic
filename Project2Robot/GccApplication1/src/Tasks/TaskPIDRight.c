/*
* TaskPIDRight.c
*
*  Author: Martin, Michael and Elvin. Review by William.
*
* Content:  A task containing logic for PID-regulation for right wheel
*/

#include <asf.h>
#include <inttypes.h>
#include "PWMFunctions/PWMFunctions.h"
#include "Tasks/TaskCalculateRightWheel.h"
#include "Tasks/TaskMatlab.h"
#include "Tasks/TaskPIDRight.h"

#define POSITIONS 4
static uint32_t sampleTimeRight = 50; //  task time[ms]
static float filterRight[POSITIONS] = {0};
float desiredValueRight = 0;
static float finalURight = 0;
float errorRight = 0;
static float prevErrorRight = 0;
static float wRight = 0;
float currentVRight = 0;
uint32_t hastighetRightWheel;

static float kpRight = 0.66124;
static float kiRight = 2.9641;
static float kdRight = -0.039706;
static float samplingTimeRight = 0.05;


/**************************************************************************
Task for driving the right wheel forward and backward. The task contains logic
for running the wheel with a PID-regulator. It calls on a function containing
the actual PID and another function translating actual speed values to PWM
signals.
**************************************************************************/
void TaskPIDRight(void *p)
{
	
	uint32_t joystick_y;
	uint32_t joystick_x;
	portTickType xLastWakeTime; //Last time the task was active.
	portTickType xSampleTime;
	xLastWakeTime = xTaskGetTickCount();
	int averageSensorValue = 0;
	uint32_t temp = 0;
	while(1){
		xSampleTime = (portTickType)sampleTimeRight;
		vTaskDelayUntil(&xLastWakeTime, xSampleTime); //Wait for the next cycle the task will be active.
		
		if((desiredValueRight > 0.0) && (desiredValueRight < 5)){
			//Moving average
			filterRight[POSITIONS-1] = hastighetRightWheel;
			
			for(int i = 0; i<POSITIONS; i++)
			{
				averageSensorValue =  (averageSensorValue + filterRight[i]);
			}
			
			averageSensorValue =  (averageSensorValue / POSITIONS);
			
			for(int i = 0; i<POSITIONS-1; i++)
			{
				filterRight[i] = filterRight[i+1];
			}
			
			filterRight[POSITIONS-1] = 0;
			// End of moving average
			
			currentVRight = averageSensorValue;
			errorRight =  (float) ((float)desiredValueRight - (float)currentVRight/1000); // current error
			
			prevErrorRight = errorRight;													// previous error
			wRight = wRight + errorRight;													// sum of error

			finalURight = (float)CalcSignalRight(samplingTimeRight, kpRight, kiRight, kdRight, errorRight, prevErrorRight, wRight); // control signal
			if(finalURight < 0)
			{
				finalURight = 0;
			}
			valuesforPWMRight(finalURight);
			//temp = finalURight * 1000;
			//SendControlSignalLeftPID(temp, desiredValueRight,errorRight,averageSensorValue); // this function is used to set the values which will be sent to matlab.
		}else if (desiredValueRight == 0) // standby
		{
			wRight = 0;
			finalURight = 0.0;
			valuesforPWMRight(finalURight);
		}else if(desiredValueRight == 5) // backward
		{
			wRight  = 0;
			RightWheelPWM(1690);
		}
	}
}

/**************************************************************************
The PID-regulator.
**************************************************************************/
float CalcSignalRight(float sampTime, float k_p, float k_i, float k_d, float currErr, float prevErr, float sumErr)
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

/*********************************************
Function for translating actual speed values to PWM signals.
***********************************************/
void valuesforPWMRight(float finalULeft){
	
	if(finalULeft <= 0.017){
		RightWheelPWM(1500);
	}
	else if(finalULeft >= 0.018 && finalULeft <= 0.029){
		RightWheelPWM(1390);
	}
	else if(finalULeft >= 0.03 && finalULeft <= 0.055){
		RightWheelPWM(1370);
	}
	else if(finalULeft >= 0.056 && finalULeft <= 0.085){
		RightWheelPWM(1350);
	}
	else if(finalULeft >= 0.086 && finalULeft <= 0.128){
		RightWheelPWM(1330);
	}
	else if(finalULeft >= 0.129 && finalULeft <= 0.155){
		RightWheelPWM(1310);
	}
	else if(finalULeft >= 0.156 && finalULeft <= 0.182){
		RightWheelPWM(1290);
	}
	else if(finalULeft >= 0.183 && finalULeft <= 0.220){
		RightWheelPWM(1270);
	}
	else if(finalULeft >= 0.221 && finalULeft <= 0.267){
		RightWheelPWM(1250);
	}
	else if(finalULeft >= 0.268 && finalULeft <= 0.334){
		RightWheelPWM(1230);
	}
	else if(finalULeft >= 0.335 && finalULeft <= 0.372){
		RightWheelPWM(1210);
	}
	else if(finalULeft > 0.372){
		RightWheelPWM(1200);
	}
}
/*********************************************************
Returns desiredValue.
**********************************************************/
float getDesiredValueRight(void){
	return desiredValueRight;
}

/*********************************************************
Sets value for drive forward and backwards and the setpoint for PID-regulator
**********************************************************/
void setDesiredValueRight(float tempdesire){
	desiredValueRight = tempdesire;
}