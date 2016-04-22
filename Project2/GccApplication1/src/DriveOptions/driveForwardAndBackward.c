/*
 * driveForward.c
 *
 * Created: 2016-04-19 12:46:04
 * Author: Michael och Martin.
 * 
 * Content: Methods that make the robot move forward. A
 * method for standby mode, where the robot do not move
 * at all.
 */ 

#include <asf.h>
#include <inttypes.h>
#include "DelayFunctions/DelayFunctions.h"
#include "DriveOptions/driveForwardAndBackward.h"

/**************************************************************************
* The standby mode. Both wheels receive the signal for not moving.
* The PWM signal is generated with bit-banging.
**************************************************************************/
void standBymode()
{
	ioport_set_pin_level(pin9,HIGH);		// s�tter pin 9 till h�g
	delayMicroseconds(1500);				// v�ntar i 1500 �s
	ioport_set_pin_level(pin9,LOW);			// s�tter pin 9 till l�g
	delayMicroseconds(1150);				// v�ntar i 1150 �s
	ioport_set_pin_level(pin9,HIGH);		// s�tter pin 9 till h�g
	delayMicroseconds(1500);				// v�ntar i 1500 �s
	ioport_set_pin_level(pin9,LOW);			// s�tter pin 9 till l�g
	delayMicroseconds(5350);				// v�ntar i 5350 �s
}

/**************************************************************************
* Method for moving backward at half speed. 
* The PWM signal is generated with bit-banging.
**************************************************************************/
void Backward_50()
{
	ioport_set_pin_level(pin9,HIGH);		// s�tter pin 9 till h�g
	delayMicroseconds(1850);				// v�ntar i 1850 �s
	ioport_set_pin_level(pin9,LOW);			// s�tter pin 9 till l�g
	delayMicroseconds(1150);				// v�ntar i 1150 �s
	ioport_set_pin_level(pin9,HIGH);		// s�tter pin 9 till h�g
	delayMicroseconds(1850);				// v�ntar i 1850 �s
	ioport_set_pin_level(pin9,LOW);			// s�tter pin 9 till l�g
	delayMicroseconds(5350);				// v�ntar i 5350 �s
}

/**************************************************************************
* Method for moving forward at full speed. This however is just our full 
* speed, not the highest speed the robot can achieve. If we were to send the
* signal for full speed a start-up, the engines might fail.
* The PWM signal is generated with bit-banging.
**************************************************************************/
void Forward_100()
{
	ioport_set_pin_level(pin9,HIGH);		// s�tter pin 9 till h�g
	delayMicroseconds(950);					// v�ntar i 1500 �s
	ioport_set_pin_level(pin9,LOW);			// s�tter pin 9 till l�g
	delayMicroseconds(1150);				// v�ntar i 1150 �s
	ioport_set_pin_level(pin9,HIGH);		// s�tter pin 9 till h�g
	delayMicroseconds(950);					// v�ntar i 1500 �s
	ioport_set_pin_level(pin9,LOW);			// s�tter pin 9 till l�g
	delayMicroseconds(5350);				// v�ntar i 5350 �s
}

