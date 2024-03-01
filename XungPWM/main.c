#include "main.h"
#include "../lib/delay.h"

#define up 0
#define down 1

sbit BTN = P1^0;

unsigned int T, Th, Tl;
unsigned char Ton_h_reload, Ton_l_reload, Toff_h_reload, Toff_l_reload;

void PWM_START()
{
	TR1 = 1;
}

void PWM_STOP()
{
	TR1 = 0;
}

//ck(us)
void PWM_Init(unsigned int ck)
{
	P2_0 = 1;
	TMOD = 0x0F; 		//Xoa di cac mode cua Timer1;
	TMOD = 0x10;		//Tiemr0 mode 1;16bit
	
	ET1 = 1; 		//cho phep ngat timer1
	EA = 1; 		//cho phep ngat toan cuc
	
	T = ck;
	Th  = T/2;
	Tl = T - Th ; 
	
	Ton_h_reload = (65536 - Th) >> 8;			//thoi gian o muc 1;
	Ton_l_reload = (65536 - Th) & 0x00FF;	//thoi gian o muc 1;
	
	Toff_h_reload = (65536 - Tl) >> 8; 			//thoi gian o muc 0;
	Toff_l_reload = (65536 - Tl) & 0x00FF;			//thoi gian o muc 0;
	
	
		// hien tai P2_0 dang muc 1;
	TH1 = Ton_h_reload ;
	TL1 = Ton_l_reload ;
	
}

//cycle duty
void PWM_set_Duty(unsigned char duty)
{
	if(duty == 0){
		P2_0 = 0;
		ET1 = 0;
	}
	else if(duty == 100){
		P2_0 = 1;
		ET1 = 0;
	}
	else 
	{
		Th = (unsigned long)T*duty/100;
		
		Tl = T - Th;
		
		Ton_h_reload = (65536 - Th) >> 8;			//thoi gian o muc 1;
		Ton_l_reload = (65536 - Th) & 0x00FF;	//thoi gian o muc 1;
		
		Toff_h_reload = (65536 - Tl) >> 8; 			//thoi gian o muc 0;
		Toff_l_reload = (65536 - Tl) & 0x00FF;			//thoi gian o muc 0;
		
		ET1 = 1;
	}
	
}

void main(){
	unsigned char dir = up , duty = 0;
	PWM_Init(10000);
	PWM_set_Duty(duty);
	PWM_START();
	
	while(1){
		if(dir == up){
			if(BTN == 0){
				duty += 10;
				while(BTN == 0);
				if(duty == 100){
					dir = down;
			}
		}
		}
		else if(dir == down){
			if(BTN == 0){
				duty -= 10;
				while(BTN == 0);
				if(duty == 0){
					dir = up;
				}
			}
		}
		PWM_set_Duty(duty);
	}

}

void ISR_PWM(void) interrupt 3
{

	P2_0 = !P2_0;
	if(P2_0 == 0)
	{
		TH1 = Toff_h_reload ;
		TL1 = Toff_l_reload ;
	}
	else 
	{
		TH1 = Ton_h_reload;
		TL1 = Ton_l_reload;
	}
}