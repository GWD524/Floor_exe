#include "includes.h"
#include "Key_INIT.h"
#include "Floor_INIT.h"
#include "Usart.h"
#include "Delay_time.h"

INT8U UP_Flag,Down_Flag;	 //电梯上升下降标志位
/******************
*******	函数名称： KEY_IN()
*******	函数功能： 电梯按键检测函数
*******	返回值  ： INT8U  0 1 2
******************/
INT8U KEY_IN(void)
{		
	if(Key0 == 0)
	{
		Delay_nms(2);
		if(Key0 == 0){
		LED0 = 1;
		send_string_uart("按下0层按键\r\n");
		return 0;
		}
	} else		
	if(Key1 == 0)
	{	
		Delay_nms(2);
		if(Key1 == 0){
		LED1 = 1;
		send_string_uart("按下1层按键\r\n");
		return 1;
		}
	} else
	if(Key2 == 0)
	{	
		Delay_nms(2);
		if(Key2 == 0){
		LED2 = 1;
		send_string_uart("按下2层按键\r\n");
		return 2;
		}
	}
	return 3;
}
/******************
*******	函数名称： Key_INIT()
*******	函数功能： 电梯上升检测函数
*******	返回值  ： NULL
******************/
void Key_INIT()
{
	if(Key0_UP == 0)
	{								 
		Delay_nms(2);
		if(Key0_UP == 0){
		LED0_UP = 1;
		UP_Flag = 0;
		send_string_uart("按下0层上键\r\n");
		}
	}

	if(Key1_UP == 0)
	{
		Delay_nms(2);
		if(Key1_UP == 0){
		LED1_UP = 1;
		UP_Flag = 1;
		send_string_uart("按下1层上键\r\n");
		}
	}		
	if(Key1_DOWN == 0)
	{
		Delay_nms(2);
		if(Key1_DOWN == 0){
		LED1_DOWN = 1;
		Down_Flag = 1;
		send_string_uart("按下1层下键\r\n");
		}
	}

	if(Key2_DOWN == 0)
	{
		Delay_nms(2);
		if(Key2_DOWN == 0){
		LED2_DOWN = 1;
		Down_Flag = 2;
		send_string_uart("按下2层下键\r\n");
		}
	}
}
