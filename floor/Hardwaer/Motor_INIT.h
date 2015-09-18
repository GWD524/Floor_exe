#ifndef _MOTOR_INIT_H
#define _MOTOR_INIT_H
#include "includes.h"

sbit PWM1 = P1^7;
sbit PWM2 = P3^7;
extern void Motor_INIT();
extern void Motor_Set(INT8U v);
extern void Motor_UP_INIT();
extern void Motor_DOWN_INIT();
extern INT8U KEY_IN(void);
#endif