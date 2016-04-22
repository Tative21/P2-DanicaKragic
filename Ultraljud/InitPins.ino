void initPins(){
  pinMode(TP_Forward,OUTPUT);       // set TP output for trigger  
  pinMode(EP_Forward,INPUT);        // set EP input for echo
  pinMode(Forward,OUTPUT);
  pinMode(Left,OUTPUT);           //ADD TP AND EP FOR LEFT AND RIGHT
  pinMode(Right,OUTPUT);
}

