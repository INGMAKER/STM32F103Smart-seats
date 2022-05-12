#include "exti.h"
#include "led.h"
#include "key.h"
#include "delay.h"
#include "usart.h"
#include "beep.h"

//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK战舰STM32开发板
//外部中断 驱动代码	   
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//修改日期:2012/9/3
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 广州市星翼电子科技有限公司 2009-2019
//All rights reserved									  
//////////////////////////////////////////////////////////////////////////////////   
//外部中断0服务程序
u8 Res;

void EXTIX_Init(void)
{
 
		EXTI_InitTypeDef EXTI_InitStructure;
		NVIC_InitTypeDef NVIC_InitStructure;

    KEY_Init();	 //	按键端口初始化

  	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);	//使能复用功能时钟

			//GPIOE.2 中断线以及中断初始化配置   下降沿触发
  	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE,GPIO_PinSource2);
		GPIO_EXTILineConfig(GPIO_PortSourceGPIOE,GPIO_PinSource3);
	
	
		EXTI_InitStructure.EXTI_Line=EXTI_Line3;	//KEY3	
  	EXTI_InitStructure.EXTI_Line=EXTI_Line2;	//KEY2
  	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	
  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
  	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  	EXTI_Init(&EXTI_InitStructure);	 	//根据EXTI_InitStruct中指定的参数初始化外设EXTI寄存器

  	NVIC_InitStructure.NVIC_IRQChannel = EXTI2_IRQn;			//使能按键WK_UP所在的外部中断通道
  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;	//抢占优先级2， 
  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;					//子优先级3
  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//使能外部中断通道
  	NVIC_Init(&NVIC_InitStructure); 
 
		NVIC_InitStructure.NVIC_IRQChannel = EXTI3_IRQn;			//使能按键WK_UP所在的外部中断通道
  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 3;	//抢占优先级2， 
  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;					//子优先级3
  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//使能外部中断通道
  	NVIC_Init(&NVIC_InitStructure); 
 
}
//外部中断2服务程序
void EXTI_IRQHandler(void)
{
	delay_ms(10);//消抖
	if(Res==1)	  //按键KEY2
	{
		TIM_SetCompare2(TIM3,1500); //45度,1ms
		delay_ms(1000); 
	}
	if(Res==0)	  //按键KEY2
	{
		TIM_SetCompare2(TIM3,2500); //45度,1ms
		delay_ms(1000); 
	}	
	if(Res==2)	  //按键KEY2
	{
		TIM_SetCompare3(TIM3,1500); //45度,1ms
		delay_ms(1000); 
	}	
	if(Res==3)	  //按键KEY2
	{
		TIM_SetCompare3(TIM3,2500); //45度,1ms
		delay_ms(1000); 
	}	
	EXTI_ClearITPendingBit(EXTI_Line2);  //清除LINE2上的中断标志位
	EXTI_ClearITPendingBit(EXTI_Line3);
}