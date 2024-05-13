/*头文件*/
#include "BLDC.h"
#include "TIM3.h"

/*用户自定义参数*/

/*直流无刷电机下半桥臂端口及引脚配置初始化函数*/
void BrushLess_Motor_GPIO_Init(void)
{
    Motor_Phase_CLK_ENABLE;
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.Pin = U_Phase_L;                                                    //直流无刷电机U相下桥臂控制引脚
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;                                         //推挽输出
    GPIO_InitStruct.Pull = GPIO_NOPULL;                                                 //不使用引脚推拉模式
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;                                  //引脚输出频率最大
    HAL_GPIO_Init(Motor_Phase,&GPIO_InitStruct);                                        //直流无刷电机U相下桥臂控制端口及引脚配置初始化
    GPIO_InitStruct.Pin = V_Phase_L;                                                    //直流无刷电机U相下桥臂控制引脚
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;                                         //推挽输出
    GPIO_InitStruct.Pull = GPIO_NOPULL;                                                 //不使用引脚推拉模式
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;                                  //引脚输出频率最大
    HAL_GPIO_Init(Motor_Phase,&GPIO_InitStruct);                                        //直流无刷电机U相下桥臂控制端口及引脚配置初始化
    GPIO_InitStruct.Pin = W_Phase_L;                                                    //直流无刷电机U相下桥臂控制引脚
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;                                         //推挽输出
    GPIO_InitStruct.Pull = GPIO_NOPULL;                                                 //不使用引脚推拉模式
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;                                  //引脚输出频率最大
    HAL_GPIO_Init(Motor_Phase,&GPIO_InitStruct);                                        //直流无刷电机U相下桥臂控制端口及引脚配置初始化
}

/*霍尔传感器配置初始化函数*/
void HALL_Init(void)
{
    HALL_CLK_ENABLE;                                                                    //开启霍尔传感器端口时钟
    GPIO_InitTypeDef GPIO_InitStruct = {0};                                             
    GPIO_InitStruct.Pin = HALL_1;                                                       //霍尔传感器1引脚
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;                                             //引脚输入模式
    GPIO_InitStruct.Pull = GPIO_NOPULL;                                                 //不使用引脚推拉模式
    HAL_GPIO_Init(HALL, &GPIO_InitStruct);                                              //霍尔传感器1检测端口及引脚初始化
    GPIO_InitStruct.Pin = HALL_2;                                                       //霍尔传感器2引脚
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;                                             //引脚输入模式
    GPIO_InitStruct.Pull = GPIO_NOPULL;                                                 //不使用引脚推拉模式
    HAL_GPIO_Init(HALL, &GPIO_InitStruct);                                              //霍尔传感器2检测端口及引脚初始化
    GPIO_InitStruct.Pin = HALL_3;                                                       //霍尔传感器3引脚
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;                                             //引脚输入模式
    GPIO_InitStruct.Pull = GPIO_NOPULL;                                                 //不使用引脚推拉模式
    HAL_GPIO_Init(HALL, &GPIO_InitStruct);                                              //霍尔传感器3检测端口及引脚初始化
}

/*霍尔传感器状态获取函数*/
uint32_t HALL_Get_State(void)
{
    __IO uint32_t State = 0;                                                            //定义一个可读写的状态变量
    if(HALL_1_STATE != GPIO_PIN_RESET)                                                  //霍尔传感器1检测到相位
    {
        State |= 0x01U;                                                                 //状态变量的bit0 = 1
    }
    if(HALL_2_STATE != GPIO_PIN_RESET)                                                  //霍尔传感器2检测到相位
    {
        State |= 0x02U;                                                                 //状态变量的bit1 = 1
    }
    if(HALL_3_STATE != GPIO_PIN_RESET)                                                  //霍尔传感器3检测到相位
    {
        State |= 0x04U;                                                                 //状态变量的bit2 = 1
    }
    return State;                                                                       //返回状态变量的值
}

/*直流无刷电机UHVL输出函数*/
void BLDC_UHVL(uint32_t Pulse)
{
    U_Phase_H_ON(&TIM3_HandleInit,TIM_CHANNEL_1,Pulse);                                 //控制直流无刷电机U相绕组上半桥臂导通
    V_Phase_H_OFF(&TIM3_HandleInit,TIM_CHANNEL_2);                                      //关闭直流无刷电机V相绕组上半桥臂
    W_Phase_H_OFF(&TIM3_HandleInit,TIM_CHANNEL_3);                                      //关闭直流无刷电机W相绕组上半桥臂
    V_Phase_L_ON;                                                                       //控制直流无刷电机V相绕组下半桥臂导通
    U_Phase_L_OFF;                                                                      //关闭直流无刷电机U相绕组下半桥臂
    W_Phase_L_OFF;                                                                      //关闭直流无刷电机W相绕组下半桥臂
}

/*直流无刷电机UHWL输出函数*/
void BLDC_UHWL(uint32_t Pulse)
{
    U_Phase_H_ON(&TIM3_HandleInit,TIM_CHANNEL_1,Pulse);                                 //控制直流无刷电机U相绕组上半桥臂导通
    V_Phase_H_OFF(&TIM3_HandleInit,TIM_CHANNEL_2);                                      //关闭直流无刷电机V相绕组上半桥臂
    W_Phase_H_OFF(&TIM3_HandleInit,TIM_CHANNEL_3);                                      //关闭直流无刷电机W相绕组上半桥臂
    W_Phase_L_ON;                                                                       //控制直流无刷电机W相绕组下半桥臂导通
    U_Phase_L_OFF;                                                                      //关闭直流无刷电机U相绕组下半桥臂
    V_Phase_L_OFF;                                                                      //关闭直流无刷电机V相绕组下半桥臂
}

