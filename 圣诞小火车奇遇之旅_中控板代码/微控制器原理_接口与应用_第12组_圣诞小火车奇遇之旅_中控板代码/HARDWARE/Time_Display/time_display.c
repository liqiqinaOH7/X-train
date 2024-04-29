#include "time_display.h"
#include "rtc.h"
#include "lcd.h"
#include "led.h"
#include "delay.h"
void time_display(void)
{
	u8 t;
	LCD_ShowString(40,302,200,16,16,"    -  -     ");	   
	LCD_ShowString(60,284,200,16,16,"  :  :  ");
	if(t!=calendar.sec)
		{
			t=calendar.sec;
			LCD_ShowNum(40,302,calendar.w_year,4,16);									  
			LCD_ShowNum(80,302,calendar.w_month,2,16);									  
			LCD_ShowNum(104,302,calendar.w_date,2,16);	 
			switch(calendar.week)
			{
				case 0:
					LCD_ShowString(136,302,200,16,16,"Sunday   ");
					break;
				case 1:
					LCD_ShowString(136,302,200,16,16,"Monday   ");
					break;
				case 2:
					LCD_ShowString(136,302,200,16,16,"Tuesday  ");
					break;
				case 3:
					LCD_ShowString(136,302,200,16,16,"Wednesday");
					break;
				case 4:
					LCD_ShowString(136,302,200,16,16,"Thursday ");
					break;
				case 5:
					LCD_ShowString(136,302,200,16,16,"Friday   ");
					break;
				case 6:
					LCD_ShowString(136,302,200,16,16,"Saturday ");
					break;  
			}
			LCD_ShowNum(60,284,calendar.hour,2,16);									  
			LCD_ShowNum(84,284,calendar.min,2,16);									  
			LCD_ShowNum(108,284,calendar.sec,2,16);
		}		
}