#include "main.h"
#include "../lib/delay.h"
#include "port.h"
#include "../Lib/ADC0804.h"
#include "../Lib/LCD16x2_cmd.h"



void main(){
	unsigned char Temp;
	LCD_Init();
	LCD_str_row_col(1, 1 ,"Nhiet DO: ");
	LCD_str_row_col(2, 6 ,"Do C");
	while(1){
		Temp = (ADC_0804_Read()+0.5 )* 1.91f;
		
		LCD_char_row_col(2, 1 ,Temp/100 + 0x30);
		LCD_char_row_col(2, 2 ,Temp/10%10 + 0x30);
		LCD_char_row_col(2, 3 ,Temp%10 + 0x30);
		
		Delay(300);
	}

}