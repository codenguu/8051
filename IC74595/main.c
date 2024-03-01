#include "main.h"
#include "../lib/delay.h"
#include "port.h"
#include "../lib/IE74595_OUT.h"


void IE74595_OUT(unsigned char *p,unsigned char n);
unsigned char code arrLED[]={~0x3f, ~0x6, ~0x5b, ~0x4f, ~0x66, ~0x6d,~0x7d, ~0x07, ~0x7f, ~0x6f };

void main() {

	unsigned char i ;
	unsigned char buffer[2];
	while(1){
		for(i = 0; i < 99 ; i++){
			buffer[0] = arrLED[i/10];
			buffer[1] = arrLED[i%10];
			
			IE74595_OUT(buffer,2);
			Delay(100);
		}
	}
}