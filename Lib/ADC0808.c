#include "main.h"
#include "port.h"
#include "../Lib/ADC0808.h"

void ADC_Init()
{
	ADC0808_START = 0;
	ADC0808_ALE = 0;
	ADC0808_OE = 0;
}

unsigned char ADC0808_Read(unsigned char channel){
	unsigned char kq;
	ADC0808_ADDA = channel & 0x01; 		
	ADC0808_ADDB = channel & 0x02;
	ADC0808_ADDC = channel & 0x04;
	
	ADC0808_ALE = 1;			//Giao tiep
	ADC0808_START = 1;		//Bat dau chuyen doi
	ADC0808_ALE = 0;			//
	ADC0808_START = 0;
	
	
	while(ADC0808_EOC);		//cho chuyen doi 
	while(ADC0808_EOC == 0); //ket thuc chuyen doi
	
	ADC0808_OE = 1;		//doc du lieu vao port
	kq = ADC0808_DATA ;
	ADC0808_OE = 0;	
	
	return kq;
	
}
