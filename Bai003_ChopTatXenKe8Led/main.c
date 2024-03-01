#include "main.h"
#include "..\Lib\Delay.h"

#define LED_PORT P2

void main(){
	LED_PORT = 0x55;
	Delay(500);
	while(1){
		LED_PORT = ~LED_PORT;
		Delay(500);
	}
}