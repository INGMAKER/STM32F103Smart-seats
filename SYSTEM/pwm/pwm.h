#ifndef __PWM_H
#define __PWM_H
#include "sys.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"

#include "stm32f10x_it.h" 
void TIM3_PWM_Init(u16 arr,u16 psc);


#endif