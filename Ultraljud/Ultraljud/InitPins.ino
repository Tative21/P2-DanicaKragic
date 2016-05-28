/*
 * Created 04-20-2016 
 * By Patricia Jönsson
 * 
 * Initialses pins for the ultrasounds trigger pins,
 * echo pins and other needed pins.
 */

void initPins(){
  pinMode(EP_Forward,INPUT);       
  pinMode(EP_Left,INPUT);
  pinMode(EP_Right,INPUT);
  pinMode(TP_Forward,OUTPUT);        
  pinMode(TP_Left,OUTPUT);
  pinMode(TP_Right,OUTPUT);
  pinMode(FORWARD,OUTPUT);
  pinMode(LEFT,OUTPUT);           
  pinMode(RIGHT,OUTPUT);

  digitalWrite(LEFT, LOW);
  digitalWrite(RIGHT, LOW);
  digitalWrite(FORWARD, LOW);
}

