#include "Arduino.h"
#include "DCMotor.h"
#define R 36.25
#define encoderPin1 51
#define encoderPin2 52



//Variables for motor

extern uint8_t pwm1;
extern uint8_t pwm2;
extern uint8_t pwm3;
extern uint8_t pwm4;

extern uint8_t dir1;
extern uint8_t dir2;
extern uint8_t dir3;
extern uint8_t dir4;
extern uint16_t PPR;
uint8_t flag = 0 ;

//Variables for motor











//Code for motor

void DCMotor::stopp()  //function used to stop motor
{ 
	int i;
	flag = 0;
	if (max == 0){
		for (i = max; i >= 0; (i = (i-d)))
		{
			if (ssfl > 0)
			{
				analogWrite(pwm1, i);
			}
		
			if (ssfr > 0)
			{
				analogWrite(pwm4, i);
			}
		
			if (ssbl > 0)
			{
				analogWrite(pwm3, i);
			}
		
			if (ssbr > 0)
			{
				analogWrite(pwm2, i);
			}
			delay(ds);
		}
	}
	
	analogWrite(pwm1, 0);
	analogWrite(pwm2, 0);
	analogWrite(pwm3, 0);
	analogWrite(pwm4, 0);
  max = 0;
}

void DCMotor::motorinit() //Setting motor pins as output 
{
	pinMode(encoderPin1,INPUT);
	pinMode(encoderPin2,INPUT);
	
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
	Serial.println("Enable pins set as output");
}

void DCMotor::dcforward(uint8_t sfl,uint8_t sfr,uint8_t sbl,uint8_t sbr) //Giving forward motion
{
	max = max(sfl, sfr);
	max = max(max, sbl);
	max = max(max, sbr);
	
	frontlt_CW();   //Giving clockwise motion to front left wheel
	frontrt_CCW();  //Giving counter-clockwise motion to front right wheel
	backlt_CCW();   //Giving counter-clockwise motion to back left wheel
	backrt_CW();   //Giving clockwise motion to back rightt wheel
	
	if (flag == 0)
	{
		for(uint8_t i=1;i<max;i+=5)
		{
			if(i<sfl) {analogWrite(pwm1, i); }
			if(i<sfr) {analogWrite(pwm4, i); }
			if(i<sbl) {analogWrite(pwm3, i); }
			if(i<sbr) {analogWrite(pwm2, i); }
		}
		delay(d);
		flag = 1;
	}

	else 
	{
		analogWrite(pwm1, sfl);
		analogWrite(pwm4, sfr);
		analogWrite(pwm3, sbl);    
		analogWrite(pwm2, sbr);
	}

	Serial.print("Speed of Front left motor set to: ");
	Serial.println(sfl);
	Serial.print("Speed of Front right motor set to: ");
	Serial.println(sfr);
	Serial.print("Speed of Back left motor set to: ");
	Serial.println(sbl);
	Serial.print("Speed of Back right motor set to: ");
	Serial.println(sbr);
    
	ssfl = sfl;
  ssfr = sfr;
  ssbl = sbl;
  ssbr = sbr;
}
	
//Giving clockwise motion to back right wheel

void DCMotor::dcreverse(uint8_t sfl,uint8_t sfr,uint8_t sbl,uint8_t sbr) //Giving backward motion 
{
  max = max(sfl, sfr);
	max = max(max, sbl);
	max = max(max, sbr);

	frontlt_CCW();//Giving counter-clockwise motion to front left wheel
	frontrt_CW(); //Giving clockwise motion to front right wheel
	backlt_CW(); //Giving clockwise motion to back left wheel
	backrt_CCW(); //Giving counter-clockwise motion to back right wheel
	
	if (flag == 0)
	{
		for(uint8_t i=1;i<max;i+=5)		{
			if(i<sfl) {analogWrite(pwm1, i); }
			if(i<sfr) {analogWrite(pwm4, i); }
			if(i<sbl) {analogWrite(pwm3, i); }
			if(i<sbr) {analogWrite(pwm2, i); }
		}
		delay(d);
		flag = 1;
	}

	else 
	{
		analogWrite(pwm1, sfl);
		analogWrite(pwm4, sfr);
		analogWrite(pwm3, sbl);    
		analogWrite(pwm2, sbr);
	}

	Serial.print("Speed of Front left motor set to: ");
	Serial.println(sfl);
	Serial.print("Speed of Front right motor set to: ");
	Serial.println(sfr);
	Serial.print("Speed of Back left motor set to: ");
	Serial.println(sbl);
	Serial.print("Speed of Back right motor set to: ");
	Serial.println(sbr);
    
	ssfl = sfl;
  ssfr = sfr;
  ssbl = sbl;
  ssbr = sbr;

}

