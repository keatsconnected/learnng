#include "leds.h"
#include "delay.h"
#include "led.h"

void LEDS(void)
{
	LED_GPIO_Low();
	delay_ms(1000);
	LED_GPIO_High();
	delay_ms(1000);
}
