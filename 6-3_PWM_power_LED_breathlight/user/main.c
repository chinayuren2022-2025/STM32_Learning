#include "stm32f10x.h"
#include "Delay.h"
#include "OLED.h"
#include "PWM.h"

uint8_t i;

int main(void)
{
	OLED_Init();
	PWM_Init();
	
	while (1)
	{
		OLED_ShowNum(1, 1, i, 4);
		for (i = 1; i <= 100; i ++)
		{
			PWM_SetCompare1(i);
			Delay_ms(10);
		}
				for (i = 1; i <= 100; i ++)
		{
			PWM_SetCompare1(100-i);
			Delay_ms(10);
		}

	}
	
}
