#include "stm32f10x.h"

#include "delay.h"
#include "oled.h"
#include "stdio.h"
#include "string.h"
#include "KEY.h"
#include "beep.h"
#include "usart.h"
#include "led.h"
#include "dht11.h"

u8 humidityH;	  //湿度整数部分
u8 humidityL;	  //湿度小数部分
u8 temperatureH;   //温度整数部分
u8 temperatureL;   //温度小数部分

int main(void)
{

	delay_init();
	Usart1_Init(115200);

	OLED_Init();
	OLED_Display_On();
	OLED_Clear();
	DHT11_Init();
	LED_GPIO_Config();

	delay_ms(10);
	while(1)
	{
		  DHT11_Read_Data(&humidityH,&humidityL,&temperatureH,&temperatureL);
			UsartPrintf(USART1,"湿度：%d %d   温度 %d %d \r\n",humidityH,humidityL,temperatureH,temperatureL);//串口发送函数
			OLED_ShowString(0,3,(uint8_t *)("RED:"),5);
			//OLED_ShowNumber(45,3,rgb.r,3,10);
			
			OLED_ShowString(0,4,(uint8_t *)("GREEN:"),5);
			//OLED_ShowNumber(45,4,rgb.g,3,10);
					
			OLED_ShowString(0,5,(uint8_t *)"BLUE:",8);
			//OLED_ShowNumber(45,5,rgb.b,3,8);
			LED=0;
			//printf("R=%d G=%d B=%d C=%d\r\n",rgb.r,rgb.g,rgb.b,rgb.c);//使用串口打印
		  delay_ms(1000);
	}
}

