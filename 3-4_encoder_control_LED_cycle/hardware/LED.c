#include "stm32f10x.h"
#include "Delay.h"

extern int Num;
void LED_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	GPIO_SetBits(GPIOA, GPIO_Pin_1);
}
void LED1_ON(void)
{
	GPIO_ResetBits (GPIOA, GPIO_Pin_1);	
}

void LED1_OFF(void)
{
	GPIO_SetBits (GPIOA, GPIO_Pin_1);
}
void LED1_Mode_1(void)
{
	while(Num == 1)
	{
	LED1_ON ();
	Delay_ms (100);
	LED1_OFF ();
	Delay_ms (100);
	}
}
void LED1_Mode_2(void)
{
	while(Num == 2)
	{
	LED1_ON ();
	Delay_ms (500);
	LED1_OFF ();
	Delay_ms (500);
	}
}
void LED1_Mode_3(void)
{
	while (Num == 3)
	{
	LED1_ON ();
	}
}
// void Mode_Go(void)
//{
//	extern int ModeNum;
//	if (ModeNum==3)
//	{
//		ModeNum = 1;
//	}
//	else
//	{
//		ModeNum+=1;
//	}
//}