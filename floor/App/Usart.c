#include "includes.h"
#include "Usart.h"

INT8U CMD[10];
/************************************************
***函数名： Usart_Init
***函数描述: 串口初始化函数
***返回值 : NULL
*************************************************/
void Usart_Init(){		//INT8U Baud

	SCON  |= 0x50;     //SM0=0，SM1=1 ，启动允许串行接收 REN=1；
	TMOD  |= 0x20;	// 配置用 定时器T1 方式2  8位自动重装
	
	TH1  = 0xf3;	   
	TL1  = 0xf3;
	TR1  = 1;	   //开启定时器
	EA=1;		  //开启总中断
}

/************************************************
***函数名： send_data_uart1
***函数描述: 向串口发送数一个字符
***返回值 : NULL
*************************************************/
void send_data_uart(INT8U BYTE)
{
  	ES = 0 ;
    SBUF = BYTE;
    while(!TI); 			//TI发送中断标志位，手动清零
    TI = 0 ;
    ES = 1 ;
}

/************************************************
***函数名： send_string_uart1
***函数描述: 将一个字符串传送至串口
***返回值 : NULL
*************************************************/ 
void send_string_uart(INT8U * S)
{
    while(*S)
    {
        send_data_uart(*S++);
    }
}	
	
void USART_IRQHandler() interrupt 4 using 1
{
    INT8U ch;
	INT16U len;
	if(RI)
    {
		RI=0;
		ch = SBUF;  
		CMD[len] = ch;   	
    }

}	   
  