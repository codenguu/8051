#ifndef _UART_MODE1_
#define _UART_MODE1_

void UART_init();// khoi tao UART

//kiem tra xem nhan duoc byte du lieu chua ?
//tra ve 1 da nhan duoc , san sang doc du lieu
//tra ve 0 chua nhan duoc.
char UART_Ready();


//doc byte nhan duoc tu UART
char UART_Read();


//Gui 1 ky tu vao UART
void UART_Write(char c);

//Gui 1 chuoi text vao UART
void UART_Write_text(char *str);


#endif