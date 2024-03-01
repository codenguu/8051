#include "main.h"
#include "../lib/delay.h"
#include "stdio.h"
void Guibit(bit b){
	if(b){
		TR2 = 1; 
		Delay(1);
		TR2 = 0;
		P1_0 = 1;
		Delay(3);
	}
	else 
	{
		TR2 = 1; 
		Delay(3);
		TR2 = 0;
		P1_0 = 1;
		Delay(1);
	}

}


void GuiByte(unsigned char b)
{
	unsigned char i; 
	for(i = 0; i < 8; i++)
	{
		Guibit(b & 0x80); 
		//dich bit sang trai
		b <<= 1;
	}
	
}

void main(){
	//cogfigure cho timer2 phat xung clock tai chan T2;
	T2CON = 0x00;		//bit C/T2 = 0;
	T2MOD = 0x02;		//bit T2OE = 1;
	
	RCAP2H = 0xFF;
	RCAP2L = 0xB1;
	
	TH2 = 0xFF;
	TL2 = 0xB1; 
	
	TR2 = 1;
	//cau hinh uart che do mode 1
	SCON = 0x50;
	TMOD = 0x20; 		//timer 1 mode 2;
	
	TH1 = 0xE6; 		//baud rate 1200, tan nso thach anh 12mhz
	TR1 = 1; 				//timer 1 bat dau chay
	
	TI = 1;					//bat dau truyen du lieu

	printf("Dep trai vai l");
	
	while(1){
		
	}

}