#include "main.h"
#include "../lib/delay.h"
#include "../lib/LCD16x2_cmd.h"
#include "port.h"
#include "../lib/Rtc_Ds1307.h"
#include "../lib/Soft_I2C.h"








void main(){
	
	unsigned char hour ,minute , second, mode, day , date, month, year ;
	
	//khoi tao 
	Soft_I2c_Init();
	Ds1307_Init();
	//khoi tao lcd
	LCD_Init();
	
	while(1){
		Ds1307_Read_Time(&hour, &minute,&second,&mode);
		LCD_char_row_col(1,4,hour/10 + 0x30);
		LCD_Data_char(hour%10 + 0x30);
		LCD_Data_char(':');
		LCD_Data_char(minute/10+0x30);
		LCD_Data_char(minute%10 + 0x30);
		LCD_Data_char(':');
		LCD_Data_char(second/10+0x30);
		LCD_Data_char(second%10 + 0x30);
	
	}
}