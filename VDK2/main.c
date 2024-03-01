#include "main.h"
#include "../lib/delay.h"
#include "../lib/UART_Mode1.h"
#include <string.h>




void main(){

	UART_init();
	
	
	while(1){
		if(UART_Ready() != 0){
			UART_Read();
			break;
		}
	}

}