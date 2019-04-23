
#include "relay.h"


void Relay::reinit()
{
     pinMode(R11,OUTPUT);
	 pinMode(R21,OUTPUT);
	 pinMode(R31,OUTPUT);
	 pinMode(R41,OUTPUT);
	 
	 digitalWrite(R11,LOW);
	 digitalWrite(R21,LOW);
	 digitalWrite(R31,LOW);
	 digitalWrite(R41,LOW);
}


void Relay::relay(uint8_t ch)
{
   switch(ch)
   {
     case 10 :  digitalWrite(R11,HIGH);
			    Serial.println("relay one low");
				break; 
	
	case 11 :  digitalWrite(R11,LOW); 
				Serial.println("relay one high");
				break; 
	
	case 20 :  digitalWrite(R21,HIGH); 
				Serial.println("relay two low");
				break; 
	
	case 21 :  digitalWrite(R21,LOW); 
				Serial.println("relay two high");
				break; 
	
	case 30 :  digitalWrite(R31,HIGH); 
				Serial.println("relay three low");
				break;  
	
	case 31 :digitalWrite(R31,LOW); 
				Serial.println("relay three high");
				break;  
	
	case 40 :digitalWrite(R41,HIGH); 
				Serial.println("relay four low");
				break; 
	
	case 41 :digitalWrite(R41,LOW); 
				Serial.println("relay four high");
				break;  	
				
   }
}

