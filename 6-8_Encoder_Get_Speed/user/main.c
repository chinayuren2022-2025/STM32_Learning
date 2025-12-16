#include "stm32f10x.h"
#include "Delay.h"
#include "OLED.h"
#include "timer.h"
#include "encoder.h"

volatile int16_t Speed;

int main(void)
{
	OLED_Init();
	Timer_Init();
	Encoder_Init();
	OLED_ShowString(1, 1, "Speed:");
	
	while (1)
	{
		OLED_ShowSignedNum(1, 7, Speed, 5);
//		OLED_ShowNum(2, 1, TIM_GetCounter(TIM2), 5);
//		Delay_ms(300);
	}
	
}

void TIM2_IRQHandler(void)
{
	if (TIM_GetITStatus(TIM2, TIM_IT_Update) == SET)
	{
		Speed = Encoder_Get();
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
	}
}
