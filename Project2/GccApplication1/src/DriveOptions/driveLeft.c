/*
 * driveLeft.c
 *
 * Created: 2016-04-18 15:38:59
 * Author: Spellabbet
 * 
 * Content: Methods for turning left. A turn is
 * achieved by changing the speed of one wheel,
 * while the speed of the second wheel remain
 * constant.
 */ 

#include <asf.h>
#include <inttypes.h>
#include "DriveOptions/driveLeft.h"
#include "DelayFunctions/DelayFunctions.h"

/*
* Method for turning left.
*/
void Left_15Degrees()
{
	ioport_set_pin_level(pin9,HIGH);		// sätter pin 8 till hög
	delayMicroseconds(1100);				// väntar i 1900 µs
	ioport_set_pin_level(pin9,LOW);			// sätter pin 8 till låg
	delayMicroseconds(1150);				// väntar i 20000 µs
	ioport_set_pin_level(pin9,HIGH);		// sätter pin 8 till hög
	delayMicroseconds(1050);				// väntar i 1900 µs
	ioport_set_pin_level(pin9,LOW);			// sätter pin 8 till låg
	delayMicroseconds(5350);	
}

/*
* Method for turning left.
*/
void Left_30Degrees()
{
	ioport_set_pin_level(pin9,HIGH);		// sätter pin 8 till hög
	delayMicroseconds(1100);				// väntar i 1900 µs
	ioport_set_pin_level(pin9,LOW);			// sätter pin 8 till låg
	delayMicroseconds(1150);				// väntar i 20000 µs
	ioport_set_pin_level(pin9,HIGH);		// sätter pin 8 till hög
	delayMicroseconds(1000);				// väntar i 1900 µs
	ioport_set_pin_level(pin9,LOW);			// sätter pin 8 till låg
	delayMicroseconds(5350);
}

/*
* Method for turning left.
*/
void Left_45Degrees()
{
	ioport_set_pin_level(pin9,HIGH);		// sätter pin 8 till hög
	delayMicroseconds(1100);				// väntar i 1900 µs
	ioport_set_pin_level(pin9,LOW);			// sätter pin 8 till låg
	delayMicroseconds(1150);				// väntar i 20000 µs
	ioport_set_pin_level(pin9,HIGH);		// sätter pin 8 till hög
	delayMicroseconds(950);					// väntar i 1900 µs
	ioport_set_pin_level(pin9,LOW);			// sätter pin 8 till låg
	delayMicroseconds(5350);
}

/*
* Method for turning left.
*/
void Left_60Degrees()
{
	ioport_set_pin_level(pin9,HIGH);		// sätter pin 8 till hög
	delayMicroseconds(1100);				// väntar i 1900 µs
	ioport_set_pin_level(pin9,LOW);			// sätter pin 8 till låg
	delayMicroseconds(1150);				// väntar i 20000 µs
	ioport_set_pin_level(pin9,HIGH);		// sätter pin 8 till hög
	delayMicroseconds(900);					// väntar i 1900 µs
	ioport_set_pin_level(pin9,LOW);			// sätter pin 8 till låg
	delayMicroseconds(5350);
}

/*
* Method for turning left.
*/
void Left_75Degrees()
{
	ioport_set_pin_level(pin9,HIGH);		// sätter pin 8 till hög
	delayMicroseconds(1100);				// väntar i 1900 µs
	ioport_set_pin_level(pin9,LOW);			// sätter pin 8 till låg
	delayMicroseconds(1150);				// väntar i 20000 µs
	ioport_set_pin_level(pin9,HIGH);		// sätter pin 8 till hög
	delayMicroseconds(850);					// väntar i 1900 µs
	ioport_set_pin_level(pin9,LOW);			// sätter pin 8 till låg
	delayMicroseconds(5350);
}

/*
* Method for turning left.
*/
void Left_90Degrees()
{
	ioport_set_pin_level(pin9,HIGH);		// sätter pin 8 till hög
	delayMicroseconds(1100);				// väntar i 1900 µs
	ioport_set_pin_level(pin9,LOW);			// sätter pin 8 till låg
	delayMicroseconds(1150);				// väntar i 20000 µs
	ioport_set_pin_level(pin9,HIGH);		// sätter pin 8 till hög
	delayMicroseconds(800);					// väntar i 1900 µs
	ioport_set_pin_level(pin9,LOW);			// sätter pin 8 till låg
	delayMicroseconds(5350);
}