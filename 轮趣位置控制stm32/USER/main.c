#include "sys.h"
  /**************************************************************************
���ߣ�ƽ��С��֮��
�ҵ��Ա�С�꣺http://shop114407458.taobao.com/

**************************************************************************/

int Encoder,Position=10000,Target_Position=10000; //���������������
int Moto;//���PWM���� Ӧ��Motor�� ��Moto�¾�
float Position_KP=120,Position_KI=0.1,Position_KD=500; //PIDϵ��

int main(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //�����жϷ���Ϊ2
	delay_init(72);                 //=====��ʱ��ʼ��
	uart_init(128000);              //=====��ʼ������1
	MiniBalance_Motor_Init();       //=====��ʼ�����Ƶ�������IO
	MiniBalance_PWM_Init(7199,0);   //=====��ʼ��PWM 10KHZ������������� 
	KEY_Init();						//=====������ʼ��
	Encoder_Init_TIM4();            //=====��ʼ����������TIM4�ı������ӿ�ģʽ�� 
	Timer1_Init(99,7199);           //=====��ʱ�жϳ�ʼ�� 
	delay_ms(100);
	while(1)
		{
//			printf("Position: %d  ",Position);		//��ǰ������λ�ô�ӡ������
//			printf("Moto: %d  ",Moto);				//��ǰ��PID�����������ӡ������
//			printf("Target: %d\r\n",Target_Position);//��ǰ��λ��Ŀ��ֵ��ӡ������
//			delay_ms(200);
			
			DataScope();//Minibalance��λ����ʾ����
			delay_ms(50);//��λ����Ҫ����ʱ���ϸ�50ms
		} 
}

