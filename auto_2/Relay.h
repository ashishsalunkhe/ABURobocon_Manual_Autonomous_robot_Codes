
#ifndef _relay_h
#define _relay_h
#include "arduino.h"

extern uint8_t R11;
extern uint8_t R21;
extern uint8_t R31;
extern uint8_t R41;


class Relay{
	public:
	void relay(uint8_t ch);
	void reinit();
};

#endif
