#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "usart.h"
#include "exti.h"
#include "beep.h"
#include "timer.h"
 

int main(void)
{		
	delay_init();	    	 //延时函数初始化	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	KEY_Init();         	//初始化与按键连接的硬件接口
	uart_init(115200);    //按键配置
	TIM3_PWM_Init(20000-1,72-1);    //定时器arr 跟 psc值的确定

	while(1)
	{	    
//		
//		delay_ms(10);//消抖
	if(Res=='1')	  //按键KEY2
	{
		TIM_SetCompare2(TIM3,1500); //45度,1ms
	}
	else if(Res== '0')	  //按键KEY2
	{
		TIM_SetCompare2(TIM3,2500); //45度,1ms
	}	
	else if(Res=='2')	  //按键KEY2
	{
		TIM_SetCompare3(TIM3,1500); //45度,1ms 
	}	
	else if(Res=='3')	  //按键KEY2
	{
		TIM_SetCompare3(TIM3,2500); //45度,1ms  
	}
	else TIM_SetCompare2(TIM3,1500); 
 }

}






