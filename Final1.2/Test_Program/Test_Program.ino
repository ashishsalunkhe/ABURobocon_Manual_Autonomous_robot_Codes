///////final


#include "def.h"
//#include "DCmotor.h"
//#include "Servo.h"      //ashish
//Servo myservo
 uint16_t x;
  uint16_t y;


 uint8_t sensorF;
 uint8_t sensorB;
 uint8_t sensorR;
 uint8_t sensorL;
 char received;
 
 
void assignSensor()
{
  sensorF = LineF.readsensor();
      // Serial1.print("Front read =");
      // Serial1.println(sensorF);  
       
  sensorB = LineB.readsensor();
      // Serial1.print("Back read =");
      // Serial1.println( sensorB);
       
  sensorR = LineR.readsensor();
      // Serial1.print("Right read =");
      // Serial1.println(sensorR);
       
  sensorL = LineL.readsensor();
      // Serial1.print("Left read =");
     //  Serial1.println(sensorL);

       //delay(2000);
}



//encoder e;

void numatics()
{ 
  uint8_t in = 0;
  Serial2.println('b');

          //  while(Serial2.available() == 0);
           digitalWrite(A2,HIGH);
    digitalWrite(A3,LOW);
    in =((digitalWrite(A0)<<0) || (digitalWrite(A1)<<1) )
   
            received = Serial2.read();
            
            if(received == 'b' ){
              

              
                Serial2.print('c');
              Serial2.print(received);
                
              
                        
            
                        assignSensor();
                        while(sensorR > 0 && sensorL > 0)
                        {mymotor.dcleft(80,80,80,80);
                          assignSensor();
                          }

                        while(sensorL > 0 || sensorL < 192)             // reverse motion
                        { 
                          mymotor.dcleft(70,70,70,70);
                   
                          assignSensor();
                          if(sensorL > 0 && sensorL < 8)
                          {
                            mymotor.left_rotation(75,75,75,75);
                             assignSensor();}
                          else if(sensorL > 64 && sensorL < 192)
                            { mymotor.right_rotation(75,75,75,75);
                              assignSensor();
                            }
                         else if(sensorF >= 4 && sensorB > 0 )
                              { 
                                assignSensor();
                               // Serial1.println("Stopped beacuse of : front and right");
                                mymotor.stop1();
                                break;
                                }
                         }
                         mymotor.stop1();
            }    }   
 

void gripper()
{uint8_t in = 0;
    Serial2.println('a');
    digitalWrite(A2,HIGH);
    digitalWrite(A3,LOW);
    in =((digitalWrite(A0)<<0) || (digitalWrite(A1)<<1) )
    
             //received = Serial2.read();
             if(received == 0x01){
                delay(500);
                  
                while((sensorF > 0) && (sensorB > 0))
                  {
                    assignSensor();
                    mymotor.dcright(70,70,70,70);
                  }

            
         
          mymotor.dcright(70,70,70,70);
          assignSensor();
          while(sensorR > 0 || sensorR < 192)
          {
            mymotor.dcright(100,100,100,100);
            assignSensor();
            if(sensorR > 0  && sensorR < 8)
               {mymotor.left_rotation(80,80,80,80);
               
                 
                 assignSensor();}
            else if(sensorR > 64 && sensorR < 192)
               {mymotor.right_rotation(80,80,80,80);
                  
                  assignSensor();}
          
             else if(sensorF >=4 && sensorB > 0 )
                  { 
                    assignSensor();
                  //  Serial1.println("Stopped beacuse of : front and right");
                    mymotor.stop1();
                    break;}

                  
        //    else {mymotor.stop1();}
            
          }

          mymotor.stop1();

         }
         numatics();
         
}
     




