#include "main.h"
#include "../lib/Delay.h"

sbit LED1 = P2^0;
sbit LED2 = P2^1;


//Ma LEd
unsigned char code arrLED[]={0x3f, 0x6, 0x5b, 0x4f, 0x66, 0x6d,0x7d, 0x07, 0x7f, 0x6f };

void main(){
	
	unsigned char i;
	
	LED1 = LED2 = 0;
	while(1){
		
		for(i = 0; i < 100 ; i++){
			P0 =  ~arrLED[i/10];
			LED1 = 1;
			LED1 = 0;
			
			P0 =  ~arrLED[i%10];
			LED2 = 1;
			LED2 = 0;
		
			
			Delay(200);
			
		}
	
	}

}