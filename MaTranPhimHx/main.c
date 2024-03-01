#include "main.h"
#include "../lib/delay.h"
#include "../lib/Keypress.h"



#define LED P2

sbit LED_PIN1 = P3^0;//CHan dieu khien led
sbit LED_PIN2 = P3^1;


unsigned char code arrLED[]={0x3f, 0x6, 0x5b, 0x4f, 0x66, 0x6d,0x7d, 0x07, 0x7f, 0x6f };

unsigned char KeyPress();

void main(){
	unsigned char key, tmp ;
	while(1){
		key = KeyPress();
		if(key != 0){
			tmp = key;
		}
		LED_PIN2 = 0;
		LED = ~arrLED[tmp%10];
		Delay(1);
		LED_PIN2 = 1;
		
		LED_PIN1 = 0;
		LED = ~arrLED[tmp/10];
		Delay(1);
		LED_PIN1 = 1;
		
	}
}

