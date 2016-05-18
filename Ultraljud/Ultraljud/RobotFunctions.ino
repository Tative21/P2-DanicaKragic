/*
 * Created 04-20-2016 
 * By Patricia Jönsson, Hamoud Abdoula and William Ouda
 * 
 *Calculates the distance in form of cm or inches
 *  Distance_CM  = ((Duration of high level)*(Sonic :340m/s))/2
 *               = ((Duration of high level)*(Sonic :0.034 cm/us))/2
 *               = ((Duration of high level)/(Sonic :29.4 cm/us))/2
 */
long getDistance(long time, int flag){
  long distance;
  if(flag)
    distance = time /29 / 2  ;    //CM
  else
    distance = time / 74 / 2;      // INC
  return distance;
}

/*Start up the ultrasound and return the pulse-time*/
long TP_init(int TP, int EP){                     
  digitalWrite(TP, LOW);                    
  delayMicroseconds(2);
  digitalWrite(TP, HIGH);                 // pull the Trig pin to high level for more than 10us impulse 
  delayMicroseconds(10);
  digitalWrite(TP, LOW);
  long microseconds = pulseIn(EP,HIGH);   // waits for the pin to go HIGH, and returns the length of the pulse in microseconds
  return microseconds;                    // return microseconds
}
/*
 * Depending on witch flag a pin is set high
 */

void obsticalCheck(long distance, int flag){
  /*When an obstical is detected the pin is set high*/
  if(flag==FORWARD){
    if(distance > MaxDistance){
      digitalWrite(FORWARD, LOW);
      Serial.println("Inget hinder");
    }if(distance<MaxDistance){
      digitalWrite(FORWARD, HIGH);
      Serial.println("HINDER");
    }
  }                                         //TA BORT SERIAL.PRINT
  if(flag==LEFT){
    if(distance > MaxDistance){
      digitalWrite(LEFT, LOW);
      Serial.println("Inget hinder");
    }if(distance<MaxDistance){
      digitalWrite(LEFT, HIGH);
      Serial.println("HINDER");  
    }
  }
  if(flag==RIGHT){
    if(distance > MaxDistance){
      digitalWrite(RIGHT, LOW);
      Serial.println("Inget hinder");
    }if(distance<MaxDistance){
      digitalWrite(RIGHT, HIGH);
      Serial.println("HINDER");
    }
  }
}


