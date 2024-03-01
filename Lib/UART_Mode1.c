#include "main.h"
#include "delay.h"
#include "UART_Mode1.h"

#if (FREQ_OSC != 11059200)
	#error " Chi ho tro tan so thach anh 11059200"
#endif

//khoi tao che do uart mode 1
void UART_init(){
	//KHAI BAO CHE DO UART MODE 1 , 8 BIT VOI CHE DO DAM BAO
	SM0 = 0;
	SM1 = 1;
	
	TMOD &= 0x0F;// giu lai cac bit cuoi cua byte TMOD

	TMOD |= 0x20 ; // 0010 xxxx - Timer1 hoat dong o che do 8 bit tu dong nap lai
	#if(BAUD_RATE == 9600)// Toc do baud 9600
		TH1 = 0xFD;
	
	#elif(BAUD_RATE == 2400)
		TH1 = 0xF4; 
	#elif(BAUD_RATE == 1200)
		TH1 = 0xE8;
	#elif(BAUD_RATE == 19200)
		TH1 = 0xE8;
		PCON =| 0x80;
	#else 
		#error "Ch? ho tro cho Baud rate la 1200 , 2400 , 9600 , 19200"
	#endif
	TR1 = 1; // bit nay dieu khien hoat dong cua timer1
	
	TI = 1; 	//san sang gui du lieu
	
	REN = 1;// Khi REN = 1, bo thu là ho?t d?ng và s?n sàng nh?n d? li?u.
					//Khi REN = 0, bo thu không hoat dong.
}

//San sang doc du lieu
char UART_Ready(){
	
	return RI;// Bit này duoc set khi bo thu dã nhann du lieu và nó san sàng de doc. 
						//Nó duoc clear khi ban doc du lieu tu thanh ghi SBUF.
}

//Doc tin du lieu tu SBUFF
char UART_Read(){
	RI = 0;//
	return SBUF ;
}


void UART_Write(char c){
	
		while(TI == 0); //cho den khi nao truyen du lieu xong thi TI duoc set = 1;
		TI = 0; 				//Sau do ta clear no de gui ma moi vao
		SBUF = c ; // Luu ki tu 'A' vao bo dem
	
}

//chuoi ki tu
void UART_Write_text(char *str){
	unsigned char i = 0;
	while(str[i] != 0){
		UART_Write(str[i]);
		i++;
	}
}
