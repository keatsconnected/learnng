#include"key.h"
#include"delay.h"

void KEY_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;//����GPIO��ʼ���ṹ��
	
	RCC_APB2PeriphClockCmd(KEY_GPIO_CLK, ENABLE);//����ʱ��
	
	GPIO_InitStruct.GPIO_Pin = KEY_GPIO_PIN;//���ö˿�
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;
	//GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(KEY_GPIO_PORT, &GPIO_InitStruct);
}

uint8_t KEY_Scan(void)
{
	static uint8_t flag = 1;
	if(!((uint32_t)0x04 & *(uint32_t*)0x40011808) && flag)//��ⰴ���Ƿ���
	{	
		delay_ms(10);//��ʱ10ms
		flag = 0;//��¼��ǰ��������ֹ������ȡ����ֵ
		if(!((uint32_t)0x0004 & *(uint32_t*)0x40011808))//�ٴμ�ⰴ��
		{
			return 1;//ȷ�ϰ������£�ִ�ж���
		}
	}
	else if((uint32_t)0x0004 & *(uint32_t*)0x40011808)//����δ������
	{
		flag = 1;
	}
	return 0;
}
