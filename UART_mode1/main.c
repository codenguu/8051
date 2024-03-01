#include "main.h"
#include "../lib/Delay.h"
#include "../lib/UART_Mode1.h"




void main(){
	char c;
	// khoi tao UART
	UART_init();
	
	while(1){
		UART_Write_text("Nhap ky tu : "); 
		while(UART_Ready() == 0);		//duoc set neu nhu bo thu da nhan su lieu, neu khong thi loop den khi nao nhan du lieu
		
		c = UART_Read();
		c -= 32;
		UART_Write_text("->");
		UART_Write(c);

		UART_Write_text("\r\n");
		
	}

}