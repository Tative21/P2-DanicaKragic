/*
* SerialUART.c
*
*/
#include <asf.h>
#include "SerialUART.h"

/************************************************************************/
/* Configuration of the UART. */
/************************************************************************/
void setupUART(void){
	pio_configure(PINS_UART_PIO, PINS_UART_TYPE, PINS_UART_MASK, PIO_DEFAULT);
	pmc_enable_periph_clk(ID_UART);
	const sam_uart_opt_t uart0_settings = { sysclk_get_cpu_hz(), CONF_UART_BAUDRATE, UART_MR_PAR_NO };
	ioport_set_pin_mode(PIO_PA8_IDX, IOPORT_MODE_PULLUP);
	uart_init(UART, &uart0_settings);
}

/************************************************************************/
/* Configuration of the Standard Input Output (STDIO). */
/************************************************************************/
void setupSTDIO(void){
	const usart_serial_options_t uart_serial_options = { .baudrate = CONF_UART_BAUDRATE, .paritytype = CONF_UART_PARITY };
	stdio_serial_init(CONF_UART, &uart_serial_options);
	#if defined(__GNUC__)
	setbuf(stdout, NULL);
	#else
	#endif
}

/************************************************************************/
/* Get and return a binary value. */
/************************************************************************/
uint8_t readByte(void){
	uint8_t value;
	uart_read(CONF_UART, &value);
	return value;
}

/************************************************************************/
/* Check if reciever side of UART is ready. */
/************************************************************************/
uint32_t isRXReady(void){
	return UART->UART_SR & UART_SR_RXRDY;
}

/************************************************************************/
/* Wait for reciever side of UART to be ready. */
/************************************************************************/
uint32_t waitRXReady(void){
	while (!(UART->UART_SR & UART_SR_RXRDY));
	return 1;
}

/************************************************************************/
/* Returns a double. */
/************************************************************************/
double readDouble(void){
	double result = 0.0;
	char str[10] ={0};
	scanf("%s", str);
	result = atof(str);

	return result;
}