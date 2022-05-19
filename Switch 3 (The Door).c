#include "TM4C123GH6PM.H"
#include <stdint.h>

void SW3_Init(void)
{
	SYSCTL_RCGCGPIO_R |=0x14; 
  while ((SYSCTL_PRGPIO_R&0x14) == 0){}; 
	GPIO_PORTE_LOCK_R=0x4C4F434B; 	
	GPIO_PORTE_CR_R |=0x20;  
	GPIO_PORTE_AFSEL_R &=~0x20; 
	GPIO_PORTE_PCTL_R |=0XF00000; 
	GPIO_PORTE_AMSEL_R &=~0x20; 
	GPIO_PORTE_DIR_R &=~0x20; 
	GPIO_PORTE_DEN_R |=0x20; 
	GPIO_PORTE_PUR_R |=0x20; 
}
unsigned char SW3_input(void){
 return GPIO_PORTE_DATA_R & 0x20;}

void Door_close(void){     ////when the SW2 is pressed continue to cook
while(1){
		Buttons = SWs_input();
		led_blink();
	if(Buttons==0x10){
		LCD_CountDown(Cook_String);
	 	SysTick_wait(480000);
		break;}
	}
}
void Door_open(void){   /////pause the cooking when the door is open
	SysTick_wait(160000);
while(1){ 
		Door = SW3_input();
		led_blink();
	if(Door==0x20){
		Door_close();
		SysTick_wait(480000);
		break;}
    }		  
 }