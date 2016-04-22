/*
 * JoystickOptionsYAxis.h
 *
 * Created: 2016-04-18 15:01:42
 *  Author: Spellabbet
 */ 


#ifndef JOYSTICKOPTIONSYAXIS_H_
#define JOYSTICKOPTIONSYAXIS_H_
#define pinMode ioport_set_pin_dir
#define setPin ioport_set_pin_level
#define Input IOPORT_DIR_INPUT
#define Output IOPORT_DIR_OUTPUT
#define Analog0 PIO_PA16_IDX
#define Analog1 PIO_PA24_IDX
#define Analog2 PIO_PA23_IDX

#define pin3 PIO_PC28_IDX
#define pin8 PIO_PC22_IDX
#define pin6 PIO_PC24_IDX
#define pin5 PIO_PC25_IDX
#define pin11 PIO_PD7_IDX

void TaskDriveForward(void *p);

#endif /* JOYSTICKOPTIONSYAXIS_H_ */