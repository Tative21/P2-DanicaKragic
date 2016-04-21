/* Ultrasonic Ranging
 Library for HC-SR04 Ultrasonic Ranging Module.librar
 created 2011
 by Robi.Wang
 www.Elecfreak.com

 Modified 20/4-2016
 */
 
#define CM 1      //Centimeter
#define INC 0     //Inches
#define TP_Forward 28      //Trig_pin
#define EP_Forward 32      //Echo_pin
/*
#define TP_Left
#define EP_Left
#define TP_Right    ADD PIN NUMBERS
#define EP_Right
*/
#define MaxDistance 20  //Max distance in cm
#define Forward 6     //Detect obstical in front
#define Left  5       //Detect obstical left
#define Right 4       //Detect obstical right


void setup(){
  initPins();        
  digitalWrite(Left, LOW);
  digitalWrite(Right, LOW);
  digitalWrite(Forward, LOW);
  Serial.begin(9600);      // init serial 9600
}

  /*Reads distance to detect obstical*/
void loop(){ 
   
  long microseconds = TP_init(TP_Forward, EP_Forward);                 //Gets the time needed to calculate the distance  
  long distance = getDistance(microseconds, CM);                       //Returns the distance in form of cm. For inches change CM to INC
  Serial.print("Distance = ");
  Serial.println(distance);
  obsticalCheck(distance);
  

}






