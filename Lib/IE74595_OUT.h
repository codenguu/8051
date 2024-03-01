//Mo rong ngo ra dung IC 74595 
//Tao file port.h nhu sau:
//sbit SH_CP = P2^0;
//sbit DS = P2^1;
//sbit ST_CP = P2^2;

#ifndef 	_MAIN_H_
#define 	_MAIN_H_

void IE74595_OUT(unsigned char *p,unsigned char n);

#endif