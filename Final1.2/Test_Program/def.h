#ifndef _def_H
#define _def_H
#include "DCmotor.h"
#include "Sensor1.h"
//#include "joystick.h"



uint8_t pwm1 = 6;//4  FL
uint8_t pwm2 = 7;//5  FR
uint8_t pwm3 = 4;//6  BL
uint8_t pwm4 = 12;//7 BR

uint8_t dir1 = 10;//8
uint8_t dir2 =11;//9
uint8_t dir3 = 8;//10
uint8_t dir4 = 9;//11
uint16_t PPR = 537;


linesensor LineF(22,24,26,28,30,32,34,36);
linesensor LineB(23,25,27,29,31,33,35,37);
linesensor LineR(39,41,43,45,47,49,51,53);
linesensor LineL(38,40,42,44,46,48,50,52);


DCMotor mymotor;
//Motion Motions;


#endif