void linesensorTest()
{           
       mymotor.dcforward(100,100,100,100);
         assignSensor();
          
          while(sensorF < 128) { assignSensor();}
           mymotor.dcforward(60,60,60,60);
              
          while(sensorR < 1)
           {  assignSensor(); }
           mymotor.stop1(); 
         
          mymotor.dcright(100,100,100,100);
          assignSensor();
          while(sensorR > 0 || sensorR < 192)
          {
            mymotor.dcright(120,120,120,120);
            assignSensor();
            if(sensorR > 0  && sensorR < 8)
               {mymotor.left_rotation(80,80,80,80);
               
                 
                 assignSensor();}
            else if(sensorR > 64 && sensorR < 192)
               {mymotor.right_rotation(80,80,80,80);
                  
                  assignSensor();}
          
             else if(sensorF >=4 && sensorB > 0 )
                  { 
                    assignSensor();
                  //  Serial1.println("Stopped beacuse of : front and right");
                    mymotor.stop1();
                    break;}

                  
        //    else {mymotor.stop1();}
            
          }

          mymotor.stop1();


            
                  assignSensor(); 
                 while(sensorB != 0)
                       { assignSensor();
                         mymotor.left_rotation(90,90,90,90); }
                 while(sensorB == 0 )
                       {
                        assignSensor();
                       mymotor.left_rotation(90,90,90,90); 
                       }

                  while((sensorB > 0) && (sensorB < 16) )
                       {assignSensor();  mymotor.left_rotation(70,70,70,70); }
                       
                 mymotor.stop1();

             //     delay(2000);

            gripper();
            gripper();
}                //rotate and repeat process or TZ2

            
                                                                                                                    /*  while((sensorR > 0) || (sensorR <= 192))
                                                                                                                      {
                                                                                                                          assignSensor();
                                                                                                                          if(sensorR < 8 && sensorR > 0 )
                                                                                                                             {
                                                                                                                              mymotor.left_rotation(60,60,60,60);
                                                                                                                              assignSensor();
                                                                                                                              while(sensorR < 8){assignSensor();};
                                                                                                                              mymotor.dcright(60,60,60,60);
                                                                                                                             if((sensorR > 8 || sensorR < 26) )
                                                                                                                              {
                                                                                                                                  mymotor.dcright(120,120,120,120);
                                                                                                                              }
                                                                                                                             }
                                                                                                                              
                                                                                                                         else if(sensorR > 64 && sensorR < 192 )
                                                                                                                             {
                                                                                                                              mymotor.right_rotation(60,60,60,60);
                                                                                                                              assignSensor();
                                                                                                                              
                                                                                                                              while(sensorR > 64){assignSensor();};
                                                                                                                              mymotor.dcright(60,60,60,60);
                                                                                                                              if((sensorR > 7  || sensorR < 26 ))
                                                                                                                              {
                                                                                                                                  mymotor.dcright(120,120,120,120);
                                                                                                                              }
                                                                                                                             }
                                                                                                                          
                                                                                                                          
                                                                                                                          
                                                                                                            
                                                                                                                          else if((sensorF>=4 && sensorL >=4) ||( sensorB >= 4  && sensorL >=4))
                                                                                                                              {assignSensor();
                                                                                                                              Serial1.println("Stopped beacuse of : front and right");
                                                                                                                              mymotor.stop1();
                                                                                                                               break;
                                                                                                            
                                                                                                                             
                                                                                                                             
                                                                                                                         // else {mymotor.dcright(120,120,120,120);
                                                                                                                                }
                                                                                                                      }*/
                                                                                                            
                       
              

  
//char data = 0;
void setup() { 
 
  mymotor.motorinit();
 // Motions.init();  
 Serial1.begin(115200);
  Serial.begin(115200);
  
  
  pinMode(dir1,OUTPUT);
  pinMode(dir2,OUTPUT);
  Serial.println("Front motor set as output");
  
  pinMode(dir3,OUTPUT);
  pinMode(dir4,OUTPUT);
  Serial.println("Back motor set as output");
  
  pinMode(pwm1,OUTPUT);
  pinMode(pwm2,OUTPUT);
  pinMode(pwm3,OUTPUT);
  pinMode(pwm4,OUTPUT);
  pinMode(A0,INPUT);
    pinMode(A1,INPUT);
      pinMode(A2,OUTPUT);
        pinMode(A3,OUTPUT);
/*delay(2000);
Serial1.println("Ready");
delay(2000);
Serial.println("Ready");*/

linesensorTest();




 /*Serial.begin(115200);
  pinMode(5,OUTPUT);
  digitalWrite(5,LOW);                                                   //new Encodder test program
  pinMode(2,INPUT);
  pinMode(3,INPUT);

  digitalWrite(2, HIGH); //turn pullup resistor on
  digitalWrite(3, HIGH); //turn pullup resistor on
  
  attachInterrupt(digitalPinToInterrupt(2),encoder, LOW); */

}

