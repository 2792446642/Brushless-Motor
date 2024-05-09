/*头文件*/
#include "BLDC.h"

/*用户自定义参数*/

/*霍尔传感器配置初始化函数*/
void HALL_Init(void)
{
    HALL_CLK_ENABLE;                                                  //开启霍尔传感器端口时钟
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.Pin = HALL_1;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    HAL_GPIO_Init(HALL, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = HALL_2;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    HAL_GPIO_Init(HALL, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = HALL_3;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    HAL_GPIO_Init(HALL, &GPIO_InitStruct);
}

/*霍尔传感器状态获取函数*/
uint32_t HALL_Get_State(void)
{
    __IO uint32_t State = 0;                                                //定义一个可读写的状态变量
    if(HALL_1_STATE != GPIO_PIN_RESET)                                      //霍尔传感器1检测到相位
    {
        State |= 0x01U;                                                     //状态变量的bit0 = 1
    }
    if(HALL_2_STATE != GPIO_PIN_RESET)                                       //霍尔传感器2检测到相位
    {
        State |= 0x02U;                                                     //状态变量的bit1 = 1
    }
    if(HALL_3_STATE != GPIO_PIN_RESET)                                      //霍尔传感器3检测到相位
    {
        State |= 0x04U;                                                     //状态变量的bit2 = 1
    }
    return State;                                                           //返回状态变量的值
}