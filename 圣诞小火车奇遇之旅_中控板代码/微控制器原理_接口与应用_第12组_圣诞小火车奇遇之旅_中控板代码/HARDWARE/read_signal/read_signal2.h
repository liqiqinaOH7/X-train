#ifndef _READtwo_H
#define _READtwo_H
#include "sys.h"
#include "stm32f1xx_hal.h"
#include "read.h"
void MX_USART2_UART_Init(void);
void read_signal2(void);
void send_signal (GPIO_TypeDef* GPIOx_red, uint16_t GPIO_Pin_red,GPIO_TypeDef* GPIOx_yellow, uint16_t GPIO_Pin_yellow,GPIO_TypeDef* GPIOx_green, uint16_t GPIO_Pin_green);
#endif
