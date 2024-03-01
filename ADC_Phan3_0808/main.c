#include "main.h"
#include "../lib/delay.h"
#include "port.h"
#include "../Lib/LCD16x2_cmd.h"
#include "../Lib/ADC0808.h"

void main(){
	unsigned char ADC_value;
	unsigned int voltage;
	ADC_Init();
	LCD_Init();
	
	LCD_str_row_col(1,1 , "GiaTri:");
	LCD_str_row_col(1,8 , "Voltage:");
	while(1){
		ADC_value = ADC0808_Read(0);
		
		
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
