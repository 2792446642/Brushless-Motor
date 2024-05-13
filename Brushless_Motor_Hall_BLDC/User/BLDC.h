#ifndef __BLDC_H__
#define __BLDC_H__

/*头文件*/
#include "stm32f4xx.h"

/*用户自定义参数*/
#define HALL                                                    GPIOA              
#define HALL_1                                                  GPIO_PIN_1
#define HALL_2                                                  GPIO_PIN_2
#define HALL_3                                                  GPIO_PIN_3
#define HALL_CLK_ENABLE                                         __HAL_RCC_GPIOA_CLK_ENABLE()
//霍尔传感器端口及引脚参数定义

#define HALL_1_STATE                                            HAL_GPIO_ReadPin(HALL,HALL_1)
#define HALL_2_STATE                                            HAL_GPIO_ReadPin(HALL,HALL_2)
#define HALL_3_STATE                                            HAL_GPIO_ReadPin(HALL,HALL_3)
//霍尔传感器状态读取宏定义

#define Motor_Phase                                             GPIOB              
#define U_Phase_L                                               GPIO_PIN_6
#define V_Phase_L                                               GPIO_PIN_7
#define W_Phase_L                                               GPIO_PIN_8
#define Motor_Phase_CLK_ENABLE                                  __HAL_RCC_GPIOB_CLK_ENABLE()
//直流无刷电机端口及引脚参数定义

#define U_Phase_L_ON                                            HAL_GPIO_WritePin(Motor_Phase,U_Phase_L,GPIO_PIN_SET)
#define V_Phase_L_ON                                            HAL_GPIO_WritePin(Motor_Phase,V_Phase_L,GPIO_PIN_SET)
#define W_Phase_L_ON                                            HAL_GPIO_WritePin(Motor_Phase,W_Phase_L,GPIO_PIN_SET)
#define U_Phase_L_OFF                                           HAL_GPIO_WritePin(Motor_Phase,U_Phase_L,GPIO_PIN_RESET)
#define V_Phase_L_OFF                                           HAL_GPIO_WritePin(Motor_Phase,V_Phase_L,GPIO_PIN_RESET)
#define W_Phase_L_OFF                                           HAL_GPIO_WritePin(Motor_Phase,W_Phase_L,GPIO_PIN_RESET)
//直流无刷电机三相绕组下半桥臂状态控制宏定义

#define U_Phase_H_ON(__HANDLE__,__CHANNEL__,__COMPARE__)        __HAL_TIM_SetCompare(__HANDLE__,__CHANNEL__,__COMPARE__)
#define V_Phase_H_ON(__HANDLE__,__CHANNEL__,__COMPARE__)        __HAL_TIM_SetCompare(__HANDLE__,__CHANNEL__,__COMPARE__)
#define W_Phase_H_ON(__HANDLE__,__CHANNEL__,__COMPARE__)        __HAL_TIM_SetCompare(__HANDLE__,__CHANNEL__,__COMPARE__)
#define U_Phase_H_OFF(__HANDLE__,__CHANNEL__)                   __HAL_TIM_SetCompare(__HANDLE__,__CHANNEL__,0)
#define V_Phase_H_OFF(__HANDLE__,__CHANNEL__)                   __HAL_TIM_SetCompare(__HANDLE__,__CHANNEL__,0)
#define W_Phase_H_OFF(__HANDLE__,__CHANNEL__)                   __HAL_TIM_SetCompare(__HANDLE__,__CHANNEL__,0)
//直流无刷电机三相绕组上半桥臂状态控制宏定义

typedef struct 
{
    __IO uint8_t    Run_Flag;                                   /* 运行标志 */
    __IO uint8_t    Bolck_Flag;                                 /* 堵转标记 */
    __IO uint8_t    Current_State;                              /* 本次霍尔状态 */
    __IO uint8_t    Hall_single_state;                          /* 单个霍尔状态 */
    __IO uint8_t    Hall_State_Edge;                            /* 单个霍尔状态跳变 */
    __IO uint8_t    Step_Previous;                              /* 上次霍尔状态 */
    __IO uint8_t    Motor_Dir;                                  /* 电机旋转方向 */
    __IO int32_t    Motor_Pos;                                  /* 电机转子位置 */
    __IO int32_t    Motor_Speed;                                /* 电机转速 */
    __IO int16_t    Motor_Current;                              /* 电机相电流 */
    __IO uint16_t   PWM_Duty;                                   /* 电机占空比 */
    __IO uint32_t   Hall_Hold_Time;                             /* 霍尔保持时间 */
    __IO uint32_t   Pulse_Count;                                /* 霍尔传感器脉冲计数 */
    __IO uint32_t   Block_Time;                                 /* 电机堵转时间 */
}   BLDC_TypeDef;
//电机相关参数结构体

/*用户函数声明*/
void BrushLess_Motor_GPIO_Init(void);
void HALL_Init(void);                                   
uint32_t HALL_Get_State(void);
void BLDC_UHVL(uint32_t Pulse);
void BLDC_UHWL(uint32_t Pulse);
void BLDC_VHUL(uint32_t Pulse);
void BLDC_VHWL(uint32_t Pulse);
void BLDC_WHUL(uint32_t Pulse);
void BLDC_WHVL(uint32_t Pulse);
void BrushLess_Motor_Stop(void);

#endif
