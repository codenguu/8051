#include "main.h"
#include "../lib/delay.h"
#include "../lib/UART_Mode1.h"
#include <stdio.h>
#include <string.h>

sbit ON = P1^0;
sbit OFF = P1^1;


void main(){
	//khoi tao uart
	UART_init();
	
	while(1){
		UART_Write_text("Quang Truong \r\n");
		Delay(1000);
	}

}