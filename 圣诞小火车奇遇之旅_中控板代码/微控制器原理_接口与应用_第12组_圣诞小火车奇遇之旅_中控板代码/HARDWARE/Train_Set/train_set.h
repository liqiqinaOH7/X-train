#ifndef _TRAIN_SET_H
#define _TRAIN_SET_H
#include "stm32f1xx_hal.h"
//ÐÅºÅµÆ1
#define G1  HAL_GPIO_ReadPin(GPIOF, GPIO_PIN_6)
#define Y1  HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13)
#define R1  HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_0)

//ÐÅºÅµÆ2
#define G2  HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4)
#define Y2  HAL_GPIO_ReadPin(GPIOF, GPIO_PIN_12)
#define R2  HAL_GPIO_ReadPin(GPIOF, GPIO_PIN_11)

//ÐÅºÅµÆ3
#define G3  HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_6)
#define Y3  HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_1)
#define R3  HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_15)

//ÐÅºÅµÆ4
#define G4  HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)
#define Y4  HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_0)
#define R4  HAL_GPIO_ReadPin(GPIOF, GPIO_PIN_13)

//ÐÅºÅµÆ5
#define G5  HAL_GPIO_ReadPin(GPIOF, GPIO_PIN_8)
#define Y5  HAL_GPIO_ReadPin(GPIOF, GPIO_PIN_7)
#define R5  HAL_GPIO_ReadPin(GPIOF, GPIO_PIN_9)
extern int i;
extern int j;
extern int speed;
void train_set(void);
void light_set(void);
void speed_set(void);
void back_set(int flag);
#endif