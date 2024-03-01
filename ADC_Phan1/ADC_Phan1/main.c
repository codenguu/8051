#include "main.h"
#include "..\lib\Delay.h"
#include "..\lib\Lcd4.h"

unsigned char Adc_Read();

void main()
{
	unsigned char adc_value;
	unsigned int voltage;

	Lcd_Init();

	while(1)
	{
		adc_value = Adc_Read();
		voltage = adc_value * 1.953125f;
		// 0.00 -> 5.00;
		// 000 -> 500
		
		Lcd_Chr(1,1,adc_value/100+0x30);
		Lcd_Chr_Cp(adc_value%100/10+0x30);
		Lcd_Chr_Cp(adc_value%10+0x30);
		
		Lcd_Chr(2,1,voltage/100+0x30);
		Lcd_Chr_Cp('.');
		Lcd_Chr_Cp(voltage%100/10+0x30);
		Lcd_Chr_Cp(voltage%10+0x30);

		Delay_ms(500);	
	}
}

unsigned char Adc_Read()
{
 	P2 = 255;
	while(P3_0)
	{
		P2--;
		if(P2==0)	break;
	}

	return P2;
}