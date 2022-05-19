char N ;
void Cooking_Beef();
void Beef_countdown(){           //defrosting time for beef 
     Keypad_Getkey();
	   N = keypad[i][j];
	   LCD_data(N);
	    generic_delay(2000);
	    LCD_command(0X01);
	    LCD_printString("Beef");
if(N =='1'){
	    LCD_cursor(0,1);
	    LCD_printString("00:30");
			SysTick_wait(8000000);
    	LCD_CountDown("00:30");
	}
		else if(N=='2')
		{
			LCD_cursor(0,1);
	    LCD_printString("01:00");
			SysTick_wait(8000000);
	    LCD_CountDown("01:00");
		}
		else if(N=='3')
		{
   	LCD_cursor(0,1);
	LCD_printString("01:30");
			SysTick_wait(8000000);
	LCD_CountDown("01:30");
		}
		  
		else if(N=='4')
		{
			LCD_cursor(0,1);
	LCD_printString("02:00");
			SysTick_wait(8000000);
	LCD_CountDown("02:00");
		}
		else if(N=='5')
		{
	LCD_cursor(0,1);
	LCD_printString("02:30");
			SysTick_wait(8000000);
	LCD_CountDown("02:30");
	  }
		else if(N=='6')
		{
		LCD_cursor(0,1);
	LCD_printString("03:00");
			SysTick_wait(8000000);
	LCD_CountDown("03:00");
		 
		}
		else if(N=='7'){
			LCD_cursor(0,1);
	LCD_printString("03:30");
			SysTick_wait(8000000);
	LCD_CountDown("03:30");
		 
		}
		else if(N=='8')
		{
  	LCD_cursor(0,1);
	LCD_printString("04:00");
			SysTick_wait(8000000);
	LCD_CountDown("04:00");
	 
		}
		else if(N=='9')
		{
		LCD_cursor(0,1);
	LCD_printString("04:30");
			SysTick_wait(8000000);
	LCD_CountDown("04:30");
	
		}
	else  { 
		  LCD_command(0X01);
		  LCD_printString("Err");
		  generic_delay(2000);
		   Cooking_Beef();
	     }
	    
 
 }