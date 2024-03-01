//khai bao các cong giao tiep
/*#ifndef 	_PORT_H_
#define 	_PORT_H_

//Khai bao cac cong giao tiep port
sbit LCD_RS = P2^0 ;
sbit LCD_EN = P2^1 ;
#define LCD P3

sbit ADC0804_CS = P2^2;
sbit ADC0804_RD = P2^3;
sbit ADC0804_WR = P2^4;
sbit ADC0804_INTR = P2^5;

#define ADC0804_DATA P1


#endif
*/


#include "ADC0804.h"
#include "main.h"
#include "port.h"



unsigned char ADC_0804_Read(){
	unsigned char kq;
	
	//chon chip
	ADC0804_CS = 0;
	
	//Tao xung bat dau chuyen doi
	ADC0804_WR = 0;
	ADC0804_WR = 1;
	
	//Doi den khi nao chuyen doi xong;
	while(ADC0804_INTR);
	
	//Doc gia tri sau khi chuyen doi
	
	ADC0804_RD = 0;
	kq = ADC0804_DATA ;
	ADC0804_RD = 1;
	
	return kq;
 
}