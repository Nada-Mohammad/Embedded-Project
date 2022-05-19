#include "TM4C123GH6PM.H"
#include <stdint.h>
#include  "LCD.h"
unsigned char LCD_CountDown( char *array){    ////This function is used to count down time on LCD
	int m,w,k ;
	 Cook_String[2] = ':';
	 Cook_String[0]= array[0] ;
	 Cook_String[1]= array[1] ;
	 Cook_String[3]= array[3] ;
	 Cook_String[4]= array[4] ;
	while(1){
	for (m=0; m<5;m++){
		LEDS_On();
		Buttons = SWs_input();
		Door = SW3_input();
		if(Buttons==0x11&&Door==0x20){
	     if( Cook_String[4] !='0'){
				 for( w=0; w <= 9;w++){
						  Buttons = SWs_input();
	        	  Door = SW3_input();
	         	if(Buttons==0x11&&Door==0x20){
	             Cook_String[4] = Cook_String[4]- 1;
	             LCD_cursor(4,1);
	             LCD_data(Cook_String[4]);
	             SysTick_wait(80000000);
						   if(Cook_String[4] =='0'){
							 break;}
		          }
		else if(Door==0x00||Buttons==0x01){
	       for(k=0;k<10;k++){	
	           return Cook_String[k];}
				 break;}		
	        } 
				}
					
	     else if( Cook_String[3]!='0'){
				        Cook_String[4] = '9';
			          LCD_cursor(4,1);
		   	        LCD_data(Cook_String[4]);		  
			          Cook_String[3] = Cook_String[3] - 1;
                LCD_cursor(3,1);
			          LCD_data(Cook_String[3]);
				        SysTick_wait(80000000);
			        }
		   else {break;}
		 }
			 else if(Door==0x00||Buttons==0x01){
		      for(k=0;k<10;k++){	
	        return Cook_String[k];}
					break;}		
	 }
     
if(Cook_String[4]=='0' && Cook_String[3]=='0'&&Cook_String[1]!='0' ){
		  Cook_String[4]= '9';
		  LCD_cursor(4,1);
		  LCD_data(Cook_String[4]);
		  Cook_String[3] = '5';
		  LCD_cursor(3,1);
		  LCD_data(Cook_String[3]);
		  Cook_String[1] = Cook_String[1] -1;
		  LCD_cursor(1,1);
		  LCD_data(Cook_String[1]);
	    SysTick_wait(80000000);
	}
else if(Cook_String[1]=='0' && Cook_String[0]!='0'){
		 Cook_String[4]= '9';
		 LCD_cursor(4,1);
		 LCD_data(Cook_String[4]);
		 Cook_String[3] = '5';
	   LCD_cursor(3,1);
		 LCD_data(Cook_String[3]);
		 Cook_String[1] = '9' ;
		 LCD_cursor(1,1);
		 LCD_data(Cook_String[1]);
		 Cook_String[0]=Cook_String[0] -1 ;
		 LCD_cursor(0,1);
		 LCD_data(Cook_String[0]);
		 SysTick_wait(80000000);
	} 
	else if(Cook_String[4]=='0' && Cook_String[3]=='0' && Cook_String[1]=='0' && Cook_String[0]=='0'){ 
		Count_Zero(); 
		LCD_command(0X01);
	   break;}
	}
}