#include "stm32f1xx_hal.h"
#include "train_set.h"
#include "lcd.h"
#include "touch.h"
#include "24cxx.h"
#include "read.h"
//#include "pic.h"
int i=0;
int j=0;
int speed=50;
void train_set(void)
{
	int i;
	u16 space=44;   //ÐÐ¾à
	u16 width=75;   //ÁÐ¿í
	LCD_ShowString(54,6,132,24,24,"*play mode*");
	for(i=0;i<5;i++)
	{
		LCD_ShowString(5,47+i*space,16,16,16,"L");
		LCD_ShowNum(13,47+i*space,i+1,1,16);
		
//		LCD_Draw_ColorCircle(51,55+i*space,20,GREEN);
//		LCD_Draw_ColorCircle(126,55+i*space,20,YELLOW);	
//		LCD_Draw_ColorCircle(201,55+i*space,20,RED);
	}
	if(G1==0) LCD_Draw_ColorCircle(51,55,17,LGRAY);
	else 			LCD_Draw_ColorCircle(51,55,17,GREEN);
	if(Y1==0) LCD_Draw_ColorCircle(126,55,17,LGRAY);	
	else 			LCD_Draw_ColorCircle(126,55,17,YELLOW);	
	if(R1==0) LCD_Draw_ColorCircle(201,55,17,LGRAY);
	else			LCD_Draw_ColorCircle(201,55,17,RED);

	if(G2==0) LCD_Draw_ColorCircle(51,55+space,17,LGRAY);
	else 			LCD_Draw_ColorCircle(51,55+space,17,GREEN);
	if(Y2==0) LCD_Draw_ColorCircle(126,55+space,17,LGRAY);	
	else 			LCD_Draw_ColorCircle(126,55+space,17,YELLOW);	
	if(R2==0) LCD_Draw_ColorCircle(201,55+space,17,LGRAY);
	else			LCD_Draw_ColorCircle(201,55+space,17,RED);
	
	if(G3==0) LCD_Draw_ColorCircle(51,55+2*space,17,LGRAY);
	else 			LCD_Draw_ColorCircle(51,55+2*space,17,GREEN);
	if(Y3==0) LCD_Draw_ColorCircle(126,55+2*space,17,LGRAY);	
	else 			LCD_Draw_ColorCircle(126,55+2*space,17,YELLOW);	
	if(R3==0) LCD_Draw_ColorCircle(201,55+2*space,17,LGRAY);
	else			LCD_Draw_ColorCircle(201,55+2*space,17,RED);
	
	if(G4==0) LCD_Draw_ColorCircle(51,55+3*space,17,LGRAY);
	else 			LCD_Draw_ColorCircle(51,55+3*space,17,GREEN);
	if(Y4==0) LCD_Draw_ColorCircle(126,55+3*space,17,LGRAY);	
	else 			LCD_Draw_ColorCircle(126,55+3*space,17,YELLOW);	
	if(R4==0) LCD_Draw_ColorCircle(201,55+3*space,17,LGRAY);
	else			LCD_Draw_ColorCircle(201,55+3*space,17,RED);
	
	if(G5==0) LCD_Draw_ColorCircle(51,55+4*space,17,LGRAY);
	else 			LCD_Draw_ColorCircle(51,55+4*space,17,GREEN);
	if(Y5==0) LCD_Draw_ColorCircle(126,55+4*space,17,LGRAY);	
	else 			LCD_Draw_ColorCircle(126,55+4*space,17,YELLOW);	
	if(R5==0) LCD_Draw_ColorCircle(201,55+4*space,17,LGRAY);
	else			LCD_Draw_ColorCircle(201,55+4*space,17,RED);
}
void light_set(void)
{
	u8 w=75,h=44;
	TP_Scan(0);
	if(tp_dev.sta&TP_PRES_DOWN){
		//ÐÅºÅµÆ1
		if((tp_dev.x[0]>34 && tp_dev.x[0]<68 && tp_dev.y[0]>38 && tp_dev.y[0]<72) && i==0)
		{
			HAL_GPIO_WritePin(TFLIGHT_GREEN_1, GPIO_PIN_SET);
		}
		else if((tp_dev.x[0]>34 && tp_dev.x[0]<68 && tp_dev.y[0]>38 && tp_dev.y[0]<72)&& i==1)
		{	
			HAL_GPIO_WritePin(TFLIGHT_GREEN_1, GPIO_PIN_RESET);
		}
		else if((tp_dev.x[0]>34+w && tp_dev.x[0]<68+w && tp_dev.y[0]>38 && tp_dev.y[0]<72) && i==0)
		{
			HAL_GPIO_WritePin(TFLIGHT_YELLOW_1, GPIO_PIN_SET);
		}
		else if((tp_dev.x[0]>34+w && tp_dev.x[0]<68+w && tp_dev.y[0]>38 && tp_dev.y[0]<72)&& i==1)
		{	
			HAL_GPIO_WritePin(TFLIGHT_YELLOW_1, GPIO_PIN_RESET);
		}
		else if((tp_dev.x[0]>34+2*w && tp_dev.x[0]<68+2*w && tp_dev.y[0]>38 && tp_dev.y[0]<72) && i==0)
		{
			HAL_GPIO_WritePin(TFLIGHT_RED_1, GPIO_PIN_SET);
		}
		else if((tp_dev.x[0]>34+2*w && tp_dev.x[0]<68+2*w && tp_dev.y[0]>38 && tp_dev.y[0]<72)&& i==1)
		{	
			HAL_GPIO_WritePin(TFLIGHT_RED_1, GPIO_PIN_RESET);
		}
		//ÐÅºÅµÆ2
		if((tp_dev.x[0]>34 && tp_dev.x[0]<68 && tp_dev.y[0]>38+h && tp_dev.y[0]<72+h) && i==0)
		{
			HAL_GPIO_WritePin(TFLIGHT_GREEN_2, GPIO_PIN_SET);
		}
		else if((tp_dev.x[0]>34 && tp_dev.x[0]<68 && tp_dev.y[0]>38+h && tp_dev.y[0]<72+h)&& i==1)
		{	
			HAL_GPIO_WritePin(TFLIGHT_GREEN_2, GPIO_PIN_RESET);
		}
		else if((tp_dev.x[0]>34+w && tp_dev.x[0]<68+w && tp_dev.y[0]>38+h && tp_dev.y[0]<72+h) && i==0)
		{
			HAL_GPIO_WritePin(TFLIGHT_YELLOW_2, GPIO_PIN_SET);
		}
		else if((tp_dev.x[0]>34+w && tp_dev.x[0]<68+w && tp_dev.y[0]>38+h && tp_dev.y[0]<72+h)&& i==1)
		{	
			HAL_GPIO_WritePin(TFLIGHT_YELLOW_2, GPIO_PIN_RESET);
		}
		else if((tp_dev.x[0]>34+2*w && tp_dev.x[0]<68+2*w && tp_dev.y[0]>38+h && tp_dev.y[0]<72+h) && i==0)
		{
			HAL_GPIO_WritePin(TFLIGHT_RED_2, GPIO_PIN_SET);
		}
		else if((tp_dev.x[0]>34+2*w && tp_dev.x[0]<68+2*w && tp_dev.y[0]>38+h && tp_dev.y[0]<72+h)&& i==1)
		{	
			HAL_GPIO_WritePin(TFLIGHT_RED_2, GPIO_PIN_RESET);
		}
		//ÐÅºÅµÆ3
		if((tp_dev.x[0]>34 && tp_dev.x[0]<68 && tp_dev.y[0]>38+2*h && tp_dev.y[0]<72+2*h) && i==0)
		{
			HAL_GPIO_WritePin(TFLIGHT_GREEN_3, GPIO_PIN_SET);
		}
		else if((tp_dev.x[0]>34 && tp_dev.x[0]<68 && tp_dev.y[0]>38+2*h && tp_dev.y[0]<72+2*h)&& i==1)
		{	
			HAL_GPIO_WritePin(TFLIGHT_GREEN_3, GPIO_PIN_RESET);
		}
		else if((tp_dev.x[0]>34+w && tp_dev.x[0]<68+w && tp_dev.y[0]>38+2*h && tp_dev.y[0]<72+2*h) && i==0)
		{
			HAL_GPIO_WritePin(TFLIGHT_YELLOW_3, GPIO_PIN_SET);
		}
		else if((tp_dev.x[0]>34+w && tp_dev.x[0]<68+w && tp_dev.y[0]>38+2*h && tp_dev.y[0]<72+2*h)&& i==1)
		{	
			HAL_GPIO_WritePin(TFLIGHT_YELLOW_3, GPIO_PIN_RESET);
		}
		else if((tp_dev.x[0]>34+2*w && tp_dev.x[0]<68+2*w && tp_dev.y[0]>38+2*h && tp_dev.y[0]<72+2*h) && i==0)
		{
			HAL_GPIO_WritePin(TFLIGHT_RED_3, GPIO_PIN_SET);
		}
		else if((tp_dev.x[0]>34+2*w && tp_dev.x[0]<68+2*w && tp_dev.y[0]>38+2*h && tp_dev.y[0]<72+2*h)&& i==1)
		{	
			HAL_GPIO_WritePin(TFLIGHT_RED_3, GPIO_PIN_RESET);
		}
		//ÐÅºÅµÆ4
		if((tp_dev.x[0]>34 && tp_dev.x[0]<68 && tp_dev.y[0]>38+3*h && tp_dev.y[0]<72+3*h) && i==0)
		{
			HAL_GPIO_WritePin(TFLIGHT_GREEN_4, GPIO_PIN_SET);
		}
		else if((tp_dev.x[0]>34 && tp_dev.x[0]<68 && tp_dev.y[0]>38+3*h && tp_dev.y[0]<72+3*h)&& i==1)
		{	
			HAL_GPIO_WritePin(TFLIGHT_GREEN_4, GPIO_PIN_RESET);
		}
		else if((tp_dev.x[0]>34+w && tp_dev.x[0]<68+w && tp_dev.y[0]>38+3*h && tp_dev.y[0]<72+3*h) && i==0)
		{
			HAL_GPIO_WritePin(TFLIGHT_YELLOW_4, GPIO_PIN_SET);
		}
		else if((tp_dev.x[0]>34+w && tp_dev.x[0]<68+w && tp_dev.y[0]>38+3*h && tp_dev.y[0]<72+3*h)&& i==1)
		{	
			HAL_GPIO_WritePin(TFLIGHT_YELLOW_4, GPIO_PIN_RESET);
		}
		else if((tp_dev.x[0]>34+2*w && tp_dev.x[0]<68+2*w && tp_dev.y[0]>38+3*h && tp_dev.y[0]<72+3*h) && i==0)
		{
			HAL_GPIO_WritePin(TFLIGHT_RED_4, GPIO_PIN_SET);
		}
		else if((tp_dev.x[0]>34+2*w && tp_dev.x[0]<68+2*w && tp_dev.y[0]>38+3*h && tp_dev.y[0]<72+3*h)&& i==1)
		{	
			HAL_GPIO_WritePin(TFLIGHT_RED_4, GPIO_PIN_RESET);
		}
		//ÐÅºÅµÆ5
		if((tp_dev.x[0]>34 && tp_dev.x[0]<68 && tp_dev.y[0]>38+4*h && tp_dev.y[0]<72+4*h) && i==0)
		{
			HAL_GPIO_WritePin(TFLIGHT_GREEN_5, GPIO_PIN_SET);
		}
		else if((tp_dev.x[0]>34 && tp_dev.x[0]<68 && tp_dev.y[0]>38+4*h && tp_dev.y[0]<72+4*h)&& i==1)
		{	
			HAL_GPIO_WritePin(TFLIGHT_GREEN_5, GPIO_PIN_RESET);
		}
		else if((tp_dev.x[0]>34+w && tp_dev.x[0]<68+w && tp_dev.y[0]>38+4*h && tp_dev.y[0]<72+4*h) && i==0)
		{
			HAL_GPIO_WritePin(TFLIGHT_YELLOW_5, GPIO_PIN_SET);
		}
		else if((tp_dev.x[0]>34+w && tp_dev.x[0]<68+w && tp_dev.y[0]>38+4*h && tp_dev.y[0]<72+4*h)&& i==1)
		{	
			HAL_GPIO_WritePin(TFLIGHT_YELLOW_5, GPIO_PIN_RESET);
		}
		else if((tp_dev.x[0]>34+2*w && tp_dev.x[0]<68+2*w && tp_dev.y[0]>38+4*h && tp_dev.y[0]<72+4*h) && i==0)
		{
			HAL_GPIO_WritePin(TFLIGHT_RED_5, GPIO_PIN_SET);
		}
		else if((tp_dev.x[0]>34+2*w && tp_dev.x[0]<68+2*w && tp_dev.y[0]>38+4*h && tp_dev.y[0]<72+4*h)&& i==1)
		{	
			HAL_GPIO_WritePin(TFLIGHT_RED_5, GPIO_PIN_RESET);
		}
		i=!i;
	}
}

