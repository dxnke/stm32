#include "moto.h"
  /**************************************************************************
���ߣ�ƽ��С��֮��
�ҵ��Ա�С�꣺http://shop114407458.taobao.com/
**************************************************************************/
void MiniBalance_Motor_Init(void)          //��ʼ�����Ƶ�������IO
{
	GPIO_InitTypeDef GPIO_InitStruct;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);  //ʹ��GPIOB��ʱ��

	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;         //�������
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_12|GPIO_Pin_13;   //PB12 PB13
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStruct);
}
void MiniBalance_PWM_Init(u16 arr,u16 psc) //��ʼ��pwm�������
{		 	

	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
	TIM_OCInitTypeDef TIM_OCInitStruct;
	GPIO_InitTypeDef GPIO_InitStruct;                             

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);   //ʹ�ܶ�ʱ��3ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);  //ʹ��GPIOB��ʱ��

	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;          //�������
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_1;                //PB1
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStruct);

	TIM_TimeBaseInitStruct.TIM_Period = arr;              //�趨�������Զ���װֵ 
	TIM_TimeBaseInitStruct.TIM_Prescaler  = psc;          //�趨Ԥ��Ƶ��
	TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;//TIM���ϼ���ģʽ
	TIM_TimeBaseInitStruct.TIM_ClockDivision = 0;         //����ʱ�ӷָ�
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseInitStruct);       //��ʼ����ʱ��

	TIM_OCInitStruct.TIM_OCMode = TIM_OCMode_PWM1;             //ѡ��PWM1ģʽ
	TIM_OCInitStruct.TIM_OutputState = TIM_OutputState_Enable; //�Ƚ����ʹ��
	TIM_OCInitStruct.TIM_Pulse = 0;                            //���ô�װ�벶��ȽϼĴ���������ֵ
	TIM_OCInitStruct.TIM_OCPolarity = TIM_OCPolarity_High;     //�����������
	TIM_OC4Init(TIM3,&TIM_OCInitStruct);                       //��ʼ������Ƚϲ���

	TIM_OC4PreloadConfig(TIM3,TIM_OCPreload_Enable);   //CH4ʹ��Ԥװ�ؼĴ���

	TIM_ARRPreloadConfig(TIM3, ENABLE);                //ʹ��TIM3��ARR�ϵ�Ԥװ�ؼĴ���

	TIM_Cmd(TIM3,ENABLE);                              //ʹ�ܶ�ʱ��3
} 

