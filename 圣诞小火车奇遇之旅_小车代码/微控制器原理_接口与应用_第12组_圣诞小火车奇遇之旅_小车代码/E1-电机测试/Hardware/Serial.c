#include "stm32f10x.h" // Device header
#include <stdio.h>
#include <stdarg.h>
#include "Serial.h"

uint8_t Serial_RxData;
uint8_t Serial_RxFlag;
static void USART3_NVIC_Config(void)
{
	NVIC_InitTypeDef NVIC_InitStructure;

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);

	NVIC_InitStructure.NVIC_IRQChannel = USART3_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
}
void Serial_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);  // ʹ��GPIOʱ��
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE); // ʹ��USART3ʱ��

	/*TX_GPIO*/
	GPIO_InitStructure.GPIO_Pin = USART3_GPIO_TX_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(USART3_GPIO_TX_PORT, &GPIO_InitStructure);

	/*RX_GPIO*/
	GPIO_InitStructure.GPIO_Pin = USART3_GPIO_RX_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(USART3_GPIO_RX_PORT, &GPIO_InitStructure);

	/*USART3*/
	USART_InitStructure.USART_BaudRate = 9600;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	USART_Init(USART3, &USART_InitStructure);

	USART3_NVIC_Config();
	USART_ITConfig(USART3, USART_IT_RXNE, ENABLE); // ʹ�ܴ��ڽ����ն�
	USART_Cmd(USART3, ENABLE);					   // ʹ�ܴ���
}

void Serial_SendByte(uint8_t Byte)
{
	USART_SendData(USART3, Byte);
	while (USART_GetFlagStatus(USART3, USART_FLAG_TXE) == RESET)
		;
}

void Serial_SendArray(uint8_t *Array, uint16_t Length)
{
	uint16_t i;
	for (i = 0; i < Length; i++)
	{
		Serial_SendByte(Array[i]);
	}
}

void Serial_SendString(char *String)
{
	uint8_t i;
	for (i = 0; String[i] != '\0'; i++)
	{
		Serial_SendByte(String[i]);
	}
}

uint32_t Serial_Pow(uint32_t X, uint32_t Y)
{
	uint32_t Result = 1;
	while (Y--)
	{
		Result *= X;
	}
	return Result;
}

void Serial_SendNumber(uint32_t Number, uint8_t Length)
{
	uint8_t i;
	for (i = 0; i < Length; i++)
	{
		Serial_SendByte(Number / Serial_Pow(10, Length - i - 1) % 10 + '0');
	}
}

int fputc(int ch, FILE *f)
{
	Serial_SendByte(ch);
	return ch;
}

void Serial_Printf(char *format, ...)
{
	char String[100];
	va_list arg;
	va_start(arg, format);
	vsprintf(String, format, arg);
	va_end(arg);
	Serial_SendString(String);
}

uint8_t Serial_GetRxFlag(void)
{
	if (Serial_RxFlag == 1)
	{
		Serial_RxFlag = 0;
		return 1;
	}
	return 0;
}

uint8_t Serial_GetRxData(void)
{
	return Serial_RxData;
}

void USART3_IRQHandler(void)
{
	if (USART_GetITStatus(USART3, USART_IT_RXNE) == SET)
	{
		Serial_RxData = USART_ReceiveData(USART3);
		Serial_RxFlag = 1;
		USART_ClearITPendingBit(USART3, USART_IT_RXNE);
	}
}
void GPIOs_Init(void) // IO ???
{

	GPIO_InitTypeDef GPIO_InitStructure;

	/* GPIO Ports Clock Enable */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOC, ENABLE);

	/*Configure GPIO pin Output Level */

	/*Configure GPIO pin : PC13 */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  //????
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; // IO ???? 50MHz
	GPIO_Init(GPIOC, &GPIO_InitStructure);			  //??? GPIOB.5
	GPIO_SetBits(GPIOC, GPIO_Pin_13);				  // PB.5 ???
}
