#include"key.h"
#include"delay.h"

void KEY_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;//定义GPIO初始化结构体
	
	RCC_APB2PeriphClockCmd(KEY_GPIO_CLK, ENABLE);//配置时钟
	
	GPIO_InitStruct.GPIO_Pin = KEY_GPIO_PIN;//配置端口
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;
	//GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(KEY_GPIO_PORT, &GPIO_InitStruct);
}

uint8_t KEY_Scan(void)
{
	static uint8_t flag = 1;
	if(!((uint32_t)0x04 & *(uint32_t*)0x40011808) && flag)//检测按键是否按下
	{	
		delay_ms(10);//延时10ms
		flag = 0;//记录当前按键，防止连续读取按键值
		if(!((uint32_t)0x0004 & *(uint32_t*)0x40011808))//再次检测按键
		{
			return 1;//确认按键按下，执行动作
		}
	}
	else if((uint32_t)0x0004 & *(uint32_t*)0x40011808)//按键未被按下
	{
		flag = 1;
	}
	return 0;
}
