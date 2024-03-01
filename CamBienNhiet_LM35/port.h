#ifndef 	_PORT_H_
#define 	_PORT_H_

//Khai bao cac cong giao tiep port
sbit LCD_RS = P2^0 ;
sbit LCD_EN = P2^1 ;
#define LCD P0

sbit ADC0804_CS = P2^2;
sbit ADC0804_RD = P2^3;
sbit ADC0804_WR = P2^4;
sbit ADC0804_INTR = P2^5;

#define ADC0804_DATA P3


#endif