#include "stm32f10x.h"
#include "Delay.h"
#include "OLED.h"
#include "timer.h"

uint16_t Num;

int main(void)
{
	OLED_Init();
	Timer_Init();
	
	while (1)
	{
		OLED_ShowNum(1, 1, Num, 4);
		OLED_ShowNum(2, 1, TIM_GetCounter(TIM2), 5);
	}
	
}
