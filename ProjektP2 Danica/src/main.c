/**
 * Author: Martin William Elvin
 *
 *
 *\file
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
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */
#include <asf.h>
#include "adc/adcFunctions.h"
#include "TaskJoystick.h"
#include <FreeRTOS.h>
#include <consoleFunctions.h>

//void wdt_disable(void);

int main (void)
{
	//void wdt_disable(void);

		/* Initialise the Due board */
		sysclk_init();
		board_init();
		analogInit();
		/* Initialise console UART */
		configureConsole();

		/* Print demo information on the terminal*/
		printf("-- Terminal by William & Elvin--\n\r");
		
		

		/* Create the first task for running the code lock */
		if (xTaskCreate(TaskJoystickX, (const signed char * const) "TaskJoystickX", 1024, NULL, 2, NULL) != pdPASS){
			printf("Failed to create TaskJoystick\n");
		}
		if (xTaskCreate(TaskJoystickY, (const signed char * const) "TaskJoystickY", 1024, NULL, 2, NULL) != pdPASS){
			printf("Failed to create TaskJoystick\n");
		}
		
		
		vTaskStartScheduler();
		
	}
