/*
 * adcFunctions.c
 *
 * Created: 2016-04-10 13:00:57
 *  Author: Martin William Elvin
 */ 

#include <inttypes.h>
#include <asf.h>
#include "adcFunctions.h"


int analogInit(void)
{
	pmc_enable_periph_clk(ID_ADC);
	adc_init(ADC,sysclk_get_main_hz(),1000000,8);
	adc_configure_timing(ADC,0,ADC_SETTLING_TIME_3,1);
	adc_set_resolution(ADC,ADC_MR_LOWRES_BITS_12);
	adc_enable_channel(ADC,ADC_CHANNEL_7);
	adc_enable_channel(ADC,ADC_CHANNEL_6);
	adc_configure_trigger(ADC,ADC_TRIG_SW,0);
}

uint32_t ReadAnalog0(void)
{
	uint32_t xAngle;
	adc_start(ADC);
	xAngle = adc_get_channel_value(ADC,ADC_CHANNEL_7);
	return xAngle;
}

uint32_t ReadAnalog1(void)
{
	uint32_t yAngle;
	adc_start(ADC);
	yAngle = adc_get_channel_value(ADC,ADC_CHANNEL_6);
	return yAngle;
}

