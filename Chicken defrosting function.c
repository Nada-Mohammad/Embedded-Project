char N;  void Cooking_Chicken();
void Chicken_countdown(){           
     Keypad_Getkey();
	   N = keypad[i][j];
	   LCD_data(N);
	   generic_delay(2000);
	   LCD_command(0X01);
	LCD_printString("Chicken");
if(N =='1'){
	   LCD_command(0XC0);
	    LCD_printString("00:12");
			SysTick_wait(8000000);
    	LCD_CountDown("00:12");
	}
		else if(N=='2')
		{
			LCD_cursor(0,1);
	    LCD_printString("00:24");
			SysTick_wait(8000000);
	    LCD_CountDown("00:24");
		}
		else if(N=='3')
		{
   	LCD_cursor(0,1);
	LCD_printString("00:36");
			SysTick_wait(8000000);
	LCD_CountDown("00:36");
		}
		  
		else if(N=='4')
		{
			LCD_cursor(0,1);
	LCD_printString("00:48");
			SysTick_wait(8000000);
	LCD_CountDown("00:48");
		}
		else if(N=='5')
		{
	LCD_cursor(0,1);
	LCD_printString("01:00");
			SysTick_wait(8000000);
	LCD_CountDown("01:00");
	  }
		else if(N=='6')
		{
		LCD_cursor(0,1);
	LCD_printString("01:12");
			SysTick_wait(8000000);
	LCD_CountDown("01:12");
		 
		}
		else if(N=='7'){
			LCD_cursor(0,1);
	LCD_printString("01:24");
			SysTick_wait(8000000);
	LCD_CountDown("01:24");
		 
		}
		else if(N=='8')
		{
  	LCD_cursor(0,1);
	LCD_printString("01:36");
			SysTick_wait(8000000);
	LCD_CountDown("01:36");
	 
		}
		else if(N=='9')
		{
		LCD_cursor(0,1);
	LCD_printString("01:48");
			SysTick_wait(8000000);
	LCD_CountDown("01:48");
	
		}
	else {
		  LCD_command(0X01);
		  LCD_printString("Err");
		  generic_delay(2000);
		   Cooking_Chicken();
	     }
		 }
void Cooking_Chicken(){
	  	 LCD_command(0X01);
	    LCD_printString("Chicken Weight?");
	    generic_delay(150);
	    LCD_command(0X01);
      Chicken_countdown();
	
}