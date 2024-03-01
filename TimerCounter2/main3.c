#include "main.h"
#include "../lib/delay.h"




void main(){
	//Cau hinh timer/counter 2 lam bo tao xung clock
	T2CON = 0x00; 		//C/T2 = 0;
	T2MOD = 0x02 ; 		//T2OE = 1;
	
	
	RCAP2H = 0xFF; //
	RCAP2L = 0xB1;	//
	

	
	TR2 = 1; 		//BAT DAU DEM
		
		////Cau hinh timer1/counter1 lam bo tao xung clock chan P2.0;
//		TMOD &= 0x0F;
//		TMOD |= 0x10;
		
	while(1){
		
//		TH1 = 0xFC ; 
//		TL1 = 0x18 ;
//		
//		TR1 = 1;

//		while(TF1 == 0);

//		P2_0 = !P2_0;
//	
//		TF1 = 0;
	}

}