#include "Arduino.h"
#include "DCMotor.h"
#define R 36.25
#define encoderPin1 2
#define encoderPin2 3



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



//Variables for motor











//Code for motor

void DCMotor::stop1()  //function used to stop motor
{ 
  analogWrite(pwm1,0);
  analogWrite(pwm2,0);
  analogWrite(pwm3,0);
  analogWrite(pwm4,0);

  Serial.println("Stopped");
}














void DCMotor::stop()  //function used to stop motor
{ 
	int i;
	

	for (i = max; i >= 0; (i = (i-2)))
	{
		if (ssfl > 0)
		{
			analogWrite(pwm1, i);
		}
		
		if (ssfr > 0)
		{
			analogWrite(pwm2, i);
		}
		
		if (ssbl > 0)
		{
			analogWrite(pwm3, i);
		}
		
		if (ssbr > 0)
		{
			analogWrite(pwm4, i);
		}
		
		//delay(ds);
	}
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
 // stop();
    max = max(sfl, sfr);
	max = max(max, sbl);
	max = max(max, sbr);

	
	
		frontlt_CCW();	//Giving clockwise motion to front left wheel
		frontrt_CW();	//Giving counter-clockwise motion to front right wheel
	
		backlt_CCW();	//Giving clockwise motion to back left wheel
		backrt_CCW();
	
	
	for (int i=0; i <= max; i = 2*i+k)
	{
	  if (i < sfl)
		{
			analogWrite(pwm1, i);
		}
		
		if (i < sfr)
		{
			analogWrite(pwm2, i);
		}
		
		if (i < sbl)
		{
			analogWrite(pwm3, i);
		}
		
		if (i < sbr)
		{
			analogWrite(pwm4, i);
		}
		//delay(d1);
	}
		
  Serial.print("Speed of Front left motor set to: ");
	Serial.println(sfl);

	Serial.print("Speed of Front right motor set to: ");
	Serial.println(sfr);

	Serial.print("Speed of Back left motor set to: ");
	Serial.println(sbl);
	
	Serial.print("Speed of Back right motor set to: ");
	Serial.println(sbr);
	  ssfr = sfr;
    ssfl = sfl;
    ssbr = sbr;
    ssbl = sbl;
	
//Giving clockwise motion to back right wheel
}


void DCMotor::dcreverse(uint8_t sfl,uint8_t sfr,uint8_t sbl,uint8_t sbr) //Giving backward motion 
{
  //stop();
    
    max = max(sfl, sfr);
	max = max(max, sbl);
	max = max(max, sbr);

		

   frontlt_CW();//Giving counter-clockwise motion to front left wheel
 frontrt_CCW(); //Giving clockwise motion to front right wheel
  
  backlt_CW(); //Giving clockwise motion to back left wheel
  backrt_CW();
	for (int i=0; i <= max; i = 2*i+k)
	{
		if (i < sfl)
		{
			analogWrite(pwm1, i);
		}
		
		if (i < sfr)
		{
			analogWrite(pwm2, i);
		}
		
		if (i < sbl)
		{
			analogWrite(pwm3, i);
		}
		
		if (i < sbr)
		{
			analogWrite(pwm4, i);
		}
	//	delay(d1);
	}		
	
	  ssfr = sfr;
    ssfl = sfl;
    ssbr = sbr;
    ssbl = sbl;
	 //Giving counter-clockwise motion to back right wheel
}

void DCMotor::dcleft(uint8_t sfl,uint8_t sfr,uint8_t sbl,uint8_t sbr) // Motion towards left
{
   // stop();
	    max = max(sfl, sfr);
  max = max(max, sbl);
  max = max(max, sbr);


	frontlt_CW(); //Giving counter-clockwise motion to front left wheel
	frontrt_CW(); //Giving counter-clockwise motion to front right wheel
	
	backlt_CCW(); //Giving counter-clockwise motion to back left wheel
	backrt_CW(); //Giving counter-clockwise motion to back right wheel
		
		
	

	for (int i=0; i <= max; i = i+k)
	{
		if (i < sfl)
		{
			analogWrite(pwm1, i);
		}
		
		if (i < sfr)
		{
			analogWrite(pwm2, i);
		}
		
		if (i < sbl)
		{
			analogWrite(pwm3, i);
		}
		
		if (i < sbr)
		{
			analogWrite(pwm4, i);
		}
		//delay(d);
	}
    ssfr = sfr;
    ssfl = sfl;
    ssbr = sbr;
    ssbl = sbl;
	
}

