#include <AccelStepper.h>
#include <LiquidCrystal.h>

const int rs = A0, en = A1, d4 = A2, d5 = A3, d6 = A4, d7 = A5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

AccelStepper stepperA(1,A9,A8);
AccelStepper stepperB(1,A11,A10);

void setup() {
Serial3.begin(115200);
Serial.begin(115200);
  stepperA.setMaxSpeed(450);
  stepperA.setAcceleration(225);
  stepperB.setMaxSpeed(450);
  stepperB.setAcceleration(225);

  lcd.begin(16, 2);
}

int stepper_speed = 0,steps = 0;

void loop() {
  char stepper,dir;
while(Serial3.available()>0)
{
    stepper = Serial3.read();

   if (stepper == 'a' || stepper == 'b'){
    while(Serial3.available() == 0);
       dir = Serial3.read();
       Serial.println(stepper);
       Serial.println(dir);
   } 

    else if(stepper == 'c') {stepper_speed += 10; stepperA.setMaxSpeed(450+stepper_speed);  stepperB.setMaxSpeed(450+stepper_speed);}

    else if(stepper == 'd') 
    {
      if (stepper_speed != 0) { stepper_speed -= 10;  stepperA.setMaxSpeed(450+stepper_speed);  stepperB.setMaxSpeed(450+stepper_speed); }
    }

    else if(stepper == 'e') {steps += 500;  }

    else if(stepper == 'f') 
    {
      if (steps != 0) { steps -= 500; }
    }
}
  
  if(stepper == 'a')
  { 
           if (dir == '0')
          {
             stepperA.moveTo(1000+steps);
          }

          else if(dir == '1')
          {
            stepperA.moveTo(-1000-steps);
          }
  }

    if (stepper == 'b')
    { 
          if (dir == '0')
          {
             stepperB.moveTo(1000+steps); 
          }

          else if(dir == '1')
          {
            stepperB.moveTo(-1000-steps);
            
          }
   
    }

  stepperA.run();
  stepperB.run();

        if(stepperA.distanceToGo() == 0)
          {
            stepperA.setCurrentPosition(0);
          }
        if(stepperB.distanceToGo() == 0)
        {
            stepperB.setCurrentPosition( 0 );
        }

         lcd.setCursor(0, 1);
         lcd.print("speed ");
         lcd.print(stepper_speed);

         
         lcd.setCursor(1, 0);
         lcd.print("steps ");
         lcd.print(steps);

 }



