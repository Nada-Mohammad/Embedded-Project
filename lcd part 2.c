#include "TM4C123GH6PM.H"
#include <stdint.h>
#include  "lcdd.h"
#include "tm123.h"

unsigned char Cooking_Time(){
	 int state , l;
	 SysTick_wait(80000000);
 	  LCD_command(0XC0);
		LCD_printString("00:00");
		for(state = 0;state<4;state ++){
		if(state==0 ) {  //&& keypaed is pused
			Keypad_Getkey();
			Cook_String[4]=  keypad[i][j]; 
		  LCD_cursor(4,1);
		 	LCD_data(Cook_String[4]);
			
		}
		
		else if (state==1){
			SysTick_wait(80000000);
			Cook_String[3]=Cook_String[4];
		  LCD_cursor(3,1);
			LCD_data(Cook_String[3]);
		  Cook_String[4]= '0'; 
	    LCD_cursor(4,1);
			LCD_data(Cook_String[4]);
	    SysTick_wait(80000000);
			Keypad_Getkey();
			Cook_String[4]=  keypad[i][j];
		  LCD_cursor(4,1);
			LCD_data(Cook_String[4]);
		}
		else if (state==2){
      SysTick_wait(80000000);		//&& keypaed is pused
	  	Cook_String[1]=Cook_String[3];
		  LCD_cursor(1,1);
			LCD_data(Cook_String[1]);
	    Cook_String[3]= Cook_String[4];
		  LCD_cursor(3,1);
			LCD_data(Cook_String[3]);
			Cook_String[4]= '0';  
		  LCD_cursor(4,1);
			LCD_data(Cook_String[4]);
		  SysTick_wait(80000000);
			Keypad_Getkey();
		  Cook_String[4]=  keypad[i][j];
		  LCD_cursor(4,1);
			LCD_data(Cook_String[4]);
			
			
		}
		
		else if (state==3){ 
      SysTick_wait(80000000);
			//&& keypaed is pused
	    Cook_String[0]=Cook_String[1];
		  LCD_cursor(0,1);
			LCD_data(Cook_String[0]);
			Cook_String[1]=Cook_String[3];
		  LCD_cursor(1,1);
			LCD_data(Cook_String[1]);
	  	Cook_String[3]=Cook_String[4];
		  LCD_cursor(3,1);
			LCD_data(Cook_String[3]);
			Cook_String[4]= '0'; 
		  LCD_cursor(4,1);
			LCD_data(Cook_String[4]);
	    SysTick_wait(80000000);
      Keypad_Getkey();
			Cook_String[4]=  keypad[i][j];
		  LCD_cursor(4,1);
			LCD_data(Cook_String[4]);
		}
	} if (Cook_String[0] > '3'){
		   generic_delay(50);
		    LCD_command(0X01); 
			LCD_printString("Invalid number");
		   generic_delay(50);
		   LCD_command(0X01);
		LCD_printString("Cooking Time?"); 
		     Cooking_Time();
		}
		for(l=0;l<10;l++){	
	     return Cook_String[l];
	}
}


// calling this function when D iS pused
void Start_Cooking(){
	while(1){
	Buttons = SWs_input();
	 if(Buttons==0x01){
	 	LCD_command(0X01); 
		LCD_printString("Cooking Time?");
		 Cooking_Time();
     SysTick_wait(480000);
    break;		 
	 }
	 else if(Buttons==0x10){
		 LEDS_On();
		 LCD_CountDown(Cook_String);
		 SysTick_wait(480000);
		 break;
	 }
 }
	}


// calling this function when BiS pused
void Cooking_Beef(){
		 LCD_command(0X01);
	 LCD_printString("Beef Weight?");
	 generic_delay(150); 
	  LCD_command(0X01);
    Beef_countdown();
}


//calling this function when C iS pused
void Cooking_Chicken(){
	  	 LCD_command(0X01);
	    LCD_printString("Chicken Weight?");
	    generic_delay(150);
	    LCD_command(0X01);
      Chicken_countdown();
	
}

//calling this function when A iS pused
void Cooking_popcorn(){
	     LEDS_On();
	   LCD_command(0X01);
	   LCD_command(0XC0);
	LCD_printString("popcorn");
    SysTick_wait(80000000);
	    LCD_command(0XC0);
	   LCD_printString("01:00");
      SysTick_wait(80000000);
	   LCD_CountDown("01:00");
}
