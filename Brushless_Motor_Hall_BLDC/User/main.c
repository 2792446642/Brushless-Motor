/*头文件*/
#include "RCC.h"
#include "Delay.h"


/*用户自定义变量*/

/*主函数*/
int main(void)
{
	SystemClock_Config();									//初始化系统时钟配置
	Delay_Init(180);										//延时函数初始化主频为180MHz

	while(1)
	{
		
	}
}


