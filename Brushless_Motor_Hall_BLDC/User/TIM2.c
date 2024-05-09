/*头文件*/
#include "TIM2.h"

/*用户自定义参数*/
TIM_HandleTypeDef TIM2_HandleInit = {0};                                        //定义定时器2句柄结构体

/*主函数*/
void TIM2_Init(uint16_t PSC,uint32_t ARR,uint32_t PUL)
{
    TIM2_CH2_CLK_ENABLE;                                                        //开启定时器2通道2时钟
    TIM2_CH3_CLK_ENABLE;                                                        //开启定时器2通道3时钟
    TIM2_CH4_CLK_ENABLE;                                                        //开启定时器2通道4时钟m
    
    TIM_ClockConfigTypeDef TIM2_ClockSourceConfig = {0};
    TIM_MasterConfigTypeDef TIM2_MasterConfig = {0};
    TIM_OC_InitTypeDef TIM2_ConfigOC = {0};
    
    GPIO_InitTypeDef GPIO_InitStruct = {0};                     
    GPIO_InitStruct.Pin = TIM2_CH2_PIN;                                         //定时器2通道2引脚
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;                                     //使用复用推挽输出
    GPIO_InitStruct.Pull = GPIO_NOPULL;                                         //不使用推拉模式
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;                          //输出速度为最快
    GPIO_InitStruct.Alternate = GPIO_AF1_TIM2;                                  //引脚复用为定时器2
    HAL_GPIO_Init(TIM2_CH2, &GPIO_InitStruct);                                  //定时器2通道2引脚配置初始化
    
    GPIO_InitStruct.Pin = TIM2_CH3_PIN;                                         //定时器2通道3引脚
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;                                     //使用复用推挽输出
    GPIO_InitStruct.Pull = GPIO_NOPULL;                                         //不使用推拉模式
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;                          //输出速度为最快
    GPIO_InitStruct.Alternate = GPIO_AF1_TIM2;                                  //引脚复用为定时器2
    HAL_GPIO_Init(TIM2_CH3, &GPIO_InitStruct);                                  //定时器2通道3引脚配置初始化
    
    GPIO_InitStruct.Pin = TIM2_CH4_PIN;                                         //定时器2通道4引脚
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;                                     //使用复用推挽输出
    GPIO_InitStruct.Pull = GPIO_NOPULL;                                         //不使用推拉模式
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;                          //输出速度为最快
    GPIO_InitStruct.Alternate = GPIO_AF1_TIM2;                                  //引脚复用为定时器2
    HAL_GPIO_Init(TIM2_CH4, &GPIO_InitStruct);                                  //定时器2通道4引脚配置初始化

    TIM2_HandleInit.Instance = TIM2;
    TIM2_HandleInit.Init.Prescaler = PSC;                                       //设置定时器2预分频系数
    TIM2_HandleInit.Init.CounterMode = TIM_COUNTERMODE_UP;                      //定时器2设置为向上计数模式
    TIM2_HandleInit.Init.Period = ARR;                                          //设置定时器2自动重装载预装载值
    TIM2_HandleInit.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;                //定时器时钟 分频系数为1
    TIM2_HandleInit.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
    HAL_TIM_Base_Init(&TIM2_HandleInit);                                        //定时器2配置初始化
    HAL_TIM_Base_Start_IT(&TIM2_HandleInit);                                    //定时器2以中断方式启动

    TIM2_ClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;              //使用内部时钟来源
    HAL_TIM_ConfigClockSource(&TIM2_HandleInit, &TIM2_ClockSourceConfig);

    HAL_TIM_PWM_Init(&TIM2_HandleInit);
    TIM2_MasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
    TIM2_MasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
    HAL_TIMEx_MasterConfigSynchronization(&TIM2_HandleInit, &TIM2_MasterConfig);
    TIM2_ConfigOC.OCMode = TIM_OCMODE_PWM1;
    TIM2_ConfigOC.Pulse = PUL;
    TIM2_ConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
    TIM2_ConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
    HAL_TIM_PWM_ConfigChannel(&TIM2_HandleInit, &TIM2_ConfigOC, TIM_CHANNEL_2);
    TIM2_ConfigOC.OCMode = TIM_OCMODE_PWM1;
    TIM2_ConfigOC.Pulse = PUL;
    TIM2_ConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
    TIM2_ConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
    HAL_TIM_PWM_ConfigChannel(&TIM2_HandleInit, &TIM2_ConfigOC, TIM_CHANNEL_3);
    TIM2_ConfigOC.OCMode = TIM_OCMODE_PWM1;
    TIM2_ConfigOC.Pulse = PUL;
    TIM2_ConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
    TIM2_ConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
    HAL_TIM_PWM_ConfigChannel(&TIM2_HandleInit, &TIM2_ConfigOC, TIM_CHANNEL_4);
}
