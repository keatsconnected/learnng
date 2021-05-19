#include "led.h"

void LED_Init(void)
{
	//1.����GPIO��ʼ���ṹ��
	GPIO_InitTypeDef GPIO_InitStruct;
	//2.����ʱ��
	RCC_APB2PeriphClockCmd(LED_GPIO_CLKA|LED_GPIO_CLKB|LED_GPIO_CLKG, ENABLE);
	//3.���ö˿�
	GPIO_InitStruct.GPIO_Pin = LED_GPIO_PIN6;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz; //50MHz
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP; //�������
	//4.��ʼ���˿�
	GPIO_Init(LED_GPIO_PORTG, &GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Pin = LED_GPIO_PIN8;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz; //50MHz
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP; //�������
	GPIO_Init(LED_GPIO_PORTA, &GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin = LED_GPIO_PIN8;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz; //50MHz
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP; //�������
	GPIO_Init(LED_GPIO_PORTB, &GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Pin = LED_GPIO_PIN9;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz; //50MHz
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP; //�������
	GPIO_Init(LED_GPIO_PORTB, &GPIO_InitStruct);
}

void LED_GPIO_High(void)
{
	GPIO_SetBits(LED_GPIO_PORTG, LED_GPIO_PIN6);
}

void LED_GPIO_Low(void)
{
	GPIO_ResetBits(LED_GPIO_PORTG, LED_GPIO_PIN6);
}
