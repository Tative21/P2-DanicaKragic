/*
 * TaskJoystick.c
 *
 * Created: 2016-04-10 13:35:22
 *  Author: Martin
 */ 

#include <asf.h>
#include <inttypes.h>
#include "TaskJoystick.h"
#include "adc/adcFunctions.h"
#include "PWMfunctions.h"
#include "DelayFunctions/DelayFunctions.h"
#include "consoleFunctions.h"



void TaskJoystick(void *p)
{
	uint32_t joystick_x;
	uint32_t joystick_y;
	portTickType xLastWakeTime;
	const portTickType xTimeIncrement = 250;
	xLastWakeTime = xTaskGetTickCount();
	
	ioport_set_pin_dir(Analog0,IOPORT_DIR_INPUT);	//x-axeln till joysticken									Analog In 0
	ioport_set_pin_dir(Analog1,IOPORT_DIR_INPUT);	//y-axeln till joysticken									Analog In 1
	
	ioport_set_pin_dir(digital,IOPORT_DIR_OUTPUT);	// digital pin för lampa									Digital Pin 3
	ioport_set_pin_dir(digital1,IOPORT_DIR_OUTPUT);	// digital pin för lampa									Digital pin 8
	ioport_set_pin_dir(digital11,IOPORT_DIR_OUTPUT);// Då man trycker på joysticken ska en lampa lyssna			Digital pin 6
	ioport_set_pin_dir(digital2,IOPORT_DIR_INPUT); //Läser av switchen på joysticken(trycker på joysticken)		Digital Pin 5
	
	printf("HEJ");
	while(1){
		joystick_x =  ReadAnalog();    //ioport_get_pin_level(Analog0);
		joystick_y = ioport_get_pin_level(Analog1);
		vTaskDelay(100);
		
		printf("%f\n",joystick_y);
	
		if(joystick_x > 159)
		{
			ioport_set_pin_level(digital,HIGH);
		}else{
			ioport_set_pin_level(digital,LOW);
		}
	
		if(joystick_y > 100)
		{
			ioport_set_pin_level(digital1,HIGH);
		}
		
		if(ioport_get_pin_level(digital2))
		{
			ioport_set_pin_level(digital11,HIGH);
		}
	}
	vTaskDelayUntil(&xLastWakeTime, xTimeIncrement);
	
	
	
}