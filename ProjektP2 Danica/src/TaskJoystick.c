/*
 * TaskJoystick.c
 *
 * Created: 2016-04-10 13:35:22
 *  Author: Martin William Patricia Elvin
 */ 

#include <asf.h>
#include <inttypes.h>
#include "TaskJoystick.h"
#include "adc/adcFunctions.h"
#include "PWMfunctions.h"
#include "DelayFunctions/DelayFunctions.h"



void TaskJoystickX(void)
{
	uint32_t joystick_x;
	uint32_t joystick_y;

	
	pinMode(Analog0,Input);	//x-axeln till joysticken									Analog In 0
	pinMode(Analog1,Input);	//y-axeln till joysticken									Analog In 1
	
	pinMode(pin3,Output);	// digital pin för lampa									Digital Pin 3
	pinMode(pin8,Output);	// digital pin för lampa									Digital pin 8
	pinMode(pin6,Output);// Då man trycker på joysticken ska en lampa lyssna			Digital pin 6
	pinMode(pin5,Input); //Läser av switchen på joysticken(trycker på joysticken)		Digital Pin 5

	while(1){
		joystick_x =  ReadAnalog0();    
		//printf("%d \n", ReadAnalog0());
		//joystick_y = ReadAnalog1();
		//printf("%d \n", ReadAnalog1());
		vTaskDelay(100);
	
		if((joystick_x > 585) && (joystick_x < 680) ) // Rakt fram
		{
			setPin(pin3,HIGH);
			
		} 
		else if((joystick_x > 681) && (joystick_x < 760 )) // 15% höger
		{
			setPin(pin3,LOW);
			
		}
		else if((joystick_x > 761) && (joystick_x < 870) ) // 30% höger
		{
			setPin(pin3,LOW);
			
		}
		else if((joystick_x > 871) && (joystick_x < 980 )) // 45% höger
		{
			setPin(pin3,LOW);
		
		}
		else if((joystick_x > 980) && (joystick_x < 1090) ) // 60% höger
		{
			setPin(pin3,LOW);
		
		}
		else if((joystick_x > 1090) && (joystick_x < 1200) ) // 75% höger
		{
			setPin(pin3,LOW);
		
		}
		else if((joystick_x > 1200) && (joystick_x < 1500) ) // 90% höger
		{
			setPin(pin3,HIGH);
		}
		else if((joystick_x > 540) && (joystick_x < 585) ) // 15% vänster
		{
			setPin(pin3,LOW);
		}
		else if((joystick_x > 420) && (joystick_x < 540) ) // 30% vänster
		{
			setPin(pin3,LOW);
		}
		else if((joystick_x > 325) && (joystick_x < 420) ) // 45% vänster
		{
			setPin(pin3,LOW);
		}
		else if((joystick_x > 215) && (joystick_x < 325) ) // 60% höger
		{
			setPin(pin3,LOW);
		}
		
		else if((joystick_x > 105) && (joystick_x < 215) ) // 75% höger
		{
			setPin(pin3,LOW);
		}
		else if((joystick_x >= 0) && (joystick_x < 105) ) // 90% höger
		{
			setPin(pin3,HIGH);
		}
		/*
		if((joystick_y > 585)) // kör fram
		{
			setPin(pin8,HIGH);
		}
		if((joystick_y <= 585)) // Kör bak
		{
			setPin(pin8,LOW);
		}
		*/
		
		else{
		setPin(pin3,LOW);
		}
		}

}
void TaskJoystickY(void)
{
		uint32_t joystick_x;
		uint32_t joystick_y;

		
		pinMode(Analog0,Input);	//x-axeln till joysticken									Analog In 0
		pinMode(Analog1,Input);	//y-axeln till joysticken									Analog In 1
		
		pinMode(pin3,Output);	// digital pin för lampa									Digital Pin 3
		pinMode(pin8,Output);	// digital pin för lampa									Digital pin 8
		pinMode(pin6,Output);// Då man trycker på joysticken ska en lampa lyssna			Digital pin 6
		pinMode(pin5,Input); //Läser av switchen på joysticken(trycker på joysticken)		Digital Pin 5
	
	
	while(1){
		joystick_y = ReadAnalog1();
		printf("%d \n", ReadAnalog1());
		
			if((joystick_y > 585)) // kör fram
			{
				setPin(pin8,HIGH);
			}
			if((joystick_y <= 585)) // Kör bak
			{
				setPin(pin8,LOW);
			}
	}
}
	