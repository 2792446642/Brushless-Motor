#ifndef __DELAY_H__
#define __DELAY_H__

/*头文件*/
#include "stm32f4xx.h"
/*用户自定义变量*/

/*用户函数声明*/
void Delay_Init(uint32_t SYSCLK_Freq);
void Delay_us(uint32_t us);
void Delay_ms(uint32_t ms);
#endif













