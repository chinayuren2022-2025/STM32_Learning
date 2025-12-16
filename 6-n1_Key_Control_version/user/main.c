#include "stm32f10x.h"
#include "Delay.h"
#include "OLED.h"
#include "PWM.h"
#include "IC.h"
#include "key.h"

extern volatile uint8_t g_Key0_Pressed_Flag;
extern volatile uint8_t g_Key1_Pressed_Flag;
volatile uint64_t PSC;
volatile uint32_t Duty;

int main(void)
{
	OLED_Init();
	PWM_Init();
	IC_Init();
	Key_Init();
	
	OLED_ShowString(1, 1, "Freq:00000Hz");
	OLED_ShowString(2, 1, "Duty:00%");
	
	PSC = 720 - 1;								 // Freq = 72M / (PSC + 1) / (ARR + 1)
	Duty = 80;										//Duty = CCR / (ARR + 1)
	
	
	while (1)
	{
			if (g_Key0_Pressed_Flag == 1)
		{
			g_Key0_Pressed_Flag = 0;
			if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_0) == 0)
			{
				PSC += 100;
			}
		}
		
		if (g_Key1_Pressed_Flag == 1)
		{
			g_Key1_Pressed_Flag = 0;
			if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1) == 0)
			{
				Duty += 1;
				if (Duty == 99)
				{
					Duty = 1;
				}
			}
		}
		
		PWM_SetPrescaler(PSC);
		PWM_SetCompare1(Duty);	

		OLED_ShowNum(1, 6, IC_GetFreq(), 5);
		OLED_ShowNum(2, 6, IC_GetDuty(), 2);
		OLED_ShowNum(3, 6, PSC, 5);
		OLED_ShowNum(4, 6, Duty, 5);

	}
	
}
