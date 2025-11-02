#include "stm32f10x.h"
#include "Delay.h"
#include "OLED.h"
#include "encoder.h"
#include "LED.h"

	int ModeNum = 0;
	int main(void)
{

	OLED_Init();
	LED_Init ();
	OLED_ShowString(1, 1, "Num:");
	Encoder_Init ();
	
	while (1)
	{
	OLED_ShowNum(1,5,ModeNum,5);
	OLED_ShowString(1, 1, "Num:");
	switch(ModeNum)
		{
			case 1:
				LED1_Mode_1 ();
				break;
			case 2:
				LED1_Mode_2 ();
				break;
			case 3:
				LED1_Mode_3 ();
				break;
			case 4:
				LED1_Mode_4 ();
				break;
		}
	}
	}
	

