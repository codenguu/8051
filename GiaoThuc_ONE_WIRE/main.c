#include "main.h"
#include "../lib/delay.h"
#include "../lib/delay_us.h"

#define DS18B20_SKIP_ROM						0xCC
#define DS18B20_CONVERT_T 					0x44
#define DS18B20_READ_SCRATCH_PAD 		0xBE


sbit DS18B20_PIN = P1^0;

unsigned char code arrLED[]={0x3f, 0x6, 0x5b, 0x4f, 0x66, 0x6d,0x7d, 0x07, 0x7f, 0x6f };

unsigned char DS18B20_Reset();
void DS18B20_Write0();
void DS18B20_Write1();
void DS18B20_Write_bit(unsigned char b);
unsigned char DS18B20_Read_bit();
void DS18B20_Write_byte(unsigned char b);
unsigned char DS18B20_Read_byte();

 
void main(){
	unsigned int temp;
	unsigned char int_part, decimal_part ;
	unsigned char chuc , donvi;
	
	TMOD |= 0x10;
	while(1){
		while(DS18B20_Reset());
		DS18B20_Write_byte(DS18B20_SKIP_ROM);
		DS18B20_Write_byte(DS18B20_CONVERT_T);
		
		
		Delay(750);
		
		while(DS18B20_Reset());
		DS18B20_Write_byte(DS18B20_SKIP_ROM);
		DS18B20_Write_byte(DS18B20_READ_SCRATCH_PAD);
		
		temp = DS18B20_Read_byte();
		temp = (DS18B20_Read_byte() << 8 ) | temp ;
	
		int_part  = temp >> 4;
		chuc = int_part /10;
		donvi = int_part % 10;
		
		decimal_part = temp & 0x000F;
		decimal_part = decimal_part * 10/16;
		
		P0 = arrLED[chuc];
		P2 = arrLED[donvi];
		P3 = arrLED[decimal_part];
	}

}

unsigned char DS18B20_Reset()
{
	unsigned char result;

	DS18B20_PIN = 0;
	Delay_us(480);
	
	DS18B20_PIN = 1;
	Delay_us(70);
	
	result = DS18B20_PIN;
	Delay_us(410);
	
	return result;
	
}

void DS18B20_Write0(){
	DS18B20_PIN = 0;
	Delay_us(60);
	DS18B20_PIN = 1;
	Delay_us(10);

}

void DS18B20_Write1(){
	DS18B20_PIN = 0;
	Delay_us(6);
	
	DS18B20_PIN = 1;
	Delay_us(64);

}


void DS18B20_Write_bit(unsigned char b){
	if(b == 1){
		DS18B20_Write1();
	}
	else 
	{
		DS18B20_Write0();
	}
}

unsigned char DS18B20_Read_bit()
{ 
	unsigned char result;
	DS18B20_PIN = 0;
	Delay_us(6);
	
	DS18B20_PIN = 1;
	Delay_us(9);
	
	result = DS18B20_PIN;
	Delay_us(55);
	
	return result;
}

void DS18B20_Write_byte(unsigned char b){
	unsigned char i = 8;
	
	while(i--){
		DS18B20_Write_bit(b & 0x01);
		b >>= 1;
	}
}

unsigned char DS18B20_Read_byte()
{
	unsigned char i = 8 , result = 0;
	
	while(i--){
		result >>= 1;
		result = (DS18B20_Read_bit() << 7); //GUI BIT CAO TRUOC NEN PHAI NHAN BIT CAO TRUOC
		
		//0000 0001 << 7 = 1000 0000;
	}
	return result;
}
