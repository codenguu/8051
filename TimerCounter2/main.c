#include "main.h"
#include "../lib/delay.h"


void DelayTimer2_1ms(unsigned int t){
	unsigned char i ;
		//Khoi tao timer o che do tu nap lai
	T2CON = 0x00;
	T2MOD = 0x00;
	
	//khoi tao gia tri ban dau cho bit luu;
	RCAP2H = 0x3C;
	RCAP2L = 0xB0;
	
	TH2 = 0x3C ;
	TL2 = 0xB0 ;
	
	TR2 = 1;
	for(i = 0 ; i < (1/50)*t ; i ++){
		while(TF2 == 0);
		TF2 = 0;
	}
	TR2 = 0;
}


void main(){
	
	while(1){
		P1 = ~P1;
		DelayTimer2_1ms(200);
	}

}