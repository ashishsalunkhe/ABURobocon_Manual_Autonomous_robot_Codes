
#include "def.h"
#include "DCmotor.h"

char data = 0;

void setup() 
 {
  mymotor.motorinit();       // Motor initalization
  Serial.begin(115200);
 }


void loop() 
 {
  
 //char data = 0;
 if(Serial.available() > 0)      // Send data only when you receive data:
   {
      data = Serial.read();        //Read the incoming data & store into data
      Serial1.println(data);          //Print Value inside data in Serial monitor
      Serial.println(data); 
      switch(data)
      {
        case '1':mymotor.dcforward(70,70,70,70);                // 
                  Serial1.println("Moving Forward");
                  Serial.println("Moving Forward");
                  break;
        case '2': mymotor.dcreverse(70,70,70,70);               //
                  Serial1.println("Moving Reverse");
                  Serial.println("Moving Reverse");
                  break;
        case '3': mymotor.left_rotation(70,70,70,70);           //
                  Serial1.println("Left rotation");
                  Serial.println("Left rotation");
                  break;
        case '4': mymotor.right_rotation(70,70,70,70);          //
                  Serial1.println("Right Rotation");
                  Serial.println("Right Rotation");
                  break;
        case '5': mymotor.dcleft(70,70,70,70);                 //
                  Serial1.println("Moving left");
                  Serial.println("Moving left");
                  break;
        case '6': mymotor.dcright(70,70,70,70);               //
                  Serial1.println(" Moving Right");
                  Serial.println(" Moving Right");
                  break;       
      }
   }


delay(2000);
mymotor.stop();

}
  
 



