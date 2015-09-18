#include "includes.h"
#include "Motor_INIT.h"
#include "Delay_time.h"
#include "Key_INIT.h"
INT8U PWM_H=0,n=0,i=0;
/******************
*******	函数名称： Motor_INIT（）
*******	函数功能： 电梯电机初始化函数
*******	返回值  ： NULL
******************/
void Motor_INIT()
{
	EA=1;
	ET1=1;
	TMOD=TMOD & 0X0F | 0x20;		
}
/******************
*******	函数名称： Motor_Set（）
*******	函数功能： 电梯运行速度设置函数	（4级速度可调：0、1、2、3；对应占空比：0、1/4、2/4、3/4）
*******	返回值  ： INT8U v
******************/
void Motor_Set(INT8U v)
{
	if(v>3) 
		v=3;
	if(v == 0)	
		TR1 = 0;
	else
	{
		TR1 = 1;
		PWM_H = v;
	}
}

/******************
*******	函数名称： Motor_UP（）
*******	函数功能： 电梯上升函数
*******	返回值  ： NULL
******************/
void Motor_UP_INIT()
{
	PWM1 = 0;
	PWM2 = 1;
	while(1)
	{
		if(KEY_IN() == 1)
		{
			Delay_nms(5);
			Motor_Set(1);
			Delay_nms(10000);
			Motor_Set(1);
			PWM2 = 0;
		}
		if(KEY_IN() == 2)
		{
			Delay_nms(5);
			Motor_Set(1);
			Delay_nms(18000);
			Motor_Set(1);
			PWM2 = 0;		
		}
	}	
}
/******************
*******	函数名称： Motor_DOWN_INIT（）
*******	函数功能： 电梯下降函数
*******	返回值  ： NULL
******************/
void Motor_DOWN_INIT()
{
	PWM1 = 1;
	PWM2 = 0;
	while(1)
	{
		if(KEY_IN() == 1)
		{
			Delay_nms(5);
			Motor_Set(1);
			Delay_nms(10000);
			Motor_Set(1);
			PWM1 = 0;
		}
		if(KEY_IN() == 2)
		{
			Delay_nms(5);
			Motor_Set(1);
			Delay_nms(18000);
			Motor_Set(1);
			PWM1 = 0;	
		}
	}
}

/******************
*******	函数名称： Motor_Run（）
*******	函数功能： 电梯运行中断函数
*******	返回值  ： NULL
******************/
void Motor_Run() interrupt	3
{	
	if(n < PWM_H) 
	{	PWM1 = 1;
		PWM2 = 1;	
	}
	else 
	{
		PWM1 = 0;
		PWM2 = 0;
	}
		n++;
	if(n>=4) 
		n=0;
}
