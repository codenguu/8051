#include "main.h"
#include "../lib/delay.h"
#include <stdio.h>


char UART_Ready(){
	return RI;
}

char UART_Read(){
	while(RI == 0); 			// Doi den khi nao RI = 1 thi clear no ve 0;
	RI = 0; 							//clear ve 0;
	return SBUF;
}

void UART_Write(char c){
	while(TI == 0);
	TI = 0;
	SBUF = c;
}


void UART_Write_text(char *str){
	unsigned char i = 0;
	while(str[i] != 0){
		UART_Write(str[i]);
		i++;
	}
}

void main(){
	unsigned char c , i ;
	
	
	
	//Khoi tao uart mode1
	SCON &= 0x0F; //Giu lai cac bit ban dau cho 4 bit thap
	SCON |= 0x53; // SM0 = 0; SM1 = 1; 
	//REN = 1 Cho phep nhan ki tu; 
	//TI = 1 co bao hieu truyen xong 1 ky tu va san sang truyen tiep theo
	//RI = 1 san sang nhan du lieu tiep theo
	
	//Thiet lap toc do Baud dung Timer1 tu dong nap 8 bit (kieu2)
	TMOD &= 0x0F;//Giu lai cac 4 bit thap cua timer0; 0b0000 xxxx;
	TMOD |= 0x20; // M1 = 1 ; M0 = 0;
	
	
	TR1 = 1 ; 		//Dieu khien Timer duoc phep dem xung
	
	//Baud rate = 9600 , thach anh 11059200ul
	TH1 = 0xFD; 
	
	
	
	
	P1_0 = 0;
	
	while(1){
		//doc du lieu nhan vao tu may tinh
		c = UART_Read();
		
		//chon
		switch (c){
			
			case 0x00:
				P1_0 = !P1_0;
				break;
			case 0x01:
				P1_1 = !P1_1;
				break;
			case 0x02:
				P1_2 = !P1_2;
				break;
			case 0x03:
				P1_3 = !P1_3;
				break;
			case 0x04:
				P1_4 = !P1_4;
				break;
			case 0x05:
				P1_5 = !P1_5;
				break;
			case 0x06:
				P1_6 = !P1_6;
				break;
			case 0x07:
				P1_7 = !P1_7;
				break;
		}
	}

}