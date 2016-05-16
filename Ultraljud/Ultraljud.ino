/* Ultrasonic Ranging
 Library for HC-SR04 Ultrasonic Ranging Module.librar
 created 2011
 by Robi.Wang
 www.Elecfreak.com

 Modified 20/4-2016 
 by Patricia Jönsson and Hamoud Abdoula
 */
 
#define CM 1      //Centimeter
#define INC 0     //Inches
#define TP_Forward 28      //Trig_pin
#define EP_Forward 32      //Echo_pin
#define TP_Left 29
#define EP_Left 31
#define TP_Right 27   
#define EP_Right  26

#define MaxDistance 20  //Max distance in cm
#define Forward 6     //Detect obstical in front
#define Left  5       //Detect obstical left
#define Right 4       //Detect obstical right


void setup(){
  initPins();        

  Serial.begin(9600);      // init serial 9600
}

  /*Reads distance to detect obstical*/
void loop(){ 
   
  long microseconds = TP_init(TP_Forward, EP_Forward);                 //Gets the time needed to calculate the distance  
  long distance = getDistance(microseconds, CM);                       //Returns the distance in form of cm. For inches change CM to INC
  //long microseconds = TP_init(TP_Left, EP_Left);
  //long microseconds = TP_init(TP_Right, EP_Right);
  Serial.print("Distance = ");
  Serial.println(distance);
  obsticalCheck(distance);
  

}