void DCMotor::dcleft(uint8_t sfl,uint8_t sfr,uint8_t sbl,uint8_t sbr) // Motion towards left
{
  
	max = max(sfl, sfr);
	max = max(max, sbl);
	max = max(max, sbr);

	frontlt_CCW(); //Giving counter-clockwise motion to front left wheel
	frontrt_CW(); //Giving clockwise motion to front right wheel	
	backlt_CCW(); //Giving counter-clockwise motion to back left wheel
	backrt_CW(); //Giving clockwise motion to back right wheel
	
	if (flag == 0)
	{
		for(uint8_t i=1;i<max;i+=5)
		{
			if(i<sfl) {analogWrite(pwm1, i); }
			if(i<sfr) {analogWrite(pwm4, i); }
			if(i<sbl) {analogWrite(pwm3, i); }
			if(i<sbr) {analogWrite(pwm2, i); }
		}
		delay(d);
		flag = 1;
	}

	else 
	{
		analogWrite(pwm1, sfl);
		analogWrite(pwm4, sfr);
		analogWrite(pwm3, sbl);    
		analogWrite(pwm2, sbr);
	}

	Serial.print("Speed of Front left motor set to: ");
	Serial.println(sfl);
	Serial.print("Speed of Front right motor set to: ");
	Serial.println(sfr);
	Serial.print("Speed of Back left motor set to: ");
	Serial.println(sbl);
	Serial.print("Speed of Back right motor set to: ");
	Serial.println(sbr);
    
	  ssfl = sfl;
    ssfr = sfr;
    ssbl = sbl;
    ssbr = sbr;
	
	
}

void DCMotor::dcright(uint8_t sfl,uint8_t sfr,uint8_t sbl,uint8_t sbr) // Motion towards right
{	
	max = max(sfl, sfr);
	max = max(max, sbl);
	max = max(max, sbr);
	
	frontlt_CW(); //Giving clockwise motion to front left wheel
	frontrt_CCW(); //Giving counter-clockwise motion to front right wheel
	backlt_CW(); //Giving clockwise motion to back left wheel
	backrt_CCW(); //Giving counter-clockwise motion to back right wheel


    if (flag == 0)
	{
		for(uint8_t i=1;i<max;i+=5)
		{
			if(i<sfl) {analogWrite(pwm1, i); }
			if(i<sfr) {analogWrite(pwm4, i); }
			if(i<sbl) {analogWrite(pwm3, i); }
			if(i<sbr) {analogWrite(pwm2, i); }
		}
		delay(d);
		flag = 1;
	}

	else 
	{
		analogWrite(pwm1, sfl);
		analogWrite(pwm4, sfr);
		analogWrite(pwm3, sbl);    
		analogWrite(pwm2, sbr);
	}

	Serial.print("Speed of Front left motor set to: ");
	Serial.println(sfl);
	Serial.print("Speed of Front right motor set to: ");
	Serial.println(sfr);
	Serial.print("Speed of Back left motor set to: ");
	Serial.println(sbl);
	Serial.print("Speed of Back right motor set to: ");
	Serial.println(sbr);
    
	  ssfl = sfl;
    ssfr = sfr;
    ssbl = sbl;
    ssbr = sbr;	
}

void DCMotor::diagonal_flt(uint8_t sfl ,uint8_t sfr,uint8_t sbl,uint8_t sbr ) // Diagonal motion towards front-left
{
	sfl=0;
    sbr=0;
	
	max = max(sfl, sfr);
	max = max(max, sbl);
	max = max(max, sbr);
	
	frontrt_CCW(); //Giving counter-clockwise motion to front right wheel
	backlt_CCW(); //Giving counter-clockwise motion to back left wheel
   

	if (flag == 0)
	{
		for(uint8_t i=1;i<max;i+=5)
		{
			if(i<sfl) {analogWrite(pwm1, i); }
			if(i<sfr) {analogWrite(pwm4, i); }
			if(i<sbl) {analogWrite(pwm3, i); }
			if(i<sbr) {analogWrite(pwm2, i); }
		}
		delay(d);
		flag = 1;
	}

	else 
	{
		analogWrite(pwm1, sfl);
		analogWrite(pwm4, sfr);
		analogWrite(pwm3, sbl);    
		analogWrite(pwm2, sbr);
	

	Serial.print("Speed of Front left motor set to: ");
	Serial.println(sfl);
	Serial.print("Speed of Front right motor set to: ");
	Serial.println(sfr);
	Serial.print("Speed of Back left motor set to: ");
	Serial.println(sbl);
	Serial.print("Speed of Back right motor set to: ");
	Serial.println(sbr);
    
	ssfl = sfl;
    ssfr = sfr;
    ssbl = sbl;
    ssbr = sbr;	
}
}

