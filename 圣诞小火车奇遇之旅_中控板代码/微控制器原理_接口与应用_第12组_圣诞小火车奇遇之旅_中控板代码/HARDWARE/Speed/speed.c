#include "stm32f1xx_hal.h"
#include "read.h"
#include "timer.h"
#define Signal_triggered (HAL_GPIO_ReadPin(SIGNAL_1) == GPIO_PIN_RESET || HAL_GPIO_ReadPin(SIGNAL_2) == GPIO_PIN_RESET || HAL_GPIO_ReadPin(SIGNAL_3) == GPIO_PIN_RESET || HAL_GPIO_ReadPin(SIGNAL_4) == GPIO_PIN_RESET || HAL_GPIO_ReadPin(SIGNAL_5) == GPIO_PIN_RESET)
#define Signal_idle (HAL_GPIO_ReadPin(SIGNAL_1) == GPIO_PIN_SET && HAL_GPIO_ReadPin(SIGNAL_2) == GPIO_PIN_SET && HAL_GPIO_ReadPin(SIGNAL_3) == GPIO_PIN_SET && HAL_GPIO_ReadPin(SIGNAL_4) == GPIO_PIN_SET && HAL_GPIO_ReadPin(SIGNAL_5) == GPIO_PIN_SET)
#define IDLE 0
#define COUNTING 1
uint8_t speed_state = 0;
uint32_t time_count = 0;
const float train_length = 2450; // 24.5mm long
float real_speed = 0.0;

float speed_stock[3];
uint8_t speed_stock_count = 0;
uint32_t time_stock[6];
uint8_t time_stock_count = 0;

uint8_t cleared_flag = 0;
void speed_Init(void)
{
    speed_stock[0] = speed_stock[1] = 0.0;
    speed_stock_count = 0;
    time_stock[0] = time_stock[1] = time_stock[2] = time_stock[3] = 0;
    time_stock_count = 0;
    cleared_flag = 0;
}
void cal_speed_pre()
{
    if (speed_state == IDLE && Signal_triggered)
    {
        time_stock[time_stock_count++] = Get_now_time_counter(0);
        Reset_time_counter(0);
        speed_state = COUNTING;
    }
    else if (speed_state == COUNTING && Signal_idle)
    {
        time_count = Get_now_time_counter(0);
        speed_state = IDLE;
        real_speed = train_length / time_count;
        time_stock[time_stock_count++] = time_count;
        speed_stock[speed_stock_count++] = real_speed;
        if (speed_stock_count == 2)
        {
            time_stock_count = 0;
            speed_stock_count = 0;
            cleared_flag = 1;
        }
    }
}
float Get_now_speed()
{
    int delta_t;
    float k;
    int nowtime;
    if (!cleared_flag)
        return real_speed;
    if (speed_stock_count == 0)
    {
        delta_t = time_stock[2] + (time_stock[3] - time_stock[1]) / 2;
        k = (speed_stock[1] - speed_stock[0]) / delta_t;
        nowtime = Get_now_time_counter(0) - time_stock[3] / 2 + delta_t;
    }
    else
    {
        delta_t = time_stock[0] + (time_stock[1] - time_stock[3]) / 2;
        k = (speed_stock[0] - speed_stock[1]) / delta_t;
        nowtime = Get_now_time_counter(0) - time_stock[1] / 2 + delta_t;
    }
    return k * nowtime + speed_stock[0];
    // return (speed_stock[0] + speed_stock[1]) / 2;
}
void floatToChar(float number, char *buffer)
{

    int integerPart = (int)number;
    int decimalPart = (number - integerPart) * 100;
    int start, end;
    int i = 0;

    // 处理整数部分
    if (integerPart == 0)
        buffer[i++] = '0';
    while (integerPart != 0)
    {
        int remainder = integerPart % 10;
        buffer[i++] = remainder + '0';
        integerPart = integerPart / 10;
    }

    // 颠倒整数部分的顺序
    for (start = 0, end = i - 1; start < end; ++start, --end)
    {
        char temp = buffer[start];
        buffer[start] = buffer[end];
        buffer[end] = temp;
    }

    // 插入小数点
    buffer[i++] = '.';
    buffer[i++] = '0' + decimalPart / 10;
    buffer[i++] = '0' + decimalPart % 10;
    // 终止符
    buffer[i] = '\0';
}
void speed_display()
{
    char sp[10];
    LCD_ShowString(40, 252, 200, 16, 16, "Speed:         cm/s");
    memset(sp, 0, sizeof(sp));
    floatToChar(real_speed, sp); // if Get_now_speed() goes wrong, change it to real_speed
    LCD_ShowString(100, 252, 200, 16, 16, sp);
    if(speed_state ==IDLE)
        LCD_ShowString(40, 232, 200, 16, 16, "state:IDLE    ");
    if (speed_state == COUNTING)
        LCD_ShowString(40, 232, 200, 16, 16, "state:COUNTING");
    // memset(sp, 0, sizeof(sp));
    // floatToChar(speed_stock[0], sp);
    // LCD_ShowString(40, 212, 200, 16, 16, "v1=");
    // LCD_ShowString(80, 212, 200, 16, 16, sp);
    // memset(sp, 0, sizeof(sp));
    // floatToChar(speed_stock[1], sp);
    // LCD_ShowString(120, 212, 50, 16, 16, "v2=");
    // LCD_ShowString(160, 212, 50, 16, 16, sp);
}