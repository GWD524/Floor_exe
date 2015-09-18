#ifndef _KEY_INIT_H
#define _KEY_INIT_H
#include "includes.h"

sbit Key0 = P2^0;
sbit Key1 = P2^1;
sbit Key2 = P2^2;
sbit Key0_UP = P2^3;
sbit Key1_UP = P2^4;
sbit Key1_DOWN = P2^5;
sbit Key2_DOWN = P2^6;
sbit LED0 = P1^0;
sbit LED1 = P1^1;
sbit LED2 = P1^2;
sbit LED0_UP = P1^3;
sbit LED1_UP = P1^4;
sbit LED1_DOWN = P1^5;
sbit LED2_DOWN = P1^6;

extern INT8U UP_Flag,Down_Flag;	 //电梯上升下降标志位
extern void Key_INIT();
#endif