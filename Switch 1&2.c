#include "TM4C123GH6PM.H"
#include <stdint.h>

void SWs_Init() {
GPIO_PORTF_LOCK_R =0x4C4F434B;
GPIO_PORTF_CR_R |=0x11;
GPIO_PORTF_AMSEL_R &=~0x11;
GPIO_PORTF_PCTL_R &=~0x000F000F;
GPIO_PORTF_DIR_R &=~0x11;
GPIO_PORTF_PUR_R |=0x11; 
GPIO_PORTF_AFSEL_R &=~0x11;
GPIO_PORTF_DEN_R |=0x11; 
GPIO_PORTF_DATA_R &=~0x0E; }

 void led_input(unsigned char led){
GPIO_PORTF_DATA_R &=~0x0E;
GPIO_PORTF_DATA_R |=led;}
//////////
unsigned char SWs_input(void){
return GPIO_PORTF_DATA_R & 0x11;
 }
//////////////////
void ContinueCooking(void){
	    LCD_CountDown(Cook_String);
			SysTick_wait(480000);
}
void SW1_Second_push(void){   ///second push to clear the time and stop
	  SysTick_wait(640000);
	  LCD_cursor(0,1);
	  LCD_printString("00:00");
	  led_input(0x00);
}

 void SW1_first_push(){     ////first push to pause
while(1){
		generic_delay(100);
		Buttons = SWs_input();
	  led_blink();
	if(Buttons==0x01){
		SW1_Second_push();
		SysTick_wait(480000);
		break;}
	if(Buttons==0x10){
	   ContinueCooking();
	   SysTick_wait(480000);
			break;}
	}
 }
