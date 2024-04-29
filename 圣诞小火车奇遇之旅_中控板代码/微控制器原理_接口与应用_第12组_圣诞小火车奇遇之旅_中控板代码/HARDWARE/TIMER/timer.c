#include "timer.h"
#include "led.h"
//////////////////////////////////////////////////////////////////////////////////
// ������ֻ��ѧϰʹ�ã�δ���������ɣ��������������κ���;
// ALIENTEK STM32F103������
// ��ʱ���ж���������
// ����ԭ��@ALIENTEK
// ������̳:www.openedv.com
// ��������:2017/5/25
// �汾��V1.0
// ��Ȩ���У�����ؾ���
// Copyright(C) �������������ӿƼ����޹�˾ 2014-2024
// All rights reserved
//////////////////////////////////////////////////////////////////////////////////

TIM_HandleTypeDef TIM3_Handler; // ��ʱ�����
#define counter_num 8
uint32_t time_counter[counter_num];
#define counting_time 1
// ͨ�ö�ʱ��3�жϳ�ʼ��
// arr���Զ���װֵ��
// psc��ʱ��Ԥ��Ƶ��
// ��ʱ�����ʱ����㷽��:Tout=((arr+1)*(psc+1))/Ft us.
// Ft=��ʱ������Ƶ��,��λ:Mhz
// ����ʹ�õ��Ƕ�ʱ��3!
void TIM3_Init(u16 arr, u16 psc)
{
    int i;
    TIM3_Handler.Instance = TIM3;                             // ͨ�ö�ʱ��3
    TIM3_Handler.Init.Prescaler = psc;                        // ��Ƶϵ��
    TIM3_Handler.Init.CounterMode = TIM_COUNTERMODE_UP;       // ���ϼ�����
    TIM3_Handler.Init.Period = arr;                           // �Զ�װ��ֵ
    TIM3_Handler.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1; // ʱ�ӷ�Ƶ����
    HAL_TIM_Base_Init(&TIM3_Handler);
    HAL_TIM_Base_Start_IT(&TIM3_Handler); // ʹ�ܶ�ʱ��3�Ͷ�ʱ��3�����жϣ�TIM_IT_UPDATE
    for (i = 0; i < counter_num; i++)
        time_counter[i] = 0;
}

// ��ʱ���ײ�����������ʱ�ӣ������ж����ȼ�
// �˺����ᱻHAL_TIM_Base_Init()��������
void HAL_TIM_Base_MspInit(TIM_HandleTypeDef *htim)
{
    if (htim->Instance == TIM3)
    {
        __HAL_RCC_TIM3_CLK_ENABLE();           // ʹ��TIM3ʱ��
        HAL_NVIC_SetPriority(TIM3_IRQn, 1, 3); // �����ж����ȼ�����ռ���ȼ�1�������ȼ�3
        HAL_NVIC_EnableIRQ(TIM3_IRQn);         // ����ITM3�ж�
    }
}

// ��ʱ��3�жϷ�����
void TIM3_IRQHandler(void)
{
    HAL_TIM_IRQHandler(&TIM3_Handler);
}

// �ص���������ʱ���жϷ���������
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    int i;
    if (htim == (&TIM3_Handler))
    {
        for (i = 0; i < counter_num; i++)
            time_counter[i] += counting_time;
    }
}
void Reset_time_counter(uint8_t num)
{
    time_counter[num] = 0;
}
uint32_t Get_now_time_counter(uint8_t num)
{
    return time_counter[num];
}
