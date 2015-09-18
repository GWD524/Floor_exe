#include "includes.h"
#include "Usart.h"

INT8U CMD[10];
/************************************************
***�������� Usart_Init
***��������: ���ڳ�ʼ������
***����ֵ : NULL
*************************************************/
void Usart_Init(){		//INT8U Baud

	SCON  |= 0x50;     //SM0=0��SM1=1 �����������н��� REN=1��
	TMOD  |= 0x20;	// ������ ��ʱ��T1 ��ʽ2  8λ�Զ���װ
	
	TH1  = 0xf3;	   
	TL1  = 0xf3;
	TR1  = 1;	   //������ʱ��
	EA=1;		  //�������ж�
}

/************************************************
***�������� send_data_uart1
***��������: �򴮿ڷ�����һ���ַ�
***����ֵ : NULL
*************************************************/
void send_data_uart(INT8U BYTE)
{
  	ES = 0 ;
    SBUF = BYTE;
    while(!TI); 			//TI�����жϱ�־λ���ֶ�����
    TI = 0 ;
    ES = 1 ;
}

/************************************************
***�������� send_string_uart1
***��������: ��һ���ַ�������������
***����ֵ : NULL
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
  