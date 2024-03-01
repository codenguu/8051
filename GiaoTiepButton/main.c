#include "main.h"
#include "..\Lib\Delay.h"
#include "port.h"


#define LED P2

unsigned char DelayQuetphim()
{
	unsigned char i;
	for(i = 0; i < 10 ; i++)
		{
			Delay(10);
			
			if(STOP == 0)
			{
				LED = 0x00;
				return 1;  //co nhan stop
			}
		}
		return 0;      //khong nhan stop
}
void nhay(){
	unsigned char i = 10;
	LED = 0x00;
	while(i){
		LED = ~LED;
		if(DelayQuetphim())
		{
			break;
		}
		i--;
	}
}
void conran(){
	unsigned char i , n = 5;
	LED = 0x00;
	while(n)
	{
		LED = 0x00;
		for(i = 0 ; i < 8 ; i++)
		{
			LED |= (1 << i);
			if(DelayQuetphim())
			{
				break;
			}
		}
		for(i = 0; i < 8 ; i++)
		{
			LED &= ~(1 << i);
			if(DelayQuetphim())
			{
				break;
			}
		}
		n--;
	}
}


void nhayxenke()
{
	unsigned char i = 10;
	LED = 0XAA;
	while(i)
	{
		LED = ~LED;
		if(DelayQuetphim())
			{
				break;
			}
		i--;
	}
	
}
void conran2()
{
	unsigned char i;
	LED = 0x00;
	for(i=0; i < 8;i++)
	{
		
	}
}



void main(){
	LED = 0;
	if(START == 0)
	{
		while(1){
			conran();
			nhay();
			nhayxenke();
			if(STOP==0)
				break;
		}
	}
}