/*头文件*/
#include "TIM3.h"

/*用户自定义参数*/
TIM_HandleTypeDef TIM3_HandleInit = {0};                            //定义定时器1句柄结构体

/*定时器3端口及引脚配置初始化函数*/
void TIM3_Init(uint16_t PSC,uint16_t ARR,uint16_t Pulse)
{
    TIM3_CH1_CLK_ENABLE;                                                                //开启定时器3通道1端口时钟
    TIM3_CH2_CLK_ENABLE;                                                                //开启定时器3通道2端口时钟
    TIM3_CH3_CLK_ENABLE;                                                                //开启定时器3通道3端口时钟
    TIM3_CLK_ENABLE;                                                                    //开启定时器3外设时钟
    TIM_MasterConfigTypeDef TIM3_MasterConfig = {0};
    TIM_OC_InitTypeDef TIM3_ConfigOC = {0};
    TIM_ClockConfigTypeDef TIM3_ClockConfigInit = {0};
    GPIO_InitTypeDef GPIO_InitStruct = {0};                                             //定义引脚结构体
    GPIO_InitStruct.Pin = TIM3_CH1_PIN;                                                 //定时器3通道1引脚
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;                                             //复用推挽输出
    GPIO_InitStruct.Pull = GPIO_NOPULL;                                                 //不使用引脚推拉模式
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;                                  //引脚输出频率最大
    GPIO_InitStruct.Alternate = GPIO_AF2_TIM3;                                          //引脚复用为定时器3输出功能
    HAL_GPIO_Init(TIM3_CH1,&GPIO_InitStruct);                                           //定时器3通道1端口及引脚配置初始化
    GPIO_InitStruct.Pin = TIM3_CH2_PIN;                                                 //定时器3通道2引脚
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;                                             //复用推挽输出
    GPIO_InitStruct.Pull = GPIO_NOPULL;                                                 //不使用引脚推拉模式
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;                                  //引脚输出频率最大
    GPIO_InitStruct.Alternate = GPIO_AF2_TIM3;                                          //引脚复用为定时器3输出功能
    HAL_GPIO_Init(TIM3_CH2,&GPIO_InitStruct);                                           //定时器3通道2端口及引脚配置初始化
    GPIO_InitStruct.Pin = TIM3_CH3_PIN;                                                 //定时器3通道3引脚
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;                                             //复用推挽输出
    GPIO_InitStruct.Pull = GPIO_NOPULL;                                                 //不使用引脚推拉模式
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;                                  //引脚输出频率最大
    GPIO_InitStruct.Alternate = GPIO_AF2_TIM3;                                          //引脚复用为定时器3输出功能
    HAL_GPIO_Init(TIM3_CH3,&GPIO_InitStruct);                                           //定时器3通道3端口及引脚配置初始化
    TIM3_HandleInit.Instance = TIM3;                                                    //使用定时器3外设
    TIM3_HandleInit.Init.Prescaler = PSC - 1;                                           //设置定时器3的预分频系数
    TIM3_HandleInit.Init.CounterMode = TIM_COUNTERMODE_UP;                              //定时器3设置为向上计数模式
    TIM3_HandleInit.Init.Period = ARR - 1;                                              //设置定时器3的自动重装载值
    TIM3_HandleInit.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;                        //定时器3时钟预分频系数为1
    TIM3_HandleInit.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;            //关闭定时器3的重装载预装载功能
	HAL_TIM_Base_Init(&TIM3_HandleInit);                                                //定时器3配置初始化
    HAL_TIM_PWM_Init(&TIM3_HandleInit);                                                 //定时器3的PWM输出配置初始化
    TIM3_ClockConfigInit.ClockSource = TIM_CLOCKSOURCE_INTERNAL;                        //定时器3的时钟源来自内部片外
	HAL_TIM_ConfigClockSource(&TIM3_HandleInit,&TIM3_ClockConfigInit);                  //定时器3时钟源配置初始化
    TIM3_MasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;                             //
    TIM3_MasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;                    //关闭定时器3的主从模式设置
    HAL_TIMEx_MasterConfigSynchronization(&TIM3_HandleInit, &TIM3_MasterConfig);        //定时器3主从模式配置初始化
    TIM3_ConfigOC.OCMode = TIM_OCMODE_PWM1;                                             //定时器3使用PWM模式1
    if(Pulse == 0)
    TIM3_ConfigOC.Pulse = 0;                                                            //设置输出通道方波的占空比
    else
    TIM3_ConfigOC.Pulse = Pulse - 1;                                                    //设置输出通道方波的占空比
    TIM3_ConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;                                     //方波输出极性为高电平
    TIM3_ConfigOC.OCFastMode = TIM_OCFAST_DISABLE;                                      //关闭定时器3输出比较的快速模式
    HAL_TIM_PWM_ConfigChannel(&TIM3_HandleInit, &TIM3_ConfigOC, TIM_CHANNEL_1);         //配置定时器3的PWM输出通道1
    HAL_TIM_PWM_ConfigChannel(&TIM3_HandleInit, &TIM3_ConfigOC, TIM_CHANNEL_2);         //配置定时器3的PWM输出通道2
    HAL_TIM_PWM_ConfigChannel(&TIM3_HandleInit, &TIM3_ConfigOC, TIM_CHANNEL_3);         //配置定时器3的PWM输出通道3
    HAL_TIM_PWM_Start(&TIM3_HandleInit,TIM_CHANNEL_1);                                  //启动定时器3通道1方波输出
    HAL_TIM_PWM_Start(&TIM3_HandleInit,TIM_CHANNEL_2);                                  //启动定时器3通道2方波输出
    HAL_TIM_PWM_Start(&TIM3_HandleInit,TIM_CHANNEL_3);                                  //启动定时器3通道3方波输出
    HAL_TIM_Base_Start(&TIM3_HandleInit);                                               //启动定时器3
    
}