void Buzzer (void){
	GPIO_PORTA_DATA_R|=0X10;
	
}
void Count_Zero(void){     //when timer is zero leds blink for 3 times

	int n;
for(n=0;n<=3;n++){
      Buzzer();
   GPIO_PORTF_DATA_R|=0X0E;   
		SysTick_wait(40000000);
		GPIO_PORTF_DATA_R=	GPIO_PORTF_DATA_R^0X0E; 
	  SysTick_wait(40000000);
		
}
}
void LEDS_On(void){              //leds always on

		GPIO_PORTF_DATA_R|=0X0E;
	
}

void led_blink (void){     //when timer is zero leds blink for 3 times
      	GPIO_PORTF_DATA_R|=0X0E;                  	 
	  generic_delay(150);
	 GPIO_PORTF_DATA_R=	GPIO_PORTF_DATA_R^0X0E;
	  generic_delay(150);
}