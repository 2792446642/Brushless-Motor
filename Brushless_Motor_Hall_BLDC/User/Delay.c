/*头文件*/
#include "delay.h"

/*用户自定义变量*/
float systick_Freq = 0;

/*延时初始化函数*/
void Delay_Init(uint32_t SYSCLK_Freq)
{	
	SysTick->CTRL = 0;											//系统滴答时钟控制寄存器全部置零
	systick_Freq = (float)SYSCLK_Freq / 8;						//获取系统滴答时钟频率(MHz)，使用外部时钟源固定8分频
	HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK_DIV8);	//系统滴答定时器使用外部时钟源，则固定8分频，使用FCLK时钟源则不分频
}

/*微秒级函数*/
void Delay_us(uint32_t us)
{
	uint32_t temp = 0;
	SysTick->LOAD = us*systick_Freq;							//自动重装载寄存器赋值
	SysTick->VAL = 0;											//清空计数器
	SysTick->CTRL = 1;											//开启滴答定时器
	do
	{
		temp = SysTick->CTRL;									//将滴答定时器的控制寄存器值赋给temp
	}while((temp & 0x01)&&!(temp&(1<<16)));						//等待计数器值减为零
	SysTick->CTRL = 0;											//关闭滴答定时器
}

/*毫秒级函数*/
void Delay_ms(uint32_t ms)
{
	uint32_t temp = 0;
	SysTick->LOAD = ms*1000*systick_Freq;						//自动重装载寄存器赋值
	SysTick->VAL = 0;											//清空计数器
	SysTick->CTRL = 1;											//开启滴答定时器
	do
	{
		temp = SysTick->CTRL;									//将滴答定时器的控制寄存器值赋给temp
	}while((temp & 0x01)&&!(temp&(1<<16)));						//等待计数器值减为零
	SysTick->CTRL = 0;											//关闭滴答定时器
}

/*复写系统自带延时函数*/
void HAL_Delay(uint32_t ms)
{
	uint32_t temp = 0;
	SysTick->LOAD = ms*1000*systick_Freq;						//自动重装载寄存器赋值
	SysTick->VAL = 0;											//清空计数器
	SysTick->CTRL = SysTick_CTRL_ENABLE_Msk;					//开启滴答定时器
	do
	{
		temp = SysTick->CTRL;									//将滴答定时器的控制寄存器值赋给temp
	}while((temp & 0x01)&&!(temp&(1<<16)));						//等待计数器值减为零
	SysTick->CTRL = ~SysTick_CTRL_ENABLE_Msk;					//关闭滴答定时器
}




