void DCMotor::dcright(uint8_t sfl,uint8_t sfr,uint8_t sbl,uint8_t sbr) // Motion towards right
{	
	//stop();
	frontlt_CCW(); //Giving clockwise motion to front left wheel
	frontrt_CCW(); //Giving clockwise motion to front right wheel
	
	backlt_CW(); //Giving counter-clockwise motion to back left wheel
	backrt_CCW(); //Giving clockwise motion to back right wheel
	


  max = max(sfl, sfr);
	max = max(max, sbl);
	max = max(max, sbr);
	

	
	for (int i=0; i <= max; i = i+k)
	{
		if (i < sfl)
		{
			analogWrite(pwm1, i);
		}
		
		if (i < sfr)
		{
			analogWrite(pwm2, i);
		}
		
		if (i < sbl)
		{
			analogWrite(pwm3, i);
		}
		
		if (i < sbr)
		{
			analogWrite(pwm4, i);
		}
		//delay(d);
	}
    ssfr = sfr;
    ssfl = sfl;
    ssbr = sbr;
    ssbl = sbl;
}

void DCMotor::diagonal_flt(uint8_t sfl ,uint8_t sfr,uint8_t sbl,uint8_t sbr ) // Diagonal motion towards front-left
{
	 // stop();
	sfl=0;
    sbr=0;
	frontrt_CCW(); //Giving counter-clockwise motion to front right wheel
	backlt_CCW(); //Giving counter-clockwise motion to back left wheel
   
    max = max(sfl, sfr);
	max = max(max, sbl);
	max = max(max, sbr);
	


	
	for (int i=0; i <= max; i = i+k)
	{
		if (i < sfl)
		{
			analogWrite(pwm1, i);
		}
		
		if (i < sfr)
		{
			analogWrite(pwm2, i);
		}
		
		if (i < sbl)
		{
			analogWrite(pwm3, i);
		}
		
		if (i < sbr)
		{
			analogWrite(pwm4, i);
		}
	//	delay(d);
	}
    ssfr = sfr;
    ssfl = sfl;
    ssbr = sbr;
    ssbl = sbl;
	
	
}

void DCMotor::diagonal_frt(uint8_t sfl,uint8_t sfr,uint8_t sbl,uint8_t sbr) // Diagonal motion towards front-right
{
    //stop();
	sfr=0;
    sbl=0;
	frontlt_CW(); //Giving clockwise motion to front left wheel
	backrt_CW(); //Giving clockwise motion to back right wheel

    max = max(sfl, sfr);
	max = max(max, sbl);
	max = max(max, sbr);
	
	

	
	for (int i=0; i <= max; i = i+k)
	{
		if (i < sfl)
		{
			analogWrite(pwm1, i);
		}
		
		if (i < sfr)
		{
			analogWrite(pwm2, i);
		}
		
		if (i < sbl)
		{
			analogWrite(pwm3, i);
		}
		
		if (i < sbr)
		{
			analogWrite(pwm4, i);
		}
		//delay(d);
	}
    ssfr = sfr;
    ssfl = sfl;
    ssbr = sbr;
    ssbl = sbl;

}

