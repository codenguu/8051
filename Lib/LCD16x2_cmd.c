//Khai bao cac cong giao tiep port
//sbit LCD_RS = P2^0 ;
//sbit LCD_EN = P2^1 ;
//#define LCD P3
#include "LCD16x2_cmd.h"
#include "main.h"
#include "../lib/Delay.h"
#include "port.h"

//Lenh
void LCD_cmd(unsigned char cmd){

	LCD_RS = 0;//
	LCD = cmd ;
	LCD_EN = 0;
	LCD_EN = 1;
	if(cmd <= 0x02){
		Delay(2);
	}
	else 
		Delay(1);
}
//Lenh xuat ra ky tu
void LCD_Data_char( char c){
	LCD_RS = 1;		//du lieu gui theo dang text
	LCD = c ;
	LCD_EN = 0;
	LCD_EN = 1;

}

//Lenh xuat ra ky tu tai hang row va cot col
void LCD_char_row_col(unsigned char row , unsigned char col, char c){
	unsigned char cmd;
	
	//di chuyen con tro den diem mong muon
	cmd = (row == 1 ? 0x80 : 0x80+0x40) + col -1;
	LCD_cmd(cmd);//da di chuyen con tro
	
	LCD_Data_char(c);
}

// gui va xuat ra chuoi string
void LCD_Data_str(char *c){
	unsigned char i = 0;
	while(c[i]!= 0 ){
		LCD_Data_char(c[i]);
		i++;
	}
}
void LCD_str_row_col(unsigned char row , unsigned char col, char *c){
	unsigned char cmd;
	//di chuyen con tro den vi tri can thiet
	
	cmd = (row == 1 ? 0x80 : (0x80 + 0x40)) + col - 1;
	LCD_cmd(cmd);
	
	LCD_Data_str(c);
	
}

//ham khoi tao led 
void LCD_Init(){//Khoi tao LCD 8 bit
	Delay(20);
	LCD_cmd(0x30);
	Delay(5);
	LCD_cmd(0x30);
	Delay(1);
	LCD_cmd(0x30);
	
	LCD_cmd(0x38); // so dong hien thi(neu dung 4 bit thi 0x28)
	
	LCD_cmd(0x01);//Xoa noi dung hien thi
	LCD_cmd(0x0C);

}