void speed_set(void)
{
	LCD_ShowString(5,256,40,16,16,"speed");
	LCD_ShowNum(118,256,speed,2,16);
	LCD_ShowString(86,256,8,16,16,"-");
	LCD_ShowString(158,256,8,16,16,"+");
	LCD_DrawLine(106,252,106,280);
	LCD_DrawLine(146,252,146,280);
	TP_Scan(0);
	if(tp_dev.sta&TP_PRES_DOWN){
		if((tp_dev.x[0]>42 && tp_dev.x[0]<106 && tp_dev.y[0]>252 && tp_dev.y[0]<280) && j==0 && speed>20)
		{
			speed=speed-5;
		}
		else if((tp_dev.x[0]>146 && tp_dev.x[0]<238 && tp_dev.y[0]>252 && tp_dev.y[0]<280)&& j==1 && speed<80)
		{	
			speed=speed+5;
		}
		j=!j;
		LCD_ShowNum(118,256,speed,2,16);
	}
}

void back_set(int flag)
{
	TP_Scan(0);
  LCD_ShowString(200,8,32,16,16,"back");
	//show_picture(200,8,24,24,(u16*)gImage_back); 
	if(tp_dev.sta&TP_PRES_DOWN){
		if(tp_dev.x[0]>200 && tp_dev.x[0]<240 && tp_dev.y[0]>8 && tp_dev.y[0]<24)
		{
			flag=!flag;
		}
	}
}