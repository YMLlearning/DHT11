#ifndef  __KEY_H__
#define  __KEY_H__

#include "stm32f10x.h"                  // Device header


void KEY_Init(void);
uint8_t KEY1_Get(void);//���ؼ�ֵΪ1��2��Ĭ��Ϊ0
uint8_t KEY2_Get(void);//���ؼ�ֵΪ1��2��Ĭ��Ϊ0
uint8_t KEY3_Get(void);


#endif      
