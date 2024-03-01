#ifndef _PORT_H_
#define _PORT_H_


//Khai bao cac cong giao tiep port
sbit LCD_RS = P2^0 ;
sbit LCD_EN = P2^1 ;

#define LCD P3



// Khai bao ket noi I2C
sbit SOFT_I2C_SCL	= P1^0;
sbit SOFT_I2C_SDA	= P1^1; 

// Ket noi nut nhan 
sbit BTN = P3^0;


#endif