void DCMotor::diagonal_blt(uint8_t sfl,uint8_t sfr,uint8_t sbl,uint8_t sbr) // Diagonal motion towards back-left
{
  //stop();
	sfr=0;
    sbl=0;
	frontlt_CCW(); //Giving counter-clockwise motion to front left wheel
	backrt_CCW(); //Giving counter-clockwise motion to back right wheel

  
    max = max(sfl, sfr);
	max = max(max, sbl);
	max = max(max, sbr);
	

	
	
	for (int i=0; i <= max; i = i+k)
	{
		if (i < sfl)
		{
			analogWrite(pwm1, i);
		}
		
		if (i < sfr)
		{
			analogWrite(pwm2, i);
		}
		
		if (i < sbl)
		{
			analogWrite(pwm3, i);
		}
		
		if (i < sbr)
		{
			analogWrite(pwm4, i);
		}
		//delay(d);
	}
    ssfr = sfr;
    ssfl = sfl;
    ssbr = sbr;
    ssbl = sbl;
	
}

void DCMotor::diagonal_brt(uint8_t sfl,uint8_t sfr,uint8_t sbl,uint8_t sbr) // Diagonal motion towards back-right
{
  //stop1();
	sfl=0;
    sbr=0;
	frontrt_CW(); //Giving clockwise motion to front right wheel
	backlt_CW(); //Giving clockwise motion to back left wheel

    max = max(sfl, sfr);
	max = max(max, sbl);
	max = max(max, sbr);

	
	
	for (int i=0; i <= max; i = i+k)
	{
		if (i < sfl)
		{
			analogWrite(pwm1, i);
		}
		
		if (i < sfr)
		{
			analogWrite(pwm2, i);
		}
		
		if (i < sbl)
		{
			analogWrite(pwm3, i);
		}
		
		if (i < sbr)
		{
			analogWrite(pwm4, i);
		}
		//delay(d);
	}
    ssfr = sfr;
    ssfl = sfl;
    ssbr = sbr;
    ssbl = sbl;

}

void DCMotor::right_rotation(uint8_t sfl,uint8_t sfr,uint8_t sbl,uint8_t sbr) // Turning to right
{
  

  frontlt_CCW();
	//frontrt_CCW(); //Giving counter-clockwise motion to front right wheel 
	//backlt_CCW(); //Giving clockwise motion to back left wheel 
  backrt_CW();

    max = max(sfl, sfr);
	max = max(max, sbl);
	max = max(max, sbr);


	for (int i=0; i <= max; i = i+k)
	{
		if (i < sfl)
		{
			analogWrite(pwm1, i);
		}
		
		/*if (i < sfr)
		{
			analogWrite(pwm2, i);
		}*/
		
		/*if (i < sbl)
		{
			analogWrite(pwm3, i);
		}*/
		
		if (i < sbr)
		{
			analogWrite(pwm4, i);
		}
		//delay(d);
	}
    ssfr = sfr;
    ssfl = sfl;
    ssbr = sbr;
    ssbl = sbl;
	
 /* analogWrite(pwm1,sfl);
  analogWrite(pwm2,sfr);
  analogWrite(pwm3,sbl);
  analogWrite(pwm4,sbr);*/
}

void DCMotor::left_rotation(uint8_t sfl,uint8_t sfr,uint8_t sbl,uint8_t sbr) // Turning to left
{
    
     
 // frontlt_CCW();
	frontrt_CW(); //Giving clockwise motion to front right wheel
	backlt_CW(); //Giving counter-clockwise motion to back left wheel
 //backrt_CW();

    max = max(sfl, sfr);
	max = max(max, sbl);
	max = max(max, sbr);
	

	
	for (int i=0; i <= max; i = i+k)
	{
	/*	if (i < sfl)
		{
			analogWrite(pwm1, i);
		}*/
		
		if (i < sfr)
		{
			analogWrite(pwm2, i);
		}
		
		if (i < sbl)
		{
			analogWrite(pwm3, i);
		}
		
		/*if (i < sbr)
		{
			analogWrite(pwm4, i);
		}*/
		//delay(d);
	}
    ssfr = sfr;
    ssfl = sfl;
    ssbr = sbr;
    ssbl = sbl;


/*     analogWrite(pwm1,sfl);
  analogWrite(pwm2,sfr);
  analogWrite(pwm3,sbl);
  analogWrite(pwm4,sbr);*/
}




//Code for encoder

