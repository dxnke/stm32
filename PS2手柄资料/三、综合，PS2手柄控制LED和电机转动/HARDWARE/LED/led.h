#ifndef __LED_H
#define __LED_H	 
#include "sys.h"

#define LED   PAout(1)// PA1
#define EN_A  PBout(2)// PB2

void LED_Init(void);//��ʼ��
void MOTOR_Init(void);//��ʼ��
		 				    
#endif
