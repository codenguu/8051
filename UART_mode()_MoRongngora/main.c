#include "main.h"
#include "../lib/delay.h"

void UART_mode0(unsigned char b){
	
		SBUF = b; //Dem du lieu
	
		while(TI == 0){
			//loop den khi nao TI != 0
		}
		TI = 0;
		
		P3_2 = 0;
		P3_2 = 1;
	
}


void main(){
	unsigned char i , j , b;
	SM0 = SM1 = 0; //UART mode = 0;
	

	while(1){
		for(i = 0; i <5 ; i++){
			UART_mode0(0x00);
			Delay(200);
			UART_mode0(0xff);
			Delay(200);
		}
		for(i = 0; i <5 ; i++){
			for(j = 0; j < 8 ; j++){
				b = 0x00;
				b |= (0x80 >> j);
				UART_mode0(b);
				Delay(200);
			}
		}
		for(i = 0; i <5 ; i++){
			UART_mode0(0x55);
			Delay(200);
			UART_mode0(0xAA);
			Delay(200);
		}
	}

}