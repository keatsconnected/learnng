#ifndef __KEY_H__
#define __KEY_H__

#include"stm32f10x.h"

#define KEY_GPIO_CLK RCC_APB2Periph_GPIOE
#define KEY_GPIO_PIN GPIO_Pin_2
#define KEY_GPIO_PORT GPIOE

void KEY_GPIO_Config(void);
uint8_t KEY_Scan(void);
	
#endif
