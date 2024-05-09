#ifndef __BLDC_H__
#define __BLDC_H__

/*头文件*/
#include "stm32f4xx.h"

/*用户自定义参数*/
#define HALL                GPIOC              
#define HALL_1              GPIO_PIN_1
#define HALL_2              GPIO_PIN_2
#define HALL_3              GPIO_PIN_3
#define HALL_CLK_ENABLE     __HAL_RCC_GPIOC_CLK_ENABLE()
//霍尔传感器端口及引脚参数定义

#define HALL_1_STATE        HAL_GPIO_ReadPin(HALL,HALL_1)
#define HALL_2_STATE        HAL_GPIO_ReadPin(HALL,HALL_2)
#define HALL_3_STATE        HAL_GPIO_ReadPin(HALL,HALL_3)
//霍尔传感器状态读取宏定义

typedef struct 
{
    __IO uint8_t    Run_Flag;                           /* 运行标志 */
    __IO uint8_t    Bolck_Flag;                         /* 堵转标记 */
    __IO uint8_t    Current_State;                      /* 本次霍尔状态 */
    __IO uint8_t    Hall_single_state;                  /* 单个霍尔状态 */
    __IO uint8_t    Hall_State_Edge;                    /* 单个霍尔状态跳变 */
    __IO uint8_t    Step_Previous;                      /* 上次霍尔状态 */
    __IO uint8_t    Motor_Dir;                          /* 电机旋转方向 */
    __IO int32_t    Motor_Pos;                          /* 电机转子位置 */
    __IO int32_t    Motor_Speed;                        /* 电机转速 */
    __IO int16_t    Motor_Current;                      /* 电机相电流 */
    __IO uint16_t   PWM_Duty;                           /* 电机占空比 */
    __IO uint32_t   Hall_Hold_Time;                     /* 霍尔保持时间 */
    __IO uint32_t   Pulse_Count;                         /* 霍尔传感器脉冲计数 */
    __IO uint32_t   Block_Time;                         /* 电机堵转时间 */
    __IO uint32_t   no_single;
    __IO uint32_t   count_j;
}   BLDC_TypeDef;
//电机相关参数结构体


/*用户函数声明*/
void HALL_Init(void);                                   
uint32_t HALL_Get_State(void);

#endif
