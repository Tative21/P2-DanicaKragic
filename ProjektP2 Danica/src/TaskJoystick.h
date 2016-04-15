/*
 * TaskJoystick.h
 *
 * Created: 2016-04-10 13:35:33
 *  Author: Martin William Patricia Elvin
 */ 


#ifndef TASKJOYSTICK_H_
#define TASKJOYSTICK_H_
#define pinMode ioport_set_pin_dir
#define setPin ioport_set_pin_level
#define Input IOPORT_DIR_INPUT
#define Output IOPORT_DIR_OUTPUT
#define Analog0 PIO_PA16_IDX
#define Analog1 PIO_PA24_IDX

#define pin3 PIO_PC28_IDX
#define pin8 PIO_PC22_IDX
#define pin6 PIO_PC24_IDX
#define pin5 PIO_PC25_IDX
void TaskJoystickX(void);
void TaskJoystickY(void);


#endif /* TASKJOYSTICK_H_ */