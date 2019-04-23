#include <Servo.h>

Servo myservo;  // create servo object to control a servo



void setup() {
  pinMode (8,INPUT);
  myservo.attach(9,500,2400);// attaches the servo on pin 9 to the servo object
  Serial.begin(115200);
    myservo.write(90);}

void loop() {
 
delay(500);
  uint8_t a = digitalRead(8);
  Serial.println(a);
   if(a == 0 )
  {   myservo.write(30); 
      if(a == 1)
       myservo.write(90); 
  }
   else if(a == 1) 
   {myservo.write(90);}
 
 
}




