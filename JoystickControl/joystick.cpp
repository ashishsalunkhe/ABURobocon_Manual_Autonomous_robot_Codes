#include "joystick.h"

USB Usb;
USBHub Hub(&Usb);
HIDUniversal Hid(&Usb);
JoystickEvents JoyEvents;
JoystickReportParser Joy(&JoyEvents);


void Motion::joy()
{
  Usb.Task();
          button_read = JoyEvents.button_read;
          hat_read = JoyEvents.hat_read;

          Serial.print("Button read = ");
          Serial.println(button_read);

          Serial.print("hat read = ");
          Serial.println(hat_read);
          
          
          Serial.print("Speed Divisor = ");
          Serial.println(speed_divisor);
          
          if (button_read ==  256)                                                          //tejas
          {
            state = 0;
          }


          if (button_read == 16)                                                          //tejas
          {
            speed_divisor += 0.5;
            delay(100);
          }

          
          if (button_read == 64)                                                          //tejas
          {
            if (speed_divisor != 1)
            {
              speed_divisor -= 0.5;
              delay(100);
            }
          } 


           if (button_read == 32)                                                          //tejas
          {
            speed_divisor += 0.25;
            delay(100);
          }

          
          if (button_read == 128)                                                          //tejas
          {
            if (speed_divisor != 1)
            {
              speed_divisor -= 0.25;
              delay(100);
            }
          }



          
    while(state == 0)
    {
       Usb.Task();
          button_read = JoyEvents.button_read;
         // hat_read = JoyEvents.hat_read;
  
             analogWrite(4,0);  
             analogWrite(5,0);  
             analogWrite(6,0);  
             analogWrite(7,0); 

              if(button_read == 512)                                      // state changer
              {state = 1;}
      }
   
   
   if(state == 1)                                                         // state condition
   {
    
    motor_rotation();
    if(hat_read == 1)
            { Serial2.print("a");  
             Serial2.print("0");  delay(100);}
    else if(hat_read == 16)
            { Serial2.print("a");
              Serial2.print("1"); delay(100);}
    
   
   Serial.println(hat_read);
   Serial.println(button_read);

     if(hat_read == 4)
            { Serial2.print("b");
             Serial2.print("0");  delay(100);}
     else if(hat_read == 64)
            { Serial2.print("b");
              Serial2.print("1"); delay(100);}
   }
} 
     




void Motion::init()
{
   Serial.begin(115200);
#if !defined(__MIPSEL__)
        while (!Serial); // Wait for serial port to connect - used on Leonardo, Teensy and other boards with built-in USB CDC serial connection
#endif
        Serial.println("Start");

        if (Usb.Init() == -1)
                Serial.println("OSC did not start.");

        delay(200);

        if (!Hid.SetReportParser(0, &Joy))
                ErrorMessage<uint8_t > (PSTR("SetReportParser"), 1);
            pinMode(8,OUTPUT); 
            pinMode(9,OUTPUT); 
            pinMode(10,OUTPUT); 
            pinMode(11,OUTPUT); 
}


void Motion::motor_rotation()
{

   if(JoyEvents.Y1 < 128)
  {
     if(JoyEvents.X2 < 128)
     {
       Y1 = map(JoyEvents.Y1, 0, 128, 0, 250);
       X2 = map(JoyEvents.X2, 128, 0, 0, 250);
       avg = (Y1 + X2)/2;
       diagonal_flt(avg,avg,avg,avg);
       Serial.println("Diagonal forward-left motion"); 
      }

       if(JoyEvents.X2 > 128)
      {
        Y1 = map(JoyEvents.Y1, 0, 128, 0, 250);
        X2 = map(JoyEvents.X2, 128, 255, 0, 250);
        avg = (Y1 + X2)/2;
        diagonal_frt(avg,avg,avg,avg);
        Serial.println("Diagonal forward-right motion"); 
      }

       if(JoyEvents.Y2 > 128)
      {
        Y1 = map(JoyEvents.Y1, 128, 0, 0, 125); 
        Y2 = map(JoyEvents.Y2, 128, 255, 0, 125);  
        avg = (Y1 + Y2)/2;
        avg = avg/speed_divisor;
        right_rotation(avg,avg,avg,avg);
        Serial.println("Right rotation");
      }
      else  
      {
        Y1 = map(JoyEvents.Y1, 128, 0, 0, 120);
        Y1 = Y1/speed_divisor;
        dcforward(Y1,Y1,Y1,Y1);
        Serial.println("Forward motion");
      }
     
      }
   
  
  
   else if(JoyEvents.Y1>128)
   {
     if(JoyEvents.X2 < 128)
    {
       Y1 = map(JoyEvents.Y1, 128, 255, 0, 250);
       X2 = map(JoyEvents.X2, 128, 0, 0, 250);
       avg = (Y1 + X2)/2;
       diagonal_blt(avg,avg,avg,avg);
       Serial.println("Diagonal backward-left motion"); 
    }

    else if(JoyEvents.X2 > 128)
    {
      Y1 = map(JoyEvents.Y1, 128, 255, 0, 250);
      X2 = map(JoyEvents.X2, 128, 255, 0, 250);
      avg = (Y1 + X2)/2;
      diagonal_brt(avg,avg,avg,avg);
      Serial.println("Diagonal backward-right motion"); 
    }
     if(JoyEvents.Y2<128)
    {
      Y1 = map(JoyEvents.Y1, 128, 255, 0, 125);  //chinmayee
      Y2 = map(JoyEvents.Y2, 128, 0, 0, 125);    //chinmayee
      avg = (Y1 + Y2)/2;
      avg = avg/speed_divisor;
      left_rotation(avg,avg,avg,avg);
      Serial.println("Left rotation");
    }
    else 
    {
      Y1 = map(JoyEvents.Y1, 128, 255, 0, 250);
      Y1 = Y1/speed_divisor;
      dcreverse(Y1,Y1,Y1,Y1);
      Serial.println("Reverse motion");
    }
  }

  
  else if(JoyEvents.X2 < 128)
  {
    X2 = map(JoyEvents.X2, 128, 0, 0, 250);
    X2 = X2/speed_divisor;
    dcleft(X2,X2,X2,X2);
    Serial.println("Left motion"); 
  }

  else if(JoyEvents.X2 > 128)
  {
    X2 = map(JoyEvents.X2, 128, 255, 0, 250);
    X2 = X2/speed_divisor;
    dcright(X2,X2,X2,X2);
    Serial.println("Right motion"); 
  }

  else { stopp(); }
 
  
  }

