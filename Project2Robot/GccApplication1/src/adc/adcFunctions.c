 /*
 * adcFunctions.c
 *
 * Author: Martin, Michael, William och Elvin. Comments written by Michael. 
 * 
 * Content: A method for initializing the analog pins. Various methods
 * for reading sensor values from analog pins.
 */ 

#include <asf.h>
#include <inttypes.h>
#include <stdio_serial.h>
#include "SerialUART.h"
#include "adc/adcFunctions.h"
#include "Tasks/TaskDriveLeftRight.h"
#include "Tasks/TaskPIDLeft.h"
#include "DelayFunctions/DelayFunctions.h"
#include "conf_board.h"
#include "Interrupts/InterruptPioLeftWheel.h"
#define LED PIO_PC21_IDX

/**************************************************************************
* Initializes the analog pins.
**************************************************************************/
int analogInit(void)
{
	pmc_enable_periph_clk(ID_ADC);
	adc_init(ADC,sysclk_get_main_hz(),1000000,8);
	adc_configure_timing(ADC,0,ADC_SETTLING_TIME_3,1);
	adc_set_resolution(ADC,ADC_MR_LOWRES_BITS_12);
	adc_enable_channel(ADC,ADC_CHANNEL_7);
	adc_enable_channel(ADC,ADC_CHANNEL_6);
	adc_enable_channel(ADC,ADC_CHANNEL_5);
	adc_configure_trigger(ADC,ADC_TRIG_SW,0);
}

/***************************************************************************
* Reads the Analog 0 pin on Due.
* Retun values for the x-axis of the joystick.
***************************************************************************/
uint32_t ReadAnalog0(void)
{
	uint32_t xAngle;
	adc_start(ADC);
	xAngle = adc_get_channel_value(ADC,ADC_CHANNEL_7);
	return xAngle;
}

/****************************************************************************
* Reads the Analog 1 pin on Due.
* Retun values for the y-axis of the joystick.
****************************************************************************/
uint32_t ReadAnalog1(void)
{
	uint32_t yAngle;
	adc_start(ADC);
	yAngle = adc_get_channel_value(ADC,ADC_CHANNEL_6);
	return yAngle;
}

/****************************************************************************
* Reads the Analog 2 pin on Due.
* Retun values for the IR sensor.
****************************************************************************/
uint32_t ReadAnalog2(void)
{
	uint32_t IRSensorer;
	adc_start(ADC);
	IRSensorer = adc_get_channel_value(ADC,ADC_CHANNEL_5);
	return IRSensorer;
}


