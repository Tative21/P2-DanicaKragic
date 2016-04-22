/*
 * JoystickOptions.h
 *
 * Created: 2016-04-18 14:17:55
 *  Author: Michael och Martin
 */ 


#ifndef JOYSTICKOPTIONS_H_
#define JOYSTICKOPTIONS_H_
#define pinMode ioport_set_pin_dir
#define setPin ioport_set_pin_level
#define Input IOPORT_DIR_INPUT
#define Output IOPORT_DIR_OUTPUT
#define Analog0 PIO_PA16_IDX
#define Analog1 PIO_PA24_IDX
#define Analog2 PIO_PA23_IDX
#define digital9 PIO_PC21_IDX
#define pin3 PIO_PC28_IDX
#define pin8 PIO_PC22_IDX
#define pin6 PIO_PC24_IDX
#define pin5 PIO_PC25_IDX

#define LED PIO_PB27_IDX

void TaskDriveLeftRight(void *p);

#endif /* JOYSTICKOPTIONS_H_ */





