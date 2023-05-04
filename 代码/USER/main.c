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

u8 humidityH;	  //ʪ����������
u8 humidityL;	  //ʪ��С������
u8 temperatureH;   //�¶���������
u8 temperatureL;   //�¶�С������

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
			UsartPrintf(USART1,"ʪ�ȣ�%d %d   �¶� %d %d \r\n",humidityH,humidityL,temperatureH,temperatureL);//���ڷ��ͺ���
			OLED_ShowString(0,3,(uint8_t *)("RED:"),5);
			//OLED_ShowNumber(45,3,rgb.r,3,10);
			
			OLED_ShowString(0,4,(uint8_t *)("GREEN:"),5);
			//OLED_ShowNumber(45,4,rgb.g,3,10);
					
			OLED_ShowString(0,5,(uint8_t *)"BLUE:",8);
			//OLED_ShowNumber(45,5,rgb.b,3,8);
			LED=0;
			//printf("R=%d G=%d B=%d C=%d\r\n",rgb.r,rgb.g,rgb.b,rgb.c);//ʹ�ô��ڴ�ӡ
		  delay_ms(1000);
	}
}

