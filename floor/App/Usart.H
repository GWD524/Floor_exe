#ifndef _USART_H
#define _USART_H
#include "includes.h"
#define BUFLEN 64

extern INT8U CMD[10];
extern void send_data_uart(INT8U BYTE);
extern void Usart_Init();
extern void send_string_uart(INT8U * S);
#endif