#ifndef __TIM1_H__
#define __TIM1_H__

/*头文件*/
#include "stm32f4xx.h"

/*用户自定义参数*/
#define TIM1_CH1                    GPIOA
#define TIM1_CH1_PIN                GPIO_PIN_1
#define TIM1_CH1_CLK_ENABLE         __HAL_RCC_GPIOA_CLK_ENABLE()
/***  定时器1通道1相关配置  ***/
#define TIM1_CH2                    GPIOA
#define TIM1_CH2_PIN                GPIO_PIN_2
#define TIM1_CH2_CLK_ENABLE         __HAL_RCC_GPIOA_CLK_ENABLE()
/***  定时器1通道2相关配置  ***/
#define TIM1_CH3                    GPIOA
#define TIM1_CH3_PIN                GPIO_PIN_3
#define TIM1_CH3_CLK_ENABLE         __HAL_RCC_GPIOA_CLK_ENABLE()
/***  定时器1通道3相关配置  ***/

/*用户函数声明*/
void TIM1_Init(uint16_t PSC,uint32_t ARR,uint32_t PUL);

#endif
