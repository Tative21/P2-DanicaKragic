/*
 * Created 04-20-2016 
 * By Patricia Jönsson and Hamoud Abdoula
 * 
 * 
 */

/*Calculates the distance in form of cm or inches*/
long getDistance(long time, int flag)
{

  long distance;
  if(flag)
    distance = time /29 / 2  ;     // Distance_CM  = ((Duration of high level)*(Sonic :340m/s))/2
                                   //              = ((Duration of high level)*(Sonic :0.034 cm/us))/2
                                   //              = ((Duration of high level)/(Sonic :29.4 cm/us))/2
  else
    distance = time / 74 / 2;      // INC
  return distance;
}

/*Start up the ultrasound and return the pulse-time*/
long TP_init(int TP, int EP)
{                     
  digitalWrite(TP, LOW);                    
  delayMicroseconds(2);
  digitalWrite(TP, HIGH);                 // pull the Trig pin to high level for more than 10us impulse 
  delayMicroseconds(10);
  digitalWrite(TP, LOW);
  long microseconds = pulseIn(EP,HIGH);   // waits for the pin to go HIGH, and returns the length of the pulse in microseconds
  return microseconds;                    // return microseconds
}

void obsticalCheck(long distance){
  /*If an obstical is detected the pin is set high*/
  if(distance > MaxDistance){
    digitalWrite(Forward, LOW);
    Serial.println("Inget hinder");
  }else{
    digitalWrite(Forward, HIGH);
    Serial.println("HINDER");//ADD CODE FOR LEFT AND RIGHT 
  }
}


