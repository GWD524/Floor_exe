#include "includes.h"
#include "Person_Check.h"
#include "Usart.h"

INT8U Check_Flag;
sbit Key_check = P3^6;

/******************
*******	函数名称： Person_Check（）
*******	函数功能： 电梯人体检测函数
*******	返回值  ： NULL
******************/
void Person_Check()
{
	if(CMD[7] == 0x08)
	{
		Check_Flag = 0;	
	}else if(CMD[8] == 0x09)
	{
		Check_Flag = 1;	
	}

}

		