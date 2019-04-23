#include <Servo.h>
#include "relay.h"

uint8_t R11 = A8;
uint8_t R21 = A9;
uint8_t R31 = A10;
uint8_t R41 = A11;


Relay relay;
Servo myservo;

void setup() {
 Serial.begin(115200);
 myservo.attach(10);

 relay.reinit();
}

void servoclose()
{
  myservo.write(115);
}

void servoopen()
{
  myservo.write(70);
}

void grab()
{
  int a = 0;
  while(a == 0)
  {
    if(digitalRead(8) == LOW || digitalRead(9) == LOW)
    {
      servoclose();
      a = 1;
    }
  }
}

void servorelease()
{
  myservo.write(70);
}

char receivedCharacter;

void loop() {
  
 if (Serial.available() > 0)
 {
  receivedCharacter = Serial.read();
 }

 if (receivedCharacter == 'a')
 {
  Serial.println("GRAB");
    grab();
    
 }

 else if(receivedCharacter == 'b')
 {
    servorelease();
    Serial.println("RELEASE");
 }

else if(receivedCharacter == 'c')
 {
    relay.relay(10);
 }

 else if(receivedCharacter == 'd')
 {
    relay.relay(11);
 }
 
}
