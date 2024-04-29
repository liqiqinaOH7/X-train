#include "train_display.h"
#include "lcd.h"
#include "pic.h"
void train_display(int n)
{
	//显示图像
	show_picture(80,0,80,66,(u16*)gImage_train);         //黑白火车
	show_picture(17,158,34,35,(u16*)gImage_train_station); //火车站
	//显示运行图
	LCD_DrawRectangle(4,66,236,200);      //运行图边框
	switch(n)
	{
		case 1:
			show_picture(10,109,48,48,(u16*)gImage_train_up); //卡通火车
			LCD_Fill(48,72,96,120,WHITE);
			LCD_Fill(130,72,178,120,WHITE);
			LCD_Fill(178,109,226,157,WHITE);
			LCD_Fill(130,146,178,194,WHITE);
			LCD_Draw_ColorCircle(34,96,13,GREEN);
			LCD_Draw_ColorCircle(116,96,13,GREEN);
			LCD_Draw_FilledUpperSemicircle(202,96,13,YELLOW);
			LCD_Draw_FilledLowerSemicircle(202,96,13,GREEN);
			LCD_Draw_ColorCircle(202,170,13,YELLOW);
			LCD_Draw_ColorCircle(116,170,13,RED);
			break;
		case 2:
			show_picture(48,72,48,48,(u16*)gImage_train_color); //卡通火车
			LCD_Fill(10,109,58,157,WHITE);
			LCD_Fill(130,72,178,120,WHITE);
			LCD_Fill(178,109,226,157,WHITE);
			LCD_Fill(130,146,178,194,WHITE);
			LCD_Draw_ColorCircle(34,96,13,RED);
			LCD_Draw_ColorCircle(116,96,13,GREEN);
			LCD_Draw_ColorCircle(202,96,13,GREEN);
			LCD_Draw_FilledUpperSemicircle(202,170,13,YELLOW);
			LCD_Draw_FilledLowerSemicircle(202,170,13,GREEN);
			LCD_Draw_ColorCircle(116,170,13,YELLOW);
			break;
		case 3:
			show_picture(130,72,48,48,(u16*)gImage_train_color); //卡通火车
			LCD_Fill(48,72,96,120,WHITE);
			LCD_Fill(10,109,58,157,WHITE);
			LCD_Fill(178,109,226,157,WHITE);
			LCD_Fill(130,146,178,194,WHITE);
			LCD_Draw_ColorCircle(34,96,13,YELLOW);
			LCD_Draw_ColorCircle(116,96,13,RED);
			LCD_Draw_ColorCircle(202,96,13,GREEN);
			LCD_Draw_ColorCircle(202,170,13,GREEN);
			LCD_Draw_FilledUpperSemicircle(116,170,13,YELLOW);
			LCD_Draw_FilledLowerSemicircle(116,170,13,GREEN);
			break;
		case 4:
			show_picture(178,109,48,48,(u16*)gImage_train_down); //卡通火车
			LCD_Fill(48,72,96,120,WHITE);
			LCD_Fill(130,72,178,120,WHITE);
			LCD_Fill(10,109,58,157,WHITE);
			LCD_Fill(130,146,178,194,WHITE);
			LCD_Draw_FilledUpperSemicircle(34,96,13,YELLOW);
			LCD_Draw_FilledLowerSemicircle(34,96,13,GREEN);
			LCD_Draw_ColorCircle(116,96,13,YELLOW);
			LCD_Draw_ColorCircle(202,96,13,RED);
			LCD_Draw_ColorCircle(202,170,13,GREEN);
			LCD_Draw_ColorCircle(116,170,13,GREEN);
			break;
		case 5:
			show_picture(130,146,48,48,(u16*)gImage_train_left); //卡通火车
			LCD_Fill(48,72,96,120,WHITE);
			LCD_Fill(130,72,178,120,WHITE);
			LCD_Fill(178,109,226,157,WHITE);
			LCD_Fill(10,109,58,157,WHITE);
			LCD_Draw_ColorCircle(34,96,13,GREEN);
			LCD_Draw_FilledUpperSemicircle(116,96,13,YELLOW);
			LCD_Draw_FilledLowerSemicircle(116,96,13,GREEN);
			LCD_Draw_ColorCircle(202,96,13,YELLOW);
			LCD_Draw_ColorCircle(202,170,13,RED);
			LCD_Draw_ColorCircle(116,170,13,GREEN);
			break;
	}
}