#include "stm32f10x.h"
#include "Delay.h"
#include "PWM.h"


uint8_t i;


void LED1_ON(void)
{
	PWM_SetCompare1(100);
}

void LED1_OFF(void)
{
	PWM_SetCompare1(0);
}

void LED1_Mode_1(void)  //快闪
{
	LED1_ON ();
	Delay_ms (20);
	LED1_OFF ();
	Delay_ms (20);
}

void LED1_Mode_2(void)  //慢闪
{
	LED1_ON ();
	Delay_ms (50);
	LED1_OFF ();
	Delay_ms (50);
}

void LED1_Mode_3(void)  //常亮
{
	LED1_ON ();
}
void LED1_Mode_4(void)  //关闭
{	
	LED1_OFF();
}

void LED1_Mode_5(void)  //快呼吸灯
{
			for (i = 1; i <= 100; i ++)
		{
			PWM_SetCompare1(i);
			Delay_ms(5);
		}
				for (i = 1; i <= 100; i ++)
		{
			PWM_SetCompare1(100-i);
			Delay_ms(5);
		}
}

void LED1_Mode_6(void)  //慢呼吸灯
{
			for (i = 1; i <= 100; i ++)
		{
			PWM_SetCompare1(i);
			Delay_ms(20);
		}
				for (i = 1; i <= 100; i ++)
		{
			PWM_SetCompare1(100-i);
			Delay_ms(20);
		}
}

