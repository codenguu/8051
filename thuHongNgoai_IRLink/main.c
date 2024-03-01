#include "main.h"
#include "../lib/delay.h"




void main(){
	unsigned char i, b;
	
	while(1){
		
		while(P3_2);
		b = 0;
		for(i = 0; i < 8; i++){
			b <<= 1;
			Delay(2);
			if(P3_2) {
				//bit 1;
				b |= 0x01;
			}
			else 
			{
				// bit 0;
				while(P3_2 == 0);
			}
			if(i != 7) while(P3_2);
		}
		P2 = b;
	}

}