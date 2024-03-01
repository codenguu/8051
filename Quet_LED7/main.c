#include "main.h"
#include "../lib/delay.h"

sbit LED1 = P0^0;
sbit LED2 = P0^1;
unsigned char code arrLED[]={~0x3f, ~0x6, ~0x5b, ~0x4f, ~0x66, ~0x6d,~0x7d, ~0x07, ~0x7f, ~0x6f };

void main(){
	unsigned int  dem = 0;
	unsigned char chuc , dv  ;
	while (1){
		while(1){
			unsigned int i;
			dv = dem % 10;
			chuc = dem /10 ;
			
			for( i = 0 ; i <  480 ; i++){
			
				LED1 = 0;
				P2 = arrLED[chuc];
				Delay(1);
				LED1 = 1;
				
				LED2 = 0;
				P2 = arrLED[dv];
				Delay(1);
				LED2 = 1;
			}
		dem++;
		dem %=100;
		}
	}
}