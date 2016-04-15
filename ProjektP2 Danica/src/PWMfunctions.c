/*
 * PWMfunctions.c
 *
 * Created: 2016-04-10 13:38:40
 *  Author: Martin
 */ 
#include <asf.h>
#include "PWMfunctions.h"

void InitPWM(void){
	pmc_enable_periph_clk(ID_PWM);
	pwm_channel_disable(PWM, PWM_CHANNEL_3);
	
	pwm_clock_t clock_setting = {
		.ul_clka = 1000 * 1000,
		.ul_clkb = 0,
		.ul_mck = sysclk_get_cpu_hz()
	};
	pwm_init(PWM, &clock_setting);

}