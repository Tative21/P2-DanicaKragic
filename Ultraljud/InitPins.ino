/*
 * Created 04-20-2016 
 * By Patricia Jönsson and Hamoud Abdoula
 * 
 * Initialses pins for the ultrasounds trigger pins,
 * echo pins 
 */

void initPins(){
  pinMode(TP_Forward,OUTPUT);       // set TP output for trigger  
  pinMode(EP_Forward,INPUT);        // set EP input for echo
  pinMode(EP_Left,INPUT);
  pinMode(EP_Right,INPUT);
  pinMode(TP_Left,OUTPUT);
  pinMode(TP_Right,OUTPUT);
  pinMode(Forward,OUTPUT);
  pinMode(Left,OUTPUT);           
  pinMode(Right,OUTPUT);

  digitalWrite(Left, LOW);
  digitalWrite(Right, LOW);
  digitalWrite(Forward, LOW);
}

