#include "stm32f10x.h"
#include "Delay.h"
#include "LED.h"

extern int ModeNum;
void Key_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz ;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
}

void Key_Go(void)
{
	if (GPIO_ReadInputDataBit (GPIOB, GPIO_Pin_1) == 0)
	{
		while (GPIO_ReadInputDataBit (GPIOB, GPIO_Pin_1) == 0)
		Delay_ms (20);
		Mode_Go();
	}
}
