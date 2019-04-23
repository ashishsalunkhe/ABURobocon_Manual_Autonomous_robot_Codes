
#ifndef _DCMOTOR_H
#define _DCMOTOR_H
#include "Arduino.h"
#include "Basic_Motor.h"

#define k 2
#define d 12
#define ds 90



class encoder{
	public:
		volatile uint16_t steps;
		volatile float s;
		volatile int steps_taken;
		int lastencoded = 0; 
		volatile int encoderValue = 0;
		
		int step(int a);
		int E1();
};

class DCMotor : public Basic_Motor,public encoder {
	public:
	

			
			//decision funtion
		uint8_t ssfl, ssfr, ssbl, ssbr,max;
	
		void motorinit();
		void dcforward(uint8_t sfl,uint8_t sfr,uint8_t sbl,uint8_t sbr);
		void dcreverse(uint8_t sfl,uint8_t sfr,uint8_t sbl,uint8_t sbr);
		void dcleft(uint8_t sfl,uint8_t sfr,uint8_t sbl,uint8_t sbr);
		void dcright(uint8_t sfl,uint8_t sfr,uint8_t sbl,uint8_t sbr);
		void diagonal_flt(uint8_t sfl,uint8_t sfr,uint8_t sbl,uint8_t sbr);
		void diagonal_frt(uint8_t sfl,uint8_t sfr,uint8_t sbl,uint8_t sbr);
		void diagonal_blt(uint8_t sfl,uint8_t sfr,uint8_t sbl,uint8_t sbr);
		void diagonal_brt(uint8_t sfl,uint8_t sfr,uint8_t sbl,uint8_t sbr);
		void left_rotation(uint8_t sfl,uint8_t sfr,uint8_t sbl,uint8_t sbr);
		void right_rotation(uint8_t sfl,uint8_t sfr,uint8_t sbl,uint8_t sbr);
		void stop();
    void stop1();
		void rotate(unsigned char direction, uint8_t angle);
    void rotate1(unsigned char direction, uint16_t steps);
};

#endif



