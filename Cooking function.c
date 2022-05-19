void Cooking()
{
	Keypad_Getkey();
	  SysTick_wait(800000);

  if (keypad[i][j] == 'A')
     {
		  SysTick_wait(160000);
		  Cooking_popcorn();
     }
	else if (keypad[i][j] == 'B')
     {
		   Cooking_Beef();
     }
	else if (keypad[i][j] == 'C')
     {
	    Cooking_Chicken();
     }
	else if (keypad[i][j] == 'D')
     {
		SysTick_wait(480000);
	  	LCD_command(0X01);
	  	LCD_command(0XC0);
	LCD_printString("Cooking Time?");
		Cooking_Time();
     SysTick_wait(480000);
		Start_Cooking();
			
	
     }
}