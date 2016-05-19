 /*
 * InterruptPioLeftWheel.c
 *
 * Author: Michael och Martin. Comments written by Michael.
 * 
 * Content: Methods for initializing a timer counter, configure an interrupt
 * and an interrupt service routine.  
 */ 
 
#include "asf.h"
#include "InterruptPioLeftWheel.h"
#include "adc/adcFunctions.h"

extern timerLeftWheel;
extern counterLeftWheel;

/**************************************************************************
* Initialize the timer counter.
**************************************************************************/
void configure_tc_LeftWheel(void)
{
	pmc_set_writeprotect(false);
	pmc_enable_periph_clk(ID_TC0);
	tc_init(TC0,0,TC_CMR_TCCLKS_TIMER_CLOCK3);		 /* TC0, channel 0, TCLK3 */
	tc_set_block_mode(TC0,0);	
}

/**************************************************************************
* Configure the interrupt.
* Digital Pin 13
**************************************************************************/
void configure_interrupt_pio_LeftWheel(void)
{
	pmc_enable_periph_clk(ID_PIOB); //Enable the module clock
	pio_set_input(PIOB, PIO_PB27,PIO_PULLUP);
	pio_handler_set(PIOB,ID_PIOB,PIO_PB27,PIO_IT_EDGE,pin_edge_handler1);
	pio_enable_interrupt(PIOB,PIO_PB27);
	NVIC_EnableIRQ(PIOB_IRQn);
}

/**************************************************************************
* The interrupt service routine. 
* Reads the timer counter every time the ISR fires. Resets/restarts the clock
* and maintains a counter.
**************************************************************************/
void pin_edge_handler1()
{
	timerLeftWheel = tc_read_cv(TC0, 0);
	tc_start(TC0, 0);
	counterLeftWheel++;		
}
