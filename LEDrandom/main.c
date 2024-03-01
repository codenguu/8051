#include "main.h"



sbit BTN = P1^0;

#define LED7 P2

unsigned char code arrLED[]={0x3f, 0x6, 0x5b, 0x4f, 0x66, 0x6d,0x7d, 0x07, 0x7f, 0x6f };

void main(){
	unsigned char dem = 0;
	while(1){
		while(BTN == 0){
			dem++;
		}
		LED7 = arrLED[dem%10];
	}
}