/**
 * \file
 *
 * \brief Empty user application template
 *
 */

/**
 * \mainpage User Application template doxygen documentation
 *
 * \par Empty user application template
 *
 * Bare minimum empty user application template
 *
 * \par Content
 *
 * -# Include the ASF header files (through asf.h)
 * -# "Insert system clock initialization code here" comment
 * -# Minimal main function that starts with a call to board_init()
 * -# "Insert application code here" comment
 *
 */

/*
 * Include header files for all drivers that have been imported from
 * Atmel Software Framework (ASF).
 */
 /**
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 
 
 
 
 Authors: Michael och Martin
 
 */
#include <asf.h>
#include <inttypes.h>
#include <stdio_serial.h>
#include "SerialUART.h"
#include "adc/adcFunctions.h"
#include "Tasks/TaskJoystick.h"
#include "Tasks/TaskDriveLeftRight.h"
#include "Tasks/TaskDriveForward.h"
#include "DelayFunctions/DelayFunctions.h"
#include "conf_board.h"
#define LED PIO_PC21_IDX


int configureConsole(void)
/* Enables feedback through the USB-cable back to terminal within Atmel Studio */
{
	const usart_serial_options_t uart_serial_options = {
		.baudrate = CONF_UART_BAUDRATE,
		.paritytype = CONF_UART_PARITY
	};

	/* Configure console UART. */
	sysclk_enable_peripheral_clock(CONSOLE_UART_ID);
	stdio_serial_init(CONF_UART, &uart_serial_options);
	
	/* printf("Console ready\n"); */
	return 0;
}



int main (void)
{
	// Insert system clock initialization code here (sysclk_init()).
	sysclk_init();
	board_init();
	analogInit();
	setupUART();
	configureConsole();
	delayInit();
	
	ioport_set_pin_dir(PIO_PD9_IDX,Output);
	ioport_set_pin_dir(PIO_PC4_IDX,Input);
			while(1){
			printf("%d",ioport_get_pin_level(PIO_PC4_IDX));
			if(ioport_get_pin_level(PIO_PC4_IDX)){
				ioport_set_pin_level(PIO_PD9_IDX,HIGH);
				}else{
				ioport_set_pin_level(PIO_PD9_IDX,LOW);
			}
			}


	if (xTaskCreate(TaskJoystick, (const signed char * const) "TaskJoystick", 1024, NULL, 1, NULL) != pdPASS){
		printf("Failed to create TaskJoystick\n");
	}
	
	if (xTaskCreate(TaskDriveLeftRight, (const signed char * const) "TaskDriveLeftRight", 1024, NULL, 2, NULL) != pdPASS){
		printf("Failed to create TaskJoystick\n");
	}
	
	if (xTaskCreate(TaskDriveForward, (const signed char * const) "TaskDriveForward", 1024, NULL, 3, NULL) != pdPASS){
		printf("Failed to create TaskJoystick\n");
	}
	
	
	
	vTaskStartScheduler();
	
}
