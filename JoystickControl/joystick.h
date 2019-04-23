#ifndef _JOYSTICK_H
#define  _JOYSTICK_H


#include <usbhid.h>
#include <hiduniversal.h>
#include <usbhub.h>

#include "Arduino.h"
#include "DCmotor.h"
#include "hidjoystickrptparser.h"

// Satisfy IDE, which only needs to see the include statment in the ino.
#ifdef dobogusinclude
#include <spi4teensy3.h>
#endif
#include <SPI.h>
















class Motion:public JoystickEvents,public DCMotor {

	

public:
	  uint8_t X1;
    uint8_t Y1; 
    uint8_t X2;
    uint8_t X3;
    uint8_t Y2;
    uint8_t threshold;
		uint8_t avg;
    uint16_t button_read;
    uint8_t  hat_read;
    uint8_t state =0;

    float speed_divisor = 4.0;
		
		void joy();
   void init();
   void motor_rotation();
   
};

#endif





  
 



  
  
