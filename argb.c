#include "argb.h"
#include "stm32f10x.h"


#define 	RGB_LED 	GPIO_Pin_6
#define		RGB_LED_HIGH	(GPIO_SetBits(GPIOB,RGB_LED))
#define 	RGB_LED_LOW		(GPIO_ResetBits(GPIOB,RGB_LED))

void initARGB(void)                                             //初始化IO
{
    GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB ,ENABLE);//GPIOC
	
	GPIO_InitStructure.GPIO_Mode=  GPIO_Mode_Out_PP;//SET IN/OUT
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_6;        //SET GPIO
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;//SET SPEED
	GPIO_SetBits(GPIOB,GPIO_Pin_6);
	
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	
	
}



void RGB_LED_Write0(void)                                            //寫0
{
	RGB_LED_HIGH;
	
	__nop();__nop();__nop();__nop();__nop();__nop();
	
	RGB_LED_LOW;
	
	__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();
	__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();
	__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();
	__nop();__nop();
}



void RGB_LED_Write1(void)                                                //寫1
{
	RGB_LED_HIGH;
	__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();
	__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();
	__nop();__nop();
	RGB_LED_LOW;
	__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();
	
	__nop();__nop();
}


void RGB_LED_Reset(void)                                                  //復位
{
	RGB_LED_LOW;
	delay_us(80);
}


void RGB_LED_Write_Byte(uint8_t byte)                                     //寫字節
{
	uint8_t i;

	for(i=0;i<8;i++)
		{
			if(byte&0x80)
				{
					RGB_LED_Write1();
			}
			else
				{
					RGB_LED_Write0();
			}
		byte <<= 1;
	}
}

void RGB_LED_Write_24Bits(uint8_t green,uint8_t red,uint8_t blue)        
{
	RGB_LED_Write_Byte(green);
	
	RGB_LED_Write_Byte(red);
	
	RGB_LED_Write_Byte(blue);
	
}









