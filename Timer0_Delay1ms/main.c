#include "main.h"


void Delay_timer0(unsigned int t){
	do 
	{
		TH0 = 0xFC;
		TL0 = 0x18;
		
		TR0 = 1; //bat dau dem
		
		while(TF0 == 0);
		TR0 = 0; //dung dem
		
		TF = 0; //reset flag ve 0;
			
			t--;
	}
	while(t!=0);

}


void main(){
		
	//chon mode cho timer0
	TMOD &= 0xF0; // Xoa cac bit dieu khien timer0;
	TMOD |= 0x01; //Chon mode timer 16 bit
	
	
	while(1){
	
		P2_0 = !P2_0;
		Delay_timer0(1000);
	
	}
}