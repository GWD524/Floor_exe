#include "includes.h"
#include "Delay_time.h"


/*****************************************
***������: 	Delay_nms()
***��������:��ʱ
***����ֵ�� NULL
*****************************************/

void Delay_nms(unsigned int ms)		 //N ms��ʱ����
{
	INT16U i,j;
	for(i=ms;i>0;i--)
		for(j=110;j>0;j--);
}