#include "includes.h"
#include "Delay_time.h"


/*****************************************
***函数名: 	Delay_nms()
***函数描述:延时
***返回值： NULL
*****************************************/

void Delay_nms(unsigned int ms)		 //N ms延时函数
{
	INT16U i,j;
	for(i=ms;i>0;i--)
		for(j=110;j>0;j--);
}