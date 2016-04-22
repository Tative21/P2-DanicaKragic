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
	ioport_set_pin_level(pin9,HIGH);		// s�tter pin 8 till h�g
	delayMicroseconds(1100);				// v�ntar i 1900 �s
	ioport_set_pin_level(pin9,LOW);			// s�tter pin 8 till l�g
	delayMicroseconds(1150);				// v�ntar i 20000 �s
	ioport_set_pin_level(pin9,HIGH);		// s�tter pin 8 till h�g
	delayMicroseconds(1400);				// v�ntar i 1900 �s
	ioport_set_pin_level(pin9,LOW);			// s�tter pin 8 till l�g
	delayMicroseconds(5350);
	
}

/*
* Method for turning right.
*/
void Right_30Degrees()
{
	ioport_set_pin_level(pin9,HIGH);		// s�tter pin 8 till h�g
	delayMicroseconds(1100);				// v�ntar i 1900 �s
	ioport_set_pin_level(pin9,LOW);			// s�tter pin 8 till l�g
	delayMicroseconds(1150);				// v�ntar i 20000 �s
	ioport_set_pin_level(pin9,HIGH);		// s�tter pin 8 till h�g
	delayMicroseconds(1350);				// v�ntar i 1900 �s
	ioport_set_pin_level(pin9,LOW);			// s�tter pin 8 till l�g
	delayMicroseconds(5350);
	
}

/*
* Method for turning right.
*/
void Right_45Degrees()
{
	ioport_set_pin_level(pin9,HIGH);		// s�tter pin 8 till h�g
	delayMicroseconds(1100);				// v�ntar i 1900 �s
	ioport_set_pin_level(pin9,LOW);			// s�tter pin 8 till l�g
	delayMicroseconds(1150);				// v�ntar i 20000 �s
	ioport_set_pin_level(pin9,HIGH);		// s�tter pin 8 till h�g
	delayMicroseconds(1300);				// v�ntar i 1900 �s
	ioport_set_pin_level(pin9,LOW);			// s�tter pin 8 till l�g
	delayMicroseconds(5350);
	
}

/*
* Method for turning right.
*/
void Right_60Degrees()
{
	ioport_set_pin_level(pin9,HIGH);		// s�tter pin 8 till h�g
	delayMicroseconds(1100);				// v�ntar i 1900 �s
	ioport_set_pin_level(pin9,LOW);			// s�tter pin 8 till l�g
	delayMicroseconds(1150);				// v�ntar i 20000 �s
	ioport_set_pin_level(pin9,HIGH);		// s�tter pin 8 till h�g
	delayMicroseconds(1250);				// v�ntar i 1900 �s
	ioport_set_pin_level(pin9,LOW);			// s�tter pin 8 till l�g
	delayMicroseconds(5350);
	
}

/*
* Method for turning right.
*/
void Right_75Degrees()
{
	ioport_set_pin_level(pin9,HIGH);		// s�tter pin 8 till h�g
	delayMicroseconds(1100);				// v�ntar i 1900 �s
	ioport_set_pin_level(pin9,LOW);			// s�tter pin 8 till l�g
	delayMicroseconds(1150);				// v�ntar i 20000 �s
	ioport_set_pin_level(pin9,HIGH);		// s�tter pin 8 till h�g
	delayMicroseconds(1200);				// v�ntar i 1900 �s
	ioport_set_pin_level(pin9,LOW);			// s�tter pin 8 till l�g
	delayMicroseconds(5350);
	
}

/*
* Method for turning right.
*/
void Right_90Degrees()
{
	ioport_set_pin_level(pin9,HIGH);		// s�tter pin 8 till h�g
	delayMicroseconds(1100);				// v�ntar i 1900 �s
	ioport_set_pin_level(pin9,LOW);			// s�tter pin 8 till l�g
	delayMicroseconds(1150);				// v�ntar i 20000 �s
	ioport_set_pin_level(pin9,HIGH);		// s�tter pin 8 till h�g
	delayMicroseconds(1150);				// v�ntar i 1900 �s
	ioport_set_pin_level(pin9,LOW);			// s�tter pin 8 till l�g
	delayMicroseconds(5350);
	
}
