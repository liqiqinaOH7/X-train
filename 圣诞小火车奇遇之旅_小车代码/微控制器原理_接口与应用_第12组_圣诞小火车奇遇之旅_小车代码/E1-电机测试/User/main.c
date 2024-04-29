#include "stm32f10x.h" // Device header
#include "Delay.h"
#include "OLED.h"
#include "PWM.h"
#include "Serial.h"
#include "stm32f10x_gpio.h"
uint8_t i;
uint32_t dutycycle = 0;
uint8_t RxData;
#define MaxdutyCycle 950
#define MindutyCycle 250
int main(void)
{
	// Initialize PWM channels with a period of 1000 and a prescaler of 72
	TIM3_PWM_Init(1000, 72);		   // PA6,PA7
	PWM_SetCompare1(1000 - dutycycle); // PA6
	Serial_Init();
	GPIOs_Init();
	while (1)
	{
		if (Serial_GetRxFlag() == 1)
		{
			RxData = Serial_GetRxData();
			switch (RxData)
			{
			case '+':
				dutycycle += 50;
				if (dutycycle > MaxdutyCycle)
					dutycycle = MaxdutyCycle;
				PWM_SetCompare1(1000 - dutycycle);
				// LED1_Turn();
				break;
			case '-':
				dutycycle -= 50;
				if (dutycycle < MindutyCycle)
					dutycycle = MindutyCycle;
				PWM_SetCompare1(1000 - dutycycle);
				// LED1_Turn();
				break;
			case 'S':
				dutycycle = 0;
				PWM_SetCompare1(1000 - dutycycle);
				// LED1_Turn();
				break;
			case 'P':
				dutycycle = 400;
				PWM_SetCompare1(1000 - dutycycle);
				// LED1_Turn();
				break;
			case '2':
				GPIO_SetBits(GPIOC, GPIO_Pin_13);
				break;
			case '3':
				GPIO_ResetBits(GPIOC, GPIO_Pin_13);
				break;
			default:
				break;
			}
		}
	}
}