void DCMotor::diagonal_frt(uint8_t sfl,uint8_t sfr,uint8_t sbl,uint8_t sbr) // Diagonal motion towards front-right
{
	sfr=0;
    sbl=0;
	
	max = max(sfl, sfr);
	max = max(max, sbl);
	max = max(max, sbr);
	
	frontlt_CW(); //Giving clockwise motion to front left wheel
	backrt_CW(); //Giving clockwise motion to back right wheel

	if (flag == 0)
	{
		for(uint8_t i=1;i<max;i+=5)
		{
			if(i<sfl) {analogWrite(pwm1, i); }
			if(i<sfr) {analogWrite(pwm4, i); }
			if(i<sbl) {analogWrite(pwm3, i); }
			if(i<sbr) {analogWrite(pwm2, i); }
		}
		delay(d);
		flag = 1;
	}

	else 
	{
		analogWrite(pwm1, sfl);
		analogWrite(pwm4, sfr);
		analogWrite(pwm3, sbl);    
		analogWrite(pwm2, sbr);
	}

	Serial.print("Speed of Front left motor set to: ");
	Serial.println(sfl);
	Serial.print("Speed of Front right motor set to: ");
	Serial.println(sfr);
	Serial.print("Speed of Back left motor set to: ");
	Serial.println(sbl);
	Serial.print("Speed of Back right motor set to: ");
	Serial.println(sbr);
    
   	ssfl = sfl;
    ssfr = sfr;
    ssbl = sbl;
    ssbr = sbr;
}

void DCMotor::diagonal_blt(uint8_t sfl,uint8_t sfr,uint8_t sbl,uint8_t sbr) // Diagonal motion towards back-left
{
	sfr=0;
    sbl=0;
	
	frontlt_CCW(); //Giving counter-clockwise motion to front left wheel
	backrt_CCW(); //Giving counter-clockwise motion to back right wheel

    max = max(sfl, sfr);
	max = max(max, sbl);
	max = max(max, sbr);
	
	if (flag == 0)
	{
		for(uint8_t i=1;i<max;i+=5)
		{
			if(i<sfl) {analogWrite(pwm1, i); }
			if(i<sfr) {analogWrite(pwm4, i); }
			if(i<sbl) {analogWrite(pwm3, i); }
			if(i<sbr) {analogWrite(pwm2, i); }
		}
		delay(d);
		flag = 1;
	}

	else 
	{
		analogWrite(pwm1, sfl);
		analogWrite(pwm4, sfr);
		analogWrite(pwm3, sbl);    
		analogWrite(pwm2, sbr);
	}

	Serial.print("Speed of Front left motor set to: ");
	Serial.println(sfl);
	Serial.print("Speed of Front right motor set to: ");
	Serial.println(sfr);
	Serial.print("Speed of Back left motor set to: ");
	Serial.println(sbl);
	Serial.print("Speed of Back right motor set to: ");
	Serial.println(sbr);
    
	  ssfl = sfl;
    ssfr = sfr;
    ssbl = sbl;
    ssbr = sbr;
	
}

void DCMotor::diagonal_brt(uint8_t sfl,uint8_t sfr,uint8_t sbl,uint8_t sbr) // Diagonal motion towards back-right
{
	sfl=0;
    sbr=0;
	
	frontrt_CW(); //Giving clockwise motion to front right wheel
	backlt_CW(); //Giving clockwise motion to back left wheel

    max = max(sfl, sfr);
	max = max(max, sbl);
	max = max(max, sbr);
	
	if (flag == 0)
	{
		for(uint8_t i=1;i<max;i+=5)
		{
			if(i<sfl) {analogWrite(pwm1, i); }
			if(i<sfr) {analogWrite(pwm4, i); }
			if(i<sbl) {analogWrite(pwm3, i); }
			if(i<sbr) {analogWrite(pwm2, i); }
		}
		delay(d);
		flag = 1;
	}

	else 
	{
		analogWrite(pwm1, sfl);
		analogWrite(pwm4, sfr);
		analogWrite(pwm3, sbl);    
		analogWrite(pwm2, sbr);
	}

	Serial.print("Speed of Front left motor set to: ");
	Serial.println(sfl);
	Serial.print("Speed of Front right motor set to: ");
	Serial.println(sfr);
	Serial.print("Speed of Back left motor set to: ");
	Serial.println(sbl);
	Serial.print("Speed of Back right motor set to: ");
	Serial.println(sbr);
    
	  ssfl = sfl;
    ssfr = sfr;
    ssbl = sbl;
    ssbr = sbr;
			
}

