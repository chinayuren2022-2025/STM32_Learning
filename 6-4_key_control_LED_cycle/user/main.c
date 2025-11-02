#include "stm32f10x.h"
#include "OLED.h"
#include "PWM.h"
#include "LED.h"
#include "encoder.h"

volatile uint8_t ModeNum = 0;
extern volatile uint8_t g_Key_Pressed_Flag;

int main(void)
{
	OLED_Init();
	PWM_Init();
	Key_Init();


	
	while (1)
		{
		if (g_Key_Pressed_Flag == 1)
		{
			g_Key_Pressed_Flag = 0;
			if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_0) == 0)
			{
				ModeNum ++;
				if (ModeNum == 7)
		{
			ModeNum = 1;
		}
			}
		}
	if(ModeNum == 1)
	{
		LED1_Mode_1();
	}		
	OLED_ShowNum (1, 1, ModeNum, 4);
	if(ModeNum == 2)
	{
		LED1_Mode_2();
	}
	if(ModeNum == 3)
	{
		LED1_Mode_3();
	}
	if (ModeNum == 4)
	{
		LED1_Mode_4();
	}
	if (ModeNum == 5)
	{
		LED1_Mode_5();
	}
	if (ModeNum == 6)
	{
		LED1_Mode_6();
	}

	}
	
}
