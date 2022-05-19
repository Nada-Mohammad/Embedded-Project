#define NVIC_ST_CTRL_R          (*((volatile unsigned long *)0xE000E010))
#define NVIC_ST_RELOAD_R        (*((volatile unsigned long *)0xE000E014))
#define NVIC_ST_CURRENT_R       (*((volatile unsigned long *)0xE000E018))
#include "tm4c123gh6pm.h"


void SysTick_wait ( unsigned long delay)
{while((SYSCTL_RCGCGPIO_R&0x20)==0);
GPIO_PORTF_LOCK_R =0x4C4F434B;

	NVIC_ST_CTRL_R=0x00;                           //disable until configuration
	NVIC_ST_RELOAD_R= delay-1;                     //input the value of the required delay in main
	NVIC_ST_CURRENT_R=0;
	NVIC_ST_CTRL_R=0x05;                           //Enable the ctrl register with 1 in bit zero and bit 2 which defines the clock is the same as the bus clock and the interrupt is disabled
	while((NVIC_ST_CTRL_R&0x00010000)==0){
	}	                                           	//delay for until the count bit equals 1 
}
void generic_delay (unsigned long Time)        //to create a delay can't be defined directly in reload value
{
	int i;
	for( i=0;i<Time;i++)
	{ 
	SysTick_wait(80000); //1ms delay 
	}		
}
