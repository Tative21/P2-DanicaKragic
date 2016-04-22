/*
 * TaskJoystick.h
 *
 * Created: 2016-04-10 13:35:33
 *  Author: Martin
 */ 


#ifndef TASKJOYSTICK_H_
#define TASKJOYSTICK_H_

#define Analog0 PIO_PA16_IDX
#define Analog1 PIO_PA24_IDX

#define digital PIO_PC28_IDX
#define digital1 PIO_PC22_IDX
#define digital11 PIO_PC24_IDX
#define digital2 PIO_PC25_IDX
void TaskJoystick(void *p);



#endif /* TASKJOYSTICK_H_ */