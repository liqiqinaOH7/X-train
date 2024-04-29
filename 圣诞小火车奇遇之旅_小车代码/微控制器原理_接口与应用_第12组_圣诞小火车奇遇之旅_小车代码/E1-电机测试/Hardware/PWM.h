#ifndef __PWM_H
#define __PWM_H

extern void TIM3_PWM_Init(uint16_t arr, uint16_t psc);
extern void PWM_SetCompare1(uint16_t Compare);
extern void PWM_SetCompare2(uint16_t Compare);
#endif
