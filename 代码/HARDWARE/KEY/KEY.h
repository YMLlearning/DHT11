#ifndef  __KEY_H__
#define  __KEY_H__

#include "stm32f10x.h"                  // Device header


void KEY_Init(void);
uint8_t KEY1_Get(void);//返回键值为1或2，默认为0
uint8_t KEY2_Get(void);//返回键值为1或2，默认为0
uint8_t KEY3_Get(void);


#endif      
