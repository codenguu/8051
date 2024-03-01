//Khai bao cac cong giao tiep port
//sbit LCD_RS = P2^0 ;
//sbit LCD_EN = P2^1 ;
//#define LCD P3
//Khai bao cac cong giao tiep port


#ifndef 	_LCD16x2_H_
#define 	_LCD16x2_H_

/*-------------------------------------*-
	LCD commands
-*-------------------------------------*/ 
#define _LCD_CLEAR				1   	//Xoa man hinh hien tai	
#define _LCD_RETURN_HOME		2		//tra con tro ve dau tien
#define _LCD_ENTRY_MODE			6		//Tang con tro
#define _LCD_TURN_OFF			8			
#define _LCD_TURN_ON			12
#define _LCD_CURSOR_OFF			12 	  
#define _LCD_UNDERLINE_ON		14
#define _LCD_BLINK_CURSOR_ON	15
#define _LCD_MOVE_CURSOR_LEFT	16
#define _LCD_MOVE_CURSOR_RIGHT	17
#define _LCD_SHIFT_LEFT			24
#define _LCD_SHIFT_RIGHT		28
#define _LCD_4BIT_1LINE_5x7FONT	0x20
#define _LCD_4BIT_2LINE_5x7FONT	0x28
#define _LCD_8BIT_1LINE_5x7FONT	0x30
#define _LCD_8BIT_2LINE_5x7FONT	0x38
#define _LCD_FIRST_ROW			128
#define _LCD_SECOND_ROW			192
/*-------------------------------------*-
	End of LCD commands
-*-------------------------------------*/

void LCD_cmd(unsigned char cmd);
void LCD_Data_char( char c);
void LCD_char_row_col(unsigned char row , unsigned char col, char c);
void LCD_Data_str(char *c);
void LCD_str_row_col(unsigned char row , unsigned char col, char *c);

void LCD_Init();

#endif