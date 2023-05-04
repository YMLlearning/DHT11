#include "stm32f10x.h" // Device header
#include "KEY.h"
#include "delay.h"

u8 Key1= 0;
u8 Key2= 0;
u8 Key3= 0;

u8 flag= 0;
void KEY_Init(void)

{
	
	GPIO_InitTypeDef GPIO_Initstructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

	GPIO_Initstructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_Initstructure.GPIO_Pin =  GPIO_Pin_14 | GPIO_Pin_15;
	GPIO_Init(GPIOC, &GPIO_Initstructure);
}

uint8_t KEY1_Get(void)
{
	if (GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_13) == 0)
	{
		delay_ms(20);
		while (GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_13) == 0);
		delay_ms(20);
		Key1=1;
	}
	else
		Key1=0;

	return Key1;
}

uint8_t KEY2_Get(void)
{
	if (GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_14) == 0)
	{
		delay_ms(20);
		while (GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_14) == 0);
		delay_ms(20);
		Key2= 1;
	}
	else
		Key2=0;

	return Key2;
}


uint8_t KEY3_Get(void)
{
	if (GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_15) == 0)
	{
		delay_ms(20);
		while (GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_15) == 0);
		delay_ms(20);
		Key3 = 1;
	}
	else
		Key3=0;
	return Key3;
}
