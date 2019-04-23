
#ifndef _DCMOTOR_H
#define _DCMOTOR_H
#include "Arduino.h"
#include "Basic_Motor.h"

#define k 1
#define d 20
#define ds 15
#define d1 30



class encoder{
	public:
		volatile uint16_t steps;
		volatile float s;
		volatile int steps_taken;
		int lastencoded = 0; 
		volatile int encoderValue = 0;
		
		int step(int a);
		int E1();


   
/*volatile int count = 0;//new Encodder test program
int speed = 0;//new Encodder test program
int flag = 0;//new Encodder test program


volatile int lastEncoded = 0;//new Encodder test program
volatile long encoderValue = 0;//new Encodder test program*/
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
		void right_rotation(uint8_t sfl,uint8_t sfr,uint8_t sbl,uint8_t sbr);
		void left_rotation(uint8_t sfl,uint8_t sfr,uint8_t sbl,uint8_t sbr);
		void stop();
    void stop1();
		void rotate(unsigned char direction, uint8_t angle);
    void rotate1(unsigned char direction, uint16_t steps);
    void Left_Rot_sensor(uint8_t dir , uint8_t sfl , uint8_t sbl); // Omkar
};

#endif



