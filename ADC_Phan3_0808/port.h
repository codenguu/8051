#ifndef 	_PORT_H_
#define 	_PORT_H_

//KHAI BAO CHAN LCD 

sbit LCD_RS = P0^0 ;
sbit LCD_EN = P0^1 ;
#define LCD P1 


sbit ADC0808_ADDA = P2^0;
sbit ADC0808_ADDB = P2^1;
sbit ADC0808_ADDC = P2^2;
sbit ADC0808_ALE = P2^3;
sbit ADC0808_START = P2^4;
sbit ADC0808_EOC = P2^5;
sbit ADC0808_OE = P2^6;

#define ADC0808_DATA P3




#endif