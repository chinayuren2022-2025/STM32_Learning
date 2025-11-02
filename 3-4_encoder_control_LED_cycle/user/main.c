#include "stm32f10x.h"
#include "Delay.h"
#include "OLED.h"
#include "encoder.h"
#include "LED.h"
#include "key.h"

int16_t Num;

int main(void)
{
	OLED_Init();
	LED_Init();
	Encoder_Init ();
	OLED_ShowString(1, 1, "Num:");

	while (1)
	{
		Num += Encoder_Get();
		OLED_ShowSignedNum(1, 5, Num, 5);
    	LED1_OFF();
		if (Num == 1)
		{
			LED1_Mode_1 ();
			Num += Encoder_Get();
		}
		Num += Encoder_Get();
		OLED_ShowSignedNum(1, 5, Num, 5);
		if (Num == 2)
		{
			LED1_Mode_2 ();
		}
		Num += Encoder_Get();
		OLED_ShowSignedNum(1, 5, Num, 5);
		if (Num == 3)
		{
			LED1_Mode_3 ();
		}
		Num += Encoder_Get();
		OLED_ShowSignedNum(1, 5, Num, 5);
	}
}

