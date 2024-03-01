#include "main.h"
#include "../lib/Delay.c"

sbit BTN = P1^0;
sbit LAMP = P2^0;
void main(){
	LAMP = 0;
	while(1){
		if(BTN == 0){
			Delay(20);
			if(BTN == 0){
				LAMP = !LAMP;
				while(BTN==0);
			}
		}
	}
}