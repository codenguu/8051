#include "main.h"
#include "../Lib/Delay.h"
#include "port.h"


void main(){
	unsigned char i;
	
	EX0 = 1; // cho phep ngat ngoai int0
	
	EA = 1; 	//cho phep ngat toan cuc
	
	IT0 = 0;
	
	while(1){
			
			for(i = 0; i < 8 ; i ++){
				LED8 |= (1 << i);
				Delay(200);
			}
			for(i = 0; i < 10; i++){
				LED8 = 0xaa;
				Delay(200);
				LED8 = 0x55;
				Delay(200);
			}
			for(i = 0; i < 9 ; i++){
				LED8 = (0x07 << i);
				Delay(200);
			
			}
	}
}

void EX0_ISR (void) interrupt 0
{
	P1_0 = 0;
	P0_0 = 0;
	Delay(5000);
	P1_0 = 1;
	P0_0 = 1;
}
