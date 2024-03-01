#include "main.h"
#include "../lib/Delay.h"

sbit GREEN =  P0^0; 
sbit YELLOW =  P0^1; 
sbit RED =  P0^2; 

unsigned char code arrLED[]={0x3f, 0x6, 0x5b, 0x4f, 0x66, 0x6d,0x7d, 0x07, 0x7f, 0x6f };

void DEN_GIAO_THONG1(){
		unsigned char i;
		unsigned char j;
		YELLOW = 1;
		
		P2 = arrLED[3];//So 30 truoc
		P3 = arrLED[0];
		Delay(300);
		
		for(i = 2; i >= 0; i--){
			for(j = 9 ; j >=0 ; j--){
				if(j <=4 && i == 0 && GREEN == 0){
					YELLOW = 0;
				}
				P3 = arrLED[j];
				P2 = arrLED[i];
				
				Delay(300);
				
				if(j == 0)  break;
			}
			if(i == 0){
				GREEN =!GREEN;
				RED = !RED;
				break;
			}
		}
}
void DEN_GIAO_THONG2(){
	unsigned char i;
		P2 = arrLED[3];
		P3 = arrLED[0];
	for(i = 30 ; i >= 0; i--){
		if( i <= 3 && GREEN == 0) YELLOW = 0;
		else YELLOW = 1;
		P2 = arrLED[i/10];
		P3 = arrLED[i%10];
		Delay(300);
		if(i == 0) {
			RED = !RED;
			GREEN = !GREEN;
			break;
		}
	}
	
}
void main(){
	//trang thai ban dau
		GREEN = 0;
		YELLOW = 1;
		RED = 1;
	while(1)
	{
		DEN_GIAO_THONG2();
	}
}