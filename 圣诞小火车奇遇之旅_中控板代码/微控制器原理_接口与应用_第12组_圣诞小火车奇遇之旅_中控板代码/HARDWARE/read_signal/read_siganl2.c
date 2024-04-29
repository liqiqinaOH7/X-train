#include "usart.h"
#include "read_signal2.h"
UART_HandleTypeDef huart2;

void MX_USART2_UART_Init(void)
{

	/* USER CODE END USART2_Init 1 */
	huart2.Instance = USART2;
	huart2.Init.BaudRate = 9600;
	huart2.Init.WordLength = UART_WORDLENGTH_8B;
	huart2.Init.StopBits = UART_STOPBITS_1;
	huart2.Init.Parity = UART_PARITY_NONE;
	huart2.Init.Mode = UART_MODE_TX_RX;
	huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	huart2.Init.OverSampling = UART_OVERSAMPLING_16;
	//  if (HAL_UART_Init(&huart2) != HAL_OK)
	//  {
	//    Error_Handler();
	//  }
}
void send_signal(GPIO_TypeDef *GPIOx_red, uint16_t GPIO_Pin_red, GPIO_TypeDef *GPIOx_yellow, uint16_t GPIO_Pin_yellow, GPIO_TypeDef *GPIOx_green, uint16_t GPIO_Pin_green)
{
	if (HAL_GPIO_ReadPin(GPIOx_red, GPIO_Pin_red))
	{
		printf("S");
		HAL_Delay(50);
	}
	else if (HAL_GPIO_ReadPin(GPIOx_green, GPIO_Pin_green))
	{
		printf("P");
		HAL_Delay(50);
	}
	else if (HAL_GPIO_ReadPin(GPIOx_yellow, GPIO_Pin_yellow))
	{
		printf("P");
		HAL_Delay(50);
	}
}
void read_signal2(void)
{
	if (HAL_GPIO_ReadPin(SIGNAL_1) == GPIO_PIN_RESET)
	{
		send_signal(TFLIGHT_RED_1, TFLIGHT_YELLOW_1, TFLIGHT_GREEN_1);
	}
	else if (HAL_GPIO_ReadPin(SIGNAL_2) == GPIO_PIN_RESET)
	{
		send_signal(TFLIGHT_RED_2, TFLIGHT_YELLOW_2, TFLIGHT_GREEN_2);
	}
	// ������3��⵽�ź�
	else if (HAL_GPIO_ReadPin(SIGNAL_3) == GPIO_PIN_RESET)
	{
		send_signal(TFLIGHT_RED_3, TFLIGHT_YELLOW_3, TFLIGHT_GREEN_3);
	}
	// ������4��⵽�ź�
	else if (HAL_GPIO_ReadPin(SIGNAL_4) == GPIO_PIN_RESET)
	{
		send_signal(TFLIGHT_RED_4, TFLIGHT_YELLOW_4, TFLIGHT_GREEN_4);
	}
	// ������5��⵽�ź�
	else if (HAL_GPIO_ReadPin(SIGNAL_5) == GPIO_PIN_RESET)
	{
		send_signal(TFLIGHT_RED_5, TFLIGHT_YELLOW_5, TFLIGHT_GREEN_5);
	}
}
