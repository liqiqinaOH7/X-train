#ifndef __SERIAL_H
#define __SERIAL_H

#include <stdio.h>
/*TX的GPIO端口定义*/
#define USART3_GPIO_TX_PIN					 GPIO_Pin_10
#define USART3_GPIO_TX_PORT					 GPIOB
#define USART3_GPIO_TX_CLK					 RCC_APB2Periph_GPIOB

/*RX的GPIO端口定义*/
#define USART3_GPIO_RX_PIN					 GPIO_Pin_11
#define USART3_GPIO_RX_PORT					 GPIOB
#define USART3_GPIO_RX_CLK					 RCC_APB2Periph_GPIOB

/*USART3定义*/
#define DEBUG_USARTx_CLK						 RCC_APB1Periph_USART3
void Serial_Init(void);
void Serial_SendByte(uint8_t Byte);
void Serial_SendArray(uint8_t *Array, uint16_t Length);
void Serial_SendString(char *String);
void Serial_SendNumber(uint32_t Number, uint8_t Length);
void Serial_Printf(char *format, ...);
void USART3_IRQHandler(void);
uint8_t Serial_GetRxFlag(void);
uint8_t Serial_GetRxData(void);

#endif
