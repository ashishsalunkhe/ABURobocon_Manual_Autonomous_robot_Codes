
#include "relay.h"


void Relay::reinit()
{
   pinMode(R11,OUTPUT);
	 pinMode(R21,OUTPUT);
	 pinMode(R31,OUTPUT);
	 pinMode(R41,OUTPUT);
	 pinMode(R51,OUTPUT);

	 
	 digitalWrite(R11,HIGH);
	 digitalWrite(R21,HIGH);
	 digitalWrite(R31,HIGH);
	 digitalWrite(R41,HIGH);
	 digitalWrite(R51,HIGH);

}


void Relay::relay(uint8_t ch)
{
   switch(ch)
   {
    case 10 : digitalWrite(R11,HIGH);  break; 
	  case 11 : digitalWrite(R11,LOW);   break;
	  case 20 : digitalWrite(R21,HIGH);  break; 
  	case 21 : digitalWrite(R21,LOW);   break; 
  	case 30 : digitalWrite(R31,HIGH);  break;  	
  	case 31 : digitalWrite(R31,LOW);    break; 	
  	case 40 : digitalWrite(R41,HIGH);   break; 
  	case 41 : digitalWrite(R41,LOW);    break;    	
  	case 50 : digitalWrite(R51,HIGH);   break; 
  	case 51 : digitalWrite(R51,LOW);    break;  		
   }
}

