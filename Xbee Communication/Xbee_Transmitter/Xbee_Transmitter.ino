/*
   This project is used for wireless communication between two XBee modules.
   This code is used for the transmitting XBee module.

   Authors: William, Elvin och Hamoud                                       */

#include <Printers.h>
#include <XBee.h>

/* Needed declarations */
XBee xbee = XBee();

int Up = 0;
int Down = 0;
uint8_t payload[2];

/* Setup of pins and serial */
void setup(){
  Serial.begin(9600);
  xbee.setSerial(Serial);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
}

/* Main program, reads the value of the switches, adds a
   char to position 0 in the payload array depending on which
   switch is switched on. Then sends the value of the payload
   over wirelessly to the receiving Xbee Module.              */
void loop(){
   Up = digitalRead(2);
   Down = digitalRead(3);

   payload[0]= {NULL};
  
  if(Up == HIGH){   /* Left switch (Direction) */
     payload[0] = {'A'}; /* Unique char */
  }
  
  if(Down == HIGH){ /* Right Switch (Brake) */
     payload[0] = {'B'}; /* Unique char */
  }
    /* Package gets created that is sent to the receiving Xbee. */
    Tx16Request tx16 = Tx16Request(0xFFFF, payload, sizeof(payload));
    xbee.send(tx16);
    delay(200);
}
