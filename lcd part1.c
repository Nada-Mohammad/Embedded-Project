#include "TM4C123GH6PM.H"
#include <stdint.h>
#include  "lcdd.h"
#include "tm123.h"


void LCD_command(unsigned int command){
	GPIO_PORTA_DATA_R =0x20;
	GPIO_PORTB_DATA_R = command;
  GPIO_PORTA_DATA_R =0x80;                                   
	GPIO_PORTA_DATA_R =0x00;
}

//int port all port b int port A4 A5 A6 A7
void LCD_Init(){
	SYSCTL_RCGCGPIO_R |=0x03;
	while((SYSCTL_PRGPIO_R &0x03)==0);
	GPIO_PORTB_LOCK_R =0X4C4F434B;
	GPIO_PORTB_DIR_R =0XFF;
	GPIO_PORTB_AMSEL_R =0X00;
	GPIO_PORTB_AFSEL_R =0X00;
	GPIO_PORTB_DEN_R  =0XFF;       //int port all port b
	GPIO_PORTB_CR_R =0XFF;
	GPIO_PORTB_PCTL_R =0XFFFFFFFF;
	
	GPIO_PORTA_LOCK_R =0X4C4F434B;
	GPIO_PORTA_DIR_R |=0XF0;
	GPIO_PORTA_AMSEL_R &=~0XF0;
	GPIO_PORTA_AFSEL_R &=~0XF0;       //int port 
	GPIO_PORTA_DEN_R |=0XF0;
	GPIO_PORTA_CR_R |=0XF0;
	GPIO_PORTA_PCTL_R |=0XFFFF0000;
	
	
	LCD_command(0X38);
	LCD_command(0X08);
	LCD_command(0X01);
	LCD_command(0X06);
	LCD_command(0X0C);
	LCD_command(0XC0);
	
	
}

 // this function is used when we send datd
void LCD_data( unsigned char data){
	GPIO_PORTA_DATA_R =0x20;
	GPIO_PORTB_DATA_R = data;
	GPIO_PORTA_DATA_R = 0x80 |0x20;
	SysTick_wait(160000);
	GPIO_PORTA_DATA_R =0x00;
	SysTick_wait(160000);
}

// this function is used when we send string of data and then calling data function
void LCD_printString (char *string){
	int i;
	for( i=0; string[i]!=0 ;i++){       
		LCD_data(string[i]);
		
	}
}

// this function is determine the position of cursor
void LCD_cursor(uint8_t x, uint8_t y)
{
	if(y)
		x |= 0x40;
	x |= 0x80;

	LCD_command(x);
}