#include "Relay.h"

uint8_t R11 = A8;   //Retraction
uint8_t R21 = A9;   //Expansion
uint8_t R31 = A10;  //led Panel
uint8_t R41 = A11;
uint8_t R51 = A12;

uint8_t reed1 = 23;
uint8_t reed2 = 25;
uint8_t reed3 = 27;
 

Relay relay;
char receivedCharacter;

void setup() {
Serial.begin(115200);                             //Serial Communication for rasberry pi
Serial1.begin(115200);   // Serial Communication for Main Arduino
relay.reinit();
}

void loop() {
while 
}

