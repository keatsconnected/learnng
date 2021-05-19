#include "sys.h"

int main(void)
{
	LED_Init();
	delay_init();
	
	while(1)
	{	
		LED_GPIO_High();
		delay_ms(1000);
		LED_GPIO_Low();
		delay_ms(1000);	//—” ±LED…¡À∏
	}
}
