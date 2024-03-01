#include <REG52.H>


// dat ten cho chan p0.0 la LED_LED PIN

void Delay(unsigned int t)
{
    unsigned int i , j ;
    for (i = 0 ; i < t ; i++)
    {
        for(j = 0; j < 123 ; j++){
            //
        }
    }
}

void nhayled(){
	int n = 5;
	while(n){
		P0 = 0x55;
		Delay(100);
		P0 = ~P0 ;
		Delay(100);
		n--;
	}
}

void nhapnhay(){
	int n = 5;
	while(n){
		P0 = 0x00;
		Delay(100);
		P0 = ~P0;
		Delay(100);
		P0 = ~P0;
		Delay(100);
		P0 = ~P0;
		Delay(100);
		n--;
	}
}

void Batdan(int j, int i){
	for(i = 0 ; i < 10 ; i++){
		for(j = 0; j < 9; j++){
			P0 = 0x00;
			P0|= (0xA0 >> j);
			if(j == 6) {
				P0_7 = !P0_7;
			}
			if(j == 7) {
				P0_6 = !P0_6;
			}
			Delay(100);
		}
	}
}
void vidu(int n){
	unsigned char i;
	while(n){
		P0 = 0x00;
		for(i = 0 ; i < 9 ; i++){
			Delay(70);
			P0 |= (1 << i);

		}
		P0 = 0x00;
		for(i = 0 ; i < 9 ; i++){
			
			Delay(70);
			P0 |= (0x80>> i);
		}
		n--;
	}
}
void  main()
{
	while(1){
	nhayled();
	nhapnhay();
	Batdan(0 , 0);
	vidu(10);
	}
}