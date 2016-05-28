/*
   This project is for wireless communication between two XBee modules.
   This is the code for the receiving XBee module.

   Authors: William, Elvin och Hamoud                                  */

#include <Printers.h>
#include <XBee.h>

/* Needed declarations */

XBee xbee1 = XBee();

XBeeResponse response = XBeeResponse();
Rx16Response rx16 = Rx16Response();

int data = 0;
int i = 0;
int k = 0;

/* Setup of serial, pins and motorshield. */
void setup(){
  Serial.begin(9600);
  xbee1.setSerial(Serial);

  pinMode(2, OUTPUT);         // Green LED 
  pinMode(4, OUTPUT);         // Red LED

  //DIRECTION
  pinMode(3, OUTPUT);         // IN_1
  pinMode(11, OUTPUT);        // IN_2
  //SLEEP MODE
  pinMode(12, OUTPUT);        // INH_1
  pinMode(13, OUTPUT);        // INH_2

  digitalWrite(12, HIGH);     // Motorshield INH_1 initiation
  digitalWrite(13, HIGH);     // Motorshield INH_2 initiation
}

/* Main program, reads the received package from the transmitting
   Xbee, if data is received, enter another if-statement depending
   on the received content.                                        */
void loop(){
  xbee1.readPacket(100);
  
  /* If a package is received, put the value(gets converted from
     ASCII to decimal) into "data". */
  if (xbee1.getResponse().isAvailable()){
    if (xbee1.getResponse().getApiId() == RX_16_RESPONSE){
      xbee1.getResponse().getRx16Response(rx16);
      data = rx16.getData(0);

      Serial.print(" XBee1: ");
      Serial.print( data );
      Serial.print("\n");
      delay(1);
    }
  }

  /* If the value of "data" is 66 (letter B in ASCII) turn the motor on
     in a clockwise direction. The motor will get an increasing analog value
     for every 1ms.                                                         */
  if (data == 66) {
    digitalWrite(2, HIGH);
    analogWrite(3, i);
    delay(100);
    
    if (i != 255) {
      i = i + 1;
    }
  }

  /* If the value of "data" is 65 (letter A in ASCII) turn the motor on
     in a counterclockwise direction. The motor will get an increasing analog 
     value for every 1ms.                                                    */
  else if (data == 65) {
    digitalWrite(2, LOW);
    analogWrite(11, k);
    delay(100);
    
    if (k != 255) {
      k = k + 1;
    }
  } 

  /* If the value of "data" is 0 (0 in ASCII aswell) turn off the motor
     and reset the k and i values.                                     */
  if (data == 0) {
    digitalWrite(4, HIGH);
    digitalWrite(2, LOW);
    analogWrite(3, 0);
    analogWrite(11, 0);
    k=0;
    i=0;
  }
  if (data != 0) {
    digitalWrite(4, LOW);
  }
}

