/*头文件*/
#include "RCC.h"
#include "Delay.h"
#include "BLDC.h"
#include "TIM3.h"

/*用户自定义变量*/

/*主函数*/
int main(void)
{
	SystemClock_Config();									//初始化系统时钟配置
	Delay_Init(180);										//延时函数初始化主频为180MHz
	TIM3_Init(90,1000,0);
	BrushLess_Motor_GPIO_Init();
	HALL_Init();											//霍尔传感器端口配置初始化
	while(1)
	{
		
	}
}


