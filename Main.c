#include "TM4C123GH6PM.H"
#include <stdint.h>
#include  "LCD.h"
#define  Rows  4
#define  Cols  4
#ifndef KPD_H_
#define KPD_H_
#endif
int i , j;
char Door , Buttons , N ;
char Cook_String[5];
char str[5];
void SystemInit(){
SYSCTL_RCGCGPIO_R |=0x20;
GPIO_PORTF_CR_R |=0x0E;
GPIO_PORTF_AMSEL_R &=~0x0E;
GPIO_PORTF_PCTL_R &=~0x0000FFF0;
GPIO_PORTF_DIR_R |=0x0E;
GPIO_PORTF_DEN_R |=0x0E; 
GPIO_PORTF_AFSEL_R &=~0x0E;
GPIO_PORTF_DATA_R &=~0x0E;}


int main(){
	SystemInit();
	SysTick_wait(160000);
	SW3_Init();
	SWs_Init();
	SysTick_wait(160000);
	LCD_Init();
	keypad_Init();
	LCD_command(0X01);
	LCD_command(0X0C);
while(1){
		Door = SW3_input();
		Buttons = SWs_input();
	if(Door==0x20){
			if(Buttons==0x10){
			  Cooking();}
	    else if(Buttons==0x01){
			    SW1_first_push();}
		 }
	else if(Door==0x00){
			SysTick_wait(160000);
		   Door_open();
	   }
}
}