int encoder::E1()
{

  int MSB = digitalRead(encoderPin1); //MSB = most significant bit
  int LSB = digitalRead(encoderPin2); //LSB = least significant bit
 
  int encoded = (MSB << 1) |LSB; //converting the 2 pin value to single number
  int sum  = (lastencoded << 2) | encoded; //adding it to the previous encoded value
 
  if(sum == 0b1101 || sum == 0b0100 || sum == 0b0010 || sum == 0b1011) { encoderValue ++; steps_taken++; }
  if (sum == 0b1110 || sum == 0b0111 || sum == 0b0001 || sum == 0b1000) { encoderValue ++;	steps_taken++; }
 
  lastencoded = encoded; //store this value for next time
	//Serial1.println(steps_taken);
}

int encoder::step(int a) //a is angle in degree
{
   Serial.print("direction3");
	float radian_angle;
	radian_angle = a * (3.14/180);
	s = (R * radian_angle);  									// s is distance to be traveled
	steps = s / (31.42/PPR); 											// 0.320=(31.42 cm / ppr) 
	return steps;
}

/*void updateEncoder(){
  int MSB = digitalRead(2); //MSB = most significant bit
  int LSB = digitalRead(3); //LSB = least significant bit

  int encoded = (MSB << 1) |LSB; //converting the 2 pin value to single number
  int sum  = (lastEncoded << 2) | encoded; //adding it to the previous encoded value                   //new Encodder test program

  if(sum == 0b1101 || sum == 0b0100 || sum == 0b0010 || sum == 0b1011) count ++;
  if(sum == 0b1110 || sum == 0b0111 || sum == 0b0001 || sum == 0b1000) count --;

  lastEncoded = encoded; //store this value for next time
}*/


void DCMotor::rotate(unsigned char direction, uint8_t angle) //To rotate with direction and angle
{
  //Serial.print("direction");
	steps_taken = 0;	
	int required_steps = step(angle);  
	
	switch(direction)  //Direction must be in 'L' or 'R'
	{
		case 'L':
					while (steps_taken <  required_steps)
					{
						left_rotation(100,100,100,100);  //calling left rotation function
						E1();                        
					}
					stop();  //calling stop function
		break;
		
		case 'R':
					while (steps_taken <  required_steps)
					{
						right_rotation(10,10,10,10);  //calling right rotation function
						E1();
					}
					stop();  //calling stop function
		break;
		
		default:
			        stop();
		break;
	}
}







void DCMotor::rotate1(unsigned char direction, uint16_t steps) //To rotate with direction and angle
{
  //Serial.print("direction");
  steps_taken = 0;  
    
  
  switch(direction)  //Direction must be in 'L' or 'R'
  {
    case 'L':
    left_rotation(20,20,20,20);
          while (steps_taken < steps)
          {
            //calling left rotation function
            E1();                        
          }
          stop1();  //calling stop function
    break;
    
    case 'R':
          right_rotation(7,7,7,7);
          while (steps_taken <  steps)
          {
              //calling right rotation function
            E1();
          }
          stop1();  //calling stop function
    break;
    
    default:
              stop1();
    break;
  }
}
/*void DCMotor::Front_Rotation(uint16_t direction,uint8_t sfl,uint8_t sfr,uint8_t sbl,uint8_t sbr)
{
 
    switch(direction)  //Direction must be in 'L' or 'R'
    {
      case '0':
            
        sbl=0;
        sbr=0;
        analogWrite(pwm3, sbl);
        analogWrite(pwm4, sbr);
  
        frontrt_CW(); //Giving clockwise motion to front right wheel
        frontlt_CW(); //Giving counter-clockwise motion to back left wheel

        max = max(sfl, sfr);
        max = max(max, sbl);
        max = max(max, sbr);
  

  
  for (int i=0; i <= max; i = i+k)
  {
    if (i < sfl)
    {
      analogWrite(pwm1, i);
    }
    
    if (i < sfr)
    {
      analogWrite(pwm2, i);
    }
    
    if (i < sbl)
    {
      analogWrite(pwm3, i);
    }
    
    if (i < sbr)
    {
      analogWrite(pwm4, i);
    }
    //delay(d);
  }
    ssfr = sfr;
    ssfl = sfl;
    ssbr = sbr;
    ssbl = sbl;
    Serial.print("case 0");
    break;
    
       case '1':
            
        sbl=0;
        sbr=0;
        analogWrite(pwm3, sbl);
        analogWrite(pwm4, sbr);
  
        frontrt_CCW(); //Giving clockwise motion to front right wheel
        frontlt_CCW(); //Giving counter-clockwise motion to back left wheel

        max = max(sfl, sfr);
        max = max(max, sbl);
        max = max(max, sbr);
  

  
  for (int i=0; i <= max; i = i+k)
  {
    if (i < sfl)
    {
      analogWrite(pwm1, i);
    }
    
    if (i < sfr)
    {
      analogWrite(pwm2, i);
    }
    
    if (i < sbl)
    {
      analogWrite(pwm3, i);
    }
    
    if (i < sbr)
    {
      analogWrite(pwm4, i);
    }
    //delay(d);
  }
    ssfr = sfr;
    ssfl = sfl;
    ssbr = sbr;
    ssbl = sbl;
            Serial.print("case 1");
    break;
    
    default:
              stop1();
    break;
  }
  

}*/


