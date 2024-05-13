#ifndef __TIM3_H__
#define __TIM3_H__

/*头文件*/
#include "stm32f4xx.h"

/*用户自定义参数*/
#define TIM3_CH1                    GPIOC
#define TIM3_CH1_PIN                GPIO_PIN_6
#define TIM3_CH1_CLK_ENABLE         __HAL_RCC_GPIOC_CLK_ENABLE()
/***  定时器3通道1相关配置  ***/
#define TIM3_CH2                    GPIOC
#define TIM3_CH2_PIN                GPIO_PIN_7
#define TIM3_CH2_CLK_ENABLE         __HAL_RCC_GPIOC_CLK_ENABLE()
/***  定时器3通道2相关配置  ***/
#define TIM3_CH3                    GPIOC
#define TIM3_CH3_PIN                GPIO_PIN_8
#define TIM3_CH3_CLK_ENABLE         __HAL_RCC_GPIOC_CLK_ENABLE()
/***  定时器3通道3相关配置  ***/
#define TIM3_CLK_ENABLE             __HAL_RCC_TIM3_CLK_ENABLE()

/***  定时器3结构体句柄外部声明  ***/
extern TIM_HandleTypeDef TIM3_HandleInit;

/*用户函数声明*/
void TIM3_Init(uint16_t PSC,uint16_t ARR,uint16_t Pulse);

#endif
