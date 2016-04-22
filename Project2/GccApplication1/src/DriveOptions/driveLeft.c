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
	ioport_set_pin_level(pin9,HIGH);		// s�tter pin 8 till h�g
	delayMicroseconds(1100);				// v�ntar i 1900 �s
	ioport_set_pin_level(pin9,LOW);			// s�tter pin 8 till l�g
	delayMicroseconds(1150);				// v�ntar i 20000 �s
	ioport_set_pin_level(pin9,HIGH);		// s�tter pin 8 till h�g
	delayMicroseconds(1050);				// v�ntar i 1900 �s
	ioport_set_pin_level(pin9,LOW);			// s�tter pin 8 till l�g
	delayMicroseconds(5350);	
}

/*
* Method for turning left.
*/
void Left_30Degrees()
{
	ioport_set_pin_level(pin9,HIGH);		// s�tter pin 8 till h�g
	delayMicroseconds(1100);				// v�ntar i 1900 �s
	ioport_set_pin_level(pin9,LOW);			// s�tter pin 8 till l�g
	delayMicroseconds(1150);				// v�ntar i 20000 �s
	ioport_set_pin_level(pin9,HIGH);		// s�tter pin 8 till h�g
	delayMicroseconds(1000);				// v�ntar i 1900 �s
	ioport_set_pin_level(pin9,LOW);			// s�tter pin 8 till l�g
	delayMicroseconds(5350);
}

/*
* Method for turning left.
*/
void Left_45Degrees()
{
	ioport_set_pin_level(pin9,HIGH);		// s�tter pin 8 till h�g
	delayMicroseconds(1100);				// v�ntar i 1900 �s
	ioport_set_pin_level(pin9,LOW);			// s�tter pin 8 till l�g
	delayMicroseconds(1150);				// v�ntar i 20000 �s
	ioport_set_pin_level(pin9,HIGH);		// s�tter pin 8 till h�g
	delayMicroseconds(950);					// v�ntar i 1900 �s
	ioport_set_pin_level(pin9,LOW);			// s�tter pin 8 till l�g
	delayMicroseconds(5350);
}

/*
* Method for turning left.
*/
void Left_60Degrees()
{
	ioport_set_pin_level(pin9,HIGH);		// s�tter pin 8 till h�g
	delayMicroseconds(1100);				// v�ntar i 1900 �s
	ioport_set_pin_level(pin9,LOW);			// s�tter pin 8 till l�g
	delayMicroseconds(1150);				// v�ntar i 20000 �s
	ioport_set_pin_level(pin9,HIGH);		// s�tter pin 8 till h�g
	delayMicroseconds(900);					// v�ntar i 1900 �s
	ioport_set_pin_level(pin9,LOW);			// s�tter pin 8 till l�g
	delayMicroseconds(5350);
}

/*
* Method for turning left.
*/
void Left_75Degrees()
{
	ioport_set_pin_level(pin9,HIGH);		// s�tter pin 8 till h�g
	delayMicroseconds(1100);				// v�ntar i 1900 �s
	ioport_set_pin_level(pin9,LOW);			// s�tter pin 8 till l�g
	delayMicroseconds(1150);				// v�ntar i 20000 �s
	ioport_set_pin_level(pin9,HIGH);		// s�tter pin 8 till h�g
	delayMicroseconds(850);					// v�ntar i 1900 �s
	ioport_set_pin_level(pin9,LOW);			// s�tter pin 8 till l�g
	delayMicroseconds(5350);
}

/*
* Method for turning left.
*/
void Left_90Degrees()
{
	ioport_set_pin_level(pin9,HIGH);		// s�tter pin 8 till h�g
	delayMicroseconds(1100);				// v�ntar i 1900 �s
	ioport_set_pin_level(pin9,LOW);			// s�tter pin 8 till l�g
	delayMicroseconds(1150);				// v�ntar i 20000 �s
	ioport_set_pin_level(pin9,HIGH);		// s�tter pin 8 till h�g
	delayMicroseconds(800);					// v�ntar i 1900 �s
	ioport_set_pin_level(pin9,LOW);			// s�tter pin 8 till l�g
	delayMicroseconds(5350);
}