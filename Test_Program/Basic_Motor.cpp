#include "Arduino.h"
#include "Basic_Motor.h"

extern uint8_t dir1;
extern uint8_t dir2;
extern uint8_t dir3;
extern uint8_t dir4;


void Basic_Motor::frontlt_CW() 	{ digitalWrite(dir1,HIGH)  ;	}
void Basic_Motor::frontlt_CCW()	{ digitalWrite(dir1,LOW) ;	}

void Basic_Motor::frontrt_CW() 	{ digitalWrite(dir2,HIGH)  ;	}
void Basic_Motor::frontrt_CCW()	{ digitalWrite(dir2,LOW) ;	}

void Basic_Motor::backlt_CW() 	{ digitalWrite(dir3,LOW)  ;	}
void Basic_Motor::backlt_CCW()	{ digitalWrite(dir3,HIGH) ;	}

void Basic_Motor::backrt_CW() 	{ digitalWrite(dir4,LOW)  ;	}
void Basic_Motor::backrt_CCW()	{ digitalWrite(dir4,HIGH) ;	}



