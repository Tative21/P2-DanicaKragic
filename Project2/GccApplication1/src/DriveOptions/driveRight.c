/*
* Styrning.c
*
* Created: 2016-04-18 13:59:11
* Author: Michael och Martin
*
* Content: Methods for turning left. A turn is
* achieved by changing the speed of one wheel,
* while the speed of the second wheel remain
* constant.
*/

#include <asf.h>
#include <inttypes.h>
#include "DelayFunctions/DelayFunctions.h"
#include "DriveOptions/driveRight.h"

/*
* Method for turning right.
*/
void Right_15Degrees()
{
	ioport_set_pin_level(pin9,HIGH);		// sätter pin 8 till hög
	delayMicroseconds(1100);				// väntar i 1900 µs
	ioport_set_pin_level(pin9,LOW);			// sätter pin 8 till låg
	delayMicroseconds(1150);				// väntar i 20000 µs
	ioport_set_pin_level(pin9,HIGH);		// sätter pin 8 till hög
	delayMicroseconds(1400);				// väntar i 1900 µs
	ioport_set_pin_level(pin9,LOW);			// sätter pin 8 till låg
	delayMicroseconds(5350);
	
}

/*
* Method for turning right.
*/
void Right_30Degrees()
{
	ioport_set_pin_level(pin9,HIGH);		// sätter pin 8 till hög
	delayMicroseconds(1100);				// väntar i 1900 µs
	ioport_set_pin_level(pin9,LOW);			// sätter pin 8 till låg
	delayMicroseconds(1150);				// väntar i 20000 µs
	ioport_set_pin_level(pin9,HIGH);		// sätter pin 8 till hög
	delayMicroseconds(1350);				// väntar i 1900 µs
	ioport_set_pin_level(pin9,LOW);			// sätter pin 8 till låg
	delayMicroseconds(5350);
	
}

/*
* Method for turning right.
*/
void Right_45Degrees()
{
	ioport_set_pin_level(pin9,HIGH);		// sätter pin 8 till hög
	delayMicroseconds(1100);				// väntar i 1900 µs
	ioport_set_pin_level(pin9,LOW);			// sätter pin 8 till låg
	delayMicroseconds(1150);				// väntar i 20000 µs
	ioport_set_pin_level(pin9,HIGH);		// sätter pin 8 till hög
	delayMicroseconds(1300);				// väntar i 1900 µs
	ioport_set_pin_level(pin9,LOW);			// sätter pin 8 till låg
	delayMicroseconds(5350);
	
}

/*
* Method for turning right.
*/
void Right_60Degrees()
{
	ioport_set_pin_level(pin9,HIGH);		// sätter pin 8 till hög
	delayMicroseconds(1100);				// väntar i 1900 µs
	ioport_set_pin_level(pin9,LOW);			// sätter pin 8 till låg
	delayMicroseconds(1150);				// väntar i 20000 µs
	ioport_set_pin_level(pin9,HIGH);		// sätter pin 8 till hög
	delayMicroseconds(1250);				// väntar i 1900 µs
	ioport_set_pin_level(pin9,LOW);			// sätter pin 8 till låg
	delayMicroseconds(5350);
	
}

/*
* Method for turning right.
*/
void Right_75Degrees()
{
	ioport_set_pin_level(pin9,HIGH);		// sätter pin 8 till hög
	delayMicroseconds(1100);				// väntar i 1900 µs
	ioport_set_pin_level(pin9,LOW);			// sätter pin 8 till låg
	delayMicroseconds(1150);				// väntar i 20000 µs
	ioport_set_pin_level(pin9,HIGH);		// sätter pin 8 till hög
	delayMicroseconds(1200);				// väntar i 1900 µs
	ioport_set_pin_level(pin9,LOW);			// sätter pin 8 till låg
	delayMicroseconds(5350);
	
}

/*
* Method for turning right.
*/
void Right_90Degrees()
{
	ioport_set_pin_level(pin9,HIGH);		// sätter pin 8 till hög
	delayMicroseconds(1100);				// väntar i 1900 µs
	ioport_set_pin_level(pin9,LOW);			// sätter pin 8 till låg
	delayMicroseconds(1150);				// väntar i 20000 µs
	ioport_set_pin_level(pin9,HIGH);		// sätter pin 8 till hög
	delayMicroseconds(1150);				// väntar i 1900 µs
	ioport_set_pin_level(pin9,LOW);			// sätter pin 8 till låg
	delayMicroseconds(5350);
	
}
