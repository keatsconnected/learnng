#include "sys.h"

int main(void)
{
	delay_Init();
	led_Init();
	
	while(1)
	{
		led_ch(LED1);
		delay_ms(1000);
		led_ch(LED1);
		delay_ms(1000);
		led_ch(LED2);
		delay_ms(1000);
		led_ch(LED2);
		delay_ms(1000);	
	}
}
