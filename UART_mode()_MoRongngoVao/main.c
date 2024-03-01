#include "main.h"
#include "../lib/delay.h"





void main(){
	unsigned char b;
	P1_0 = 0;
	//Cau hinh UART voi  che do8 bit khong dam bao
	SM0 = 0; 
	SM1 = 0;
	REN = 1;		// San sang nhan du lieu
	
	
	
	
	while(1){
		P3_2 = 0;			//tao xung chot du lieu
		Delay(2);
		P3_2 = 1;
		
		RI = 0;
		while(RI == 0);
		b = SBUF;
		
		if((b & 0x02) == 0){
			P1_0 = 1;
		}
		if((b & 0x01) == 0) {
			P1_0 = 0;
		}

	}

}