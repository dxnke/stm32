#include "control.h"		
  /**************************************************************************
���ߣ�ƽ��С��֮��
�ҵ��Ա�С�꣺http://shop114407458.taobao.com/
**************************************************************************/
/**************************************************************************
�������ܣ����еĿ��ƴ��붼��������
          TIM1���ƵĶ�ʱ�ж� 
**************************************************************************/
int TIM1_UP_IRQHandler(void)  
{    
	if(TIM_GetFlagStatus(TIM1,TIM_FLAG_Update)==SET)//5ms��ʱ�ж�
	{   
		TIM_ClearITPendingBit(TIM1,TIM_IT_Update);                             //===�����ʱ��1�жϱ�־λ	  
		Position=Read_Position(4);                      //===����λ����Ϣ
		Key();                                          //===��������Ŀ��ֵ
		Moto=Position_PID(Position,Target_Position);    //===λ��PID������
		Xianfu_Pwm();                                  //===PWM�޷�
		Set_Pwm(Moto);
		
	}       	
	 return 0;	  
} 


/**************************************************************************
�������ܣ���ֵ��PWM�Ĵ���
��ڲ�����PWM
����  ֵ����
**************************************************************************/
void Set_Pwm(int moto)
{
    	if(moto<0)			AIN2=0,			AIN1=1;
			else 	          AIN2=1,			AIN1=0;
			PWMA=myabs(moto);
}



/**************************************************************************
�������ܣ�����PWM��ֵ 
��ڲ�������
����  ֵ����
**************************************************************************/
void Xianfu_Pwm(void)
{	
	  int Amplitude=7100;    //===PWM������7200 ������7100
	  if(Moto<-Amplitude) Moto=-Amplitude;	
		if(Moto>Amplitude)  Moto=Amplitude;		
}
/**************************************************************************
�������ܣ������޸�����״̬ 
��ڲ�������
����  ֵ����
**************************************************************************/
void Key(void)  
{	
	int tmp,Position_Amplitude=260; 
	tmp=click_N_Double(10);//��ⰴ�� 
	if(tmp==1)Target_Position+=Position_Amplitude;  //��������λ��
	else if(tmp==2)Target_Position-=Position_Amplitude;  //��������λ��
	
 }
/**************************************************************************
�������ܣ�ȡ����ֵ
��ڲ�����int
����  ֵ��unsigned int
**************************************************************************/
int myabs(int a)
{ 		   
	  int temp;
		if(a<0)  temp=-a;  
	  else temp=a;
	  return temp;
}

/**************************************************************************
�������ܣ�λ��ʽPID������
��ڲ���������������λ����Ϣ��Ŀ��λ��
����  ֵ�����PWM
����λ��ʽ��ɢPID��ʽ 
pwm=Kp*e(k)+Ki*��e(k)+Kd[e��k��-e(k-1)]
e(k)������ƫ�� 
e(k-1)������һ�ε�ƫ��  
��e(k)����e(k)�Լ�֮ǰ��ƫ����ۻ���;����kΪ1,2,,k;
pwm�������
**************************************************************************/
int Position_PID (int position,int target)
{ 	
	 static float Bias,Pwm,Integral_bias,Last_Bias;
	 Bias=target-position;                                  //����ƫ��
	 Integral_bias+=Bias;	                                 //���ƫ��Ļ���
	if(Integral_bias>3000)Integral_bias=3000;
	if(Integral_bias<-3000)Integral_bias=-3000;
	 Pwm=Position_KP*Bias+Position_KI*Integral_bias+Position_KD*(Bias-Last_Bias);       //λ��ʽPID������
	 Last_Bias=Bias;                                       //������һ��ƫ�� 
	 return Pwm;                                           //�������
}
