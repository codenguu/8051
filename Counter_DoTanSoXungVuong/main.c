#include "main.h"
#include "../lib/delay.h"
#include "../lib/LCD16x2_cmd.h"
#include "port.h"


void main(){
	unsigned int  t,f ;  //t : th?i gian nua chu ky: T/2 (s); f = 1/T (hz)
	LCD_Init();
	LCD_str_row_col(1 , 1 , "T = ");
	LCD_str_row_col(2 , 1 , "f = ");

	TMOD &= 0xF0;
	TMOD |= 0x09;		//GATE = 1; M0 = 1;
	
	
	
	while(1){
		
		TH0 = 0;
		TL0 = 0;
		
		while(INT0); 		//bo qua muc 1 dau tien
		while(!INT0);		//bo qua muc 0 
		//khi INT0  len muc 1 bo dinh thoi duoc mo cong va  nhan xung clock 1mhz
		TR0 = 1; 	//cho phep dem;
		
		while(INT0);  // dem den khi nào INT0 = 0; thì TR0 = 0 (dung dem);
		
		TR0 = 0;
		
		t = TH0;
		t <<= 8;
		t |= TL0 ;
		
		t*=2;
		LCD_char_row_col(1 , 5 ,t/10000 +0x30 );
		LCD_Data_char(t%10000/1000 + 0x30);
		LCD_Data_char(t%1000/100 + 0x30);
		LCD_Data_char(t%100/10 + 0x30);
		LCD_Data_char(t%10 + 0x30);
		
		f = 1000000/t;
		LCD_char_row_col(2 , 5 ,f/10000 + 0x30 );
		LCD_Data_char(f%10000/1000 + 0x30);
		LCD_Data_char(f%1000/100 + 0x30);
		LCD_Data_char(f%100/10 + 0x30);
		LCD_Data_char(f%10 + 0x30);
		
	}

}