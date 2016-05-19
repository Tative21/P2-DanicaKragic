 /*
 * adcFunctions.c
 *
 * Author: Martin och Michael. Comments written by Michael.
 * 
 * Content: Methods for initializing and creating a delay  
 */ 

#include <asf.h>
#include <inttypes.h>
#include "DelayFunctions.h"

/**************************************************************************
* Initialize the delay.
**************************************************************************/
int delayInit(void)		/* Initializes the timer used for delays */
{
	pmc_set_writeprotect(false);
	pmc_enable_periph_clk(ID_TC4);
	tc_init(TC1,1,0);		 /* TC1, channel 1, TCLK1 och capturemode */
	tc_set_block_mode(TC1,0);
	tc_stop(TC1,1);			/* making sure the timer does not run  */
}

/**************************************************************************
* Function for creating a delay (in microseconds).
**************************************************************************/
void delayMicroseconds(uint32_t us)		/* A simple implementation for a delay in us (not calibrated) */
{
	tc_start(TC1,1);
	while (tc_read_cv(TC1,1) < us*42);
	tc_stop(TC1,1);
}
