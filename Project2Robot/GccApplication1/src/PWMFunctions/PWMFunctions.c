 /*
 * PWMFunctions.c
 *
 * Author: Michael och Martin. Comments written by Michael.
 * 
 * Content: Initializes PWM. Initializes pin 38 och 40 on the DUE
 * for PWM. Functions for writing PWM values to the engines.   
 */ 

#include <asf.h>
#include "PWMFunctions.h"

pwm_channel_t PWMPin40;
pwm_channel_t PWMPin38;

/************************************************************************
* Configuration of the Pulse Width Modulation (PWM). 
/************************************************************************/
void PWMInit(void)
{
	pmc_enable_periph_clk(ID_PWM);
	pwm_channel_disable(PWM, PWM_CHANNEL_3);
	pwm_channel_disable(PWM, PWM_CHANNEL_2);
	
	pwm_clock_t clock_setting = {
		.ul_clka = 50 * 19999,
		.ul_clkb = 0,
		.ul_mck = sysclk_get_cpu_hz()
	};
	pwm_init(PWM, &clock_setting);
	
	InitPIN40();
	InitPIN38();
}

/************************************************************************
* Initiation of digital pin 40 on the Arduino Due board. 
/************************************************************************/
void InitPIN40(void)
{
	PWMPin40.channel = PWM_CHANNEL_3;
	PWMPin40.ul_prescaler = PWM_CMR_CPRE_CLKA;
	PWMPin40.ul_duty = 0;
	PWMPin40.ul_period = 19999;
	pwm_channel_init(PWM, &PWMPin40);
	pio_set_peripheral(PIOC, PIO_PERIPH_B, PIO_PC8B_PWML3);
	pwm_channel_enable(PWM, PWM_CHANNEL_3);
}

/************************************************************************
* Initiation of digital pin 38 on the Arduino Due board.
/************************************************************************/
void InitPIN38(void)
{
	PWMPin38.channel = PWM_CHANNEL_2;
	PWMPin38.ul_prescaler = PWM_CMR_CPRE_CLKA;
	PWMPin38.ul_duty = 0;
	PWMPin38.ul_period = 19999;
	pwm_channel_init(PWM, &PWMPin38);
	pio_set_peripheral(PIOC, PIO_PERIPH_B, PIO_PC6B_PWML2);
	pwm_channel_enable(PWM, PWM_CHANNEL_2);
}


/************************************************************************
* Function for setting a PWM value to the left engine. 
/************************************************************************/
void LeftWheelPWM(uint32_t dutyCycle)
{
	pwm_channel_update_duty(PWM, &PWMPin40, dutyCycle);
}

/************************************************************************
* Function for setting a PWM value to the right engine.
/************************************************************************/
void RightWheelPWM(uint32_t dutyCycle)
{
	pwm_channel_update_duty(PWM, &PWMPin38, dutyCycle);
}