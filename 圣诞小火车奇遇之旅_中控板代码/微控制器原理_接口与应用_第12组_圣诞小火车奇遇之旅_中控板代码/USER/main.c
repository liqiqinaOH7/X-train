#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "lcd.h"
#include "usmart.h"
#include "rtc.h"
#include "gpio.h"
#include "read.h"
#include "speed.h"
#include "train_display.h"
#include "time_display.h"
#include "timer.h"
#include "train_set.h"
#include "key.h"
#include "touch.h"
#include "24cxx.h"
#include "cover.h"
/************************************************
 ALIENTEK ս��STM32F103������ ʵ��15
 RTCʵ��-HAL�⺯����
 ����֧�֣�www.openedv.com
 �Ա����̣� http://eboard.taobao.com
 ��ע΢�Ź���ƽ̨΢�źţ�"����ԭ��"����ѻ�ȡSTM32���ϡ�
 �������������ӿƼ����޹�˾
 ���ߣ�����ԭ�� @ALIENTEK
************************************************/

int main(void)
{
	u8 key;
	int flag = 0;
	HAL_Init();						// ��ʼ��HAL��
	Stm32_Clock_Init(RCC_PLL_MUL9); // ����ʱ��,72M
	delay_init(72);					// ��ʼ����ʱ����
	uart_init(9600);				// ��ʼ������
	LED_Init();						// ��ʼ��LED
	LCD_Init();						// ��ʼ��LCD FSMC�ӿ�
	usmart_dev.init(84);			// ��ʼ��USMART
	RTC_Init();						// ��ʼ��RTC
	GPIO_Init();					// ��ʼ��GPIO
	KEY_Init();						// ��ʼ������
	// MX_USART2_UART_Init();	//��ʼ������2
	TIM3_Init(1000 - 1, 72 - 1); // 1ms clock

	while (RTC_Init()) // RTC��ʼ��	��һ��Ҫ��ʼ���ɹ�
	{
		LCD_ShowString(30, 266, 200, 16, 16, "RTC ERROR!   ");
		delay_ms(800);
		LCD_ShowString(30, 266, 200, 16, 16, "RTC Trying...");
	}
	//	//��ʾʱ��
	//	LCD_ShowString(40,302,200,16,16,"    -  -     ");
	//	LCD_ShowString(60,284,200,16,16,"  :  :  ");

	while (1)
	{
		//		printf("1");
		show_picture(0, 0, 240, 320, (u16 *)gImage_cover);
		key = KEY_Scan(0); // ����ɨ��
		if (key == WKUP_PRES && flag == 0)
		{
			LCD_Clear(WHITE);
			speed_Init();
			while (flag == 0)
			{
				time_display();
				cal_speed_pre();
				speed_display();
				read_signal();//Arriving time display is here
				key = KEY_Scan(0);
				if (key == WKUP_PRES)
					break;
			}
			flag = 1;
		}
		else if (key == WKUP_PRES && flag == 1)
		{
			LCD_Clear(WHITE);
			LCD_DrawRectangle(2, 34, 238, 252);	 // �źŵƱ߿�
			LCD_DrawRectangle(2, 252, 238, 280); // �ٶȱ߿�
			tp_dev.init();						 // ��������ʼ��
			while (flag == 1)
			{
				read_signal2();
				time_display();
				train_set();
				light_set();
				speed_set();
				key = KEY_Scan(0);
				if (key == WKUP_PRES)
					break;
			};
			flag = 0;
		}

		//		if(t!=calendar.sec)
		//		{
		//			t=calendar.sec;
		//			LCD_ShowNum(40,302,calendar.w_year,4,16);
		//			LCD_ShowNum(80,302,calendar.w_month,2,16);
		//			LCD_ShowNum(104,302,calendar.w_date,2,16);
		//			switch(calendar.week)
		//			{
		//				case 0:
		//					LCD_ShowString(136,302,200,16,16,"Sunday   ");
		//					break;
		//				case 1:
		//					LCD_ShowString(136,302,200,16,16,"Monday   ");
		//					break;
		//				case 2:
		//					LCD_ShowString(136,302,200,16,16,"Tuesday  ");
		//					break;
		//				case 3:
		//					LCD_ShowString(136,302,200,16,16,"Wednesday");
		//					break;
		//				case 4:
		//					LCD_ShowString(136,302,200,16,16,"Thursday ");
		//					break;
		//				case 5:
		//					LCD_ShowString(136,302,200,16,16,"Friday   ");
		//					break;
		//				case 6:
		//					LCD_ShowString(136,302,200,16,16,"Saturday ");
		//					break;
		//			}
		//			LCD_ShowNum(60,284,calendar.hour,2,16);
		//			LCD_ShowNum(84,284,calendar.min,2,16);
		//			LCD_ShowNum(108,284,calendar.sec,2,16);
		//			LED0=!LED0;
		//		}
		//		delay_ms(10);
	};
}
