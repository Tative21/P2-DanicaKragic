 /*
 * InterruptPioRightWheel.h
 *
 * Author: Martin och Michael. 
 */

#ifndef INTERRUPTPIORIGHTWHEEL_H_

#define INTERRUPTPIORIGHTWHEEL_H_

void configure_tc_RightWheel(void);
void configure_interrupt_pio_RightWheel(void);
void pin_edge_handler(void);

#endif /* INTERRUPTPIORIGHTWHEEL_H_ */