void DCMotor::left_rotation(uint8_t sfl,uint8_t sfr,uint8_t sbl,uint8_t sbr) // Turning to left
{
	  //sfl=0;
    //sbr=0;
	frontlt_CCW(); //Giving counter-clockwise motion to front left wheel
	frontrt_CCW(); //Giving counter-clockwise motion to front right wheel
	backlt_CW(); //Giving clockwise motion to back left wheel
 backrt_CW(); //Giving clockwise motion to back left wheel

    max = max(sfl, sfr);
	max = max(max, sbl);
	max = max(max, sbr);
	
	if (flag == 0)
	{
		for(uint8_t i=1;i<max;i+=5)
		{
			if(i<sfl) {analogWrite(pwm1, i); }
			if(i<sfr) {analogWrite(pwm4, i); }
			if(i<sbl) {analogWrite(pwm3, i); }
			if(i<sbr) {analogWrite(pwm2, i); }
		}
		delay(d);
		flag = 1;
	}

	else 
	{
		analogWrite(pwm1, sfl);
		analogWrite(pwm4, sfr);
		analogWrite(pwm3, sbl);    
		analogWrite(pwm2, sbr);
	}

	Serial.print("Speed of Front left motor set to: ");
	Serial.println(sfl);
	Serial.print("Speed of Front right motor set to: ");
	Serial.println(sfr);
	Serial.print("Speed of Back left motor set to: ");
	Serial.println(sbl);
	Serial.print("Speed of Back right motor set to: ");
	Serial.println(sbr);
    
	  ssfl = sfl;
    ssfr = sfr;
    ssbl = sbl;
    ssbr = sbr;
}

void DCMotor::right_rotation(uint8_t sfl,uint8_t sfr,uint8_t sbl,uint8_t sbr) // Turning to right
{
    sfr=0;
    sbl=0;
	
	frontlt_CW(); //Giving clockwise motion to front left wheel
  frontrt_CW(); //Giving clockwise motion to front right wheel
  backlt_CCW(); //Giving counter-clockwise motion to back left wheel
	backrt_CCW(); //Giving counter-clockwise motion to back right wheel

    max = max(sfl, sfr);
	max = max(max, sbl);
	max = max(max, sbr);
	
	if (flag == 0)
	{
		for(uint8_t i=1;i<max;i+=5)
		{
			if(i<sfl) {analogWrite(pwm1, i); }
			if(i<sfr) {analogWrite(pwm4, i); }
			if(i<sbl) {analogWrite(pwm3, i); }
			if(i<sbr) {analogWrite(pwm2, i); }
		}
		delay(d);
		flag = 1;
	}

	else 
	{
		analogWrite(pwm1, sfl);
		analogWrite(pwm4, sfr);
		analogWrite(pwm3, sbl);    
		analogWrite(pwm2, sbr);
	}

	Serial.print("Speed of Front left motor set to: ");
	Serial.println(sfl);
	Serial.print("Speed of Front right motor set to: ");
	Serial.println(sfr);
	Serial.print("Speed of Back left motor set to: ");
	Serial.println(sbl);
	Serial.print("Speed of Back right motor set to: ");
	Serial.println(sbr);
    
	  ssfl = sfl;
    ssfr = sfr;
    ssbl = sbl;
    ssbr = sbr;
		
}




//Code for encoder

int encoder::E1()
{
  int MSB = digitalRead(encoderPin1); //MSB = most significant bit
  int LSB = digitalRead(encoderPin2); //LSB = least significant bit
 
  int encoded = (MSB << 1) |LSB; //converting the 2 pin value to single number
  int sum  = (lastencoded << 2) | encoded; //adding it to the previous encoded value
 
  if(sum == 0b1101 || sum == 0b0100 || sum == 0b0010 || sum == 0b1011) encoderValue ++; steps_taken++;
  if(sum == 0b1110 || sum == 0b0111 || sum == 0b0001 || sum == 0b1000) encoderValue ++;	steps_taken++; 
 
  lastencoded = encoded; //store this value for next time
	
}

int encoder::step(int a) //a is angle in degree
{
	float radian_angle;
	radian_angle = a * (3.14/180);
	s = (R * radian_angle);  									// s is distance to be traveled
	steps = s / (31.42/PPR); 											// 0.320=(31.42 cm / ppr) 
	return steps;
}


void DCMotor::rotate(unsigned char direction, uint8_t angle) //To rotate with direction and angle
{
	steps_taken = 0;	
	int required_steps = step(angle);  
	
	switch(direction)  //Direction must be in 'L' or 'R
	{
		case 'L':
					while (steps_taken <  required_steps)
					{
						left_rotation(200,200,200,200);  //calling left rotation function
						E1();                        
					}
					stopp();  //calling stop function
		break;
		
		case 'R':
					while (steps_taken <  required_steps)
					{
						right_rotation(200,200,200,200);  //calling right rotation function
						E1();
					}
					stopp();  //calling stop function
		break;
		
		default:
			        stopp();
		break;
	}
}
