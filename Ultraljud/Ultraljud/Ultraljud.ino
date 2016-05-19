/* Ultrasonic Ranging
 Library for HC-SR04 Ultrasonic Ranging Module.librar
 created 2011
 by Robi.Wang
 www.Elecfreak.com

 Modified 20/4-2016 
 by Patricia Jönsson, William Ouda and Hamoud Abdoula
 */
 
#define CM 1      //Centimeter
#define INC 0     //Inches
#define TP_Forward 28      //Trig_pin
#define EP_Forward 29      //Echo_pin
#define TP_Left 30
#define EP_Left 31
#define TP_Right 32   
#define EP_Right 33

#define MaxDistance 35  //Max distance in cm
#define FORWARD 3       //Detect obstical in front
#define LEFT  4         //Detect obstical left
#define RIGHT 5         //Detect obstical right


void setup(){
  initPins();        
  Serial.begin(9600);  
}

void loop(){  
  long microseconds_F = TP_init(TP_Forward, EP_Forward);    //Gets the time needed to calculate the distance  
  long microseconds_R = TP_init(TP_Right, EP_Right);       
  long microseconds_L = TP_init(TP_Left, EP_Left);
  long distance_F = getDistance(microseconds_F, CM);        //Returns the distance in form of cm. For inches change CM to INC
  long distance_L = getDistance(microseconds_L, CM);
  long distance_R = getDistance(microseconds_R, CM);
  
  obsticalCheck(distance_F, FORWARD);
  obsticalCheck(distance_R, RIGHT);
  obsticalCheck(distance_L, LEFT);
  
 /* 
  Serial.print("Distance Forward = ");
  Serial.println(distance_F);
  Serial.print("Distance Left = ");
  Serial.println(distance_L);
  //Serial.print("Distance Right = ");
  //Serial.println(distance_R);
  */
  

}






