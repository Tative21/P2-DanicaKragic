/*
* main.c
*
* Authors: Michael och Martin
*/

#include <asf.h>
#include <inttypes.h>
#include "stdio/stdio_serial/stdio_serial.h"
#include "SerialUARTFunctions/SerialUART.h"
#include "Tasks/TaskCalculateLeftWheel.h"
#include "Tasks/TaskDriveLeftRight.h"
#include "Tasks/TaskPIDLeft.h"
#include "Tasks/TaskCalculateRightWheel.h"
#include "Tasks/TaskMatlab.h"
#include "Tasks/TaskPIDRight.h"
#include "Tasks/TaskUltraljud.h"
#include "conf_board.h"
#include "Interrupts/InterruptPioLeftWheel.h"
#include "Interrupts/InterruptPioRightWheel.h"
#include "adc/adcFunctions.h"
#include "PWMFunctions/PWMFunctions.h"



/**************************************
* Initializing terminal window.
**************************************/
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

	return 0;
}
/**************************************************
* main method. Initialize every thing.
***************************************************/
int main (void)
{
	// initializing A/D, PWM Time counter, Interrupts etc.
	sysclk_init();
	board_init();
	analogInit();
	setupUART();
	configureConsole();
	configure_tc_LeftWheel();
	configure_tc_RightWheel();
	configure_interrupt_pio_LeftWheel();
	configure_interrupt_pio_RightWheel();
	PWMInit();

	/*Start every Task*/
	if (xTaskCreate(TaskDriveLeftRight, (const signed char * const) "TaskDrive", 1024, NULL, 2, NULL) != pdPASS){
		printf("Failed to create TaskDriveLeftRight\n");
	}
	if (xTaskCreate(TaskMatLab, (const signed char * const) "TaskMatlab", 1024, NULL, 1, NULL) != pdPASS){
		printf("Failed to create TaskDriveForward\n");
	}
	if (xTaskCreate(TaskPIDLeft, (const signed char * const) "TaskPIDLeft", 1024, NULL, 3, NULL) != pdPASS){
		printf("Failed to create TaskDriveForward\n");
	}
	if (xTaskCreate(TaskPIDRight, (const signed char * const) "TaskPIDRight", 1024, NULL, 3, NULL) != pdPASS){
		printf("Failed to create TaskDriveForward\n");
	}
	if (xTaskCreate(TaskCalculateLeftWheel, (const signed char * const) "TaskCalcLeft", 1024, NULL, 4, NULL) != pdPASS){
		printf("Failed to create TaskCalculateLeftWheel\n");
	}
	if (xTaskCreate(TaskCalculateRightWheel, (const signed char * const) "TaskCalcRight", 1024, NULL, 4, NULL) != pdPASS){
		printf("Failed to create TaskCalculateLeftWheel\n");
	}
	if (xTaskCreate(TaskUltraLjud, (const signed char * const) "TaskUltra", 1024, NULL, 1, NULL) != pdPASS){
		printf("Failed to create TaskCalculateLeftWheel\n");
	}
	
	vTaskStartScheduler();
}


