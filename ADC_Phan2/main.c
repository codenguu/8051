#include "main.h"
#include "../lib/delay.h"
#include "../Lib/LCD16x2_cmd.h"
#include "port.h"
#include "../LIB/ADC0804.h"



unsigned char ADC_0804_Read();

void main(){
	unsigned char ADC_value;
	unsigned int voltage;
	
	LCD_Init();
	
	LCD_str_row_col(1,1 , "GiaTri:");
	LCD_str_row_col(1,8 , "Voltage:");
	while(1){
		ADC_value = ADC_0804_Read();
		
		
		LCD_char_row_col(2, 1, ADC_value / 100 + 0x30);
		LCD_char_row_col(2, 2, ADC_value/10%10 + 0x30);
		LCD_char_row_col(2, 3, ADC_value%10 + 0x30);
		
		voltage = ADC_value * 19.61f;
		LCD_char_row_col(2, 8, voltage / 1000 + 0x30);
		LCD_char_row_col(2, 9, '.');
		LCD_char_row_col(2, 10, voltage%1000/100 + 0x30);
		LCD_char_row_col(2, 11, voltage%100/10 + 0x30);
		LCD_char_row_col(2, 12, voltage%10 + 0x30);
		Delay(300);
	}


}