/*直流无刷电机VHUL输出函数*/
void BLDC_VHUL(uint32_t Pulse)
{
    V_Phase_H_ON(&TIM3_HandleInit,TIM_CHANNEL_1,Pulse);                                 //控制直流无刷电机V相绕组上半桥臂导通
    U_Phase_H_OFF(&TIM3_HandleInit,TIM_CHANNEL_2);                                      //关闭直流无刷电机U相绕组上半桥臂
    W_Phase_H_OFF(&TIM3_HandleInit,TIM_CHANNEL_3);                                      //关闭直流无刷电机W相绕组上半桥臂
    U_Phase_L_ON;                                                                       //控制直流无刷电机U相绕组下半桥臂导通
    V_Phase_L_OFF;                                                                      //关闭直流无刷电机V相绕组下半桥臂
    W_Phase_L_OFF;                                                                      //关闭直流无刷电机W相绕组下半桥臂
}

/*直流无刷电机VHWL输出函数*/
void BLDC_VHWL(uint32_t Pulse)
{
    V_Phase_H_ON(&TIM3_HandleInit,TIM_CHANNEL_1,Pulse);                                 //控制直流无刷电机V相绕组上半桥臂导通
    U_Phase_H_OFF(&TIM3_HandleInit,TIM_CHANNEL_2);                                      //关闭直流无刷电机U相绕组上半桥臂
    W_Phase_H_OFF(&TIM3_HandleInit,TIM_CHANNEL_3);                                      //关闭直流无刷电机W相绕组上半桥臂
    W_Phase_L_ON;                                                                       //控制直流无刷电机W相绕组下半桥臂导通
    U_Phase_L_OFF;                                                                      //关闭直流无刷电机U相绕组下半桥臂
    V_Phase_L_OFF;                                                                      //关闭直流无刷电机V相绕组下半桥臂
}

/*直流无刷电机WHUL输出函数*/
void BLDC_WHUL(uint32_t Pulse)
{
    W_Phase_H_ON(&TIM3_HandleInit,TIM_CHANNEL_1,Pulse);                                 //控制直流无刷电机W相绕组上半桥臂导通
    V_Phase_H_OFF(&TIM3_HandleInit,TIM_CHANNEL_2);                                      //关闭直流无刷电机V相绕组上半桥臂
    U_Phase_H_OFF(&TIM3_HandleInit,TIM_CHANNEL_3);                                      //关闭直流无刷电机U相绕组上半桥臂
    U_Phase_L_ON;                                                                       //控制直流无刷电机U相绕组下半桥臂导通
    V_Phase_L_OFF;                                                                      //关闭直流无刷电机V相绕组下半桥臂
    W_Phase_L_OFF;                                                                      //关闭直流无刷电机W相绕组下半桥臂
}

/*直流无刷电机WHVL输出函数*/
void BLDC_WHVL(uint32_t Pulse)
{
    W_Phase_H_ON(&TIM3_HandleInit,TIM_CHANNEL_1,Pulse);                                 //控制直流无刷电机W相绕组上半桥臂导通
    V_Phase_H_OFF(&TIM3_HandleInit,TIM_CHANNEL_2);                                      //关闭直流无刷电机V相绕组上半桥臂
    U_Phase_H_OFF(&TIM3_HandleInit,TIM_CHANNEL_3);                                      //关闭直流无刷电机U相绕组上半桥臂
    V_Phase_L_ON;                                                                       //控制直流无刷电机V相绕组下半桥臂导通
    U_Phase_L_OFF;                                                                      //关闭直流无刷电机U相绕组下半桥臂
    W_Phase_L_OFF;                                                                      //关闭直流无刷电机W相绕组下半桥臂
}

/*直流无刷电机停止函数*/
void BrushLess_Motor_Stop(void)
{
    U_Phase_H_OFF(&TIM3_HandleInit,TIM_CHANNEL_1);                                      //关闭直流无刷电机U相绕组上半桥臂导通
    V_Phase_H_OFF(&TIM3_HandleInit,TIM_CHANNEL_2);                                      //关闭直流无刷电机V相绕组上半桥臂
    W_Phase_H_OFF(&TIM3_HandleInit,TIM_CHANNEL_3);                                      //关闭直流无刷电机W相绕组上半桥臂
    V_Phase_L_OFF;                                                                      //关闭直流无刷电机V相绕组下半桥臂导通
    U_Phase_L_OFF;                                                                      //关闭直流无刷电机U相绕组下半桥臂
    W_Phase_L_OFF;                                                                      //关闭直流无刷电机W相绕组下半桥臂
}

/*直流无刷电机启动函数*/
void BrushLess_Motor_Start(void)
{
    HAL_TIM_PWM_Start(&TIM3_HandleInit,TIM_CHANNEL_1);                                  //开启定时器3通道1PWM输出
    HAL_TIM_PWM_Start(&TIM3_HandleInit,TIM_CHANNEL_2);                                  //开启定时器3通道2PWM输出
    HAL_TIM_PWM_Start(&TIM3_HandleInit,TIM_CHANNEL_3);                                  //开启定时器3通道3PWM输出
}