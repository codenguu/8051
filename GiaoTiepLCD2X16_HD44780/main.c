#include "main.h"
#include "../lib/delay.h"
#include <string.h>
#include "../lib/LCD16x2_cmd.h"
#include "port.h"



void main(){
	char str[]="Nhin con cac" ;
	LCD_Init();//Khoi tao LCD

	LCD_str_row_col(1 , (16 - strlen(str)) /2  + 1, str);
	while(1){
		unsigned char i;
		for(i = 0; i <16 ; i++){
			Delay(300);
			LCD_cmd(0x18);
		}
		LCD_cmd(0x02);
	}
}