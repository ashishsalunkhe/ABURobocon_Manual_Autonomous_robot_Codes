#ifndef _Basic_Motor_H
#define	_Basic_Motor_H
#include "Arduino.h"

class Basic_Motor{
public:
			void frontlt_CW(); 	
			void frontlt_CCW();	

			void frontrt_CW(); 	
			void frontrt_CCW();	

			void backlt_CW(); 	
			void backlt_CCW();	

			void backrt_CW();	
			void backrt_CCW();	
};
#endif