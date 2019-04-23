#ifndef __linesensor_h
#define __linesensor_h
#include "Arduino.h"


class linesensor
{
  public:
  uint8_t l1; 
  uint8_t l2;
  uint8_t l3;
  uint8_t l4;
  uint8_t l5;
  uint8_t l6;
  uint8_t l7;
  uint8_t l8;
  linesensor(uint8_t a1 , uint8_t a2 , uint8_t a3 , uint8_t a4 , uint8_t a5 , uint8_t a6 , uint8_t a7 , uint8_t a8);
  uint8_t readsensor();
};


#endif
