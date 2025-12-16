#include "stm32f10x.h"                  // Device header
#include "Delay.h"

volatile uint16_t Key_Count;
volatile uint8_t g_Key0_Pressed_Flag;
volatile uint8_t g_Key1_Pressed_Flag;

void Key_Init(void)
{
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB, ENABLE );
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_AFIO, ENABLE );
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init( GPIOB, &GPIO_InitStructure );
	
	GPIO_EXTILineConfig( GPIO_PortSourceGPIOB, GPIO_PinSource0 );
	GPIO_EXTILineConfig( GPIO_PortSourceGPIOB, GPIO_PinSource1);

	
	EXTI_InitTypeDef EXTI_InitStructure; 
	EXTI_InitStructure.EXTI_Line = EXTI_Line0 | EXTI_Line1;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_Init( &EXTI_InitStructure );
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_Init ( &NVIC_InitStructure );
	
	NVIC_InitStructure.NVIC_IRQChannel = EXTI1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
	NVIC_Init ( &NVIC_InitStructure );

	
}

// uint8_t Key_GetNum(void)
//{
//	uint8_t KeyNum = 0;
	//if ( GPIO_ReadInputDataBit( GPIOB, GPIO_Pin_0 ) == 0 )
	//{
		//Delay_ms(20);
		//while ( GPIO_ReadInputDataBit( GPIOB, GPIO_Pin_0 ) == 0 );
		//Delay_ms(20);
		//KeyNum = 1;
//	}
//	return KeyNum;
//}

uint16_t Key_Get(void)
{
	volatile uint16_t Temp;
	Temp = Key_Count;
	Key_Count = 0;
	return Temp;
}

void EXTI0_IRQHandler(void)
{
	if(EXTI_GetITStatus (EXTI_Line0 ) == SET)
	{
		if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_0) == 0)
		{
			g_Key0_Pressed_Flag = 1;
		}
	}
		EXTI_ClearITPendingBit (EXTI_Line0);
}

void EXTI1_IRQHandler(void)
{
	if(EXTI_GetITStatus (EXTI_Line1 ) == SET)
	{
		if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1) == 0)
		{
			g_Key1_Pressed_Flag = 1;
		}
	}
		EXTI_ClearITPendingBit (EXTI_Line1);
}

void Test(void)
{
	if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_0) == 0)
	{
		Delay_ms(20);
		if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_0) == 1)
		{

		}
	}
}



