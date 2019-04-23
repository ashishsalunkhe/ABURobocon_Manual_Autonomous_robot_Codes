
#include "def.h"

//DCMotor mymotor;





void setup() { 

Motions.init();
Serial.begin(115200);
Serial2.begin(115200);
}



void loop() 
 { 
  Motions.joy();
  

 
 /* while ((Serial.available()) > 0)
  {
   // b = (char)Serial.read();
    //Serial.println(b);
      //a[i] += b;
    //i++;
    speed1 = Serial.parseInt();
  }
  //a[i] = '\0';
  Serial.println(speed2);
  
  if (speed1 > 0)
  {
    speed2 = speed1;
    analogWrite(2,speed2);
  }
 // delay(1000);
  }

*/
 }
