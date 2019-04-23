#include "joystick.h"

USB Usb;
USBHub Hub(&Usb);
HIDUniversal Hid(&Usb);
JoystickEvents JoyEvents;
JoystickReportParser Joy(&JoyEvents);


void Motion::joy()
{
   Usb.Task();
  if( JoyEvents.Y1 > 128 && JoyEvents.X2 > 128)
  {
    Y1 = map(JoyEvents.Y1, 128, 255, 0, 255);
    X2 = map(JoyEvents.X2, 128, 255, 0, 255);
    avg = (Y1 + X2)/2;
    diagonal_brt(avg,avg,avg,avg);
    Serial.println("Diagonal backward-right motion"); 
    
  }
  
  else if(JoyEvents.Y1>128 && JoyEvents.Y2<128)
  {
    Y1 = map(JoyEvents.Y1, 128, 255, 0, 255);
    Y2 = map(JoyEvents.Y2, 0, 128, 0, 255);
    avg = (Y1 + Y2)/2;
    left_rotation(avg,avg,avg,avg);
    Serial.println("Left rotation");
  }

  
  else if(JoyEvents.Y1<128 && JoyEvents.Y2>128)
  {
    Y1 = map(JoyEvents.Y1, 0, 128, 0, 255);
    Y2 = map(JoyEvents.Y2, 128, 255, 0, 255);
    avg = (Y1 + Y2)/2;
    right_rotation(avg,avg,avg,avg);
    Serial.println("Right rotation");
    
  }

   else if( JoyEvents.Y1 < 128 && JoyEvents.X2 < 128)
  {
    Y1 = map(JoyEvents.Y1, 0, 128, 0, 255);
    X2 = map(JoyEvents.X2, 0, 128, 0, 255);
    avg = (Y1 + X2)/2;
    diagonal_flt(avg,avg,avg,avg);
    Serial.println("Diagonal forward-left motion"); 
   }
  
  
  else if( JoyEvents.Y1 > 128 && JoyEvents.X2 < 128)
  {
    Y1 = map(JoyEvents.Y1, 128, 255, 0, 255);
    X2 = map(JoyEvents.X2, 0, 128, 0, 255);
    avg = (Y1 + X2)/2;
    diagonal_blt(avg,avg,avg,avg);
    Serial.println("Diagonal backward-left motion"); 
   }
  
  else if(JoyEvents.Y1<128)
  {
    Y1 = map(JoyEvents.Y1, 0, 128, 0, 255);
     dcforward(Y1,Y1,Y1,Y1);
     Serial.println("Forward motion");
   }
  
  
  else if(JoyEvents.Y1>128)
  {
    Y1 = map(JoyEvents.Y1, 128, 255, 0, 255);
    dcreverse(Y1,Y1,Y1,Y1);
    Serial.println("Reverse motion");     
  }

  
  else if(JoyEvents.X2 < 128)
  {
    X2 = map(JoyEvents.X2, 0, 128, 0, 255);
    dcleft(X2,X2,X2,X2);
    Serial.println("Left motion");
    
  }

  
  else if(JoyEvents.X2 > 128)
  {
    X2 = map(JoyEvents.X2, 128, 255, 0, 255);
    dcright(X2,X2,X2,X2);
    Serial.println("Right motion"); 
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
}

