#include "main.h"
#include "../lib/delay.h"

unsigned char count = 5 ;



void main(){
	
	unsigned char i ;
	
	TMOD &= 0xF0; 
	TMOD |= 0x01; //Mode 1;
	
	TH0 = 0x3C;
	TL0 = 0xB0 ;
	
	ET0 = 1; 		//cho phep ngat timer0
	
	EA = 1 ; 		//Cho phep ngat toan cuc
	
	TR0  = 1 ; 		//cho phep timer0  dem ;
	//Dem den khi nao ngat timer0 duoc kich hoat
	//khi ham ngat thuc hien xong se quay lai tiep tuc thuc hien ham main
	
	while(1){
		P1 = 0x00;
		for(i = 0; i < 9 ; i++){
			P1 |= (1 << i );
			Delay(200);
		}
	}

}

void TimeOverflow(void) interrupt 1
	{ 
	
	TH0 = 0x3C;
	TL0 = 0xB0 ;
	//Dem den khi chan; 
	count--;
	
	if(count == 0){
		
		//reset count = 5;
		count = 5;
		
		//thuc hien chuong trinh
		P2_0 = !P2_0;
	}

}
