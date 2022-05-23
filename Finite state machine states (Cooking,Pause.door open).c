

     Cooking:
if (k == 'A' && SW2=0)           //If "A" is pressed while SW2 in pressed
	 {
		timer = 1;                   //cook for 1 minute
	  state = IDLE;
    }
		
else if (k == 'B' && SW2=0)      //If "B" is pressed while SW2 in pressed
	 {
    timer = 0.5*k;               //cook for 0.5*k minutes	
	  state = IDLE;7
		}
		
else if (k == 'c' && SW2=0)       //If "B" is pressed while SW2 in pressed
{
    timer = 0.2*k;	             //cook for 0.2*k minutes
	  state = IDLE;
		}
		
else if (k == 'D') 	            
{
     timer = k;		               //cook for time (k) input by user
	  state = IDLE;
		}
		
else if ( SW1 =0)                //SW1 is pressed
	{state = Pause;}               //Stop cooking and go to pause state
	
else if ( SW3 =0)                //SW3 is pressed
{
	state = Door_Open;
		}
	
else
{
  state = Cooking;
}
		break;



	
		  Pause:		
if (SW1 =0)                      //SW1 is pressed the first time
{	
    if ( SW1 =0)                 //SW1 is pressed second time
	{
		state = IDLE;
	}
	 else if ( SW2 =0)             //SW2 is pressed
	 {		 
	state = Cooking;
	 }
 }
else
{
  state = Pause;
}	
			
		break;

		  
	Door_Open:
		if (SW3 = 0) {
			if (SW1 = 0)             //SW1 is pressed
			{
				state = Door_Open;
			}
			else if (SW2 = 0)  //SW2 is pressed
			{
				state = Cooking;
			}

			else
			{
				state = Door_Open; // loop in state door open
			}
		}

    break;
         
    }
}
}