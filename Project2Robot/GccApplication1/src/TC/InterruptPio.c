/*
* Interupt_Timer_Init.c
*
* Created: 1/22/2015 7:29:37 PM
*  Author: Michael
*/
#include "asf.h"
#include "InterruptPio.h"
#include "adc/adcFunctions.h"
uint32_t ultimatetimer;
uint32_t timer;
uint32_t counter = 0;

void configure_tc(void)
{
	uint32_t ul_div;
	uint32_t ul_tcclks;
	uint32_t ul_sysclk = sysclk_get_cpu_hz();
	
	/* Configure power management of timer clocks */
	pmc_enable_periph_clk(ID_TC0);
	
	/* Configure TC for a 44,1kHz frequency and trigger on
	RC compare. */
	tc_find_mck_divisor(44100, ul_sysclk, &ul_div, &ul_tcclks, ul_sysclk);
	
	tc_init(TC0, 0, ul_tcclks | TC_CMR_CPCTRG);
	//tc_write_rc(TC0, 0, (ul_sysclk / ul_div) / 44100);
	
}



void configure_interrupt_pio(void)
{
	pmc_enable_periph_clk(ID_PIOB); //Enable the module clock
	pio_set_input(PIOB, PIO_PB27,PIO_PULLUP);
	pio_handler_set(PIOB,ID_PIOB,PIO_PB27,PIO_IT_EDGE,pin_edge_handler);
	pio_enable_interrupt(PIOB,PIO_PB27);
	NVIC_EnableIRQ(PIOB_IRQn);
}

void pin_edge_handler()
{
	tc_stop(TC0,0);
	
	timer = tc_read_cv(TC0,0);
	
	
	printf("%d \n", timer);
	if(counter == 50)
	{
		counter++;
		 ultimatetimer = (((1/timer)/counter)*1000000);
		 counter = 0;
		 timer = 0;
		 
	}
	tc_start(TC0, 0);
}