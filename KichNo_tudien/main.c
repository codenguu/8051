#include "main.h"
#include "../lib/delay.h"

sbit BTN = P1^0;
sbit RELAY = P0^0;

#define LED P2 

unsigned char code arrLED[]={0x3f, 0x6, 0x5b, 0x4f, 0x66, 0x6d,0x7d, 0x07, 0x7f, 0x6f };

void main(){
	unsigned char i ;
	while (1){
		if(BTN == 0){
			for(i = 9;i >= 0; i--){
				LED = arrLED[i];
				Delay(250);
				if(i == 0) break;
			}
			RELAY = 0;
			for(i = 0; i< 10; i++){
				LED = arrLED[i];
				Delay(250);
			}
			RELAY = 1;
			break;
		}
	
	}
}
