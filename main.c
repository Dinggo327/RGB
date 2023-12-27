#include "stm32f10x.h"
#include "argb.h"
#include "delay.h"


#define Nums 11


void RGB_LED_Red(void)
{
	 uint8_t i;
	
	for(i=0;i<Nums;i++)
		{
			RGB_LED_Write_24Bits(0, 0xff, 0);
	}
}

void RGB_LED_Green(void)
{
	uint8_t i;

	for(i=0;i<Nums;i++)
		{
			RGB_LED_Write_24Bits(0xff, 0, 0);
	}
}

void RGB_LED_Blue(void)
{
	uint8_t i;

	for(i=0;i<Nums;i++)
		{
			RGB_LED_Write_24Bits(0, 0, 0xff);
	}
}


void main(void)
{
	
	delay_init();
	
	initARGB();
	
	while(1)
	{
	  RGB_LED_Red();
		
	  delay_ms(1000);
	 
		
      RGB_LED_Green();
	  delay_ms(1000);
	 
		
      RGB_LED_Blue();
		
	  delay_ms(1000);
	}

}
