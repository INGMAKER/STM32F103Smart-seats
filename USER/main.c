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
	delay_init();	    	 //��ʱ������ʼ��	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	KEY_Init();         	//��ʼ���밴�����ӵ�Ӳ���ӿ�
	uart_init(115200);    //��������
	TIM3_PWM_Init(20000-1,72-1);    //��ʱ��arr �� pscֵ��ȷ��

	while(1)
	{	    
//		
//		delay_ms(10);//����
	if(Res=='1')	  //����KEY2
	{
		TIM_SetCompare2(TIM3,1500); //45��,1ms
	}
	else if(Res== '0')	  //����KEY2
	{
		TIM_SetCompare2(TIM3,2500); //45��,1ms
	}	
	else if(Res=='2')	  //����KEY2
	{
		TIM_SetCompare3(TIM3,1500); //45��,1ms 
	}	
	else if(Res=='3')	  //����KEY2
	{
		TIM_SetCompare3(TIM3,2500); //45��,1ms  
	}
	else TIM_SetCompare2(TIM3,1500); 
 }

}






