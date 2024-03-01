#ifndef _PORT_H_
#define _PORT_H_
//khai bao cac chan giap tiep spi
sbit	SPI_SCLK = P2^0;
sbit	SPI_MOSI = P2^1;
sbit	SPI_MISO = P2^2;
sbit	SPI_CS = P2^3;


//DEFINE CAC THANH GHI TREN 25LCXXX
#define READ 0x03
#define WRITE 0x02
#define WRDI 0x04
#define WREN 0x06
#define RDSR 0x05
#define WRSR 0x01


#endif