void DCMotor::Left_Rot_sensor(uint8_t dir,uint8_t sfl , uint8_t sbl)
{
  

  switch(dir)  //Direction must be  0 or 1
    {
      case 0 :
            
                analogWrite(pwm1, sfl);
                analogWrite(pwm3, sbl);
                                                          
                frontlt_CW(); //Giving clockwise motion to front right wheel
                backlt_CW(); //Giving counter-clockwise motion to back left wheel
                                                        
                max = max(sfl, sbl);
                for (int i=0; i <= max; i = i+k)
                      {
                        if (i < sfl)
                         {
                              analogWrite(pwm1, i);
                         } 
                         if (i < sbl)
                         {
                           analogWrite(pwm3, i);
                         }
                           //delay(d);
                      }
  
    Serial.print("case 0");
    break;
    
       case 1 :
                analogWrite(pwm1, sfl);
                analogWrite(pwm3, sbl);
          
                frontlt_CCW(); //Giving clockwise motion to front right wheel
                backlt_CCW(); //Giving counter-clockwise motion to back left wheel
          
                max = max(sfl, sbl);
                for (int i=0; i <= max; i = i+k)
                    {
                      if (i < sfl)
                      {
                        analogWrite(pwm1, i);
                      } 
                      if (i < sbl)
                      {
                        analogWrite(pwm3, i);
                      }
                      
                      //delay(d);
                      }      Serial.print("case 1");
                      break;
                      
               default:
                                stop1();
                      break;
  }
  
}


/*void DCMotor::left_CWrotation(uint8_t sfl,uint8_t sbl)
{
      analogWrite(pwm1, sfl);
      analogWrite(pwm3, sbl);

      frontlt_CW(); //Giving clockwise motion to front right wheel
      backlt_CW(); //Giving counter-clockwise motion to back left wheel

      max = max(sfl, sbl);
      for (int i=0; i <= max; i = i+k)
  {
    if (i < sfl)
    {
      analogWrite(pwm1, i);
    } 
    if (i < sbl)
    {
      analogWrite(pwm3, i);
    }
    
    //delay(d);
  }
  
      
 }

void DCMotor::left_CCWrotation(uint8_t sfl,uint8_t sbl)
{
      analogWrite(pwm1, sfl);
      analogWrite(pwm3, sbl);

      frontlt_CCW(); //Giving clockwise motion to front right wheel
      backlt_CCW(); //Giving counter-clockwise motion to back left wheel

      max = max(sfl, sbl);
      for (int i=0; i <= max; i = i+k)
  {
    if (i < sfl)
    {
      analogWrite(pwm1, i);
    } 
    if (i < sbl)
    {
      analogWrite(pwm3, i);
    }
    
    //delay(d);
  }
}*/



