#include "includes.h"
#include "Key_INIT.h"
#include "Floor_INIT.h"
#include "Usart.h"
#include "Delay_time.h"

INT8U UP_Flag,Down_Flag;	 //���������½���־λ
/******************
*******	�������ƣ� KEY_IN()
*******	�������ܣ� ���ݰ�����⺯��
*******	����ֵ  �� INT8U  0 1 2
******************/
INT8U KEY_IN(void)
{		
	if(Key0 == 0)
	{
		Delay_nms(2);
		if(Key0 == 0){
		LED0 = 1;
		send_string_uart("����0�㰴��\r\n");
		return 0;
		}
	} else		
	if(Key1 == 0)
	{	
		Delay_nms(2);
		if(Key1 == 0){
		LED1 = 1;
		send_string_uart("����1�㰴��\r\n");
		return 1;
		}
	} else
	if(Key2 == 0)
	{	
		Delay_nms(2);
		if(Key2 == 0){
		LED2 = 1;
		send_string_uart("����2�㰴��\r\n");
		return 2;
		}
	}
	return 3;
}
/******************
*******	�������ƣ� Key_INIT()
*******	�������ܣ� ����������⺯��
*******	����ֵ  �� NULL
******************/
void Key_INIT()
{
	if(Key0_UP == 0)
	{								 
		Delay_nms(2);
		if(Key0_UP == 0){
		LED0_UP = 1;
		UP_Flag = 0;
		send_string_uart("����0���ϼ�\r\n");
		}
	}

	if(Key1_UP == 0)
	{
		Delay_nms(2);
		if(Key1_UP == 0){
		LED1_UP = 1;
		UP_Flag = 1;
		send_string_uart("����1���ϼ�\r\n");
		}
	}		
	if(Key1_DOWN == 0)
	{
		Delay_nms(2);
		if(Key1_DOWN == 0){
		LED1_DOWN = 1;
		Down_Flag = 1;
		send_string_uart("����1���¼�\r\n");
		}
	}

	if(Key2_DOWN == 0)
	{
		Delay_nms(2);
		if(Key2_DOWN == 0){
		LED2_DOWN = 1;
		Down_Flag = 2;
		send_string_uart("����2���¼�\r\n");
		}
	}
}
