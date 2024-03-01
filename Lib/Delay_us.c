#include "main.h"
#include "../lib/Delay_us.h"

void Delay_us(unsigned int us){
	//Timer1 mode 1
	TMOD &= 0x0F;
	TMOD |= 0x10;
	
	TH1 = (65536 - us) >> 8;
	TL1 = (65536 - us) & 0x00FF;
	
	TR1 = 1;
	
	while(TF1 == 0);
	
	TR1 = 0;
	TF1 = 0;

}