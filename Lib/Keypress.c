#include "main.h"
#include "../lib/Keypress.h"


unsigned char KeyPress(){
		unsigned char key = 0;
	//Kiem tra hang 1; 
	row1 = 0;
	if(col1 == 0) key = 1;
	if(col2 == 0) key = 2;
	if(col3 == 0) key = 3;
	if(col4 == 0)	key = 4;
	row1 = 1;
	//kiem tra hang 2;
	row2 = 0;
	if(col1 == 0) key = 5;
	if(col2 == 0) key = 6;
	if(col3 == 0) key = 7;
	if(col4 == 0)	key = 8;
	row2 = 1;
	
	//Kiem tra hang 3; 
	row3 = 0;
	if(col1 == 0) key = 9;
	if(col2 == 0) key = 10;
	if(col3 == 0) key = 11;
	if(col4 == 0)	key =12;
	row3 =1;
	//kiem tra hang 4;
	row4 = 0;
	if(col1 == 0) key = 13;
	if(col2 == 0) key = 14;
	if(col3 == 0) key = 15;
	if(col4 == 0)	key = 16;
	row4 = 1;
	
	return key;
	
	}