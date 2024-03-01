#include "main.h"
#include "../lib/delay.h"




void main(){
	P2 = 0;
	while(1){
		do
		{
			P2++;
			Delay(5);
		}
		while(P2 != 255);
		do{
			P2--;
			Delay(5);
		}
		while(P2 != 0);
	}

}