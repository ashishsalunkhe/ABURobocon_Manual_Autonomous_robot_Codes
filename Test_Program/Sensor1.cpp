
#include "arduino.h"
#include "Sensor1.h"



linesensor::linesensor(uint8_t a1 , uint8_t a2 , uint8_t a3 , uint8_t a4 , uint8_t a5 , uint8_t a6 , uint8_t a7 , uint8_t a8)
{
	l1=a1; l2=a2; l3=a3; l4=a4; l5=a5; l6=a6; l7=a7; l8=a8; 
	
	pinMode(a1,INPUT);
	pinMode(a2,INPUT);
	pinMode(a3,INPUT);
	pinMode(a4,INPUT);
	pinMode(a5,INPUT);
	pinMode(a6,INPUT);
	pinMode(a7,INPUT);
	pinMode(a8,INPUT);
}

uint8_t linesensor::readsensor()
{
	uint8_t read = 0;
	if(digitalRead(l1) == HIGH)
 {
  read |= (1<<0);
  Serial.println("L1 HIGH");
 }
 else
 {
  read &= ~(1<<0);
 }

if(digitalRead(l2)==HIGH)
 {
  read |= (1<<1);
  Serial.println("L2 HIGH");
 }
 else
 {
  read &= ~(1<<1);
 }

if(digitalRead(l3)==HIGH)
 {
  read |= (1<<2);
  Serial.println("L3 HIGH");
 }
 else
 {
  read &= ~(1<<2);
 }

 if(digitalRead(l4)==HIGH)
 {
  read |= (1<<3);
  Serial.println("L4 HIGH");
 }
 else
 {
  read &= ~(1<<3);
 }

 if(digitalRead(l5)==HIGH)
 {
  read |= (1<<4);
  Serial.println("L5 HIGH");
 }
 else
 {
  read &= ~(1<<4);
 }

 if(digitalRead(l6)==HIGH)
 {
  read |= (1<<5);
  Serial.println("L6 HIGH");
 }
 else
 {
  read &= ~(1<<5);
 }

if(digitalRead(l7)== HIGH)
 {
  read |= (1<<6);
  Serial.println("L7 HIGH");
 }
 else
 {
  read &= ~(1<<6);
 }

 if(digitalRead(l8)== HIGH)
 {
  read |= (1<<7);
  Serial.println("L8 HIGH");
 }
 else
 {
  read &= ~(1<<7);
 }
 
 
	return (read);
}



