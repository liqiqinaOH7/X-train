#include "stm32f1xx_hal.h"
#include "read.h"
#include "train_display.h"
#include "lcd.h"
#include "rtc.h"
#include "speed.h"
#define IntervalLength 80 // The length between every light/sensor is 80cm
// int foruse[5]={1,2,3,4,5};
uint16_t arriving_time;
void set_light(int n)
{
	switch (n)
	{
	case 1:
	{
		HAL_GPIO_WritePin(TFLIGHT_RED_1, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(TFLIGHT_YELLOW_1, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(TFLIGHT_GREEN_1, GPIO_PIN_SET);
		//+1
		HAL_GPIO_WritePin(TFLIGHT_RED_2, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(TFLIGHT_YELLOW_2, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(TFLIGHT_GREEN_2, GPIO_PIN_SET);
		//+2
		HAL_GPIO_WritePin(TFLIGHT_RED_3, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(TFLIGHT_YELLOW_3, GPIO_PIN_SET);
		HAL_GPIO_WritePin(TFLIGHT_GREEN_3, GPIO_PIN_SET);
		//+3
		HAL_GPIO_WritePin(TFLIGHT_RED_4, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(TFLIGHT_YELLOW_4, GPIO_PIN_SET);
		HAL_GPIO_WritePin(TFLIGHT_GREEN_4, GPIO_PIN_RESET);
		//+4
		HAL_GPIO_WritePin(TFLIGHT_RED_5, GPIO_PIN_SET);
		HAL_GPIO_WritePin(TFLIGHT_YELLOW_5, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(TFLIGHT_GREEN_5, GPIO_PIN_RESET);
		break;
	}
	case 2:
	{
		HAL_GPIO_WritePin(TFLIGHT_RED_2, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(TFLIGHT_YELLOW_2, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(TFLIGHT_GREEN_2, GPIO_PIN_SET);
		//+1
		HAL_GPIO_WritePin(TFLIGHT_RED_3, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(TFLIGHT_YELLOW_3, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(TFLIGHT_GREEN_3, GPIO_PIN_SET);
		//+2
		HAL_GPIO_WritePin(TFLIGHT_RED_4, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(TFLIGHT_YELLOW_4, GPIO_PIN_SET);
		HAL_GPIO_WritePin(TFLIGHT_GREEN_4, GPIO_PIN_SET);
		//+3
		HAL_GPIO_WritePin(TFLIGHT_RED_5, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(TFLIGHT_YELLOW_5, GPIO_PIN_SET);
		HAL_GPIO_WritePin(TFLIGHT_GREEN_5, GPIO_PIN_RESET);
		//+4
		HAL_GPIO_WritePin(TFLIGHT_RED_1, GPIO_PIN_SET);
		HAL_GPIO_WritePin(TFLIGHT_YELLOW_1, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(TFLIGHT_GREEN_1, GPIO_PIN_RESET);
		break;
	}
	case 3:
	{
		HAL_GPIO_WritePin(TFLIGHT_RED_3, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(TFLIGHT_YELLOW_3, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(TFLIGHT_GREEN_3, GPIO_PIN_SET);
		//+1
		HAL_GPIO_WritePin(TFLIGHT_RED_4, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(TFLIGHT_YELLOW_4, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(TFLIGHT_GREEN_4, GPIO_PIN_SET);
		//+2
		HAL_GPIO_WritePin(TFLIGHT_RED_5, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(TFLIGHT_YELLOW_5, GPIO_PIN_SET);
		HAL_GPIO_WritePin(TFLIGHT_GREEN_5, GPIO_PIN_SET);
		//+3
		HAL_GPIO_WritePin(TFLIGHT_RED_1, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(TFLIGHT_YELLOW_1, GPIO_PIN_SET);
		HAL_GPIO_WritePin(TFLIGHT_GREEN_1, GPIO_PIN_RESET);
		//+4
		HAL_GPIO_WritePin(TFLIGHT_RED_2, GPIO_PIN_SET);
		HAL_GPIO_WritePin(TFLIGHT_YELLOW_2, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(TFLIGHT_GREEN_2, GPIO_PIN_RESET);
		break;
	}
	case 4:
	{
		HAL_GPIO_WritePin(TFLIGHT_RED_4, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(TFLIGHT_YELLOW_4, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(TFLIGHT_GREEN_4, GPIO_PIN_SET);
		//+1
		HAL_GPIO_WritePin(TFLIGHT_RED_5, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(TFLIGHT_YELLOW_5, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(TFLIGHT_GREEN_5, GPIO_PIN_SET);
		//+2
		HAL_GPIO_WritePin(TFLIGHT_RED_1, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(TFLIGHT_YELLOW_1, GPIO_PIN_SET);
		HAL_GPIO_WritePin(TFLIGHT_GREEN_1, GPIO_PIN_SET);
		//+3
		HAL_GPIO_WritePin(TFLIGHT_RED_2, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(TFLIGHT_YELLOW_2, GPIO_PIN_SET);
		HAL_GPIO_WritePin(TFLIGHT_GREEN_2, GPIO_PIN_RESET);
		//+4
		HAL_GPIO_WritePin(TFLIGHT_RED_3, GPIO_PIN_SET);
		HAL_GPIO_WritePin(TFLIGHT_YELLOW_3, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(TFLIGHT_GREEN_3, GPIO_PIN_RESET);
		break;
	}
	case 5:
	{
		HAL_GPIO_WritePin(TFLIGHT_RED_5, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(TFLIGHT_YELLOW_5, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(TFLIGHT_GREEN_5, GPIO_PIN_SET);
		//+1
		HAL_GPIO_WritePin(TFLIGHT_RED_1, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(TFLIGHT_YELLOW_1, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(TFLIGHT_GREEN_1, GPIO_PIN_SET);
		//+2
		HAL_GPIO_WritePin(TFLIGHT_RED_2, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(TFLIGHT_YELLOW_2, GPIO_PIN_SET);
		HAL_GPIO_WritePin(TFLIGHT_GREEN_2, GPIO_PIN_SET);
		//+3
		HAL_GPIO_WritePin(TFLIGHT_RED_3, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(TFLIGHT_YELLOW_3, GPIO_PIN_SET);
		HAL_GPIO_WritePin(TFLIGHT_GREEN_3, GPIO_PIN_RESET);
		//+4
		HAL_GPIO_WritePin(TFLIGHT_RED_4, GPIO_PIN_SET);
		HAL_GPIO_WritePin(TFLIGHT_YELLOW_4, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(TFLIGHT_GREEN_4, GPIO_PIN_RESET);
		break;
	}
	}
}

void display_arriving_time()
{
	LCD_ShowString(20, 206, 220, 16, 16, "Arriving in      seconds");
	LCD_ShowNum(118, 206, arriving_time - Get_now_time_counter(1) / 1000, 3, 16);
}

void read_signal(void)
{
	static int state = 1;
	static int next_state = 1;
	switch (state)
	{
	case ST1:
		set_light(1);
		train_display(1);
		next_state = ST1;
		arriving_time = (int)(IntervalLength * 5 / real_speed);
		if (HAL_GPIO_ReadPin(SIGNAL_2) == GPIO_PIN_RESET)
			next_state = ST2;
		if (HAL_GPIO_ReadPin(SIGNAL_3) == GPIO_PIN_RESET)
			next_state = ST3;
		if (HAL_GPIO_ReadPin(SIGNAL_4) == GPIO_PIN_RESET)
			next_state = ST4;
		if (HAL_GPIO_ReadPin(SIGNAL_5) == GPIO_PIN_RESET)
			next_state = ST5;
		break;
	case ST2:
		set_light(2);
		train_display(2);
		next_state = ST2;
		arriving_time = (int)(IntervalLength * 4 / real_speed);
		if (HAL_GPIO_ReadPin(SIGNAL_1) == GPIO_PIN_RESET)
			next_state = ST1;
		if (HAL_GPIO_ReadPin(SIGNAL_3) == GPIO_PIN_RESET)
			next_state = ST3;
		if (HAL_GPIO_ReadPin(SIGNAL_4) == GPIO_PIN_RESET)
			next_state = ST4;
		if (HAL_GPIO_ReadPin(SIGNAL_5) == GPIO_PIN_RESET)
			next_state = ST5;
		break;
	case ST3:
		set_light(3);
		train_display(3);
		next_state = ST3;
		arriving_time = (int)(IntervalLength * 3 / real_speed);
		if (HAL_GPIO_ReadPin(SIGNAL_1) == GPIO_PIN_RESET)
			next_state = ST1;
		if (HAL_GPIO_ReadPin(SIGNAL_2) == GPIO_PIN_RESET)
			next_state = ST2;
		if (HAL_GPIO_ReadPin(SIGNAL_4) == GPIO_PIN_RESET)
			next_state = ST4;
		if (HAL_GPIO_ReadPin(SIGNAL_5) == GPIO_PIN_RESET)
			next_state = ST5;
		break;
	case ST4:
		set_light(4);
		train_display(4);
		next_state = ST4;
		arriving_time = (int)(IntervalLength * 2 / real_speed);
		if (HAL_GPIO_ReadPin(SIGNAL_1) == GPIO_PIN_RESET)
			next_state = ST1;
		if (HAL_GPIO_ReadPin(SIGNAL_2) == GPIO_PIN_RESET)
			next_state = ST2;
		if (HAL_GPIO_ReadPin(SIGNAL_3) == GPIO_PIN_RESET)
			next_state = ST3;
		if (HAL_GPIO_ReadPin(SIGNAL_5) == GPIO_PIN_RESET)
			next_state = ST5;
		break;
	case ST5:
		set_light(5);
		train_display(5);
		next_state = ST5;
		arriving_time = (int)(IntervalLength * 1 / real_speed);
		if (HAL_GPIO_ReadPin(SIGNAL_1) == GPIO_PIN_RESET)
			next_state = ST1;
		if (HAL_GPIO_ReadPin(SIGNAL_2) == GPIO_PIN_RESET)
			next_state = ST2;
		if (HAL_GPIO_ReadPin(SIGNAL_4) == GPIO_PIN_RESET)
			next_state = ST4;
		if (HAL_GPIO_ReadPin(SIGNAL_3) == GPIO_PIN_RESET)
			next_state = ST3;
		break;
	}
	if (next_state != state)
	{
		Reset_time_counter(1);
	}
	display_arriving_time();
	state = next_state;
	//	//�źŵ�+���⴫�в���
	//	//������1��⵽�ź�
	//	if(HAL_GPIO_ReadPin(SIGNAL_1)) == GPIO_PIN_RESET)
	//	{
	//		set_light(1);
	//		train_display(1);
	//	}
	//	else if(HAL_GPIO_ReadPin(SIGNAL_2) == GPIO_PIN_RESET)
	//	{
	//		set_light(2);
	//		train_display(2);
	//	}
	//	//������3��⵽�ź�
	//	else if(HAL_GPIO_ReadPin(SIGNAL_3) == GPIO_PIN_RESET)
	//	{
	//		set_light(3);
	//		train_display(3);
	//	}
	//	//������4��⵽�ź�
	//	else if(HAL_GPIO_ReadPin(SIGNAL_4) == GPIO_PIN_RESET)
	//	{
	//		set_light(4);
	//		train_display(4);
	//	}
	//	//������5��⵽�ź�
	//	else if(HAL_GPIO_ReadPin(SIGNAL_5) == GPIO_PIN_RESET)
	//	{
	//		set_light(5);
	//		train_display(5);
	//	}
}