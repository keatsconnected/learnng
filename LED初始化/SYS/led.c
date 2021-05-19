#include "led.h"

//LED标志，1表示LED灯处于亮着状态，0表示LED灯处于熄灭状态
static uint8_t flag1 = 1;
static uint8_t flag2 = 1;
static uint8_t flag3 = 1;
static uint8_t flag4 = 1;

//配置LED引脚并全部熄灭
void led_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(LED1_CLOCK | LED2_CLOCK | LED3_CLOCK, ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = LED1_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(LED1_PORT, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = LED2_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(LED2_PORT, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = LED3_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(LED3_PORT, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = LED4_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(LED4_PORT, &GPIO_InitStructure);
	
	led_off(LED1);
	led_off(LED2);
	led_off(LED3);
	led_off(LED4);
}

//点亮LED函数，并将对应LED的标志位置1，使得在翻转的时候获取当前状态
void led_on(uint32_t LEDx)
{
	switch(LEDx)
	{
		case LED1: GPIO_ResetBits(LED1_PORT, LED1_PIN), flag1 = 1; break;
		case LED2: GPIO_ResetBits(LED2_PORT, LED2_PIN), flag2 = 1; break;
		case LED3: GPIO_ResetBits(LED3_PORT, LED3_PIN), flag3 = 1; break;
		case LED4: GPIO_ResetBits(LED4_PORT, LED4_PIN), flag4 = 1; break;
		default: break;
	}
}

//熄灭LED函数，并将对应LED的标志位置0，使得在翻转的时候获取当前状态
void led_off(uint32_t LEDx)
{
	switch(LEDx)
	{
		case LED1: GPIO_SetBits(LED1_PORT, LED1_PIN); flag1 = 0; break;
		case LED2: GPIO_SetBits(LED2_PORT, LED2_PIN); flag2 = 0; break;
		case LED3: GPIO_SetBits(LED3_PORT, LED3_PIN); flag3 = 0; break;
		case LED4: GPIO_SetBits(LED4_PORT, LED4_PIN); flag4 = 0; break;
		default: break;
	}
}

//状态翻转
void led_ch(uint32_t LEDx)
{

	if(LEDx == LED1)
	{
		if(flag1)
			led_off(LED1);
		else
			led_on(LED1);
	}
	if(LEDx == LED2)
	{
		if(flag2)
			led_off(LED2);
		else
			led_on(LED2);
	}
	if(LEDx == LED3)
	{
		if(flag3)
			led_off(LED3);
		else
			led_on(LED3);
	}
	if(LEDx == LED4)
	{
		if(flag4)
			led_off(LED4);
		else
			led_on(LED4);
	}
}
