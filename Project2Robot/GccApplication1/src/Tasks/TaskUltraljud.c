/*
 * TaskUltraljud.c
 *
 * Created: 2016-05-16 15:19:22
 *  Author: William Patricia Hamoud
 */ 
#include "TaskUltraljud.h"
#include <asf.h>
#include <inttypes.h>
#include "init_pins.h"

static uint32_t sampleTimeLeft = 100;

void TaskUltraLjud (void *p)
{
	portTickType xLastWakeTime;
	portTickType xSampleTime;
	xLastWakeTime = xTaskGetTickCount();
	pinMode(pin3,INPUT);		
	pinMode(pin4,INPUT);
	pinMode(pin5,INPUT);
	pinMode(pin6,INPUT);
	pinMode(pin11,OUTPUT);
	pinMode(pin12,OUTPUT);
	pinMode(pin13,OUTPUT);
	drive=0;
	
	while (1)
	{
		xSampleTime = (portTickType)sampleTimeLeft;
		vTaskDelayUntil(&xLastWakeTime, xSampleTime);
		
		
		if (getPin(pin3)==HIGH)                //Raktfram ultraljudet
		{
			drive=1;
			setPin(pin11,HIGH);
			
				if (getPin(pin4)==HIGH)        //vänster ultraljudet      12.5 cm,  45%, 0.3m/s, 0.4 sekunder 
				{
					setPin(pin12,HIGH);
			}    
			else if (getPin(pin4)==LOW)
			{
				setPin(pin12,LOW);
			}                         //glöm ej höger ultraljud
			
		}
		
		else if (getPin(pin3)==LOW)
		{
			drive=0;
			setPin(pin11,LOW);
		}
//--------------------------------------------------------------------
	
		
	}
	};