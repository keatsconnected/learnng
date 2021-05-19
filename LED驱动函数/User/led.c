#include "led.h"

void LED_Init(void)
{
	//1.定义GPIO初始化结构体
	GPIO_InitTypeDef GPIO_InitStruct;
	//2.配置时钟
	RCC_APB2PeriphClockCmd(LED_GPIO_CLKA|LED_GPIO_CLKB|LED_GPIO_CLKG, ENABLE);
	//3.配置端口
	GPIO_InitStruct.GPIO_Pin = LED_GPIO_PIN6;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz; //50MHz
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP; //推挽输出
	//4.初始化端口
	GPIO_Init(LED_GPIO_PORTG, &GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Pin = LED_GPIO_PIN8;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz; //50MHz
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP; //推挽输出
	GPIO_Init(LED_GPIO_PORTA, &GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin = LED_GPIO_PIN8;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz; //50MHz
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP; //推挽输出
	GPIO_Init(LED_GPIO_PORTB, &GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Pin = LED_GPIO_PIN9;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz; //50MHz
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP; //推挽输出
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
