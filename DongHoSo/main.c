#include "main.h"
#include "../lib/delay.h"

sbit GIO_CHUC = P3^0;
sbit GIO_DV = P3^1;
sbit PHUT_CHUC = P3^2;
sbit PHUT_DV = P3^3;
sbit GIAY_CHUC = P3^4;
sbit GIAY_DV = P3^5;


unsigned char code arrLED[]={0x3f, 0x6, 0x5b, 0x4f, 0x66, 0x6d,0x7d, 0x07, 0x7f, 0x6f };


void main(){
	unsigned char gio, giay, phut ;
	unsigned char chuc , dv;
	
	gio = 0;
	giay = 0;
	phut = 0;
	while(1){
		unsigned int i;
	
		for( i = 0; i < 30 ; i ++)
		{
			//Cai gio truoc
			dv = gio % 10;
			chuc = gio/10;
			GIO_CHUC = 0;
			P2 = ~arrLED[chuc];
			Delay(1);
			GIO_CHUC = 1;
			
			GIO_DV = 0;
			P2 = ~arrLED[dv];
			Delay(1);
			GIO_DV = 1;
			
			//Cai phut
			dv = phut%10;
			chuc = phut/ 10; 
			PHUT_CHUC = 0;
			P2 = ~arrLED[chuc];
			Delay(1);
			PHUT_CHUC = 1;
			
			PHUT_DV = 0;
			P2 = ~arrLED[dv];
			Delay(1);
			PHUT_DV = 1;
			
			//cai giay
			dv = giay%10;
			chuc = giay/ 10; 
			GIAY_CHUC = 0;
			P2 = ~arrLED[chuc];
			Delay(1);
			GIAY_CHUC = 1;
			
			GIAY_DV = 0;
			P2 = ~arrLED[dv];
			Delay(1);
			GIAY_DV = 1;
		}
		giay++;
		if(giay == 60){
			giay = 0;//reset giay;
			phut++;
			if(phut == 60){
				phut = 0;//reset phut
				gio++;
				if(gio == 24) break;
			}
		}
	}
}