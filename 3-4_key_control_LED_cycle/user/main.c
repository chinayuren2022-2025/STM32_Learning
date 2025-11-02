#include "stm32f10x.h"
#include "Delay.h"
#include "LED.h"
#include "key.h"
#include "OLED.h"

uint8_t ModeNum = 1;
int main(void)
{
	LED_Init ();
	Key_Init ();
	OLED_Init();
		OLED_ShowNum(1,1,ModeNum,5);
	
	while(1)
	{
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
