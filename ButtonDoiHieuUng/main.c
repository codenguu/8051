#include "main.h"
#include "..\lib\delay.h"

#include <REGX52.H>

sbit BTN = P1^0;
#define LED P2
bit pressedFlag = 0;

unsigned char DelayQuetPhim(){
	unsigned  char i;
	for(i = 0; i< 10;i++){
		Delay(10);
		if(BTN == 0){
			if(pressedFlag == 0){
				pressedFlag = 1;
				return 1;
			}
			else pressedFlag = 1;
		}
	}
	return 0;
}
void main(){
	unsigned char i ;
	while(1){
		LED = 0x00;
		for(i = 0; i < 20;i++){
			if(DelayQuetPhim()) break;
			LED = ~LED;
		}
		LED = 0x55;
		for(i =0 ; i< 20 ;i++){
			if(DelayQuetPhim()) break;
			LED = ~LED ;
		}
		LED = 0x0f;
		for(i = 0; i < 20 ; i++){
			LED = ~LED;
			if(DelayQuetPhim()) break;
		}
	}
}