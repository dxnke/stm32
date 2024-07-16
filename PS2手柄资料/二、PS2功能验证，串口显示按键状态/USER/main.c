#include "led.h"
#include "sys.h"
#include "delay.h"
#include "pstwo.h"
#include "usart.h"
 int main(void)
 {		
	int PS2_LX,PS2_LY,PS2_RX,PS2_RY,PS2_KEY;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); 	 //����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	uart_init(115200);	 //���ڳ�ʼ��Ϊ115200
	PS2_Init();					 //PS2�˿ڳ�ʼ��
	LED_Init();			     //LED�˿ڳ�ʼ��
	delay_init();
 	while(1)
	{
  	LED=1;
		
		PS2_LX=PS2_AnologData(PSS_LX);
		PS2_LY=PS2_AnologData(PSS_LY);
		PS2_RX=PS2_AnologData(PSS_RX);
		PS2_RY=PS2_AnologData(PSS_RY);
		PS2_KEY=PS2_DataKey();
		
		printf("PS2_LX=%d    ",PS2_LX);
		printf("PS2_LY=%d    ",PS2_LY);
		printf("PS2_RX=%d    ",PS2_RX);
		printf("PS2_RY=%d    ",PS2_RY);
		printf("PS2_KEY=%d    \r\n",PS2_KEY);
		delay_ms(80);
	}	 
 }

