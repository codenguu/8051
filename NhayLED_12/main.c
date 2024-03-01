#include "main.h"
#include "..\Lib\Delay.h"

#define LED_PORT P2
void BTatdan()
{
	unsigned char i;
	LED_PORT = 0x00;
	for(i = 0 ; i<8 ; i++)
	{
		LED_PORT |= (0x80 >> i);
		Delay(100);
	}
	for(i = 0; i < 8 ; i++){
		LED_PORT &= ~(0x80 >> i);
		Delay(100);
}
}
void BTatdan1()
{
	unsigned char i;
	LED_PORT = 0x00;
	for (i = 0 ; i < 8 ; i++ ){
		LED_PORT |= (1 << i);
		Delay(100);
	}
	for (i = 0 ; i < 8 ; i++ ){
		LED_PORT &= ~(1 << i);
		Delay(100);
	}
}
void nhayled(){
	unsigned char i;
		for(i = 0; i < 10 ; i++){
			LED_PORT = 0xaa;
			Delay(100);
			LED_PORT = ~LED_PORT;
			Delay(100);
		}
}
void conran(){
	unsigned char i;
	for (i = 0; i < 8 ; i++){
		LED_PORT = 0x00 ; 
		LED_PORT |= (0x5 << i);
		if(i == 6) {
				P2_0 = !P2_0;
			}
			if(i == 7) {
				P2_1 = !P2_1;
			}
		Delay(100);
	}
}


void main(){
		BTatdan();
		BTatdan1();
		nhayled();
		conran();
}

