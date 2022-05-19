enum { IDLE, Waiting, Cooking, Pause, Door_Open };

void MicrowaveController()
{
	int state = IDLE;
	int k = keypad[i][j];
	int cook;
	int wait;
	int door_open;
	
	while(1)
	{
		switch (state){
			
			IDLE: 
			LCD_printString(" ");
			
if (k == 'A')
	{
	state = Cooking;  
	}
	
else if (k == 'B')
	{
	state = Waiting;
	}
		
else if (k == 'C')
	{
		state = Waiting;
	}
		
else if (k == 'D')
		{
		state = Waiting;
		}
else 
	{
	  state=IDLE;
	}
	break;
	
	
		
			Waiting:
if (k == 'B' | 'C')
{	
	if (k >0 | k <10 )       //Number of kilos between 1:9
	{
		state = Cooking;
	}
	
	else{
		LCD_printString("Err");
		state = Waiting;
	}		
else if (k == 'D')
{	
	if ('kk:kk' < '31:00') // k between 1:30
	{
	state = Cooking;
	}
	
	else
		LCD_printString("Err");
		{
		state = Waiting;
		}
	}
else
{
	state=Waiting;
}
   
  break;
}
}
}
}
