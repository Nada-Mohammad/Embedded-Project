#include "tm4c123gh6pm.h"
#define  Rows  4
#define  Cols  4

#ifndef KPD_H_
#define KPD_H_


unsigned char Keypad_Getkey(void);

#endif	

void keypad_Init(void){
	
	SYSCTL_RCGCGPIO_R |=0x14; // active clock for port C and port E
  while ((SYSCTL_PRGPIO_R&0x14) == 0){}; // wait
	GPIO_PORTC_LOCK_R=0x4C4F434B; 	// unlock GPIO port C
	GPIO_PORTE_CR_R |=0x1E;  // allow changes to PE4-1
	GPIO_PORTE_DIR_R |=0x00; // PE4-1 IN (set pine4-1 as rows)
	GPIO_PORTE_DEN_R |=0x1E; // enable digital I/O on PE4-1
	GPIO_PORTE_PDR_R |=0x1E; // enable pull-down on PE4-1 for rows 
	GPIO_PORTE_DATA_R |=0x00; // disable all rows
	
		
	GPIO_PORTC_CR_R |=0xF0; // allow changes to PC7-4
	GPIO_PORTC_DIR_R |=0x00; // PPC7-4 IN (set pinc7-4 as cols)
	GPIO_PORTC_DEN_R |=0xF0; // enable digital I/O on PC7-4
	GPIO_PORTC_DATA_R |=0x00; // disable all cols
}


unsigned char keypad[Rows][Cols]={
                                         {'1', '2', '3','A'},
                                         {'4', '5', '6','B'},
			                                   {'7', '8', '9','C'},
   			                                 {'*', '0', '#','D'}
                                  };

int i;
int j;
																	
unsigned char Keypad_Getkey()
{
	while(1)
	{
	for (j=0; j<4; j++) 
	{
		GPIO_PORTC_DATA_R = 0xF0 &(0x01 << (j+4));		//check the Col pressed
	  SysTick_Wait(800000);
	for (i=0; i<4; i++) 
	{
		if ((GPIO_PORTE_DATA_R & 0x1E) &(0x01 << (i+1)))	 //chech the Row pressed
			return keypad[i][j];                           // return the key pressed                                    
		}
	}
  }
 }

void Cooking(){	
	
while(1)
{
  if (keypad[i][j] == 'A'){ // if A is pressed
		Cook_Popcorn();
		generic_delay(2000);
	}
	else if (keypad[i][j] == 'B'){ // if B is pressed
		Cook_Beef();
		generic_delay(2000);
	}
	else if (keypad[i][j] == 'C'){ // if C is pressed
		Cook_Chicken();
		generic_delay(2000);
	}
	else if (keypad[i][j] == 'D'){ // if D is pressed
		shifttime();
		generic_delay(2000);
	}
}
}
