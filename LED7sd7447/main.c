#include "main.h"
#include "../lib/delay.h"


#define GIO P2
#define PHUT P3
#define GIAY P1


void main(){
	unsigned int dem = 0;
	unsigned char  tram,chuc ,dv;
		
	while(1){
			dv = dem % 10;
			chuc = (dem%100)/10;
			tram = dem /100;
			
			GIAY = dv;
			PHUT = chuc;
			GIO = tram;
			Delay(50);
			dem++;
			dem%= 1000;
		
	}
}