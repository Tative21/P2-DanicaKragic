/*
 * Interupt_Timer_Init.h
 *
 * Created: 1/22/2015 7:29:58 PM
 *  Author: Ola
 */ 


#ifndef INTERUPT_TIMER_INIT_H_
#define INTERUPT_TIMER_INIT_H_


void configure_interrupt_pio(void);
void pin_edge_handler(void);
void configure_tc(void);

#endif /* INTERUPT_TIMER_INIT_H_ */