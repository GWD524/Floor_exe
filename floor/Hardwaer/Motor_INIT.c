#include "includes.h"
#include "Motor_INIT.h"
#include "Delay_time.h"
#include "Key_INIT.h"
INT8U PWM_H=0,n=0,i=0;
/******************
*******	�������ƣ� Motor_INIT����
*******	�������ܣ� ���ݵ����ʼ������
*******	����ֵ  �� NULL
******************/
void Motor_INIT()
{
	EA=1;
	ET1=1;
	TMOD=TMOD & 0X0F | 0x20;		
}
/******************
*******	�������ƣ� Motor_Set����
*******	�������ܣ� ���������ٶ����ú���	��4���ٶȿɵ���0��1��2��3����Ӧռ�ձȣ�0��1/4��2/4��3/4��
*******	����ֵ  �� INT8U v
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
*******	�������ƣ� Motor_UP����
*******	�������ܣ� ������������
*******	����ֵ  �� NULL
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
*******	�������ƣ� Motor_DOWN_INIT����
*******	�������ܣ� �����½�����
*******	����ֵ  �� NULL
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
*******	�������ƣ� Motor_Run����
*******	�������ܣ� ���������жϺ���
*******	����ֵ  �� NULL
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
