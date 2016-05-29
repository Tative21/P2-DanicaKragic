 /*
 * InterruptPioRightWheel.c
 *
 * Author: Michael and Martin. Review by William. Comments written by Michael.
 *
 * Content: Methods for initializing a timer counter, configure an interrupt
 * and an interrupt service routine.
 */
 #include "asf.h"
 #include "InterruptPioRightWheel.h"
 #include "adc/adcFunctions.h"

 extern timerRightWheel;
 extern counterRightWheel;

 /**************************************************************************
 Initialize the timer counter.
 **************************************************************************/
 void configure_tc_RightWheel(void)
 {
	 pmc_set_writeprotect(false);
	 pmc_enable_periph_clk(ID_TC7);
	 tc_init(TC2,1,TC_CMR_TCCLKS_TIMER_CLOCK3);		 /* TC2, channel 1, TCLK3 and capturemode */
	 tc_set_block_mode(TC2,1);
	 
	 
 }
 /**************************************************************************
 Configure the interrupt.
 Digital Pin 12
 **************************************************************************/
 void configure_interrupt_pio_RightWheel(void)
 {
	 pmc_enable_periph_clk(ID_PIOD); //Enable the module clock
	 pio_set_input(PIOD, PIO_PD8,PIO_PULLUP);
	 pio_handler_set(PIOD,ID_PIOD,PIO_PD8,PIO_IT_EDGE,pin_edge_handler);
	 pio_enable_interrupt(PIOD,PIO_PD8);
	 NVIC_EnableIRQ(PIOD_IRQn);

 }

 /**************************************************************************
 The interrupt service routine.
 Reads the timer counter every time the ISR fires. Resets/restarts the clock
 and maintains a counter.
 **************************************************************************/
 void pin_edge_handler()
 {
	 timerRightWheel = tc_read_cv(TC2, 1);
	 tc_start(TC2, 1);
	 counterRightWheel++;
 }

