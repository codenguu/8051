//Mo rong ngo ra dung IC 74595 
//Tao file port.h nhu sau:
//sbit SH_CP = P2^0;
//sbit DS = P2^1;
//sbit ST_CP = P2^2;

#include "main.h"
#include "port.h"
#include "../lib/IE74595_OUT.h"



//Lay n byte trong vdk	
void IE74595_OUT(unsigned char *p,unsigned char n){
	unsigned char i , j , b;
	for(i = 0; i < n ; i++){
		
		b = *(p + n -i -1);//Lay byte  cuoi cung xep tu dau vao cuoi ic
		for(j =0; j  < 8 ; j++){
			
			DS = b & (0x80 >> j);
			
			//tao xung dich du lieu
			SH_CP = 0;
			SH_CP = 1;
			
		}
	}
		//tao xung xuat du lieu
		ST_CP = 0; 
		ST_CP = 1; 
}