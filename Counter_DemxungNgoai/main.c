#include "main.h"
#include "../lib/delay.h"

unsigned char code arrLED[]={0x3f, 0x6, 0x5b, 0x4f, 0x66, 0x6d,0x7d, 0x07, 0x7f, 0x6f };

void Display(unsigned int n){
	

		unsigned char tramnghin,chucnghin,nghin,tram,  chuc, donvi;
		
		chuc = (n/10)%10;
		donvi = n%10;
		tram = (n /100) % 10;
		nghin = (n / 1000) % 10;
		chucnghin = (n / 10000) % 10;
		tramnghin = (n / 100000);
	
		P2_5 = 1;
		P0 = ~arrLED[donvi];
		Delay(1);
		P2_5 = 0;
		
		
		P2_4 = 1;
		P0 = ~arrLED[chuc];
		Delay(1);
		P2_4 = 0;
		
		P2_3 = 1;
		P0 = ~arrLED[tram];
		Delay(1);
		P2_3 = 0;
		
		
		P2_2 = 1;
		P0 = ~arrLED[nghin];
		Delay(1);
		P2_2 = 0;
		
		P2_1 = 1;
		P0 = ~arrLED[chucnghin];
		Delay(1);
		P2_1 = 0;
		
		
		P2_0 = 1;
		P0 = ~arrLED[tramnghin];
		Delay(1);
		P2_0 = 0;


}


void main(){
	unsigned char low , high;
	unsigned int dem;
	TMOD &= 0x0F;		//k dung timer0;
	TMOD |= 0x50; 	// Mode Tiemr1 16 bit;
	
	TR1 = 1;		//Dieu khien timer1 duoc phep dem;

	TL1 = 0x00;
	TH1 = 0x00;
	
	while(1){
		do {
			high = TH1;
			low = TL1;
			}while(high != TH1);
		
			
		
		dem = high;
		dem <<= 8;
		dem |= low;
		
		Display(dem);
	}

}