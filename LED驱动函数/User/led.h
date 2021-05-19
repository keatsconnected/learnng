#ifndef __LED_H__
#define __LED_H__

#include "sys.h"

#define LED_GPIO_PIN6 GPIO_Pin_6
#define LED_GPIO_PIN8 GPIO_Pin_8
#define LED_GPIO_PIN9 GPIO_Pin_9
#define LED_GPIO_PORTG GPIOG
#define LED_GPIO_PORTA GPIOA
#define LED_GPIO_PORTB GPIOB
#define LED_GPIO_CLKA RCC_APB2Periph_GPIOA
#define LED_GPIO_CLKB RCC_APB2Periph_GPIOB
#define LED_GPIO_CLKG RCC_APB2Periph_GPIOG


void LED_Init(void);
void LED_GPIO_High(void);
void LED_GPIO_Low(void);

#endif
