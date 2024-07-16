#ifndef __LED_H
#define __LED_H	 
#include "sys.h"

#define LED   PAout(1)// PA1
#define EN_A  PBout(2)// PB2

void LED_Init(void);//初始化
void MOTOR_Init(void);//初始化
		 				    
#endif
