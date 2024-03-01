#include "main.h"
#include "port.h" 
#include "../Lib/Delay.h"

void Soft_SPI_Init();
void Soft_SPI_Write(unsigned char byte);
unsigned char Soft_SPI_Read();

void EEPROM_25LCxxx_Write(unsigned int add, unsigned char byte );
unsigned char EEPROM_25LCxxx_Read(unsigned int add);
unsigned char EEPROM_25LCxxx_WIP();

void main(){
	unsigned char i;
	//KHOI TAO CHO GIAO TIEP SPI
	Soft_SPI_Init();
	for(i = 0; i < 100; i++){
		EEPROM_25LCxxx_Write(i,i);
	}
	

	while(1){
		for(i = 0 ; i < 100; i++){
			P1 = EEPROM_25LCxxx_Read(0);
			Delay(500);
		}
	}

}

void EEPROM_25LCxxx_Write(unsigned int add, unsigned char byte )
{
	SPI_CS = 0;
	Soft_SPI_Write(0x06);		//gui lenh WREN
	SPI_CS = 1;
	
	SPI_CS = 0;
	Soft_SPI_Write(0x02);
	Soft_SPI_Write(add >> 8);		// gui 1 byte cao cua dia chi
	Soft_SPI_Write(add & 0x00ff);		//gui byte thap cua dia chi di
	Soft_SPI_Write(byte);
	SPI_CS = 1;
	
	
	while(EEPROM_25LCxxx_WIP());
}
//Giao tiep spi mode 1
//Ham khoi tao SPI
void Soft_SPI_Init(){
	SPI_CS = 1;
	SPI_MISO = 1;
	SPI_SCLK = 0;
}

//HAM GUI 1 BYTE SANG CHO SLAVE
void Soft_SPI_Write(unsigned char byte){
	unsigned char i;
	for(i = 0; i < 8 ; i++){//lay bit cao truoc
		if(byte & 0x80)
			SPI_MOSI = 1;
		else
			SPI_MOSI = 0;
		
		SPI_SCLK = 1;
		SPI_SCLK = 0;
		byte <<= 1;
	}
}



//Ham nhan 1 byte tu Slave
unsigned char Soft_SPI_Read(){
	unsigned char i , byte;
	for(i = 0; i < 8; i++){
		byte <<= 1; //dua bit thap nhat ve 0;
		SPI_SCLK = 1;
		if(SPI_MISO)
			byte |= 0x01;
		SPI_SCLK = 0;
	}
	return byte;
	
}


unsigned char EEPROM_25LCxxx_Read(unsigned int add){
	unsigned char byte;
	SPI_CS = 0;									
	Soft_SPI_Write(READ);				//Gui lenh doc
	Soft_SPI_Write(add >> 8);		//Gui byte cao cua dia chi
	Soft_SPI_Write(add & 0x00FF);				//Gui byte thap
	byte = Soft_SPI_Read();
	return byte;
}


unsigned char EEPROM_25LCxxx_WIP()
{
	unsigned result;
	SPI_CS = 0;
	Soft_SPI_Write(RDSR);
	result = Soft_SPI_Read();
	SPI_CS = 1;
	return result & 0x01;
}