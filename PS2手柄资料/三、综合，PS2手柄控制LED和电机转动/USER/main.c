#include "led.h"
#include "sys.h"
#include "delay.h"
#include "pstwo.h"
#include "usart.h"
 int main(void)
 {		
	int PS2_LX,PS2_LY,PS2_RX,PS2_RY,PS2_KEY;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); 	 //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	uart_init(115200);	 //串口初始化为115200
	PS2_Init();					 //PS2端口初始化
	LED_Init();			     //LED端口初始化
	MOTOR_Init();
	delay_init();
 	while(1)
	{
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
		
		switch(PS2_KEY)
		{
			case 5://按方向上，LED亮，电机转动
				LED=0;
				EN_A=0;
			break;
			
			case 7://按方向下，LED亮，电机不转
				LED=0;
				EN_A=1;
			break;
			
			default://不进行按键操作，LED灭，电机不转
				LED=1;
				EN_A=1;
			break;
		}
	}	 
 }