/*void encoder()
{
    updateEncoder();    //new Encodder test program
}*/

void loop() 
{
 // e.E1();
 
 assignSensor();
 
/*Serial.print("Front read = ");
Serial.println(LineF.readsensor());*/


/*Serial1.print("Back read = ");
Serial1.println(LineB.readsensor());*/


/*Serial1.print("Right read = ");
Serial1.println(LineR.readsensor())*/


/*Serial1.print("Left read = ");
Serial1.println(LineL.readsensor());








char data = 0;
if(Serial.available() > 0)      // Send data only when you receive data:
   {
      data = Serial.read();        //Read the incoming data & store into data
      Serial1.println(data);          //Print Value inside data in Serial monitor
      Serial.println(data); 
      switch(data)
      {
        case '1':mymotor.dcforward(80,80,80,80);
                  Serial1.println("Moving Forward");
                  Serial.println("Moving Forward");
                  break;
        case '2': mymotor.dcreverse(80,80,80,80);
                  Serial1.println("Moving Reverse");
                  Serial.println("Moving Reverse");
                  break;
        case '3': mymotor.right_rotation(120,120,120,120);
                  Serial1.println("right rotation");
                  Serial.println("right rotation");
                  break;
        case '4': mymotor.left_rotation(80,80,80,80);
                  Serial1.println("left Rotation");
                  Serial.println("left Rotation");
                  break;
        case '5': mymotor.dcleft(80,80,80,80);
                  Serial1.println("Moving left");
                  Serial.println("Moving left");
                  break;
        case '6': mymotor.dcright(80,80,80,80);
                  Serial1.println(" Moving Right");
                  Serial.println(" Moving Right");
                  break; 
        case '7': mymotor.diagonal_flt(80,80,80,80);
                  Serial1.println(" Moving Diagonal front left");
                  Serial.println(" Moving Diagonal front left");
                  break; 
        case '8': mymotor.diagonal_frt(80,80,80,80);
                  Serial1.println(" Moving diagonal front right");
                  Serial.println(" Moving diagonal front right");
                  break;
        case '9': mymotor.diagonal_blt(80,80,80,80);
                  Serial1.println(" Moving diagonal bacl left");
                  Serial.println(" Moving diagonal bacl left");
                  break; 
        case 'a': mymotor.diagonal_brt(80,80,80,80);
                  Serial1.println(" Moving diagonal back right");
                  Serial.println(" Moving diagonal back right");
                  break;
        case 'b': mymotor.stop();
                  Serial1.println("STOP");
                  Serial.println("STOP");
                  break;      
                     
      }
   


delay(1500);
mymotor.stop();









  
  //Motions.joy();
  /*if(Serial.available() > 0)
  {
    x=Serial.parseInt();
    Serial.println(x);
    
      Serial.print("inside");
      mymotor.rotate1('L',x);   
  }*/
//  Serial.println(e.E1());


  /* Serial.print("count = ");
  Serial.println(count);
  if (Serial.available())
  {
    char a = Serial.read();
    switch(a)
    {                                    //new Encodder test program
      case 'a':
      speed+=5;
      analogWrite(4,speed);
      Serial.println(speed);
      break;

      case 's':
      speed-=5;
      analogWrite(4,speed);
      Serial.println(speed);
      break;

      case 'z':
      count = 0;
      break;

      case 't':
      //analogWrite(4,0);
      flag = 0;
      digitalWrite(5,LOW);
      break;

      case 'g':
      //analogWrite(4,0);
      flag = 1;
      digitalWrite(5,HIGH);
      break;
    }
  }
  
delay(100);*/
 }


 


