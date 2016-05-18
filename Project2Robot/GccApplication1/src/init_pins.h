/*
 * init_pins.h
 *
 * Created: 2016-05-16 11:37:39
 *  Author: William
 */ 


#ifndef INIT_PINS_H_
#define INIT_PINS_H_

#define  pinMode ioport_set_pin_dir
#define setPin ioport_set_pin_level
#define getPin ioport_get_pin_level

#define OUTPUT IOPORT_DIR_OUTPUT
#define INPUT IOPORT_DIR_INPUT
#define pin22 PIO_PB26_IDX
#define pin23 PIO_PA14_IDX
#define pin24 PIO_PA15_IDX
#define pin25 PIO_PB16_IDX
#define pin3 PIO_PC28_IDX
#define pin4 PIO_PC26_IDX
#define pin5 PIO_PC25_IDX
#define pin6 PIO_PC24_IDX
#define pin7 PIO_PC23_IDX
#define pin8 PIO_PC22_IDX

#define pin11 PIO_PD7_IDX
#define pin12 PIO_PD8_IDX
#define pin13 PIO_PB27_IDX

extern int drive;
#endif /* INIT_PINS_H_ */