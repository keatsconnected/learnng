#ifndef __LED_H__
#define __LED_H__

#include "sys.h"

#define LED1 (GPIO_Pin_6 | (1UL<<16))
#define LED2 (GPIO_Pin_8 | (2UL<<16))
#define LED3 (GPIO_Pin_8 | (3UL<<16))
#define LED4 (GPIO_Pin_9 | (4UL<<16))
#define LED1_CLOCK RCC_APB2Periph_GPIOG
#define LED2_CLOCK RCC_APB2Periph_GPIOA
#define LED3_CLOCK RCC_APB2Periph_GPIOB
#define LED4_CLOCK RCC_APB2Periph_GPIOB
#define LED1_PORT GPIOG
#define LED2_PORT GPIOA
#define LED3_PORT GPIOB
#define LED4_PORT GPIOB
#define LED1_PIN GPIO_Pin_6
#define LED2_PIN GPIO_Pin_8
#define LED3_PIN GPIO_Pin_8
#define LED4_PIN GPIO_Pin_9

void led_Init(void);
void led_ch(uint32_t LEDx);
void led_on(uint32_t LEDx);
void led_off(uint32_t LEDx);

#endif
